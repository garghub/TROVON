static int
dissect_ftam_Protocol_Version_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Protocol_Version_U_bits, hf_index, ett_ftam_Protocol_Version_U,
NULL);
return offset;
}
static int
dissect_ftam_Protocol_Version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 0, TRUE, dissect_ftam_Protocol_Version_U);
return offset;
}
static int
dissect_ftam_GraphicString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_Implementation_Information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 1, TRUE, dissect_ftam_GraphicString);
return offset;
}
static int
dissect_ftam_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_ftam_Service_Class_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Service_Class_U_bits, hf_index, ett_ftam_Service_Class_U,
NULL);
return offset;
}
static int
dissect_ftam_Service_Class(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_ftam_Service_Class_U);
return offset;
}
static int
dissect_ftam_Functional_Units_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Functional_Units_U_bits, hf_index, ett_ftam_Functional_Units_U,
NULL);
return offset;
}
static int
dissect_ftam_Functional_Units(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 4, TRUE, dissect_ftam_Functional_Units_U);
return offset;
}
static int
dissect_ftam_Attribute_Groups_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Attribute_Groups_U_bits, hf_index, ett_ftam_Attribute_Groups_U,
NULL);
return offset;
}
static int
dissect_ftam_Attribute_Groups(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 5, TRUE, dissect_ftam_Attribute_Groups_U);
return offset;
}
static int
dissect_ftam_EXTERNAL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_external_type(implicit_tag, tree, tvb, offset, actx, hf_index, NULL);
return offset;
}
static int
dissect_ftam_Shared_ASE_Information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 20, TRUE, dissect_ftam_EXTERNAL);
return offset;
}
static int
dissect_ftam_FTAM_Quality_of_Service_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_FTAM_Quality_of_Service(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 6, TRUE, dissect_ftam_FTAM_Quality_of_Service_U);
return offset;
}
static int
dissect_ftam_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
return offset;
}
static int
dissect_ftam_Document_Type_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 14, TRUE, dissect_ftam_OBJECT_IDENTIFIER);
return offset;
}
static int
dissect_ftam_Abstract_Syntax_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 0, TRUE, dissect_ftam_OBJECT_IDENTIFIER);
return offset;
}
static int
dissect_ftam_Contents_Type_List_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Contents_Type_List_item_choice, hf_index, ett_ftam_Contents_Type_List_item,
NULL);
return offset;
}
static int
dissect_ftam_Contents_Type_List_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Contents_Type_List_U_sequence_of, hf_index, ett_ftam_Contents_Type_List_U);
return offset;
}
static int
dissect_ftam_Contents_Type_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 7, TRUE, dissect_ftam_Contents_Type_List_U);
return offset;
}
static int
dissect_ftam_User_Identity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 22, TRUE, dissect_ftam_GraphicString);
return offset;
}
static int
dissect_ftam_Account(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 4, TRUE, dissect_ftam_GraphicString);
return offset;
}
static int
dissect_ftam_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_Password_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Password_U_choice, hf_index, ett_ftam_Password_U,
NULL);
return offset;
}
static int
dissect_ftam_Password(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 17, FALSE, dissect_ftam_Password_U);
return offset;
}
static int
dissect_ftam_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_F_INITIALIZE_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_INITIALIZE_request_sequence, hf_index, ett_ftam_F_INITIALIZE_request);
return offset;
}
static int
dissect_ftam_State_Result_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_State_Result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 21, TRUE, dissect_ftam_State_Result_U);
return offset;
}
static int
dissect_ftam_Action_Result_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_Action_Result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 5, TRUE, dissect_ftam_Action_Result_U);
return offset;
}
static int
dissect_ftam_T_diagnostic_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_Entity_Reference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_Diagnostic_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Diagnostic_item_sequence, hf_index, ett_ftam_Diagnostic_item);
return offset;
}
static int
dissect_ftam_Diagnostic_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Diagnostic_U_sequence_of, hf_index, ett_ftam_Diagnostic_U);
return offset;
}
static int
dissect_ftam_Diagnostic(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 13, TRUE, dissect_ftam_Diagnostic_U);
return offset;
}
static int
dissect_ftam_F_INITIALIZE_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_INITIALIZE_response_sequence, hf_index, ett_ftam_F_INITIALIZE_response);
return offset;
}
static int
dissect_ftam_F_TERMINATE_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_TERMINATE_request_sequence, hf_index, ett_ftam_F_TERMINATE_request);
return offset;
}
static int
dissect_ftam_Charging_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Charging_item_sequence, hf_index, ett_ftam_Charging_item);
return offset;
}
static int
dissect_ftam_Charging_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Charging_U_sequence_of, hf_index, ett_ftam_Charging_U);
return offset;
}
static int
dissect_ftam_Charging(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 9, TRUE, dissect_ftam_Charging_U);
return offset;
}
static int
dissect_ftam_F_TERMINATE_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_TERMINATE_response_sequence, hf_index, ett_ftam_F_TERMINATE_response);
return offset;
}
static int
dissect_ftam_F_U_ABORT_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_U_ABORT_request_sequence, hf_index, ett_ftam_F_U_ABORT_request);
return offset;
}
static int
dissect_ftam_F_P_ABORT_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_P_ABORT_request_sequence, hf_index, ett_ftam_F_P_ABORT_request);
return offset;
}
static int
dissect_ftam_FTAM_Regime_PDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 92 "../../asn1/ftam/ftam.cnf"
gint branch_taken;
offset = dissect_ber_choice(actx, tree, tvb, offset,
FTAM_Regime_PDU_choice, hf_index, ett_ftam_FTAM_Regime_PDU,
&branch_taken);
if( (branch_taken!=-1) && ftam_FTAM_Regime_PDU_vals[branch_taken].strptr ){
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s:", ftam_FTAM_Regime_PDU_vals[branch_taken].strptr);
}
return offset;
}
int
dissect_ftam_Pathname(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Pathname_sequence_of, hf_index, ett_ftam_Pathname);
return offset;
}
static int
dissect_ftam_Pathname_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Pathname_Attribute_choice, hf_index, ett_ftam_Pathname_Attribute,
NULL);
return offset;
}
static int
dissect_ftam_Select_Attributes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Select_Attributes_U_sequence, hf_index, ett_ftam_Select_Attributes_U);
return offset;
}
static int
dissect_ftam_Select_Attributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 19, TRUE, dissect_ftam_Select_Attributes_U);
return offset;
}
static int
dissect_ftam_Access_Request_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Access_Request_U_bits, hf_index, ett_ftam_Access_Request_U,
NULL);
return offset;
}
static int
dissect_ftam_Access_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 3, TRUE, dissect_ftam_Access_Request_U);
return offset;
}
static int
dissect_ftam_Pass_Passwords(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Pass_Passwords_sequence_of, hf_index, ett_ftam_Pass_Passwords);
return offset;
}
static int
dissect_ftam_Access_Passwords_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Access_Passwords_U_sequence, hf_index, ett_ftam_Access_Passwords_U);
return offset;
}
static int
dissect_ftam_Access_Passwords(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 2, TRUE, dissect_ftam_Access_Passwords_U);
return offset;
}
static int
dissect_ftam_Path_Access_Passwords_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Path_Access_Passwords_item_sequence, hf_index, ett_ftam_Path_Access_Passwords_item);
return offset;
}
static int
dissect_ftam_Path_Access_Passwords_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Path_Access_Passwords_U_sequence_of, hf_index, ett_ftam_Path_Access_Passwords_U);
return offset;
}
static int
dissect_ftam_Path_Access_Passwords(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 27, TRUE, dissect_ftam_Path_Access_Passwords_U);
return offset;
}
static int
dissect_ftam_Lock(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_Concurrency_Control_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Concurrency_Control_U_sequence, hf_index, ett_ftam_Concurrency_Control_U);
return offset;
}
static int
dissect_ftam_Concurrency_Control(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 10, TRUE, dissect_ftam_Concurrency_Control_U);
return offset;
}
static int
dissect_ftam_F_SELECT_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_SELECT_request_sequence, hf_index, ett_ftam_F_SELECT_request);
return offset;
}
static int
dissect_ftam_Referent_Indicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 29, TRUE, dissect_ftam_BOOLEAN);
return offset;
}
static int
dissect_ftam_F_SELECT_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_SELECT_response_sequence, hf_index, ett_ftam_F_SELECT_response);
return offset;
}
static int
dissect_ftam_F_DESELECT_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_DESELECT_request_sequence, hf_index, ett_ftam_F_DESELECT_request);
return offset;
}
static int
dissect_ftam_F_DESELECT_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_DESELECT_response_sequence, hf_index, ett_ftam_F_DESELECT_response);
return offset;
}
static int
dissect_ftam_Override(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_Object_Type_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_ftam_Permitted_Actions_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Permitted_Actions_Attribute_bits, hf_index, ett_ftam_Permitted_Actions_Attribute,
NULL);
return offset;
}
static int
dissect_ftam_T_parameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 75 "../../asn1/ftam/ftam.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_ftam_T_document_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_document_type_sequence, hf_index, ett_ftam_T_document_type);
return offset;
}
static int
dissect_ftam_Constraint_Set_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 11, TRUE, dissect_ftam_OBJECT_IDENTIFIER);
return offset;
}
static int
dissect_ftam_T_constraint_set_and_abstract_Syntax(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_constraint_set_and_abstract_Syntax_sequence, hf_index, ett_ftam_T_constraint_set_and_abstract_Syntax);
return offset;
}
static int
dissect_ftam_Contents_Type_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Contents_Type_Attribute_choice, hf_index, ett_ftam_Contents_Type_Attribute,
NULL);
return offset;
}
static int
dissect_ftam_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_ftam_Account_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Account_Attribute_choice, hf_index, ett_ftam_Account_Attribute,
NULL);
return offset;
}
static int
dissect_ftam_T_actual_values8(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_ftam_Object_Availability_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Object_Availability_Attribute_choice, hf_index, ett_ftam_Object_Availability_Attribute,
NULL);
return offset;
}
int
dissect_ftam_Object_Size_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Object_Size_Attribute_choice, hf_index, ett_ftam_Object_Size_Attribute,
NULL);
return offset;
}
static int
dissect_ftam_Concurrency_Key(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Concurrency_Key_bits, hf_index, ett_ftam_Concurrency_Key,
NULL);
return offset;
}
int
dissect_ftam_Concurrency_Access(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Concurrency_Access_sequence, hf_index, ett_ftam_Concurrency_Access);
return offset;
}
static int
dissect_ftam_AP_title(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 87 "../../asn1/ftam/ftam.cnf"
return offset;
}
static int
dissect_ftam_AE_qualifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 89 "../../asn1/ftam/ftam.cnf"
return offset;
}
static int
dissect_ftam_AE_title(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AE_title_sequence, hf_index, ett_ftam_AE_title);
return offset;
}
static int
dissect_ftam_Application_Entity_Title(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 7, FALSE, dissect_ftam_AE_title);
return offset;
}
static int
dissect_ftam_Access_Control_Element(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Access_Control_Element_sequence, hf_index, ett_ftam_Access_Control_Element);
return offset;
}
static int
dissect_ftam_SET_OF_Access_Control_Element(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_Access_Control_Element_set_of, hf_index, ett_ftam_SET_OF_Access_Control_Element);
return offset;
}
static int
dissect_ftam_Access_Control_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Access_Control_Attribute_choice, hf_index, ett_ftam_Access_Control_Attribute,
NULL);
return offset;
}
int
dissect_ftam_Legal_Qualification_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Legal_Qualification_Attribute_choice, hf_index, ett_ftam_Legal_Qualification_Attribute,
NULL);
return offset;
}
int
dissect_ftam_Private_Use_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Private_Use_Attribute_choice, hf_index, ett_ftam_Private_Use_Attribute,
NULL);
return offset;
}
static int
dissect_ftam_Extension_Set_Identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_ftam_T_extension_attribute_identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
return offset;
}
static int
dissect_ftam_T_extension_attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 78 "../../asn1/ftam/ftam.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_ftam_Extension_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Extension_Attribute_sequence, hf_index, ett_ftam_Extension_Attribute);
return offset;
}
static int
dissect_ftam_SEQUENCE_OF_Extension_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Extension_Attribute_sequence_of, hf_index, ett_ftam_SEQUENCE_OF_Extension_Attribute);
return offset;
}
static int
dissect_ftam_Attribute_Extension_Set(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Attribute_Extension_Set_sequence, hf_index, ett_ftam_Attribute_Extension_Set);
return offset;
}
int
dissect_ftam_Attribute_Extensions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Attribute_Extensions_sequence_of, hf_index, ett_ftam_Attribute_Extensions);
return offset;
}
static int
dissect_ftam_Create_Attributes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Create_Attributes_U_sequence, hf_index, ett_ftam_Create_Attributes_U);
return offset;
}
static int
dissect_ftam_Create_Attributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 12, TRUE, dissect_ftam_Create_Attributes_U);
return offset;
}
static int
dissect_ftam_F_CREATE_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CREATE_request_sequence, hf_index, ett_ftam_F_CREATE_request);
return offset;
}
static int
dissect_ftam_F_CREATE_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CREATE_response_sequence, hf_index, ett_ftam_F_CREATE_response);
return offset;
}
static int
dissect_ftam_F_DELETE_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_DELETE_request_sequence, hf_index, ett_ftam_F_DELETE_request);
return offset;
}
static int
dissect_ftam_F_DELETE_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_DELETE_response_sequence, hf_index, ett_ftam_F_DELETE_response);
return offset;
}
static int
dissect_ftam_Attribute_Names(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Attribute_Names_bits, hf_index, ett_ftam_Attribute_Names,
NULL);
return offset;
}
static int
dissect_ftam_Extension_Attribute_identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_ftam_SEQUENCE_OF_Extension_Attribute_identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Extension_Attribute_identifier_sequence_of, hf_index, ett_ftam_SEQUENCE_OF_Extension_Attribute_identifier);
return offset;
}
static int
dissect_ftam_Attribute_Extension_Set_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Attribute_Extension_Set_Name_sequence, hf_index, ett_ftam_Attribute_Extension_Set_Name);
return offset;
}
static int
dissect_ftam_Attribute_Extension_Names(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Attribute_Extension_Names_sequence_of, hf_index, ett_ftam_Attribute_Extension_Names);
return offset;
}
static int
dissect_ftam_F_READ_ATTRIB_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_READ_ATTRIB_request_sequence, hf_index, ett_ftam_F_READ_ATTRIB_request);
return offset;
}
static int
dissect_ftam_Child_Objects_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
Child_Objects_Attribute_set_of, hf_index, ett_ftam_Child_Objects_Attribute);
return offset;
}
static int
dissect_ftam_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
int
dissect_ftam_Date_and_Time_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Date_and_Time_Attribute_choice, hf_index, ett_ftam_Date_and_Time_Attribute,
NULL);
return offset;
}
static int
dissect_ftam_User_Identity_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
User_Identity_Attribute_choice, hf_index, ett_ftam_User_Identity_Attribute,
NULL);
return offset;
}
static int
dissect_ftam_Read_Attributes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Read_Attributes_U_sequence, hf_index, ett_ftam_Read_Attributes_U);
return offset;
}
static int
dissect_ftam_Read_Attributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 18, TRUE, dissect_ftam_Read_Attributes_U);
return offset;
}
static int
dissect_ftam_F_READ_ATTRIB_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_READ_ATTRIB_response_sequence, hf_index, ett_ftam_F_READ_ATTRIB_response);
return offset;
}
static int
dissect_ftam_T_actual_values1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_actual_values1_sequence, hf_index, ett_ftam_T_actual_values1);
return offset;
}
static int
dissect_ftam_Access_Control_Change_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Access_Control_Change_Attribute_choice, hf_index, ett_ftam_Access_Control_Change_Attribute,
NULL);
return offset;
}
static int
dissect_ftam_Change_Attributes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Change_Attributes_U_sequence, hf_index, ett_ftam_Change_Attributes_U);
return offset;
}
static int
dissect_ftam_Change_Attributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 8, TRUE, dissect_ftam_Change_Attributes_U);
return offset;
}
static int
dissect_ftam_F_CHANGE_ATTRIB_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CHANGE_ATTRIB_request_sequence, hf_index, ett_ftam_F_CHANGE_ATTRIB_request);
return offset;
}
static int
dissect_ftam_F_CHANGE_ATTRIB_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CHANGE_ATTRIB_response_sequence, hf_index, ett_ftam_F_CHANGE_ATTRIB_response);
return offset;
}
static int
dissect_ftam_T_processing_mode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_processing_mode_bits, hf_index, ett_ftam_T_processing_mode,
NULL);
return offset;
}
static int
dissect_ftam_T_open_contents_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_open_contents_type_choice, hf_index, ett_ftam_T_open_contents_type,
NULL);
return offset;
}
static int
dissect_ftam_Activity_Identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 6, TRUE, dissect_ftam_INTEGER);
return offset;
}
static int
dissect_ftam_T_request_recovery_mode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_SET_OF_Abstract_Syntax_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_Abstract_Syntax_Name_set_of, hf_index, ett_ftam_SET_OF_Abstract_Syntax_Name);
return offset;
}
static int
dissect_ftam_Degree_Of_Overlap_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_Degree_Of_Overlap(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 30, TRUE, dissect_ftam_Degree_Of_Overlap_U);
return offset;
}
static int
dissect_ftam_F_OPEN_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_OPEN_request_sequence, hf_index, ett_ftam_F_OPEN_request);
return offset;
}
static int
dissect_ftam_T_response_recovery_mode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_F_OPEN_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_OPEN_response_sequence, hf_index, ett_ftam_F_OPEN_response);
return offset;
}
static int
dissect_ftam_F_CLOSE_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CLOSE_request_sequence, hf_index, ett_ftam_F_CLOSE_request);
return offset;
}
static int
dissect_ftam_F_CLOSE_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CLOSE_response_sequence, hf_index, ett_ftam_F_CLOSE_response);
return offset;
}
static int
dissect_ftam_F_BEGIN_GROUP_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_BEGIN_GROUP_request_sequence, hf_index, ett_ftam_F_BEGIN_GROUP_request);
return offset;
}
static int
dissect_ftam_F_BEGIN_GROUP_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_BEGIN_GROUP_response_sequence, hf_index, ett_ftam_F_BEGIN_GROUP_response);
return offset;
}
static int
dissect_ftam_F_END_GROUP_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_END_GROUP_request_sequence, hf_index, ett_ftam_F_END_GROUP_request);
return offset;
}
static int
dissect_ftam_F_END_GROUP_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_END_GROUP_response_sequence, hf_index, ett_ftam_F_END_GROUP_response);
return offset;
}
static int
dissect_ftam_F_RECOVER_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_RECOVER_request_sequence, hf_index, ett_ftam_F_RECOVER_request);
return offset;
}
static int
dissect_ftam_F_RECOVER_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_RECOVER_response_sequence, hf_index, ett_ftam_F_RECOVER_response);
return offset;
}
static int
dissect_ftam_T_first_last(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_T_relative(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_T_begin_end(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_Node_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_external_type(implicit_tag, tree, tvb, offset, actx, hf_index, NULL);
return offset;
}
static int
dissect_ftam_SEQUENCE_OF_Node_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Node_Name_sequence_of, hf_index, ett_ftam_SEQUENCE_OF_Node_Name);
return offset;
}
static int
dissect_ftam_FADU_Identity_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
FADU_Identity_U_choice, hf_index, ett_ftam_FADU_Identity_U,
NULL);
return offset;
}
static int
dissect_ftam_FADU_Identity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 15, FALSE, dissect_ftam_FADU_Identity_U);
return offset;
}
static int
dissect_ftam_FADU_Lock_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_FADU_Lock(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 16, TRUE, dissect_ftam_FADU_Lock_U);
return offset;
}
static int
dissect_ftam_F_LOCATE_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_LOCATE_request_sequence, hf_index, ett_ftam_F_LOCATE_request);
return offset;
}
static int
dissect_ftam_F_LOCATE_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_LOCATE_response_sequence, hf_index, ett_ftam_F_LOCATE_response);
return offset;
}
static int
dissect_ftam_F_ERASE_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_ERASE_request_sequence, hf_index, ett_ftam_F_ERASE_request);
return offset;
}
static int
dissect_ftam_F_ERASE_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_ERASE_response_sequence, hf_index, ett_ftam_F_ERASE_response);
return offset;
}
static int
dissect_ftam_File_PDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 101 "../../asn1/ftam/ftam.cnf"
gint branch_taken;
offset = dissect_ber_choice(actx, tree, tvb, offset,
File_PDU_choice, hf_index, ett_ftam_File_PDU,
&branch_taken);
if( (branch_taken!=-1) && ftam_File_PDU_vals[branch_taken].strptr ){
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s:", ftam_File_PDU_vals[branch_taken].strptr);
}
return offset;
}
static int
dissect_ftam_T_access_context(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_Access_Context_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Access_Context_U_sequence, hf_index, ett_ftam_Access_Context_U);
return offset;
}
static int
dissect_ftam_Access_Context(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 1, TRUE, dissect_ftam_Access_Context_U);
return offset;
}
static int
dissect_ftam_F_READ_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_READ_request_sequence, hf_index, ett_ftam_F_READ_request);
return offset;
}
static int
dissect_ftam_T_file_access_data_unit_Operation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_F_WRITE_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_WRITE_request_sequence, hf_index, ett_ftam_F_WRITE_request);
return offset;
}
static int
dissect_ftam_F_DATA_END_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_DATA_END_request_sequence, hf_index, ett_ftam_F_DATA_END_request);
return offset;
}
static int
dissect_ftam_Request_Type_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_Request_Type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 31, TRUE, dissect_ftam_Request_Type_U);
return offset;
}
static int
dissect_ftam_F_TRANSFER_END_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_TRANSFER_END_request_sequence, hf_index, ett_ftam_F_TRANSFER_END_request);
return offset;
}
static int
dissect_ftam_F_TRANSFER_END_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_TRANSFER_END_response_sequence, hf_index, ett_ftam_F_TRANSFER_END_response);
return offset;
}
static int
dissect_ftam_F_CANCEL_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CANCEL_request_sequence, hf_index, ett_ftam_F_CANCEL_request);
return offset;
}
static int
dissect_ftam_F_CANCEL_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CANCEL_response_sequence, hf_index, ett_ftam_F_CANCEL_response);
return offset;
}
static int
dissect_ftam_F_RESTART_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_RESTART_request_sequence, hf_index, ett_ftam_F_RESTART_request);
return offset;
}
static int
dissect_ftam_F_RESTART_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_RESTART_response_sequence, hf_index, ett_ftam_F_RESTART_response);
return offset;
}
static int
dissect_ftam_Bulk_Data_PDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 110 "../../asn1/ftam/ftam.cnf"
gint branch_taken;
offset = dissect_ber_choice(actx, tree, tvb, offset,
Bulk_Data_PDU_choice, hf_index, ett_ftam_Bulk_Data_PDU,
&branch_taken);
if( (branch_taken!=-1) && ftam_Bulk_Data_PDU_vals[branch_taken].strptr ){
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s:", ftam_Bulk_Data_PDU_vals[branch_taken].strptr);
}
return offset;
}
static int
dissect_ftam_Destination_File_Directory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 24, FALSE, dissect_ftam_Pathname_Attribute);
return offset;
}
static int
dissect_ftam_F_CHANGE_PREFIX_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CHANGE_PREFIX_request_sequence, hf_index, ett_ftam_F_CHANGE_PREFIX_request);
return offset;
}
static int
dissect_ftam_F_CHANGE_PREFIX_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CHANGE_PREFIX_response_sequence, hf_index, ett_ftam_F_CHANGE_PREFIX_response);
return offset;
}
static int
dissect_ftam_Equality_Comparision(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Equality_Comparision_bits, hf_index, ett_ftam_Equality_Comparision,
NULL);
return offset;
}
static int
dissect_ftam_T_string_value_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_string_value_item_choice, hf_index, ett_ftam_T_string_value_item,
NULL);
return offset;
}
static int
dissect_ftam_T_string_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_string_value_sequence_of, hf_index, ett_ftam_T_string_value);
return offset;
}
static int
dissect_ftam_String_Pattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
String_Pattern_sequence, hf_index, ett_ftam_String_Pattern);
return offset;
}
static int
dissect_ftam_T_pathname_value_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_pathname_value_item_choice, hf_index, ett_ftam_T_pathname_value_item,
NULL);
return offset;
}
static int
dissect_ftam_T_pathname_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_pathname_value_sequence_of, hf_index, ett_ftam_T_pathname_value);
return offset;
}
static int
dissect_ftam_Pathname_Pattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Pathname_Pattern_sequence, hf_index, ett_ftam_Pathname_Pattern);
return offset;
}
static int
dissect_ftam_Relational_Comparision(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Relational_Comparision_bits, hf_index, ett_ftam_Relational_Comparision,
NULL);
return offset;
}
static int
dissect_ftam_Integer_Pattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Integer_Pattern_sequence, hf_index, ett_ftam_Integer_Pattern);
return offset;
}
static int
dissect_ftam_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_ftam_Bitstring_Pattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Bitstring_Pattern_sequence, hf_index, ett_ftam_Bitstring_Pattern);
return offset;
}
static int
dissect_ftam_Object_Identifier_Pattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Object_Identifier_Pattern_sequence, hf_index, ett_ftam_Object_Identifier_Pattern);
return offset;
}
static int
dissect_ftam_T_constraint_set_abstract_Syntax_Pattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_constraint_set_abstract_Syntax_Pattern_sequence, hf_index, ett_ftam_T_constraint_set_abstract_Syntax_Pattern);
return offset;
}
static int
dissect_ftam_Contents_Type_Pattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Contents_Type_Pattern_choice, hf_index, ett_ftam_Contents_Type_Pattern,
NULL);
return offset;
}
static int
dissect_ftam_Date_and_Time_Pattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Date_and_Time_Pattern_sequence, hf_index, ett_ftam_Date_and_Time_Pattern);
return offset;
}
static int
dissect_ftam_User_Identity_Pattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ftam_String_Pattern(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ftam_Boolean_Pattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Boolean_Pattern_sequence, hf_index, ett_ftam_Boolean_Pattern);
return offset;
}
static int
dissect_ftam_T_attribute_extension_attribute_identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
return offset;
}
static int
dissect_ftam_T_extension_attribute_Pattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 84 "../../asn1/ftam/ftam.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_ftam_T_extension_set_attribute_Patterns_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_extension_set_attribute_Patterns_item_sequence, hf_index, ett_ftam_T_extension_set_attribute_Patterns_item);
return offset;
}
static int
dissect_ftam_T_extension_set_attribute_Patterns(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_extension_set_attribute_Patterns_sequence_of, hf_index, ett_ftam_T_extension_set_attribute_Patterns);
return offset;
}
static int
dissect_ftam_Attribute_Extensions_Pattern_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Attribute_Extensions_Pattern_item_sequence, hf_index, ett_ftam_Attribute_Extensions_Pattern_item);
return offset;
}
static int
dissect_ftam_Attribute_Extensions_Pattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Attribute_Extensions_Pattern_sequence_of, hf_index, ett_ftam_Attribute_Extensions_Pattern);
return offset;
}
static int
dissect_ftam_AND_Set_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AND_Set_item_choice, hf_index, ett_ftam_AND_Set_item,
NULL);
return offset;
}
static int
dissect_ftam_AND_Set(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AND_Set_sequence_of, hf_index, ett_ftam_AND_Set);
return offset;
}
static int
dissect_ftam_OR_Set(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
OR_Set_sequence_of, hf_index, ett_ftam_OR_Set);
return offset;
}
static int
dissect_ftam_Attribute_Value_Assertions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 26, TRUE, dissect_ftam_OR_Set);
return offset;
}
static int
dissect_ftam_T_retrieval_scope(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_T__untag_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T__untag_item_sequence, hf_index, ett_ftam_T__untag_item);
return offset;
}
static int
dissect_ftam_Scope_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Scope_U_sequence_of, hf_index, ett_ftam_Scope_U);
return offset;
}
static int
dissect_ftam_Scope(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 28, TRUE, dissect_ftam_Scope_U);
return offset;
}
static int
dissect_ftam_F_LIST_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_LIST_request_sequence, hf_index, ett_ftam_F_LIST_request);
return offset;
}
static int
dissect_ftam_SEQUENCE_OF_Read_Attributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Read_Attributes_sequence_of, hf_index, ett_ftam_SEQUENCE_OF_Read_Attributes);
return offset;
}
static int
dissect_ftam_Objects_Attributes_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 25, TRUE, dissect_ftam_SEQUENCE_OF_Read_Attributes);
return offset;
}
static int
dissect_ftam_F_LIST_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_LIST_response_sequence, hf_index, ett_ftam_F_LIST_response);
return offset;
}
static int
dissect_ftam_F_GROUP_SELECT_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_GROUP_SELECT_request_sequence, hf_index, ett_ftam_F_GROUP_SELECT_request);
return offset;
}
static int
dissect_ftam_F_GROUP_SELECT_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_GROUP_SELECT_response_sequence, hf_index, ett_ftam_F_GROUP_SELECT_response);
return offset;
}
static int
dissect_ftam_Request_Operation_Result_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_Request_Operation_Result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 31, TRUE, dissect_ftam_Request_Operation_Result_U);
return offset;
}
static int
dissect_ftam_F_GROUP_DELETE_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_GROUP_DELETE_request_sequence, hf_index, ett_ftam_F_GROUP_DELETE_request);
return offset;
}
static int
dissect_ftam_SEQUENCE_OF_Pathname(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Pathname_sequence_of, hf_index, ett_ftam_SEQUENCE_OF_Pathname);
return offset;
}
static int
dissect_ftam_Operation_Result_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Operation_Result_U_choice, hf_index, ett_ftam_Operation_Result_U,
NULL);
return offset;
}
static int
dissect_ftam_Operation_Result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 30, FALSE, dissect_ftam_Operation_Result_U);
return offset;
}
static int
dissect_ftam_F_GROUP_DELETE_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_GROUP_DELETE_response_sequence, hf_index, ett_ftam_F_GROUP_DELETE_response);
return offset;
}
static int
dissect_ftam_Error_Action(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ftam_F_GROUP_MOVE_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_GROUP_MOVE_request_sequence, hf_index, ett_ftam_F_GROUP_MOVE_request);
return offset;
}
static int
dissect_ftam_F_GROUP_MOVE_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_GROUP_MOVE_response_sequence, hf_index, ett_ftam_F_GROUP_MOVE_response);
return offset;
}
static int
dissect_ftam_F_GROUP_COPY_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_GROUP_COPY_request_sequence, hf_index, ett_ftam_F_GROUP_COPY_request);
return offset;
}
static int
dissect_ftam_F_GROUP_COPY_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_GROUP_COPY_response_sequence, hf_index, ett_ftam_F_GROUP_COPY_response);
return offset;
}
static int
dissect_ftam_F_GROUP_LIST_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_GROUP_LIST_request_sequence, hf_index, ett_ftam_F_GROUP_LIST_request);
return offset;
}
static int
dissect_ftam_F_GROUP_LIST_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_GROUP_LIST_response_sequence, hf_index, ett_ftam_F_GROUP_LIST_response);
return offset;
}
static int
dissect_ftam_F_GROUP_CHANGE_ATTRIB_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_GROUP_CHANGE_ATTRIB_request_sequence, hf_index, ett_ftam_F_GROUP_CHANGE_ATTRIB_request);
return offset;
}
static int
dissect_ftam_F_GROUP_CHANGE_ATTRIB_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_GROUP_CHANGE_ATTRIB_response_sequence, hf_index, ett_ftam_F_GROUP_CHANGE_ATTRIB_response);
return offset;
}
static int
dissect_ftam_F_SELECT_ANOTHER_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_SELECT_ANOTHER_request_sequence, hf_index, ett_ftam_F_SELECT_ANOTHER_request);
return offset;
}
static int
dissect_ftam_F_SELECT_ANOTHER_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_SELECT_ANOTHER_response_sequence, hf_index, ett_ftam_F_SELECT_ANOTHER_response);
return offset;
}
static int
dissect_ftam_F_CREATE_DIRECTORY_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CREATE_DIRECTORY_request_sequence, hf_index, ett_ftam_F_CREATE_DIRECTORY_request);
return offset;
}
static int
dissect_ftam_F_CREATE_DIRECTORY_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CREATE_DIRECTORY_response_sequence, hf_index, ett_ftam_F_CREATE_DIRECTORY_response);
return offset;
}
static int
dissect_ftam_F_LINK_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_LINK_request_sequence, hf_index, ett_ftam_F_LINK_request);
return offset;
}
static int
dissect_ftam_F_LINK_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_LINK_response_sequence, hf_index, ett_ftam_F_LINK_response);
return offset;
}
static int
dissect_ftam_F_UNLINK_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_UNLINK_request_sequence, hf_index, ett_ftam_F_UNLINK_request);
return offset;
}
static int
dissect_ftam_F_UNLINK_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_UNLINK_response_sequence, hf_index, ett_ftam_F_UNLINK_response);
return offset;
}
static int
dissect_ftam_F_READ_LINK_ATTRIB_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_READ_LINK_ATTRIB_request_sequence, hf_index, ett_ftam_F_READ_LINK_ATTRIB_request);
return offset;
}
static int
dissect_ftam_F_READ_LINK_ATTRIB_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_READ_LINK_ATTRIB_response_sequence, hf_index, ett_ftam_F_READ_LINK_ATTRIB_response);
return offset;
}
static int
dissect_ftam_F_CHANGE_LINK_ATTRIB_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CHANGE_LINK_ATTRIB_request_sequence, hf_index, ett_ftam_F_CHANGE_LINK_ATTRIB_request);
return offset;
}
static int
dissect_ftam_F_CHANGE_LINK_ATTRIB_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_CHANGE_LINK_ATTRIB_response_sequence, hf_index, ett_ftam_F_CHANGE_LINK_ATTRIB_response);
return offset;
}
static int
dissect_ftam_F_MOVE_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_MOVE_request_sequence, hf_index, ett_ftam_F_MOVE_request);
return offset;
}
static int
dissect_ftam_F_MOVE_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_MOVE_response_sequence, hf_index, ett_ftam_F_MOVE_response);
return offset;
}
static int
dissect_ftam_F_COPY_request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_COPY_request_sequence, hf_index, ett_ftam_F_COPY_request);
return offset;
}
static int
dissect_ftam_F_COPY_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
F_COPY_response_sequence, hf_index, ett_ftam_F_COPY_response);
return offset;
}
static int
dissect_ftam_FSM_PDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 119 "../../asn1/ftam/ftam.cnf"
gint branch_taken;
offset = dissect_ber_choice(actx, tree, tvb, offset,
FSM_PDU_choice, hf_index, ett_ftam_FSM_PDU,
&branch_taken);
if( (branch_taken!=-1) && ftam_FSM_PDU_vals[branch_taken].strptr ){
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s:", ftam_FSM_PDU_vals[branch_taken].strptr);
}
return offset;
}
static int
dissect_ftam_PDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PDU_choice, hf_index, ett_ftam_PDU,
NULL);
return offset;
}
static void
dissect_ftam_unstructured_text(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree)
{
proto_tree_add_item (parent_tree, hf_ftam_unstructured_text, tvb, 0, tvb_length_remaining(tvb, 0), ENC_ASCII|ENC_NA);
}
static void
dissect_ftam_unstructured_binary(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree)
{
proto_tree_add_item (parent_tree, hf_ftam_unstructured_binary, tvb, 0, tvb_length_remaining(tvb, 0), ENC_NA);
}
static void
dissect_ftam(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
int old_offset;
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_ftam, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_ftam);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FTAM");
col_clear(pinfo->cinfo, COL_INFO);
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset=offset;
offset=dissect_ftam_PDU(FALSE, tvb, offset, &asn1_ctx, tree, -1);
if(offset == old_offset){
proto_tree_add_text(tree, tvb, offset, -1,"Internal error, zero-byte FTAM PDU");
break;
}
}
}
void proto_register_ftam(void) {
static hf_register_info hf[] =
{
{ &hf_ftam_unstructured_text,
{ "ISO FTAM unstructured text", "ftam.unstructured_text", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_ftam_unstructured_binary,
{ "ISO FTAM unstructured binary", "ftam.unstructured_binary", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL } },
#line 1 "../../asn1/ftam/packet-ftam-hfarr.c"
{ &hf_ftam_fTAM_Regime_PDU,
{ "fTAM-Regime-PDU", "ftam.fTAM_Regime_PDU",
FT_UINT32, BASE_DEC, VALS(ftam_FTAM_Regime_PDU_vals), 0,
NULL, HFILL }},
{ &hf_ftam_file_PDU,
{ "file-PDU", "ftam.file_PDU",
FT_UINT32, BASE_DEC, VALS(ftam_File_PDU_vals), 0,
NULL, HFILL }},
{ &hf_ftam_bulk_Data_PDU,
{ "bulk-Data-PDU", "ftam.bulk_Data_PDU",
FT_UINT32, BASE_DEC, VALS(ftam_Bulk_Data_PDU_vals), 0,
NULL, HFILL }},
{ &hf_ftam_fSM_PDU,
{ "fSM-PDU", "ftam.fSM_PDU",
FT_UINT32, BASE_DEC, VALS(ftam_FSM_PDU_vals), 0,
NULL, HFILL }},
{ &hf_ftam_f_initialize_request,
{ "f-initialize-request", "ftam.f_initialize_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_initialize_response,
{ "f-initialize-response", "ftam.f_initialize_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_terminate_request,
{ "f-terminate-request", "ftam.f_terminate_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_terminate_response,
{ "f-terminate-response", "ftam.f_terminate_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_u_abort_request,
{ "f-u-abort-request", "ftam.f_u_abort_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_p_abort_request,
{ "f-p-abort-request", "ftam.f_p_abort_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_protocol_Version,
{ "protocol-Version", "ftam.protocol_Version",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_implementation_information,
{ "implementation-information", "ftam.implementation_information",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_presentation_tontext_management,
{ "presentation-tontext-management", "ftam.presentation_tontext_management",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ftam_service_class,
{ "service-class", "ftam.service_class",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_functional_units,
{ "functional-units", "ftam.functional_units",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_attribute_groups,
{ "attribute-groups", "ftam.attribute_groups",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_shared_ASE_information,
{ "shared-ASE-information", "ftam.shared_ASE_information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_ftam_quality_of_Service,
{ "ftam-quality-of-Service", "ftam.ftam_quality_of_Service",
FT_INT32, BASE_DEC, VALS(ftam_FTAM_Quality_of_Service_U_vals), 0,
NULL, HFILL }},
{ &hf_ftam_contents_type_list,
{ "contents-type-list", "ftam.contents_type_list",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_initiator_identity,
{ "initiator-identity", "ftam.initiator_identity",
FT_STRING, BASE_NONE, NULL, 0,
"User_Identity", HFILL }},
{ &hf_ftam_account,
{ "account", "ftam.account",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_filestore_password,
{ "filestore-password", "ftam.filestore_password",
FT_UINT32, BASE_DEC, VALS(ftam_Password_U_vals), 0,
"Password", HFILL }},
{ &hf_ftam_checkpoint_window,
{ "checkpoint-window", "ftam.checkpoint_window",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_state_result,
{ "state-result", "ftam.state_result",
FT_INT32, BASE_DEC, VALS(ftam_State_Result_U_vals), 0,
NULL, HFILL }},
{ &hf_ftam_action_result,
{ "action-result", "ftam.action_result",
FT_INT32, BASE_DEC, VALS(ftam_Action_Result_U_vals), 0,
NULL, HFILL }},
{ &hf_ftam_diagnostic,
{ "diagnostic", "ftam.diagnostic",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam__untag_item,
{ "_untag item", "ftam._untag_item",
FT_UINT32, BASE_DEC, VALS(ftam_Contents_Type_List_item_vals), 0,
"Contents_Type_List_item", HFILL }},
{ &hf_ftam_document_type_name,
{ "document-type-name", "ftam.document_type_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_abstract_Syntax_name,
{ "abstract-Syntax-name", "ftam.abstract_Syntax_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_charging,
{ "charging", "ftam.charging",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_select_request,
{ "f-select-request", "ftam.f_select_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_select_response,
{ "f-select-response", "ftam.f_select_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_deselect_request,
{ "f-deselect-request", "ftam.f_deselect_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_deselect_response,
{ "f-deselect-response", "ftam.f_deselect_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_create_request,
{ "f-create-request", "ftam.f_create_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_create_response,
{ "f-create-response", "ftam.f_create_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_delete_request,
{ "f-delete-request", "ftam.f_delete_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_delete_response,
{ "f-delete-response", "ftam.f_delete_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_read_attrib_request,
{ "f-read-attrib-request", "ftam.f_read_attrib_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_read_attrib_response,
{ "f-read-attrib-response", "ftam.f_read_attrib_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_Change_attrib_reques,
{ "f-Change-attrib-reques", "ftam.f_Change_attrib_reques_element",
FT_NONE, BASE_NONE, NULL, 0,
"F_CHANGE_ATTRIB_request", HFILL }},
{ &hf_ftam_f_Change_attrib_respon,
{ "f-Change-attrib-respon", "ftam.f_Change_attrib_respon_element",
FT_NONE, BASE_NONE, NULL, 0,
"F_CHANGE_ATTRIB_response", HFILL }},
{ &hf_ftam_f_open_request,
{ "f-open-request", "ftam.f_open_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_open_response,
{ "f-open-response", "ftam.f_open_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_close_request,
{ "f-close-request", "ftam.f_close_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_close_response,
{ "f-close-response", "ftam.f_close_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_begin_group_request,
{ "f-begin-group-request", "ftam.f_begin_group_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_begin_group_response,
{ "f-begin-group-response", "ftam.f_begin_group_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_end_group_request,
{ "f-end-group-request", "ftam.f_end_group_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_end_group_response,
{ "f-end-group-response", "ftam.f_end_group_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_recover_request,
{ "f-recover-request", "ftam.f_recover_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_recover_response,
{ "f-recover-response", "ftam.f_recover_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_locate_request,
{ "f-locate-request", "ftam.f_locate_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_locate_response,
{ "f-locate-response", "ftam.f_locate_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_erase_request,
{ "f-erase-request", "ftam.f_erase_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_erase_response,
{ "f-erase-response", "ftam.f_erase_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_select_attributes,
{ "attributes", "ftam.attributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"Select_Attributes", HFILL }},
{ &hf_ftam_requested_access,
{ "requested-access", "ftam.requested_access",
FT_BYTES, BASE_NONE, NULL, 0,
"Access_Request", HFILL }},
{ &hf_ftam_access_passwords,
{ "access-passwords", "ftam.access_passwords_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_path_access_passwords,
{ "path-access-passwords", "ftam.path_access_passwords",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_concurrency_control,
{ "concurrency-control", "ftam.concurrency_control_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_referent_indicator,
{ "referent-indicator", "ftam.referent_indicator",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_override,
{ "override", "ftam.override",
FT_INT32, BASE_DEC, VALS(ftam_Override_vals), 0,
NULL, HFILL }},
{ &hf_ftam_initial_attributes,
{ "initial-attributes", "ftam.initial_attributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"Create_Attributes", HFILL }},
{ &hf_ftam_create_password,
{ "create-password", "ftam.create_password",
FT_UINT32, BASE_DEC, VALS(ftam_Password_U_vals), 0,
"Password", HFILL }},
{ &hf_ftam_attribute_names,
{ "attribute-names", "ftam.attribute_names",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_attribute_extension_names,
{ "attribute-extension-names", "ftam.attribute_extension_names",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_read_attributes,
{ "attributes", "ftam.attributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"Read_Attributes", HFILL }},
{ &hf_ftam_attributes,
{ "attributes", "ftam.attributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"Change_Attributes", HFILL }},
{ &hf_ftam_processing_mode,
{ "processing-mode", "ftam.processing_mode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_open_contents_type,
{ "contents-type", "ftam.contents_type",
FT_UINT32, BASE_DEC, VALS(ftam_T_open_contents_type_vals), 0,
"T_open_contents_type", HFILL }},
{ &hf_ftam_unknown,
{ "unknown", "ftam.unknown_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_proposed,
{ "proposed", "ftam.proposed",
FT_UINT32, BASE_DEC, VALS(ftam_Contents_Type_Attribute_vals), 0,
"Contents_Type_Attribute", HFILL }},
{ &hf_ftam_enable_fadu_locking,
{ "enable-fadu-locking", "ftam.enable_fadu_locking",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ftam_activity_identifier,
{ "activity-identifier", "ftam.activity_identifier",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_request_recovery_mode,
{ "recovery-mode", "ftam.recovery_mode",
FT_INT32, BASE_DEC, VALS(ftam_T_request_recovery_mode_vals), 0,
"T_request_recovery_mode", HFILL }},
{ &hf_ftam_remove_contexts,
{ "remove-contexts", "ftam.remove_contexts",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Abstract_Syntax_Name", HFILL }},
{ &hf_ftam_remove_contexts_item,
{ "Abstract-Syntax-Name", "ftam.Abstract_Syntax_Name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_define_contexts,
{ "define-contexts", "ftam.define_contexts",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Abstract_Syntax_Name", HFILL }},
{ &hf_ftam_define_contexts_item,
{ "Abstract-Syntax-Name", "ftam.Abstract_Syntax_Name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_degree_of_overlap,
{ "degree-of-overlap", "ftam.degree_of_overlap",
FT_INT32, BASE_DEC, VALS(ftam_Degree_Of_Overlap_U_vals), 0,
NULL, HFILL }},
{ &hf_ftam_transfer_window,
{ "transfer-window", "ftam.transfer_window",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_contents_type,
{ "contents-type", "ftam.contents_type",
FT_UINT32, BASE_DEC, VALS(ftam_Contents_Type_Attribute_vals), 0,
"Contents_Type_Attribute", HFILL }},
{ &hf_ftam_response_recovery_mode,
{ "recovery-mode", "ftam.recovery_mode",
FT_INT32, BASE_DEC, VALS(ftam_T_response_recovery_mode_vals), 0,
"T_response_recovery_mode", HFILL }},
{ &hf_ftam_presentation_action,
{ "presentation-action", "ftam.presentation_action",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ftam_threshold,
{ "threshold", "ftam.threshold",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_bulk_transfer_number,
{ "bulk-transfer-number", "ftam.bulk_transfer_number",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_recovefy_Point,
{ "recovefy-Point", "ftam.recovefy_Point",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_concurrent_bulk_transfer_number,
{ "concurrent-bulk-transfer-number", "ftam.concurrent_bulk_transfer_number",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_concurrent_recovery_point,
{ "concurrent-recovery-point", "ftam.concurrent_recovery_point",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_last_transfer_end_read_response,
{ "last-transfer-end-read-response", "ftam.last_transfer_end_read_response",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_last_transfer_end_write_response,
{ "last-transfer-end-write-response", "ftam.last_transfer_end_write_response",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_recovety_Point,
{ "recovety-Point", "ftam.recovety_Point",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_last_transfer_end_read_request,
{ "last-transfer-end-read-request", "ftam.last_transfer_end_read_request",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_last_transfer_end_write_request,
{ "last-transfer-end-write-request", "ftam.last_transfer_end_write_request",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_file_access_data_unit_identity,
{ "file-access-data-unit-identity", "ftam.file_access_data_unit_identity",
FT_UINT32, BASE_DEC, VALS(ftam_FADU_Identity_U_vals), 0,
"FADU_Identity", HFILL }},
{ &hf_ftam_fadu_lock,
{ "fadu-lock", "ftam.fadu_lock",
FT_INT32, BASE_DEC, VALS(ftam_FADU_Lock_U_vals), 0,
NULL, HFILL }},
{ &hf_ftam_f_read_request,
{ "f-read-request", "ftam.f_read_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_write_request,
{ "f-write-request", "ftam.f_write_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_data_end_request,
{ "f-data-end-request", "ftam.f_data_end_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_transfer_end_request,
{ "f-transfer-end-request", "ftam.f_transfer_end_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_transfer_end_response,
{ "f-transfer-end-response", "ftam.f_transfer_end_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_cancel_request,
{ "f-cancel-request", "ftam.f_cancel_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_cancel_response,
{ "f-cancel-response", "ftam.f_cancel_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_restart_request,
{ "f-restart-request", "ftam.f_restart_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_restart_response,
{ "f-restart-response", "ftam.f_restart_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_read_access_context,
{ "access-context", "ftam.access_context_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_transfer_number,
{ "transfer-number", "ftam.transfer_number",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_file_access_data_unit_Operation,
{ "file-access-data-unit-Operation", "ftam.file_access_data_unit_Operation",
FT_INT32, BASE_DEC, VALS(ftam_T_file_access_data_unit_Operation_vals), 0,
"T_file_access_data_unit_Operation", HFILL }},
{ &hf_ftam_request_type,
{ "request-type", "ftam.request_type",
FT_INT32, BASE_DEC, VALS(ftam_Request_Type_U_vals), 0,
NULL, HFILL }},
{ &hf_ftam_checkpoint_identifier,
{ "checkpoint-identifier", "ftam.checkpoint_identifier",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_access_context,
{ "access-context", "ftam.access_context",
FT_INT32, BASE_DEC, VALS(ftam_T_access_context_vals), 0,
NULL, HFILL }},
{ &hf_ftam_level_number,
{ "level-number", "ftam.level_number",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_read_password,
{ "read-password", "ftam.read_password",
FT_UINT32, BASE_DEC, VALS(ftam_Password_U_vals), 0,
"Password", HFILL }},
{ &hf_ftam_insert_password,
{ "insert-password", "ftam.insert_password",
FT_UINT32, BASE_DEC, VALS(ftam_Password_U_vals), 0,
"Password", HFILL }},
{ &hf_ftam_replace_password,
{ "replace-password", "ftam.replace_password",
FT_UINT32, BASE_DEC, VALS(ftam_Password_U_vals), 0,
"Password", HFILL }},
{ &hf_ftam_extend_password,
{ "extend-password", "ftam.extend_password",
FT_UINT32, BASE_DEC, VALS(ftam_Password_U_vals), 0,
"Password", HFILL }},
{ &hf_ftam_erase_password,
{ "erase-password", "ftam.erase_password",
FT_UINT32, BASE_DEC, VALS(ftam_Password_U_vals), 0,
"Password", HFILL }},
{ &hf_ftam_read_attribute_password,
{ "read-attribute-password", "ftam.read_attribute_password",
FT_UINT32, BASE_DEC, VALS(ftam_Password_U_vals), 0,
"Password", HFILL }},
{ &hf_ftam_change_attribute_password,
{ "change-attribute-password", "ftam.change_attribute_password",
FT_UINT32, BASE_DEC, VALS(ftam_Password_U_vals), 0,
"Password", HFILL }},
{ &hf_ftam_delete_password,
{ "delete-password", "ftam.delete_password",
FT_UINT32, BASE_DEC, VALS(ftam_Password_U_vals), 0,
"Password", HFILL }},
{ &hf_ftam_pass_passwords,
{ "pass-passwords", "ftam.pass_passwords",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_link_password,
{ "link-password", "ftam.link_password",
FT_UINT32, BASE_DEC, VALS(ftam_Password_U_vals), 0,
"Password", HFILL }},
{ &hf_ftam_pathname,
{ "pathname", "ftam.pathname",
FT_UINT32, BASE_DEC, VALS(ftam_Pathname_Attribute_vals), 0,
"Pathname_Attribute", HFILL }},
{ &hf_ftam_storage_account,
{ "storage-account", "ftam.storage_account",
FT_UINT32, BASE_DEC, VALS(ftam_Account_Attribute_vals), 0,
"Account_Attribute", HFILL }},
{ &hf_ftam_object_availability,
{ "object-availability", "ftam.object_availability",
FT_UINT32, BASE_DEC, VALS(ftam_Object_Availability_Attribute_vals), 0,
"Object_Availability_Attribute", HFILL }},
{ &hf_ftam_future_Object_size,
{ "future-Object-size", "ftam.future_Object_size",
FT_UINT32, BASE_DEC, VALS(ftam_Object_Size_Attribute_vals), 0,
"Object_Size_Attribute", HFILL }},
{ &hf_ftam_change_attributes_access_control,
{ "access-control", "ftam.access_control",
FT_UINT32, BASE_DEC, VALS(ftam_Access_Control_Change_Attribute_vals), 0,
"Access_Control_Change_Attribute", HFILL }},
{ &hf_ftam_change_path_access_control,
{ "path-access-control", "ftam.path_access_control",
FT_UINT32, BASE_DEC, VALS(ftam_Access_Control_Change_Attribute_vals), 0,
"Access_Control_Change_Attribute", HFILL }},
{ &hf_ftam_legal_qualification,
{ "legal-qualification", "ftam.legal_qualification",
FT_UINT32, BASE_DEC, VALS(ftam_Legal_Qualification_Attribute_vals), 0,
"Legal_Qualification_Attribute", HFILL }},
{ &hf_ftam_private_use,
{ "private-use", "ftam.private_use",
FT_UINT32, BASE_DEC, VALS(ftam_Private_Use_Attribute_vals), 0,
"Private_Use_Attribute", HFILL }},
{ &hf_ftam_attribute_extensions,
{ "attribute-extensions", "ftam.attribute_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam__untag_item_01,
{ "_untag item", "ftam._untag_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"Charging_item", HFILL }},
{ &hf_ftam_resource_identifier,
{ "resource-identifier", "ftam.resource_identifier",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_ftam_charging_unit,
{ "charging-unit", "ftam.charging_unit",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_ftam_charging_value,
{ "charging-value", "ftam.charging_value",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_read,
{ "read", "ftam.read",
FT_INT32, BASE_DEC, VALS(ftam_Lock_vals), 0,
"Lock", HFILL }},
{ &hf_ftam_insert,
{ "insert", "ftam.insert",
FT_INT32, BASE_DEC, VALS(ftam_Lock_vals), 0,
"Lock", HFILL }},
{ &hf_ftam_replace,
{ "replace", "ftam.replace",
FT_INT32, BASE_DEC, VALS(ftam_Lock_vals), 0,
"Lock", HFILL }},
{ &hf_ftam_extend,
{ "extend", "ftam.extend",
FT_INT32, BASE_DEC, VALS(ftam_Lock_vals), 0,
"Lock", HFILL }},
{ &hf_ftam_erase,
{ "erase", "ftam.erase",
FT_INT32, BASE_DEC, VALS(ftam_Lock_vals), 0,
"Lock", HFILL }},
{ &hf_ftam_read_attribute,
{ "read-attribute", "ftam.read_attribute",
FT_INT32, BASE_DEC, VALS(ftam_Lock_vals), 0,
"Lock", HFILL }},
{ &hf_ftam_change_attribute,
{ "change-attribute", "ftam.change_attribute",
FT_INT32, BASE_DEC, VALS(ftam_Lock_vals), 0,
"Lock", HFILL }},
{ &hf_ftam_delete_Object,
{ "delete-Object", "ftam.delete_Object",
FT_INT32, BASE_DEC, VALS(ftam_Lock_vals), 0,
"Lock", HFILL }},
{ &hf_ftam_object_type,
{ "object-type", "ftam.object_type",
FT_INT32, BASE_DEC, VALS(ftam_Object_Type_Attribute_vals), 0,
"Object_Type_Attribute", HFILL }},
{ &hf_ftam_permitted_actions,
{ "permitted-actions", "ftam.permitted_actions",
FT_BYTES, BASE_NONE, NULL, 0,
"Permitted_Actions_Attribute", HFILL }},
{ &hf_ftam_access_control,
{ "access-control", "ftam.access_control",
FT_UINT32, BASE_DEC, VALS(ftam_Access_Control_Attribute_vals), 0,
"Access_Control_Attribute", HFILL }},
{ &hf_ftam_path_access_control,
{ "path-access-control", "ftam.path_access_control",
FT_UINT32, BASE_DEC, VALS(ftam_Access_Control_Attribute_vals), 0,
"Access_Control_Attribute", HFILL }},
{ &hf_ftam__untag_item_02,
{ "_untag item", "ftam._untag_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"Diagnostic_item", HFILL }},
{ &hf_ftam_diagnostic_type,
{ "diagnostic-type", "ftam.diagnostic_type",
FT_INT32, BASE_DEC, VALS(ftam_T_diagnostic_type_vals), 0,
NULL, HFILL }},
{ &hf_ftam_error_identifier,
{ "error-identifier", "ftam.error_identifier",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_error_observer,
{ "error-observer", "ftam.error_observer",
FT_INT32, BASE_DEC, VALS(ftam_Entity_Reference_vals), 0,
"Entity_Reference", HFILL }},
{ &hf_ftam_error_Source,
{ "error-Source", "ftam.error_Source",
FT_INT32, BASE_DEC, VALS(ftam_Entity_Reference_vals), 0,
"Entity_Reference", HFILL }},
{ &hf_ftam_suggested_delay,
{ "suggested-delay", "ftam.suggested_delay",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_further_details,
{ "further-details", "ftam.further_details",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_ftam_first_last,
{ "first-last", "ftam.first_last",
FT_INT32, BASE_DEC, VALS(ftam_T_first_last_vals), 0,
"T_first_last", HFILL }},
{ &hf_ftam_relative,
{ "relative", "ftam.relative",
FT_INT32, BASE_DEC, VALS(ftam_T_relative_vals), 0,
NULL, HFILL }},
{ &hf_ftam_begin_end,
{ "begin-end", "ftam.begin_end",
FT_INT32, BASE_DEC, VALS(ftam_T_begin_end_vals), 0,
NULL, HFILL }},
{ &hf_ftam_single_name,
{ "single-name", "ftam.single_name_element",
FT_NONE, BASE_NONE, NULL, 0,
"Node_Name", HFILL }},
{ &hf_ftam_name_list,
{ "name-list", "ftam.name_list",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Node_Name", HFILL }},
{ &hf_ftam_name_list_item,
{ "Node-Name", "ftam.Node_Name_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_fadu_number,
{ "fadu-number", "ftam.fadu_number",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_graphicString,
{ "graphicString", "ftam.graphicString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_octetString,
{ "octetString", "ftam.octetString",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_ftam_linked_Object,
{ "linked-Object", "ftam.linked_Object",
FT_UINT32, BASE_DEC, VALS(ftam_Pathname_Attribute_vals), 0,
"Pathname_Attribute", HFILL }},
{ &hf_ftam_child_objects,
{ "child-objects", "ftam.child_objects",
FT_UINT32, BASE_DEC, NULL, 0,
"Child_Objects_Attribute", HFILL }},
{ &hf_ftam_primaty_pathname,
{ "primaty-pathname", "ftam.primaty_pathname",
FT_UINT32, BASE_DEC, VALS(ftam_Pathname_Attribute_vals), 0,
"Pathname_Attribute", HFILL }},
{ &hf_ftam_date_and_time_of_creation,
{ "date-and-time-of-creation", "ftam.date_and_time_of_creation",
FT_UINT32, BASE_DEC, VALS(ftam_Date_and_Time_Attribute_vals), 0,
"Date_and_Time_Attribute", HFILL }},
{ &hf_ftam_date_and_time_of_last_modification,
{ "date-and-time-of-last-modification", "ftam.date_and_time_of_last_modification",
FT_UINT32, BASE_DEC, VALS(ftam_Date_and_Time_Attribute_vals), 0,
"Date_and_Time_Attribute", HFILL }},
{ &hf_ftam_date_and_time_of_last_read_access,
{ "date-and-time-of-last-read-access", "ftam.date_and_time_of_last_read_access",
FT_UINT32, BASE_DEC, VALS(ftam_Date_and_Time_Attribute_vals), 0,
"Date_and_Time_Attribute", HFILL }},
{ &hf_ftam_date_and_time_of_last_attribute_modification,
{ "date-and-time-of-last-attribute-modification", "ftam.date_and_time_of_last_attribute_modification",
FT_UINT32, BASE_DEC, VALS(ftam_Date_and_Time_Attribute_vals), 0,
"Date_and_Time_Attribute", HFILL }},
{ &hf_ftam_identity_of_creator,
{ "identity-of-creator", "ftam.identity_of_creator",
FT_UINT32, BASE_DEC, VALS(ftam_User_Identity_Attribute_vals), 0,
"User_Identity_Attribute", HFILL }},
{ &hf_ftam_identity_of_last_modifier,
{ "identity-of-last-modifier", "ftam.identity_of_last_modifier",
FT_UINT32, BASE_DEC, VALS(ftam_User_Identity_Attribute_vals), 0,
"User_Identity_Attribute", HFILL }},
{ &hf_ftam_identity_of_last_reader,
{ "identity-of-last-reader", "ftam.identity_of_last_reader",
FT_UINT32, BASE_DEC, VALS(ftam_User_Identity_Attribute_vals), 0,
"User_Identity_Attribute", HFILL }},
{ &hf_ftam_identity_last_attribute_modifier,
{ "identity-last-attribute-modifier", "ftam.identity_last_attribute_modifier",
FT_UINT32, BASE_DEC, VALS(ftam_User_Identity_Attribute_vals), 0,
"User_Identity_Attribute", HFILL }},
{ &hf_ftam_object_size,
{ "object-size", "ftam.object_size",
FT_UINT32, BASE_DEC, VALS(ftam_Object_Size_Attribute_vals), 0,
"Object_Size_Attribute", HFILL }},
{ &hf_ftam_no_value_available,
{ "no-value-available", "ftam.no_value_available_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_actual_values3,
{ "actual-values", "ftam.actual_values",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Access_Control_Element", HFILL }},
{ &hf_ftam_actual_values3_item,
{ "Access-Control-Element", "ftam.Access_Control_Element_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_actual_values1,
{ "actual-values", "ftam.actual_values_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_actual_values1", HFILL }},
{ &hf_ftam_insert_values,
{ "insert-values", "ftam.insert_values",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Access_Control_Element", HFILL }},
{ &hf_ftam_insert_values_item,
{ "Access-Control-Element", "ftam.Access_Control_Element_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_delete_values,
{ "delete-values", "ftam.delete_values",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Access_Control_Element", HFILL }},
{ &hf_ftam_delete_values_item,
{ "Access-Control-Element", "ftam.Access_Control_Element_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_action_list,
{ "action-list", "ftam.action_list",
FT_BYTES, BASE_NONE, NULL, 0,
"Access_Request", HFILL }},
{ &hf_ftam_concurrency_access,
{ "concurrency-access", "ftam.concurrency_access_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_identity,
{ "identity", "ftam.identity",
FT_STRING, BASE_NONE, NULL, 0,
"User_Identity", HFILL }},
{ &hf_ftam_passwords,
{ "passwords", "ftam.passwords_element",
FT_NONE, BASE_NONE, NULL, 0,
"Access_Passwords", HFILL }},
{ &hf_ftam_location,
{ "location", "ftam.location",
FT_UINT32, BASE_DEC, VALS(acse_AE_title_vals), 0,
"Application_Entity_Title", HFILL }},
{ &hf_ftam_read_key,
{ "read", "ftam.read",
FT_BYTES, BASE_NONE, NULL, 0,
"Concurrency_Key", HFILL }},
{ &hf_ftam_insert_key,
{ "insert", "ftam.insert",
FT_BYTES, BASE_NONE, NULL, 0,
"Concurrency_Key", HFILL }},
{ &hf_ftam_replace_key,
{ "replace", "ftam.replace",
FT_BYTES, BASE_NONE, NULL, 0,
"Concurrency_Key", HFILL }},
{ &hf_ftam_extend_key,
{ "extend", "ftam.extend",
FT_BYTES, BASE_NONE, NULL, 0,
"Concurrency_Key", HFILL }},
{ &hf_ftam_erase_key,
{ "erase", "ftam.erase",
FT_BYTES, BASE_NONE, NULL, 0,
"Concurrency_Key", HFILL }},
{ &hf_ftam_read_attribute_key,
{ "read-attribute", "ftam.read_attribute",
FT_BYTES, BASE_NONE, NULL, 0,
"Concurrency_Key", HFILL }},
{ &hf_ftam_change_attribute_key,
{ "change-attribute", "ftam.change_attribute",
FT_BYTES, BASE_NONE, NULL, 0,
"Concurrency_Key", HFILL }},
{ &hf_ftam_delete_Object_key,
{ "delete-Object", "ftam.delete_Object",
FT_BYTES, BASE_NONE, NULL, 0,
"Concurrency_Key", HFILL }},
{ &hf_ftam_actual_values2,
{ "actual-values", "ftam.actual_values",
FT_STRING, BASE_NONE, NULL, 0,
"Account", HFILL }},
{ &hf_ftam_document_type,
{ "document-type", "ftam.document_type_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_document_type", HFILL }},
{ &hf_ftam_parameter,
{ "parameter", "ftam.parameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_constraint_set_and_abstract_Syntax,
{ "constraint-set-and-abstract-Syntax", "ftam.constraint_set_and_abstract_Syntax_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_constraint_set_and_abstract_Syntax", HFILL }},
{ &hf_ftam_constraint_set_name,
{ "constraint-set-name", "ftam.constraint_set_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_actual_values5,
{ "actual-values", "ftam.actual_values",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_ftam_actual_values8,
{ "actual-values", "ftam.actual_values",
FT_INT32, BASE_DEC, VALS(ftam_T_actual_values8_vals), 0,
"T_actual_values8", HFILL }},
{ &hf_ftam_incomplete_pathname,
{ "incomplete-pathname", "ftam.incomplete_pathname",
FT_UINT32, BASE_DEC, NULL, 0,
"Pathname", HFILL }},
{ &hf_ftam_complete_pathname,
{ "complete-pathname", "ftam.complete_pathname",
FT_UINT32, BASE_DEC, NULL, 0,
"Pathname", HFILL }},
{ &hf_ftam_actual_values7,
{ "actual-values", "ftam.actual_values",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_actual_values9,
{ "actual-values", "ftam.actual_values",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_ftam_abstract_Syntax_not_supported,
{ "abstract-Syntax-not-supported", "ftam.abstract_Syntax_not_supported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_actual_values4,
{ "actual-values", "ftam.actual_values_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNAL", HFILL }},
{ &hf_ftam_actual_values6,
{ "actual-values", "ftam.actual_values",
FT_STRING, BASE_NONE, NULL, 0,
"User_Identity", HFILL }},
{ &hf_ftam_Child_Objects_Attribute_item,
{ "Child-Objects-Attribute item", "ftam.Child_Objects_Attribute_item",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_ftam_f_Change_prefix_request,
{ "f-Change-prefix-request", "ftam.f_Change_prefix_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_Change_prefix_response,
{ "f-Change-prefix-response", "ftam.f_Change_prefix_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_list_request,
{ "f-list-request", "ftam.f_list_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_list_response,
{ "f-list-response", "ftam.f_list_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_group_select_request,
{ "f-group-select-request", "ftam.f_group_select_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_group_select_response,
{ "f-group-select-response", "ftam.f_group_select_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_group_delete_request,
{ "f-group-delete-request", "ftam.f_group_delete_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_group_delete_response,
{ "f-group-delete-response", "ftam.f_group_delete_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_group_move_request,
{ "f-group-move-request", "ftam.f_group_move_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_group_move_response,
{ "f-group-move-response", "ftam.f_group_move_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_group_copy_request,
{ "f-group-copy-request", "ftam.f_group_copy_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_group_copy_response,
{ "f-group-copy-response", "ftam.f_group_copy_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_group_list_request,
{ "f-group-list-request", "ftam.f_group_list_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_group_list_response,
{ "f-group-list-response", "ftam.f_group_list_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_group_Change_attrib_request,
{ "f-group-Change-attrib-request", "ftam.f_group_Change_attrib_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_group_Change_attrib_response,
{ "f-group-Change-attrib-response", "ftam.f_group_Change_attrib_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_select_another_request,
{ "f-select-another-request", "ftam.f_select_another_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_select_another_response,
{ "f-select-another-response", "ftam.f_select_another_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_create_directory_request,
{ "f-create-directory-request", "ftam.f_create_directory_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_create_directory_response,
{ "f-create-directory-response", "ftam.f_create_directory_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_link_request,
{ "f-link-request", "ftam.f_link_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_link_response,
{ "f-link-response", "ftam.f_link_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_unlink_request,
{ "f-unlink-request", "ftam.f_unlink_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_unlink_response,
{ "f-unlink-response", "ftam.f_unlink_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_read_link_attrib_request,
{ "f-read-link-attrib-request", "ftam.f_read_link_attrib_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_read_link_attrib_response,
{ "f-read-link-attrib-response", "ftam.f_read_link_attrib_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_Change_link_attrib_request,
{ "f-Change-link-attrib-request", "ftam.f_Change_link_attrib_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_Change_Iink_attrib_response,
{ "f-Change-Iink-attrib-response", "ftam.f_Change_Iink_attrib_response_element",
FT_NONE, BASE_NONE, NULL, 0,
"F_CHANGE_LINK_ATTRIB_response", HFILL }},
{ &hf_ftam_f_move_request,
{ "f-move-request", "ftam.f_move_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_move_response,
{ "f-move-response", "ftam.f_move_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_copy_request,
{ "f-copy-request", "ftam.f_copy_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_f_copy_response,
{ "f-copy-response", "ftam.f_copy_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_reset,
{ "reset", "ftam.reset",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ftam_destination_file_directory,
{ "destination-file-directory", "ftam.destination_file_directory",
FT_UINT32, BASE_DEC, VALS(ftam_Pathname_Attribute_vals), 0,
NULL, HFILL }},
{ &hf_ftam_attribute_value_asset_tions,
{ "attribute-value-asset-tions", "ftam.attribute_value_asset_tions",
FT_UINT32, BASE_DEC, NULL, 0,
"Attribute_Value_Assertions", HFILL }},
{ &hf_ftam_scope,
{ "scope", "ftam.scope",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_objects_attributes_list,
{ "objects-attributes-list", "ftam.objects_attributes_list",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_attribute_value_assertions,
{ "attribute-value-assertions", "ftam.attribute_value_assertions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_maximum_set_size,
{ "maximum-set-size", "ftam.maximum_set_size",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_request_Operation_result,
{ "request-Operation-result", "ftam.request_Operation_result",
FT_INT32, BASE_DEC, VALS(ftam_Request_Operation_Result_U_vals), 0,
NULL, HFILL }},
{ &hf_ftam_operation_result,
{ "operation-result", "ftam.operation_result",
FT_UINT32, BASE_DEC, VALS(ftam_Operation_Result_U_vals), 0,
NULL, HFILL }},
{ &hf_ftam_error_action,
{ "error-action", "ftam.error_action",
FT_INT32, BASE_DEC, VALS(ftam_Error_Action_vals), 0,
NULL, HFILL }},
{ &hf_ftam_last_member_indicator,
{ "last-member-indicator", "ftam.last_member_indicator",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ftam_shared_ASE_infonnation,
{ "shared-ASE-infonnation", "ftam.shared_ASE_infonnation_element",
FT_NONE, BASE_NONE, NULL, 0,
"Shared_ASE_Information", HFILL }},
{ &hf_ftam_target_object,
{ "target-object", "ftam.target_object",
FT_UINT32, BASE_DEC, VALS(ftam_Pathname_Attribute_vals), 0,
"Pathname_Attribute", HFILL }},
{ &hf_ftam_target_Object,
{ "target-Object", "ftam.target_Object",
FT_UINT32, BASE_DEC, VALS(ftam_Pathname_Attribute_vals), 0,
"Pathname_Attribute", HFILL }},
{ &hf_ftam_read_link_attributes,
{ "attributes", "ftam.attributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"Read_Attributes", HFILL }},
{ &hf_ftam_Attribute_Extension_Names_item,
{ "Attribute-Extension-Set-Name", "ftam.Attribute_Extension_Set_Name_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_extension_set_identifier,
{ "extension-set-identifier", "ftam.extension_set_identifier",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_extension_attribute_names,
{ "extension-attribute-names", "ftam.extension_attribute_names",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Extension_Attribute_identifier", HFILL }},
{ &hf_ftam_extension_attribute_names_item,
{ "Extension-Attribute-identifier", "ftam.Extension_Attribute_identifier",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_Attribute_Extensions_item,
{ "Attribute-Extension-Set", "ftam.Attribute_Extension_Set_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_extension_set_attributes,
{ "extension-set-attributes", "ftam.extension_set_attributes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Extension_Attribute", HFILL }},
{ &hf_ftam_extension_set_attributes_item,
{ "Extension-Attribute", "ftam.Extension_Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_extension_attribute_identifier,
{ "extension-attribute-identifier", "ftam.extension_attribute_identifier",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_extension_attribute,
{ "extension-attribute", "ftam.extension_attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam__untag_item_03,
{ "_untag item", "ftam._untag_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_root_directory,
{ "root-directory", "ftam.root_directory",
FT_UINT32, BASE_DEC, VALS(ftam_Pathname_Attribute_vals), 0,
"Pathname_Attribute", HFILL }},
{ &hf_ftam_retrieval_scope,
{ "retrieval-scope", "ftam.retrieval_scope",
FT_INT32, BASE_DEC, VALS(ftam_T_retrieval_scope_vals), 0,
NULL, HFILL }},
{ &hf_ftam_OR_Set_item,
{ "AND-Set", "ftam.AND_Set",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_AND_Set_item,
{ "AND-Set item", "ftam.AND_Set_item",
FT_UINT32, BASE_DEC, VALS(ftam_AND_Set_item_vals), 0,
NULL, HFILL }},
{ &hf_ftam_pathname_Pattern,
{ "pathname-Pattern", "ftam.pathname_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_object_type_Pattern,
{ "object-type-Pattern", "ftam.object_type_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Integer_Pattern", HFILL }},
{ &hf_ftam_permitted_actions_Pattern,
{ "permitted-actions-Pattern", "ftam.permitted_actions_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Bitstring_Pattern", HFILL }},
{ &hf_ftam_contents_type_Pattern,
{ "contents-type-Pattern", "ftam.contents_type_Pattern",
FT_UINT32, BASE_DEC, VALS(ftam_Contents_Type_Pattern_vals), 0,
NULL, HFILL }},
{ &hf_ftam_linked_Object_Pattern,
{ "linked-Object-Pattern", "ftam.linked_Object_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Pathname_Pattern", HFILL }},
{ &hf_ftam_child_objects_Pattern,
{ "child-objects-Pattern", "ftam.child_objects_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Pathname_Pattern", HFILL }},
{ &hf_ftam_primaty_pathname_Pattern,
{ "primaty-pathname-Pattern", "ftam.primaty_pathname_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Pathname_Pattern", HFILL }},
{ &hf_ftam_storage_account_Pattern,
{ "storage-account-Pattern", "ftam.storage_account_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"String_Pattern", HFILL }},
{ &hf_ftam_date_and_time_of_creation_Pattern,
{ "date-and-time-of-creation-Pattern", "ftam.date_and_time_of_creation_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Date_and_Time_Pattern", HFILL }},
{ &hf_ftam_date_and_time_of_last_modification_Pattern,
{ "date-and-time-of-last-modification-Pattern", "ftam.date_and_time_of_last_modification_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Date_and_Time_Pattern", HFILL }},
{ &hf_ftam_date_and_time_of_last_read_access_Pattern,
{ "date-and-time-of-last-read-access-Pattern", "ftam.date_and_time_of_last_read_access_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Date_and_Time_Pattern", HFILL }},
{ &hf_ftam_date_and_time_of_last_attribute_modification_Pattern,
{ "date-and-time-of-last-attribute-modification-Pattern", "ftam.date_and_time_of_last_attribute_modification_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Date_and_Time_Pattern", HFILL }},
{ &hf_ftam_identity_of_creator_Pattern,
{ "identity-of-creator-Pattern", "ftam.identity_of_creator_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"User_Identity_Pattern", HFILL }},
{ &hf_ftam_identity_of_last_modifier_Pattern,
{ "identity-of-last-modifier-Pattern", "ftam.identity_of_last_modifier_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"User_Identity_Pattern", HFILL }},
{ &hf_ftam_identity_of_last_reader_Pattern,
{ "identity-of-last-reader-Pattern", "ftam.identity_of_last_reader_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"User_Identity_Pattern", HFILL }},
{ &hf_ftam_identity_of_last_attribute_modifier_Pattern,
{ "identity-of-last-attribute-modifier-Pattern", "ftam.identity_of_last_attribute_modifier_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"User_Identity_Pattern", HFILL }},
{ &hf_ftam_object_availabiiity_Pattern,
{ "object-availabiiity-Pattern", "ftam.object_availabiiity_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Boolean_Pattern", HFILL }},
{ &hf_ftam_object_size_Pattern,
{ "object-size-Pattern", "ftam.object_size_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Integer_Pattern", HFILL }},
{ &hf_ftam_future_object_size_Pattern,
{ "future-object-size-Pattern", "ftam.future_object_size_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Integer_Pattern", HFILL }},
{ &hf_ftam_legal_quailfication_Pattern,
{ "legal-quailfication-Pattern", "ftam.legal_quailfication_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"String_Pattern", HFILL }},
{ &hf_ftam_attribute_extensions_pattern,
{ "attribute-extensions-pattern", "ftam.attribute_extensions_pattern",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_equality_comparision,
{ "equality-comparision", "ftam.equality_comparision",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_pathname_value,
{ "pathname-value", "ftam.pathname_value",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_pathname_value_item,
{ "pathname-value item", "ftam.pathname_value_item",
FT_UINT32, BASE_DEC, VALS(ftam_T_pathname_value_item_vals), 0,
NULL, HFILL }},
{ &hf_ftam_string_match,
{ "string-match", "ftam.string_match_element",
FT_NONE, BASE_NONE, NULL, 0,
"String_Pattern", HFILL }},
{ &hf_ftam_any_match,
{ "any-match", "ftam.any_match_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_string_value,
{ "string-value", "ftam.string_value",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_string_value_item,
{ "string-value item", "ftam.string_value_item",
FT_UINT32, BASE_DEC, VALS(ftam_T_string_value_item_vals), 0,
NULL, HFILL }},
{ &hf_ftam_substring_match,
{ "substring-match", "ftam.substring_match",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_ftam_number_of_characters_match,
{ "number-of-characters-match", "ftam.number_of_characters_match",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_match_bitstring,
{ "match-bitstring", "ftam.match_bitstring",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_ftam_significance_bitstring,
{ "significance-bitstring", "ftam.significance_bitstring",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_ftam_relational_camparision,
{ "relational-camparision", "ftam.relational_camparision",
FT_BYTES, BASE_NONE, NULL, 0,
"Equality_Comparision", HFILL }},
{ &hf_ftam_time_and_date_value,
{ "time-and-date-value", "ftam.time_and_date_value",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_ftam_relational_comparision,
{ "relational-comparision", "ftam.relational_comparision",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_integer_value,
{ "integer-value", "ftam.integer_value",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_object_identifier_value,
{ "object-identifier-value", "ftam.object_identifier_value",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_ftam_boolean_value,
{ "boolean-value", "ftam.boolean_value",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ftam_document_type_Pattern,
{ "document-type-Pattern", "ftam.document_type_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Object_Identifier_Pattern", HFILL }},
{ &hf_ftam_constraint_set_abstract_Syntax_Pattern,
{ "constraint-set-abstract-Syntax-Pattern", "ftam.constraint_set_abstract_Syntax_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_constraint_set_abstract_Syntax_Pattern", HFILL }},
{ &hf_ftam_constraint_Set_Pattern,
{ "constraint-Set-Pattern", "ftam.constraint_Set_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Object_Identifier_Pattern", HFILL }},
{ &hf_ftam_abstract_Syntax_Pattern,
{ "abstract-Syntax-Pattern", "ftam.abstract_Syntax_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
"Object_Identifier_Pattern", HFILL }},
{ &hf_ftam_Attribute_Extensions_Pattern_item,
{ "Attribute-Extensions-Pattern item", "ftam.Attribute_Extensions_Pattern_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_extension_set_attribute_Patterns,
{ "extension-set-attribute-Patterns", "ftam.extension_set_attribute_Patterns",
FT_UINT32, BASE_DEC, NULL, 0,
"T_extension_set_attribute_Patterns", HFILL }},
{ &hf_ftam_extension_set_attribute_Patterns_item,
{ "extension-set-attribute-Patterns item", "ftam.extension_set_attribute_Patterns_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_extension_set_attribute_Patterns_item", HFILL }},
{ &hf_ftam_attribute_extension_attribute_identifier,
{ "extension-attribute-identifier", "ftam.extension_attribute_identifier",
FT_OID, BASE_NONE, NULL, 0,
"T_attribute_extension_attribute_identifier", HFILL }},
{ &hf_ftam_extension_attribute_Pattern,
{ "extension-attribute-Pattern", "ftam.extension_attribute_Pattern_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam__untag_item_04,
{ "Read-Attributes", "ftam.Read_Attributes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_success_Object_count,
{ "success-Object-count", "ftam.success_Object_count",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ftam_success_Object_names,
{ "success-Object-names", "ftam.success_Object_names",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Pathname", HFILL }},
{ &hf_ftam_success_Object_names_item,
{ "Pathname", "ftam.Pathname",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ftam_Pathname_item,
{ "Pathname item", "ftam.Pathname_item",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_ftam_Pass_Passwords_item,
{ "Password", "ftam.Password",
FT_UINT32, BASE_DEC, VALS(ftam_Password_U_vals), 0,
NULL, HFILL }},
{ &hf_ftam__untag_item_05,
{ "_untag item", "ftam._untag_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"Path_Access_Passwords_item", HFILL }},
{ &hf_ftam_ap,
{ "ap", "ftam.ap",
FT_UINT32, BASE_DEC, VALS(acse_AP_title_vals), 0,
"AP_title", HFILL }},
{ &hf_ftam_ae,
{ "ae", "ftam.ae",
FT_UINT32, BASE_DEC, VALS(acse_ASO_qualifier_vals), 0,
"AE_qualifier", HFILL }},
{ &hf_ftam_Protocol_Version_U_version_1,
{ "version-1", "ftam.version-1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Protocol_Version_U_version_2,
{ "version-2", "ftam.version-2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_Service_Class_U_unconstrained_class,
{ "unconstrained-class", "ftam.unconstrained-class",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Service_Class_U_management_class,
{ "management-class", "ftam.management-class",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_Service_Class_U_transfer_class,
{ "transfer-class", "ftam.transfer-class",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_Service_Class_U_transfer_and_management_class,
{ "transfer-and-management-class", "ftam.transfer-and-management-class",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_Service_Class_U_access_class,
{ "access-class", "ftam.access-class",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_read,
{ "read", "ftam.read",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_write,
{ "write", "ftam.write",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_file_access,
{ "file-access", "ftam.file-access",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_limited_file_management,
{ "limited-file-management", "ftam.limited-file-management",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_enhanced_file_management,
{ "enhanced-file-management", "ftam.enhanced-file-management",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_grouping,
{ "grouping", "ftam.grouping",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_fadu_locking,
{ "fadu-locking", "ftam.fadu-locking",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_recovery,
{ "recovery", "ftam.recovery",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_restart_data_transfer,
{ "restart-data-transfer", "ftam.restart-data-transfer",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_limited_filestore_management,
{ "limited-filestore-management", "ftam.limited-filestore-management",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_enhanced_filestore_management,
{ "enhanced-filestore-management", "ftam.enhanced-filestore-management",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_object_manipulation,
{ "object-manipulation", "ftam.object-manipulation",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_group_manipulation,
{ "group-manipulation", "ftam.group-manipulation",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_consecutive_access,
{ "consecutive-access", "ftam.consecutive-access",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_ftam_Functional_Units_U_concurrent_access,
{ "concurrent-access", "ftam.concurrent-access",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Attribute_Groups_U_storage,
{ "storage", "ftam.storage",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Attribute_Groups_U_security,
{ "security", "ftam.security",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_Attribute_Groups_U_private,
{ "private", "ftam.private",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_Attribute_Groups_U_extension,
{ "extension", "ftam.extension",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_T_processing_mode_f_read,
{ "f-read", "ftam.f-read",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_T_processing_mode_f_insert,
{ "f-insert", "ftam.f-insert",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_T_processing_mode_f_replace,
{ "f-replace", "ftam.f-replace",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_T_processing_mode_f_extend,
{ "f-extend", "ftam.f-extend",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_T_processing_mode_f_erase,
{ "f-erase", "ftam.f-erase",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_ftam_Access_Request_U_read,
{ "read", "ftam.read",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Access_Request_U_insert,
{ "insert", "ftam.insert",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_Access_Request_U_replace,
{ "replace", "ftam.replace",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_Access_Request_U_extend,
{ "extend", "ftam.extend",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_Access_Request_U_erase,
{ "erase", "ftam.erase",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_ftam_Access_Request_U_read_attribute,
{ "read-attribute", "ftam.read-attribute",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_ftam_Access_Request_U_change_attribute,
{ "change-attribute", "ftam.change-attribute",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_ftam_Access_Request_U_delete_Object,
{ "delete-Object", "ftam.delete-Object",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_ftam_Concurrency_Key_not_required,
{ "not-required", "ftam.not-required",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Concurrency_Key_shared,
{ "shared", "ftam.shared",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_Concurrency_Key_exclusive,
{ "exclusive", "ftam.exclusive",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_Concurrency_Key_no_access,
{ "no-access", "ftam.no-access",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_read,
{ "read", "ftam.read",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_insert,
{ "insert", "ftam.insert",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_replace,
{ "replace", "ftam.replace",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_extend,
{ "extend", "ftam.extend",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_erase,
{ "erase", "ftam.erase",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_read_attribute,
{ "read-attribute", "ftam.read-attribute",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_change_attribute,
{ "change-attribute", "ftam.change-attribute",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_delete_Object,
{ "delete-Object", "ftam.delete-Object",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_pass,
{ "pass", "ftam.pass",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_link,
{ "link", "ftam.link",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_traversal,
{ "traversal", "ftam.traversal",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_reverse_traversal,
{ "reverse-traversal", "ftam.reverse-traversal",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_Permitted_Actions_Attribute_random_Order,
{ "random-Order", "ftam.random-Order",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_Equality_Comparision_no_value_available_matches,
{ "no-value-available-matches", "ftam.no-value-available-matches",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Equality_Comparision_equals_matches,
{ "equals-matches", "ftam.equals-matches",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_Relational_Comparision_no_value_available_matches,
{ "no-value-available-matches", "ftam.no-value-available-matches",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Relational_Comparision_equals_matches,
{ "equals-matches", "ftam.equals-matches",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_Relational_Comparision_less_than_matches,
{ "less-than-matches", "ftam.less-than-matches",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_Relational_Comparision_greater_than_matches,
{ "greater-than-matches", "ftam.greater-than-matches",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_pathname,
{ "read-pathname", "ftam.read-pathname",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_Object_type,
{ "read-Object-type", "ftam.read-Object-type",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_permitted_actions,
{ "read-permitted-actions", "ftam.read-permitted-actions",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_contents_type,
{ "read-contents-type", "ftam.read-contents-type",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_linked_Object,
{ "read-linked-Object", "ftam.read-linked-Object",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_Child_objects,
{ "read-Child-objects", "ftam.read-Child-objects",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_primary_pathname,
{ "read-primary-pathname", "ftam.read-primary-pathname",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_storage_account,
{ "read-storage-account", "ftam.read-storage-account",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_date_and_time_of_creation,
{ "read-date-and-time-of-creation", "ftam.read-date-and-time-of-creation",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_date_and_time_of_last_modification,
{ "read-date-and-time-of-last-modification", "ftam.read-date-and-time-of-last-modification",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_date_and_time_of_last_read_access,
{ "read-date-and-time-of-last-read-access", "ftam.read-date-and-time-of-last-read-access",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_date_and_time_of_last_attribute_modification,
{ "read-date-and-time-of-last-attribute-modification", "ftam.read-date-and-time-of-last-attribute-modification",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_identity_of_creator,
{ "read-identity-of-creator", "ftam.read-identity-of-creator",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_identity_of_last_modifier,
{ "read-identity-of-last-modifier", "ftam.read-identity-of-last-modifier",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_identity_of_last_reader,
{ "read-identity-of-last-reader", "ftam.read-identity-of-last-reader",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_identity_of_last_attribute_modifier,
{ "read-identity-of-last-attribute-modifier", "ftam.read-identity-of-last-attribute-modifier",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_Object_availability,
{ "read-Object-availability", "ftam.read-Object-availability",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_Object_size,
{ "read-Object-size", "ftam.read-Object-size",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_future_Object_size,
{ "read-future-Object-size", "ftam.read-future-Object-size",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_access_control,
{ "read-access-control", "ftam.read-access-control",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_path_access_control,
{ "read-path-access-control", "ftam.read-path-access-control",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_l8gal_qualifiCatiOnS,
{ "read-l8gal-qualifiCatiOnS", "ftam.read-l8gal-qualifiCatiOnS",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ftam_Attribute_Names_read_private_use,
{ "read-private-use", "ftam.read-private-use",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
#line 127 "../../asn1/ftam/packet-ftam-template.c"
};
static gint *ett[] = {
&ett_ftam,
#line 1 "../../asn1/ftam/packet-ftam-ettarr.c"
&ett_ftam_PDU,
&ett_ftam_FTAM_Regime_PDU,
&ett_ftam_F_INITIALIZE_request,
&ett_ftam_F_INITIALIZE_response,
&ett_ftam_Protocol_Version_U,
&ett_ftam_Service_Class_U,
&ett_ftam_Functional_Units_U,
&ett_ftam_Attribute_Groups_U,
&ett_ftam_Contents_Type_List_U,
&ett_ftam_Contents_Type_List_item,
&ett_ftam_F_TERMINATE_request,
&ett_ftam_F_TERMINATE_response,
&ett_ftam_F_U_ABORT_request,
&ett_ftam_F_P_ABORT_request,
&ett_ftam_File_PDU,
&ett_ftam_F_SELECT_request,
&ett_ftam_F_SELECT_response,
&ett_ftam_F_DESELECT_request,
&ett_ftam_F_DESELECT_response,
&ett_ftam_F_CREATE_request,
&ett_ftam_F_CREATE_response,
&ett_ftam_F_DELETE_request,
&ett_ftam_F_DELETE_response,
&ett_ftam_F_READ_ATTRIB_request,
&ett_ftam_F_READ_ATTRIB_response,
&ett_ftam_F_CHANGE_ATTRIB_request,
&ett_ftam_F_CHANGE_ATTRIB_response,
&ett_ftam_F_OPEN_request,
&ett_ftam_T_processing_mode,
&ett_ftam_T_open_contents_type,
&ett_ftam_SET_OF_Abstract_Syntax_Name,
&ett_ftam_F_OPEN_response,
&ett_ftam_F_CLOSE_request,
&ett_ftam_F_CLOSE_response,
&ett_ftam_F_BEGIN_GROUP_request,
&ett_ftam_F_BEGIN_GROUP_response,
&ett_ftam_F_END_GROUP_request,
&ett_ftam_F_END_GROUP_response,
&ett_ftam_F_RECOVER_request,
&ett_ftam_F_RECOVER_response,
&ett_ftam_F_LOCATE_request,
&ett_ftam_F_LOCATE_response,
&ett_ftam_F_ERASE_request,
&ett_ftam_F_ERASE_response,
&ett_ftam_Bulk_Data_PDU,
&ett_ftam_F_READ_request,
&ett_ftam_F_WRITE_request,
&ett_ftam_F_DATA_END_request,
&ett_ftam_F_TRANSFER_END_request,
&ett_ftam_F_TRANSFER_END_response,
&ett_ftam_F_CANCEL_request,
&ett_ftam_F_CANCEL_response,
&ett_ftam_F_RESTART_request,
&ett_ftam_F_RESTART_response,
&ett_ftam_Access_Context_U,
&ett_ftam_Access_Passwords_U,
&ett_ftam_Access_Request_U,
&ett_ftam_Change_Attributes_U,
&ett_ftam_Charging_U,
&ett_ftam_Charging_item,
&ett_ftam_Concurrency_Control_U,
&ett_ftam_Create_Attributes_U,
&ett_ftam_Diagnostic_U,
&ett_ftam_Diagnostic_item,
&ett_ftam_FADU_Identity_U,
&ett_ftam_SEQUENCE_OF_Node_Name,
&ett_ftam_Password_U,
&ett_ftam_Read_Attributes_U,
&ett_ftam_Select_Attributes_U,
&ett_ftam_Access_Control_Attribute,
&ett_ftam_SET_OF_Access_Control_Element,
&ett_ftam_Access_Control_Change_Attribute,
&ett_ftam_T_actual_values1,
&ett_ftam_Access_Control_Element,
&ett_ftam_Concurrency_Access,
&ett_ftam_Concurrency_Key,
&ett_ftam_Account_Attribute,
&ett_ftam_Contents_Type_Attribute,
&ett_ftam_T_document_type,
&ett_ftam_T_constraint_set_and_abstract_Syntax,
&ett_ftam_Date_and_Time_Attribute,
&ett_ftam_Object_Availability_Attribute,
&ett_ftam_Pathname_Attribute,
&ett_ftam_Object_Size_Attribute,
&ett_ftam_Legal_Qualification_Attribute,
&ett_ftam_Permitted_Actions_Attribute,
&ett_ftam_Private_Use_Attribute,
&ett_ftam_User_Identity_Attribute,
&ett_ftam_Child_Objects_Attribute,
&ett_ftam_FSM_PDU,
&ett_ftam_F_CHANGE_PREFIX_request,
&ett_ftam_F_CHANGE_PREFIX_response,
&ett_ftam_F_LIST_request,
&ett_ftam_F_LIST_response,
&ett_ftam_F_GROUP_SELECT_request,
&ett_ftam_F_GROUP_SELECT_response,
&ett_ftam_F_GROUP_DELETE_request,
&ett_ftam_F_GROUP_DELETE_response,
&ett_ftam_F_GROUP_MOVE_request,
&ett_ftam_F_GROUP_MOVE_response,
&ett_ftam_F_GROUP_COPY_request,
&ett_ftam_F_GROUP_COPY_response,
&ett_ftam_F_GROUP_LIST_request,
&ett_ftam_F_GROUP_LIST_response,
&ett_ftam_F_GROUP_CHANGE_ATTRIB_request,
&ett_ftam_F_GROUP_CHANGE_ATTRIB_response,
&ett_ftam_F_SELECT_ANOTHER_request,
&ett_ftam_F_SELECT_ANOTHER_response,
&ett_ftam_F_CREATE_DIRECTORY_request,
&ett_ftam_F_CREATE_DIRECTORY_response,
&ett_ftam_F_LINK_request,
&ett_ftam_F_LINK_response,
&ett_ftam_F_UNLINK_request,
&ett_ftam_F_UNLINK_response,
&ett_ftam_F_READ_LINK_ATTRIB_request,
&ett_ftam_F_READ_LINK_ATTRIB_response,
&ett_ftam_F_CHANGE_LINK_ATTRIB_request,
&ett_ftam_F_CHANGE_LINK_ATTRIB_response,
&ett_ftam_F_MOVE_request,
&ett_ftam_F_MOVE_response,
&ett_ftam_F_COPY_request,
&ett_ftam_F_COPY_response,
&ett_ftam_Attribute_Extension_Names,
&ett_ftam_Attribute_Extension_Set_Name,
&ett_ftam_SEQUENCE_OF_Extension_Attribute_identifier,
&ett_ftam_Attribute_Extensions,
&ett_ftam_Attribute_Extension_Set,
&ett_ftam_SEQUENCE_OF_Extension_Attribute,
&ett_ftam_Extension_Attribute,
&ett_ftam_Scope_U,
&ett_ftam_T__untag_item,
&ett_ftam_OR_Set,
&ett_ftam_AND_Set,
&ett_ftam_AND_Set_item,
&ett_ftam_Equality_Comparision,
&ett_ftam_Relational_Comparision,
&ett_ftam_Pathname_Pattern,
&ett_ftam_T_pathname_value,
&ett_ftam_T_pathname_value_item,
&ett_ftam_String_Pattern,
&ett_ftam_T_string_value,
&ett_ftam_T_string_value_item,
&ett_ftam_Bitstring_Pattern,
&ett_ftam_Date_and_Time_Pattern,
&ett_ftam_Integer_Pattern,
&ett_ftam_Object_Identifier_Pattern,
&ett_ftam_Boolean_Pattern,
&ett_ftam_Contents_Type_Pattern,
&ett_ftam_T_constraint_set_abstract_Syntax_Pattern,
&ett_ftam_Attribute_Extensions_Pattern,
&ett_ftam_Attribute_Extensions_Pattern_item,
&ett_ftam_T_extension_set_attribute_Patterns,
&ett_ftam_T_extension_set_attribute_Patterns_item,
&ett_ftam_SEQUENCE_OF_Read_Attributes,
&ett_ftam_Operation_Result_U,
&ett_ftam_SEQUENCE_OF_Pathname,
&ett_ftam_Pathname,
&ett_ftam_Pass_Passwords,
&ett_ftam_Path_Access_Passwords_U,
&ett_ftam_Path_Access_Passwords_item,
&ett_ftam_Attribute_Names,
&ett_ftam_AE_title,
#line 133 "../../asn1/ftam/packet-ftam-template.c"
};
proto_ftam = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("ftam", dissect_ftam, proto_ftam);
proto_register_field_array(proto_ftam, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_ftam(void) {
register_ber_oid_dissector("1.0.8571.1.1", dissect_ftam, proto_ftam,"iso-ftam(1)");
register_ber_oid_dissector("1.0.8571.2.1", dissect_ftam, proto_ftam,"ftam-pci(1)");
register_ber_oid_dissector("1.3.14.5.2.2", dissect_ftam, proto_ftam,"NIST file directory entry abstract syntax");
register_ber_oid_dissector("1.0.8571.5.1", dissect_ftam_unstructured_text, proto_ftam,"ISO FTAM unstructured text");
oid_add_from_string("ISO FTAM sequential text","1.0.8571.5.2");
oid_add_from_string("FTAM unstructured text abstract syntax","1.0.8571.2.3");
oid_add_from_string("FTAM simple-hierarchy","1.0.8571.2.5");
oid_add_from_string("FTAM hierarchical file model","1.0.8571.3.1");
oid_add_from_string("FTAM unstructured constraint set","1.0.8571.4.1");
register_ber_oid_dissector("1.0.8571.5.3", dissect_ftam_unstructured_binary, proto_ftam,"ISO FTAM unstructured binary");
oid_add_from_string("FTAM unstructured binary abstract syntax","1.0.8571.2.4");
oid_add_from_string("NBS-9 FTAM file directory file","1.3.14.5.5.9");
oid_add_from_string("NBS-9-OLD FTAM file directory file","1.3.9999.1.5.9");
oid_add_from_string("NIST file directory entry abstract syntax","1.3.9999.1.2.2");
}
