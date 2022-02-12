extern void add_ansi_tcap_subdissector(guint32 ssn, dissector_handle_t dissector) {
g_hash_table_insert(ansi_sub_dissectors,GUINT_TO_POINTER(ssn),dissector);
dissector_add_uint("sccp.ssn",ssn,tcap_handle);
}
extern void add_itu_tcap_subdissector(guint32 ssn, dissector_handle_t dissector) {
g_hash_table_insert(itu_sub_dissectors,GUINT_TO_POINTER(ssn),dissector);
dissector_add_uint("sccp.ssn",ssn,tcap_handle);
}
extern void delete_ansi_tcap_subdissector(guint32 ssn, dissector_handle_t dissector _U_) {
g_hash_table_remove(ansi_sub_dissectors,GUINT_TO_POINTER(ssn));
if (!get_itu_tcap_subdissector(ssn))
dissector_delete_uint("sccp.ssn",ssn,tcap_handle);
}
extern void delete_itu_tcap_subdissector(guint32 ssn, dissector_handle_t dissector _U_) {
g_hash_table_remove(itu_sub_dissectors,GUINT_TO_POINTER(ssn));
if (!get_ansi_tcap_subdissector(ssn))
dissector_delete_uint("sccp.ssn", ssn,tcap_handle);
}
dissector_handle_t get_ansi_tcap_subdissector(guint32 ssn) {
return (dissector_handle_t)g_hash_table_lookup(ansi_sub_dissectors,GUINT_TO_POINTER(ssn));
}
dissector_handle_t get_itu_tcap_subdissector(guint32 ssn) {
return (dissector_handle_t)g_hash_table_lookup(itu_sub_dissectors,GUINT_TO_POINTER(ssn));
}
static int
dissect_tcap_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_tcap_Dialog1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 69 "../../asn1/tcap/tcap.cnf"
offset = dissect_tcap_DialoguePDU(TRUE, tvb, offset, actx, tree, -1);
return offset;
}
static int
dissect_tcap_ExternalPDU_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ExternalPDU_U_sequence, hf_index, ett_tcap_ExternalPDU_U);
return offset;
}
static int
dissect_tcap_ExternalPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 64 "../../asn1/tcap/tcap.cnf"
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_UNI, 8, TRUE, dissect_tcap_ExternalPDU_U);
return offset;
}
static int
dissect_tcap_DialogueOC(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 59 "../../asn1/tcap/tcap.cnf"
offset = dissect_tcap_ExternalPDU(FALSE , tvb, offset, actx, tree, -1);
return offset;
}
static int
dissect_tcap_DialoguePortion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 11, TRUE, dissect_tcap_DialogueOC);
return offset;
}
static int
dissect_tcap_InvokeIdType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_OPERATION(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
OPERATION_choice, hf_index, ett_tcap_OPERATION,
NULL);
return offset;
}
static int
dissect_tcap_Parameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 74 "../../asn1/tcap/tcap.cnf"
offset = dissect_tcap_param(actx,tree,tvb,offset);
return offset;
}
static int
dissect_tcap_Invoke(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Invoke_sequence, hf_index, ett_tcap_Invoke);
return offset;
}
static int
dissect_tcap_T_resultretres(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_resultretres_sequence, hf_index, ett_tcap_T_resultretres);
return offset;
}
static int
dissect_tcap_ReturnResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReturnResult_sequence, hf_index, ett_tcap_ReturnResult);
return offset;
}
static int
dissect_tcap_INTEGER_M32768_32767(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_ErrorCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ErrorCode_choice, hf_index, ett_tcap_ErrorCode,
NULL);
return offset;
}
static int
dissect_tcap_ReturnError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReturnError_sequence, hf_index, ett_tcap_ReturnError);
return offset;
}
static int
dissect_tcap_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_tcap_T_invokeIDRej(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_invokeIDRej_choice, hf_index, ett_tcap_T_invokeIDRej,
NULL);
return offset;
}
static int
dissect_tcap_GeneralProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_InvokeProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_ReturnResultProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_ReturnErrorProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_T_problem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_problem_choice, hf_index, ett_tcap_T_problem,
NULL);
return offset;
}
static int
dissect_tcap_Reject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Reject_sequence, hf_index, ett_tcap_Reject);
return offset;
}
static int
dissect_tcap_Component(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 79 "../../asn1/tcap/tcap.cnf"
tvbuff_t *next_tvb;
gint8 ber_class;
gboolean pc;
gint tag;
guint32 len, comp_offset;
gint ind_field;
comp_offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
comp_offset = dissect_ber_length(actx->pinfo, tree, tvb, comp_offset, &len, &ind_field);
next_tvb = tvb_new_subset(tvb, offset, len+comp_offset-offset, len+comp_offset-offset);
if (!next_tvb)
return comp_offset;
TRY {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Component_choice, hf_index, ett_tcap_Component,
NULL);
}
CATCH_NONFATAL_ERRORS {
show_exception(tvb, actx->pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
dissect_tcap_ITU_ComponentPDU(implicit_tag, next_tvb, 0, actx, tcap_top_tree, hf_index);
return offset;
}
static int
dissect_tcap_SEQUENCE_SIZE_1_MAX_OF_Component(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_Component_sequence_of, hf_index, ett_tcap_SEQUENCE_SIZE_1_MAX_OF_Component);
return offset;
}
static int
dissect_tcap_ComponentPortion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 12, TRUE, dissect_tcap_SEQUENCE_SIZE_1_MAX_OF_Component);
return offset;
}
static int
dissect_tcap_Unidirectional(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Unidirectional_sequence, hf_index, ett_tcap_Unidirectional);
return offset;
}
static int
dissect_tcap_OCTET_STRING_SIZE_1_4(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_OrigTransactionID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 123 "../../asn1/tcap/tcap.cnf"
tvbuff_t *parameter_tvb;
guint8 len, i;
proto_item *tid_item;
proto_tree *subtree;
tid_item = proto_tree_add_text(tree, tvb, offset, -1, "Source Transaction ID");
subtree = proto_item_add_subtree(tid_item, ett_otid);
dissect_ber_octet_string(implicit_tag, actx, subtree, tvb, offset, hf_tcap_tid, NULL);
PROTO_ITEM_SET_HIDDEN(actx->created_item);
offset = dissect_ber_octet_string(implicit_tag, actx, subtree, tvb, offset, hf_tcap_otid,
&parameter_tvb);
if (parameter_tvb){
len = tvb_length_remaining(parameter_tvb, 0);
switch(len) {
case 1:
gp_tcapsrt_info->src_tid=tvb_get_guint8(parameter_tvb, 0);
break;
case 2:
gp_tcapsrt_info->src_tid=tvb_get_ntohs(parameter_tvb, 0);
break;
case 4:
gp_tcapsrt_info->src_tid=tvb_get_ntohl(parameter_tvb, 0);
break;
default:
gp_tcapsrt_info->src_tid=0;
break;
}
if (len){
col_append_str(actx->pinfo->cinfo, COL_INFO, "otid(");
for(i=0;i<len;i++)
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "%02x",tvb_get_guint8(parameter_tvb,i));
col_append_str(actx->pinfo->cinfo, COL_INFO, ") ");
}
}
return offset;
}
static int
dissect_tcap_Begin(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 201 "../../asn1/tcap/tcap.cnf"
gp_tcapsrt_info->ope=TC_BEGIN;
col_set_str(actx->pinfo->cinfo, COL_INFO, "Begin ");
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Begin_sequence, hf_index, ett_tcap_Begin);
return offset;
}
static int
dissect_tcap_DestTransactionID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 164 "../../asn1/tcap/tcap.cnf"
tvbuff_t *parameter_tvb;
guint8 len , i;
proto_item *tid_item;
proto_tree *subtree;
tid_item = proto_tree_add_text(tree, tvb, offset, -1, "Destination Transaction ID");
subtree = proto_item_add_subtree(tid_item, ett_dtid);
dissect_ber_octet_string(implicit_tag, actx, subtree, tvb, offset, hf_tcap_tid, NULL);
PROTO_ITEM_SET_HIDDEN(actx->created_item);
offset = dissect_ber_octet_string(implicit_tag, actx, subtree, tvb, offset, hf_tcap_dtid,
&parameter_tvb);
if (parameter_tvb){
len = tvb_length_remaining(parameter_tvb, 0);
switch(len) {
case 1:
gp_tcapsrt_info->dst_tid=tvb_get_guint8(parameter_tvb, 0);
break;
case 2:
gp_tcapsrt_info->dst_tid=tvb_get_ntohs(parameter_tvb, 0);
break;
case 4:
gp_tcapsrt_info->dst_tid=tvb_get_ntohl(parameter_tvb, 0);
break;
default:
gp_tcapsrt_info->dst_tid=0;
break;
}
if (len){
col_append_str(actx->pinfo->cinfo, COL_INFO, "dtid(");
for(i=0;i<len;i++)
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "%02x",tvb_get_guint8(parameter_tvb,i));
col_append_str(actx->pinfo->cinfo, COL_INFO, ") ");
}
}
return offset;
}
static int
dissect_tcap_End(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 215 "../../asn1/tcap/tcap.cnf"
gp_tcapsrt_info->ope=TC_END;
col_set_str(actx->pinfo->cinfo, COL_INFO, "End ");
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
End_sequence, hf_index, ett_tcap_End);
return offset;
}
static int
dissect_tcap_Continue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 222 "../../asn1/tcap/tcap.cnf"
gp_tcapsrt_info->ope=TC_CONT;
col_set_str(actx->pinfo->cinfo, COL_INFO, "Continue ");
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Continue_sequence, hf_index, ett_tcap_Continue);
return offset;
}
static int
dissect_tcap_P_AbortCause_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_P_AbortCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 10, TRUE, dissect_tcap_P_AbortCause_U);
return offset;
}
static int
dissect_tcap_Reason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Reason_choice, hf_index, ett_tcap_Reason,
NULL);
return offset;
}
static int
dissect_tcap_Abort(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 229 "../../asn1/tcap/tcap.cnf"
gp_tcapsrt_info->ope=TC_ABORT;
col_set_str(actx->pinfo->cinfo, COL_INFO, "Abort ");
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Abort_sequence, hf_index, ett_tcap_Abort);
return offset;
}
static int
dissect_tcap_TCMessage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TCMessage_choice, hf_index, ett_tcap_TCMessage,
NULL);
return offset;
}
static int
dissect_tcap_ERROR(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ERROR_choice, hf_index, ett_tcap_ERROR,
NULL);
return offset;
}
static int
dissect_tcap_AUDT_protocol_version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
AUDT_protocol_version_bits, hf_index, ett_tcap_AUDT_protocol_version,
NULL);
return offset;
}
static int
dissect_tcap_AUDT_application_context_name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 108 "../../asn1/tcap/tcap.cnf"
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &cur_oid);
tcap_private.oid= (void*) cur_oid;
tcap_private.acv=TRUE;
return offset;
}
static int
dissect_tcap_EXTERNAL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_external_type(implicit_tag, tree, tvb, offset, actx, hf_index, NULL);
return offset;
}
static int
dissect_tcap_AUDT_user_information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AUDT_user_information_sequence_of, hf_index, ett_tcap_AUDT_user_information);
return offset;
}
static int
dissect_tcap_AUDT_apdu_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AUDT_apdu_U_sequence, hf_index, ett_tcap_AUDT_apdu_U);
return offset;
}
static int
dissect_tcap_AUDT_apdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 0, TRUE, dissect_tcap_AUDT_apdu_U);
return offset;
}
int
dissect_tcap_UniDialoguePDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
UniDialoguePDU_choice, hf_index, ett_tcap_UniDialoguePDU,
NULL);
return offset;
}
static int
dissect_tcap_AARQ_protocol_version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
AARQ_protocol_version_bits, hf_index, ett_tcap_AARQ_protocol_version,
NULL);
return offset;
}
static int
dissect_tcap_AARQ_application_context_name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 113 "../../asn1/tcap/tcap.cnf"
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &cur_oid);
tcap_private.oid= (void*) cur_oid;
tcap_private.acv=TRUE;
return offset;
}
static int
dissect_tcap_AARQ_user_information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AARQ_user_information_sequence_of, hf_index, ett_tcap_AARQ_user_information);
return offset;
}
static int
dissect_tcap_AARQ_apdu_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AARQ_apdu_U_sequence, hf_index, ett_tcap_AARQ_apdu_U);
return offset;
}
static int
dissect_tcap_AARQ_apdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 0, TRUE, dissect_tcap_AARQ_apdu_U);
return offset;
}
static int
dissect_tcap_AARE_protocol_version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
AARE_protocol_version_bits, hf_index, ett_tcap_AARE_protocol_version,
NULL);
return offset;
}
static int
dissect_tcap_AARE_application_context_name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 118 "../../asn1/tcap/tcap.cnf"
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &cur_oid);
tcap_private.oid= (void*) cur_oid;
tcap_private.acv=TRUE;
return offset;
}
static int
dissect_tcap_Associate_result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_T_dialogue_service_user(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_T_dialogue_service_provider(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_Associate_source_diagnostic(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Associate_source_diagnostic_choice, hf_index, ett_tcap_Associate_source_diagnostic,
NULL);
return offset;
}
static int
dissect_tcap_AARE_user_information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AARE_user_information_sequence_of, hf_index, ett_tcap_AARE_user_information);
return offset;
}
static int
dissect_tcap_AARE_apdu_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AARE_apdu_U_sequence, hf_index, ett_tcap_AARE_apdu_U);
return offset;
}
static int
dissect_tcap_AARE_apdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 1, TRUE, dissect_tcap_AARE_apdu_U);
return offset;
}
static int
dissect_tcap_ABRT_source(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_tcap_ABRT_user_information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ABRT_user_information_sequence_of, hf_index, ett_tcap_ABRT_user_information);
return offset;
}
static int
dissect_tcap_ABRT_apdu_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ABRT_apdu_U_sequence, hf_index, ett_tcap_ABRT_apdu_U);
return offset;
}
static int
dissect_tcap_ABRT_apdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 4, TRUE, dissect_tcap_ABRT_apdu_U);
return offset;
}
int
dissect_tcap_DialoguePDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DialoguePDU_choice, hf_index, ett_tcap_DialoguePDU,
NULL);
return offset;
}
static void dissect_UniDialoguePDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_tcap_UniDialoguePDU(FALSE, tvb, 0, &asn1_ctx, tree, hf_tcap_UniDialoguePDU_PDU);
}
static void dissect_DialoguePDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_tcap_DialoguePDU(FALSE, tvb, 0, &asn1_ctx, tree, hf_tcap_DialoguePDU_PDU);
}
static void
dissect_tcap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
struct tcaphash_context_t * p_tcap_context;
dissector_handle_t subdissector_handle;
asn1_ctx_t asn1_ctx;
gint8 ber_class;
gboolean pc;
gint tag;
get_ber_identifier(tvb, 0, &ber_class, &pc, &tag);
if(ber_class == BER_CLASS_PRI){
switch(tag){
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 22:
call_dissector(ansi_tcap_handle, tvb, pinfo, parent_tree);
return;
break;
default:
return;
}
}
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tcap_top_tree = parent_tree;
tcap_stat_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TCAP");
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_tcap, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_tcap);
tcap_stat_tree=tree;
}
cur_oid = NULL;
tcapext_oid = NULL;
raz_tcap_private(&tcap_private);
pinfo->private_data = &tcap_private;
gp_tcapsrt_info=tcapsrt_razinfo();
tcap_subdissector_used=FALSE;
gp_tcap_context=NULL;
dissect_tcap_TCMessage(FALSE, tvb, 0, &asn1_ctx, tree, -1);
if (gtcap_HandleSRT && !tcap_subdissector_used ) {
p_tcap_context=tcapsrt_call_matching(tvb, pinfo, tcap_stat_tree, gp_tcapsrt_info);
tcap_private.context=p_tcap_context;
if ( p_tcap_context && cur_oid && !p_tcap_context->oid_present ) {
g_strlcpy(p_tcap_context->oid, cur_oid, sizeof(p_tcap_context->oid));
p_tcap_context->oid_present=TRUE;
if ( (subdissector_handle = dissector_get_string_handle(ber_oid_dissector_table, cur_oid)) ) {
p_tcap_context->subdissector_handle=subdissector_handle;
p_tcap_context->subdissector_present=TRUE;
}
}
if (gtcap_HandleSRT && p_tcap_context && p_tcap_context->callback) {
(p_tcap_context->callback)(tvb, pinfo, tcap_stat_tree, p_tcap_context);
}
}
}
void
proto_reg_handoff_tcap(void)
{
data_handle = find_dissector("data");
ansi_tcap_handle = find_dissector("ansi_tcap");
ber_oid_dissector_table = find_dissector_table("ber.oid");
#line 1 "../../asn1/tcap/packet-tcap-dis-tab.c"
register_ber_oid_dissector("0.0.17.773.1.1.1", dissect_DialoguePDU_PDU, proto_tcap, "id-as-dialogue");
register_ber_oid_dissector("0.0.17.773.1.2.1", dissect_UniDialoguePDU_PDU, proto_tcap, "id-as-uniDialogue");
#line 252 "../../asn1/tcap/packet-tcap-template.c"
}
void
proto_register_tcap(void)
{
static hf_register_info hf[] = {
{ &hf_tcap_tag,
{ "Tag", "tcap.msgtype",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_tcap_length,
{ "Length", "tcap.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_tcap_data,
{ "Data", "tcap.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tcap_tid,
{ "Transaction Id", "tcap.tid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tcapsrt_SessionId,
{ "Session Id",
"tcap.srt.session_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tcapsrt_BeginSession,
{ "Begin Session",
"tcap.srt.begin",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT Begin of Session", HFILL }
},
{ &hf_tcapsrt_EndSession,
{ "End Session",
"tcap.srt.end",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT End of Session", HFILL }
},
{ &hf_tcapsrt_SessionTime,
{ "Session duration",
"tcap.srt.sessiontime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Duration of the TCAP session", HFILL }
},
{ &hf_tcapsrt_Duplicate,
{ "Session Duplicate",
"tcap.srt.duplicate",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT Duplicated with Session", HFILL }
},
#line 1 "../../asn1/tcap/packet-tcap-hfarr.c"
{ &hf_tcap_UniDialoguePDU_PDU,
{ "UniDialoguePDU", "tcap.UniDialoguePDU",
FT_UINT32, BASE_DEC, VALS(tcap_UniDialoguePDU_vals), 0,
NULL, HFILL }},
{ &hf_tcap_DialoguePDU_PDU,
{ "DialoguePDU", "tcap.DialoguePDU",
FT_UINT32, BASE_DEC, VALS(tcap_DialoguePDU_vals), 0,
NULL, HFILL }},
{ &hf_tcap_oid,
{ "oid", "tcap.oid",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_tcap_dialog,
{ "dialog", "tcap.dialog",
FT_BYTES, BASE_NONE, NULL, 0,
"Dialog1", HFILL }},
{ &hf_tcap_unidirectional,
{ "unidirectional", "tcap.unidirectional_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tcap_begin,
{ "begin", "tcap.begin_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tcap_end,
{ "end", "tcap.end_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tcap_continue,
{ "continue", "tcap.continue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tcap_abort,
{ "abort", "tcap.abort_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tcap_dialoguePortion,
{ "dialoguePortion", "tcap.dialoguePortion",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tcap_components,
{ "components", "tcap.components",
FT_UINT32, BASE_DEC, NULL, 0,
"ComponentPortion", HFILL }},
{ &hf_tcap_otid,
{ "otid", "tcap.otid",
FT_BYTES, BASE_NONE, NULL, 0,
"OrigTransactionID", HFILL }},
{ &hf_tcap_dtid,
{ "dtid", "tcap.dtid",
FT_BYTES, BASE_NONE, NULL, 0,
"DestTransactionID", HFILL }},
{ &hf_tcap_reason,
{ "reason", "tcap.reason",
FT_UINT32, BASE_DEC, VALS(tcap_Reason_vals), 0,
NULL, HFILL }},
{ &hf_tcap_p_abortCause,
{ "p-abortCause", "tcap.p_abortCause",
FT_UINT32, BASE_DEC, VALS(tcap_P_AbortCause_U_vals), 0,
NULL, HFILL }},
{ &hf_tcap_u_abortCause,
{ "u-abortCause", "tcap.u_abortCause",
FT_BYTES, BASE_NONE, NULL, 0,
"DialoguePortion", HFILL }},
{ &hf_tcap__untag_item,
{ "Component", "tcap.Component",
FT_UINT32, BASE_DEC, VALS(tcap_Component_vals), 0,
NULL, HFILL }},
{ &hf_tcap_invoke,
{ "invoke", "tcap.invoke_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tcap_returnResultLast,
{ "returnResultLast", "tcap.returnResultLast_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReturnResult", HFILL }},
{ &hf_tcap_returnError,
{ "returnError", "tcap.returnError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tcap_reject,
{ "reject", "tcap.reject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tcap_returnResultNotLast,
{ "returnResultNotLast", "tcap.returnResultNotLast_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReturnResult", HFILL }},
{ &hf_tcap_invokeID,
{ "invokeID", "tcap.invokeID",
FT_INT32, BASE_DEC, NULL, 0,
"InvokeIdType", HFILL }},
{ &hf_tcap_linkedID,
{ "linkedID", "tcap.linkedID",
FT_INT32, BASE_DEC, NULL, 0,
"InvokeIdType", HFILL }},
{ &hf_tcap_opCode,
{ "opCode", "tcap.opCode",
FT_UINT32, BASE_DEC, VALS(tcap_OPERATION_vals), 0,
"OPERATION", HFILL }},
{ &hf_tcap_parameter,
{ "parameter", "tcap.parameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tcap_resultretres,
{ "resultretres", "tcap.resultretres_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tcap_errorCode,
{ "errorCode", "tcap.errorCode",
FT_UINT32, BASE_DEC, VALS(tcap_ErrorCode_vals), 0,
NULL, HFILL }},
{ &hf_tcap_invokeIDRej,
{ "invokeIDRej", "tcap.invokeIDRej",
FT_UINT32, BASE_DEC, VALS(tcap_T_invokeIDRej_vals), 0,
NULL, HFILL }},
{ &hf_tcap_derivable,
{ "derivable", "tcap.derivable",
FT_INT32, BASE_DEC, NULL, 0,
"InvokeIdType", HFILL }},
{ &hf_tcap_not_derivable,
{ "not-derivable", "tcap.not_derivable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tcap_problem,
{ "problem", "tcap.problem",
FT_UINT32, BASE_DEC, VALS(tcap_T_problem_vals), 0,
NULL, HFILL }},
{ &hf_tcap_generalProblem,
{ "generalProblem", "tcap.generalProblem",
FT_INT32, BASE_DEC, VALS(tcap_GeneralProblem_vals), 0,
NULL, HFILL }},
{ &hf_tcap_invokeProblem,
{ "invokeProblem", "tcap.invokeProblem",
FT_INT32, BASE_DEC, VALS(tcap_InvokeProblem_vals), 0,
NULL, HFILL }},
{ &hf_tcap_returnResultProblem,
{ "returnResultProblem", "tcap.returnResultProblem",
FT_INT32, BASE_DEC, VALS(tcap_ReturnResultProblem_vals), 0,
NULL, HFILL }},
{ &hf_tcap_returnErrorProblem,
{ "returnErrorProblem", "tcap.returnErrorProblem",
FT_INT32, BASE_DEC, VALS(tcap_ReturnErrorProblem_vals), 0,
NULL, HFILL }},
{ &hf_tcap_localValue,
{ "localValue", "tcap.localValue",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_tcap_globalValue,
{ "globalValue", "tcap.globalValue",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_tcap_nationaler,
{ "nationaler", "tcap.nationaler",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_tcap_privateer,
{ "privateer", "tcap.privateer",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_tcap_unidialoguePDU,
{ "unidialoguePDU", "tcap.unidialoguePDU_element",
FT_NONE, BASE_NONE, NULL, 0,
"AUDT_apdu", HFILL }},
{ &hf_tcap_audt_protocol_version,
{ "protocol-version", "tcap.protocol_version",
FT_BYTES, BASE_NONE, NULL, 0,
"AUDT_protocol_version", HFILL }},
{ &hf_tcap_audt_application_context_name,
{ "application-context-name", "tcap.application_context_name",
FT_OID, BASE_NONE, NULL, 0,
"AUDT_application_context_name", HFILL }},
{ &hf_tcap_audt_user_information,
{ "user-information", "tcap.user_information",
FT_UINT32, BASE_DEC, NULL, 0,
"AUDT_user_information", HFILL }},
{ &hf_tcap_audt_user_information_item,
{ "user-information item", "tcap.user_information_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNAL", HFILL }},
{ &hf_tcap_dialogueRequest,
{ "dialogueRequest", "tcap.dialogueRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
"AARQ_apdu", HFILL }},
{ &hf_tcap_dialogueResponse,
{ "dialogueResponse", "tcap.dialogueResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
"AARE_apdu", HFILL }},
{ &hf_tcap_dialogueAbort,
{ "dialogueAbort", "tcap.dialogueAbort_element",
FT_NONE, BASE_NONE, NULL, 0,
"ABRT_apdu", HFILL }},
{ &hf_tcap_aarq_protocol_version,
{ "protocol-version", "tcap.protocol_version",
FT_BYTES, BASE_NONE, NULL, 0,
"AARQ_protocol_version", HFILL }},
{ &hf_tcap_aarq_application_context_name,
{ "application-context-name", "tcap.application_context_name",
FT_OID, BASE_NONE, NULL, 0,
"AARQ_application_context_name", HFILL }},
{ &hf_tcap_aarq_user_information,
{ "user-information", "tcap.user_information",
FT_UINT32, BASE_DEC, NULL, 0,
"AARQ_user_information", HFILL }},
{ &hf_tcap_aarq_user_information_item,
{ "user-information item", "tcap.user_information_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNAL", HFILL }},
{ &hf_tcap_aare_protocol_version,
{ "protocol-version", "tcap.protocol_version",
FT_BYTES, BASE_NONE, NULL, 0,
"AARE_protocol_version", HFILL }},
{ &hf_tcap_aare_application_context_name,
{ "application-context-name", "tcap.application_context_name",
FT_OID, BASE_NONE, NULL, 0,
"AARE_application_context_name", HFILL }},
{ &hf_tcap_result,
{ "result", "tcap.result",
FT_INT32, BASE_DEC, VALS(tcap_Associate_result_vals), 0,
"Associate_result", HFILL }},
{ &hf_tcap_result_source_diagnostic,
{ "result-source-diagnostic", "tcap.result_source_diagnostic",
FT_UINT32, BASE_DEC, VALS(tcap_Associate_source_diagnostic_vals), 0,
"Associate_source_diagnostic", HFILL }},
{ &hf_tcap_aare_user_information,
{ "user-information", "tcap.user_information",
FT_UINT32, BASE_DEC, NULL, 0,
"AARE_user_information", HFILL }},
{ &hf_tcap_aare_user_information_item,
{ "user-information item", "tcap.user_information_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNAL", HFILL }},
{ &hf_tcap_abort_source,
{ "abort-source", "tcap.abort_source",
FT_INT32, BASE_DEC, VALS(tcap_ABRT_source_vals), 0,
"ABRT_source", HFILL }},
{ &hf_tcap_abrt_user_information,
{ "user-information", "tcap.user_information",
FT_UINT32, BASE_DEC, NULL, 0,
"ABRT_user_information", HFILL }},
{ &hf_tcap_abrt_user_information_item,
{ "user-information item", "tcap.user_information_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNAL", HFILL }},
{ &hf_tcap_dialogue_service_user,
{ "dialogue-service-user", "tcap.dialogue_service_user",
FT_INT32, BASE_DEC, VALS(tcap_T_dialogue_service_user_vals), 0,
NULL, HFILL }},
{ &hf_tcap_dialogue_service_provider,
{ "dialogue-service-provider", "tcap.dialogue_service_provider",
FT_INT32, BASE_DEC, VALS(tcap_T_dialogue_service_provider_vals), 0,
NULL, HFILL }},
{ &hf_tcap_AUDT_protocol_version_version1,
{ "version1", "tcap.version1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_tcap_AARQ_protocol_version_version1,
{ "version1", "tcap.version1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_tcap_AARE_protocol_version_version1,
{ "version1", "tcap.version1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
#line 314 "../../asn1/tcap/packet-tcap-template.c"
};
static gint *ett[] = {
&ett_tcap,
&ett_param,
&ett_otid,
&ett_dtid,
&ett_tcap_stat,
#line 1 "../../asn1/tcap/packet-tcap-ettarr.c"
&ett_tcap_ExternalPDU_U,
&ett_tcap_TCMessage,
&ett_tcap_Unidirectional,
&ett_tcap_Begin,
&ett_tcap_End,
&ett_tcap_Continue,
&ett_tcap_Abort,
&ett_tcap_Reason,
&ett_tcap_SEQUENCE_SIZE_1_MAX_OF_Component,
&ett_tcap_Component,
&ett_tcap_Invoke,
&ett_tcap_ReturnResult,
&ett_tcap_T_resultretres,
&ett_tcap_ReturnError,
&ett_tcap_Reject,
&ett_tcap_T_invokeIDRej,
&ett_tcap_T_problem,
&ett_tcap_OPERATION,
&ett_tcap_ERROR,
&ett_tcap_ErrorCode,
&ett_tcap_UniDialoguePDU,
&ett_tcap_AUDT_apdu_U,
&ett_tcap_AUDT_protocol_version,
&ett_tcap_AUDT_user_information,
&ett_tcap_DialoguePDU,
&ett_tcap_AARQ_apdu_U,
&ett_tcap_AARQ_protocol_version,
&ett_tcap_AARQ_user_information,
&ett_tcap_AARE_apdu_U,
&ett_tcap_AARE_protocol_version,
&ett_tcap_AARE_user_information,
&ett_tcap_ABRT_apdu_U,
&ett_tcap_ABRT_user_information,
&ett_tcap_Associate_source_diagnostic,
#line 324 "../../asn1/tcap/packet-tcap-template.c"
};
module_t *tcap_module;
proto_tcap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_tcap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
tcap_module = prefs_register_protocol(proto_tcap, NULL);
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
prefs_register_obsolete_preference(tcap_module, "standard");
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
prefs_register_obsolete_preference(tcap_module, "lock_info_col");
#endif
range_convert_str(&global_ssn_range, "", MAX_SSN);
ssn_range = range_empty();
prefs_register_range_preference(tcap_module, "ssn", "SCCP SSNs",
"SCCP (and SUA) SSNs to decode as TCAP",
&global_ssn_range, MAX_SSN);
prefs_register_bool_preference(tcap_module, "srt",
"Service Response Time Analyse",
"Activate the analyse for Response Time",
&gtcap_HandleSRT);
prefs_register_bool_preference(tcap_module, "persistentsrt",
"Persistent stats for SRT",
"Statistics for Response Time",
&gtcap_PersistentSRT);
prefs_register_uint_preference(tcap_module, "repetitiontimeout",
"Repetition timeout",
"Maximal delay for message repetion",
10, &gtcap_RepetitionTimeout);
prefs_register_uint_preference(tcap_module, "losttimeout",
"lost timeout",
"Maximal delay for message lost",
10, &gtcap_LostTimeout);
ansi_sub_dissectors = g_hash_table_new(g_direct_hash,g_direct_equal);
itu_sub_dissectors = g_hash_table_new(g_direct_hash,g_direct_equal);
register_dissector("tcap", dissect_tcap, proto_tcap);
tcap_handle = create_dissector_handle(dissect_tcap, proto_tcap);
register_init_routine(&init_tcap);
}
static void range_delete_callback(guint32 ssn)
{
if ( ssn && !get_ansi_tcap_subdissector(ssn) && !get_itu_tcap_subdissector(ssn) ) {
dissector_delete_uint("sccp.ssn", ssn, tcap_handle);
}
}
static void range_add_callback(guint32 ssn)
{
if (ssn && !get_ansi_tcap_subdissector(ssn) && !get_itu_tcap_subdissector(ssn) ) {
dissector_add_uint("sccp.ssn", ssn, tcap_handle);
}
}
static void init_tcap(void) {
if (ssn_range) {
range_foreach(ssn_range, range_delete_callback);
g_free(ssn_range);
}
ssn_range = range_copy(global_ssn_range);
range_foreach(ssn_range, range_add_callback);
tcapsrt_init_routine();
}
static int
dissect_tcap_param(asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset)
{
gint tag_offset, saved_offset, len_offset;
tvbuff_t *next_tvb;
proto_tree *subtree;
proto_item *pi;
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
guint32 tag_length;
guint32 len_length;
gboolean ind_field;
while (tvb_reported_length_remaining(tvb, offset) > 0)
{
saved_offset = offset;
offset = get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
tag_offset = offset;
offset = get_ber_length(tvb, offset, &len, &ind_field);
len_offset = offset;
tag_length = tag_offset - saved_offset;
len_length = len_offset - tag_offset;
if (pc)
{
pi = proto_tree_add_text(tree, tvb, saved_offset,
len + (len_offset - saved_offset),
"CONSTRUCTOR");
subtree = proto_item_add_subtree(pi, ett_param);
proto_tree_add_uint_format(subtree, hf_tcap_tag, tvb,
saved_offset, tag_length, tag,
"CONSTRUCTOR Tag");
proto_tree_add_uint(subtree, hf_tcap_tag, tvb, saved_offset,
tag_length, ber_class);
proto_tree_add_uint(subtree, hf_tcap_length, tvb, tag_offset,
len_length, len);
if (len-(2*ind_field))
{
next_tvb = tvb_new_subset(tvb, offset, len-(2*ind_field),
len-(2*ind_field));
dissect_tcap_param(actx, subtree,next_tvb,0);
}
if (ind_field)
proto_tree_add_text(subtree, tvb, offset+len-2, 2, "CONSTRUCTOR EOC");
offset += len;
}
else
{
pi = proto_tree_add_text(tree, tvb, saved_offset,
len + (len_offset - saved_offset),
"Parameter (0x%.2x)", tag);
subtree = proto_item_add_subtree(pi, ett_param);
proto_tree_add_uint(subtree, hf_tcap_tag, tvb, saved_offset,
tag_length, tag);
proto_tree_add_uint(subtree, hf_tcap_length, tvb,
saved_offset+tag_length, len_length, len);
if (len)
{
next_tvb = tvb_new_subset(tvb, offset, len, len);
dissect_ber_octet_string(TRUE, actx, tree, next_tvb, 0,
hf_tcap_data, NULL);
}
offset += len;
}
}
return offset;
}
static void raz_tcap_private(struct tcap_private_t * p_tcap_private)
{
memset(p_tcap_private,0,sizeof(struct tcap_private_t) );
}
static int
dissect_tcap_ITU_ComponentPDU(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_)
{
dissector_handle_t subdissector_handle=NULL;
gboolean is_subdissector=FALSE;
struct tcaphash_context_t * p_tcap_context=NULL;
if ( gtcap_HandleSRT ) {
if (!tcap_subdissector_used) {
p_tcap_context=tcapsrt_call_matching(tvb, actx->pinfo, tcap_stat_tree, gp_tcapsrt_info);
tcap_subdissector_used=TRUE;
gp_tcap_context=p_tcap_context;
tcap_private.context=p_tcap_context;
}else{
p_tcap_context = gp_tcap_context;
tcap_private.context=p_tcap_context;
}
}
if (p_tcap_context) {
if (cur_oid) {
if (p_tcap_context->oid_present) {
if ( strncmp(p_tcap_context->oid, cur_oid, sizeof(p_tcap_context->oid))!=0) {
g_strlcpy(p_tcap_context->oid,cur_oid, sizeof(p_tcap_context->oid));
if ( (subdissector_handle = dissector_get_string_handle(ber_oid_dissector_table, cur_oid)) ) {
p_tcap_context->subdissector_handle=subdissector_handle;
p_tcap_context->subdissector_present=TRUE;
}
}
} else {
g_strlcpy(p_tcap_context->oid, cur_oid, sizeof(p_tcap_context->oid));
p_tcap_context->oid_present=TRUE;
if ( (subdissector_handle
= dissector_get_string_handle(ber_oid_dissector_table, cur_oid)) ) {
p_tcap_context->subdissector_handle=subdissector_handle;
p_tcap_context->subdissector_present=TRUE;
} else {
if ( (subdissector_handle = get_itu_tcap_subdissector(actx->pinfo->match_uint))) {
p_tcap_context->subdissector_handle=subdissector_handle;
p_tcap_context->subdissector_present=TRUE;
}
}
}
} else {
if (p_tcap_context->oid_present) {
tcap_private.oid= (void*) p_tcap_context->oid;
tcap_private.acv=TRUE;
}
}
}
if ( p_tcap_context
&& p_tcap_context->subdissector_present) {
subdissector_handle=p_tcap_context->subdissector_handle;
is_subdissector=TRUE;
}
if (!is_subdissector && requested_subdissector_handle) {
is_subdissector = TRUE;
subdissector_handle = requested_subdissector_handle;
}
if (!is_subdissector) {
if (ber_oid_dissector_table && cur_oid) {
if ( (subdissector_handle
= dissector_get_string_handle(ber_oid_dissector_table, cur_oid)) ) {
is_subdissector=TRUE;
} else {
if ( (subdissector_handle
= get_itu_tcap_subdissector(actx->pinfo->match_uint))) {
is_subdissector=TRUE;
} else {
subdissector_handle = data_handle;
is_subdissector=TRUE;
}
}
} else {
if ( (subdissector_handle = get_itu_tcap_subdissector(actx->pinfo->match_uint))) {
is_subdissector=TRUE;
} else {
subdissector_handle = data_handle;
is_subdissector=TRUE;
}
}
} else {
}
if (is_subdissector)
call_dissector(subdissector_handle, tvb, actx->pinfo, tree);
return offset;
}
void call_tcap_dissector(dissector_handle_t handle, tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree) {
requested_subdissector_handle = handle;
TRY {
dissect_tcap(tvb, pinfo, tree);
} CATCH_ALL {
requested_subdissector_handle = NULL;
RETHROW;
} ENDTRY;
requested_subdissector_handle = NULL;
}
