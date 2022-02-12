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
#line 72 "./asn1/tcap/tcap.cnf"
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
#line 67 "./asn1/tcap/tcap.cnf"
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_UNI, 8, TRUE, dissect_tcap_ExternalPDU_U);
return offset;
}
static int
dissect_tcap_DialogueOC(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 62 "./asn1/tcap/tcap.cnf"
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
#line 77 "./asn1/tcap/tcap.cnf"
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
#line 82 "./asn1/tcap/tcap.cnf"
tvbuff_t *next_tvb;
gint8 ber_class;
gboolean pc;
gint tag;
guint32 len, comp_offset;
volatile guint32 _offset;
gint ind_field;
comp_offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
comp_offset = dissect_ber_length(actx->pinfo, tree, tvb, comp_offset, &len, &ind_field);
next_tvb = tvb_new_subset_length(tvb, offset, len+comp_offset-offset);
if (!next_tvb)
return comp_offset;
_offset = offset;
TRY {
_offset = dissect_ber_choice(actx, tree, tvb, _offset,
Component_choice, hf_index, ett_tcap_Component,
NULL);
}
CATCH_NONFATAL_ERRORS {
show_exception(tvb, actx->pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
offset = _offset;
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
#line 131 "./asn1/tcap/tcap.cnf"
tvbuff_t *parameter_tvb;
guint8 len, i;
proto_tree *subtree;
int saved_offset;
hf_index = hf_tcap_tid;
saved_offset = offset;
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 8, TRUE, dissect_tcap_OCTET_STRING_SIZE_1_4);
PROTO_ITEM_SET_HIDDEN(actx->created_item);
offset = saved_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_otid, NULL, "Source Transaction ID");
offset = dissect_ber_octet_string(implicit_tag, actx, subtree, tvb, offset, hf_tcap_otid,
&parameter_tvb);
if (parameter_tvb) {
len = tvb_reported_length_remaining(parameter_tvb, 0);
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
if (len) {
col_append_str(actx->pinfo->cinfo, COL_INFO, "otid(");
for (i = 0; i < len; i++) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "%02x",tvb_get_guint8(parameter_tvb,i));
}
col_append_str(actx->pinfo->cinfo, COL_INFO, ") ");
}
}
return offset;
}
static int
dissect_tcap_Begin(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 215 "./asn1/tcap/tcap.cnf"
gp_tcapsrt_info->ope=TC_BEGIN;
col_set_str(actx->pinfo->cinfo, COL_INFO, "Begin ");
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Begin_sequence, hf_index, ett_tcap_Begin);
return offset;
}
static int
dissect_tcap_DestTransactionID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 174 "./asn1/tcap/tcap.cnf"
tvbuff_t *parameter_tvb;
guint8 len , i;
proto_tree *subtree;
int saved_offset;
hf_index = hf_tcap_tid;
saved_offset = offset;
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 9, TRUE, dissect_tcap_OCTET_STRING_SIZE_1_4);
PROTO_ITEM_SET_HIDDEN(actx->created_item);
offset = saved_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_dtid, NULL, "Destination Transaction ID");
offset = dissect_ber_octet_string(implicit_tag, actx, subtree, tvb, offset, hf_tcap_dtid,
&parameter_tvb);
if (parameter_tvb) {
len = tvb_reported_length_remaining(parameter_tvb, 0);
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
if (len) {
col_append_str(actx->pinfo->cinfo, COL_INFO, "dtid(");
for(i = 0; i < len; i++) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "%02x",tvb_get_guint8(parameter_tvb,i));
}
col_append_str(actx->pinfo->cinfo, COL_INFO, ") ");
}
}
return offset;
}
static int
dissect_tcap_End(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 229 "./asn1/tcap/tcap.cnf"
gp_tcapsrt_info->ope=TC_END;
col_set_str(actx->pinfo->cinfo, COL_INFO, "End ");
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
End_sequence, hf_index, ett_tcap_End);
return offset;
}
static int
dissect_tcap_Continue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 236 "./asn1/tcap/tcap.cnf"
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
#line 243 "./asn1/tcap/tcap.cnf"
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
dissect_tcap_AUDT_protocol_version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
AUDT_protocol_version_bits, hf_index, ett_tcap_AUDT_protocol_version,
NULL);
return offset;
}
static int
dissect_tcap_AUDT_application_context_name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 116 "./asn1/tcap/tcap.cnf"
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &cur_oid);
tcap_private.oid= (const void*) cur_oid;
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
#line 121 "./asn1/tcap/tcap.cnf"
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &cur_oid);
tcap_private.oid= (const void*) cur_oid;
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
#line 126 "./asn1/tcap/tcap.cnf"
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &cur_oid);
tcap_private.oid= (const void*) cur_oid;
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
static int dissect_UniDialoguePDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_tcap_UniDialoguePDU(FALSE, tvb, offset, &asn1_ctx, tree, hf_tcap_UniDialoguePDU_PDU);
return offset;
}
static int dissect_DialoguePDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_tcap_DialoguePDU(FALSE, tvb, offset, &asn1_ctx, tree, hf_tcap_DialoguePDU_PDU);
return offset;
}
static void
dbg(guint level, const char* fmt, ...)
{
va_list ap;
if (level > debug_level) return;
va_start(ap,fmt);
vfprintf(stderr, fmt, ap);
va_end(ap);
}
static gint
tcaphash_context_equal(gconstpointer k1, gconstpointer k2)
{
const struct tcaphash_context_key_t *key1 = (const struct tcaphash_context_key_t *) k1;
const struct tcaphash_context_key_t *key2 = (const struct tcaphash_context_key_t *) k2;
return (key1->session_id == key2->session_id);
}
static guint
tcaphash_context_calchash(gconstpointer k)
{
const struct tcaphash_context_key_t *key = (const struct tcaphash_context_key_t *) k;
return key->session_id;
}
static gint
tcaphash_begin_equal(gconstpointer k1, gconstpointer k2)
{
const struct tcaphash_begin_info_key_t *key1 = (const struct tcaphash_begin_info_key_t *) k1;
const struct tcaphash_begin_info_key_t *key2 = (const struct tcaphash_begin_info_key_t *) k2;
if (key1->hashKey == key2->hashKey) {
if ( (key1->pc_hash == key2->pc_hash) && (key1->tid == key2->tid) )
return TRUE;
}
return FALSE;
}
static guint
tcaphash_begin_calchash(gconstpointer k)
{
const struct tcaphash_begin_info_key_t *key = (const struct tcaphash_begin_info_key_t *) k;
guint hashkey;
hashkey = key->tid;
return hashkey;
}
static gint
tcaphash_cont_equal(gconstpointer k1, gconstpointer k2)
{
const struct tcaphash_cont_info_key_t *key1 = (const struct tcaphash_cont_info_key_t *) k1;
const struct tcaphash_cont_info_key_t *key2 = (const struct tcaphash_cont_info_key_t *) k2;
if (key1->hashKey == key2->hashKey) {
if ( (key1->opc_hash == key2->opc_hash) &&
(key1->dpc_hash == key2->dpc_hash) &&
(key1->src_tid == key2->src_tid) &&
(key1->dst_tid == key2->dst_tid) ) {
return TRUE;
}
else if ( (key1->opc_hash == key2->dpc_hash) &&
(key1->dpc_hash == key2->opc_hash) &&
(key1->src_tid == key2->dst_tid) &&
(key1->dst_tid == key2->src_tid) ) {
return TRUE;
}
}
return FALSE;
}
static guint
tcaphash_cont_calchash(gconstpointer k)
{
const struct tcaphash_cont_info_key_t *key = (const struct tcaphash_cont_info_key_t *) k;
guint hashkey;
hashkey = key->src_tid + key->dst_tid;
return hashkey;
}
static gint
tcaphash_end_equal(gconstpointer k1, gconstpointer k2)
{
const struct tcaphash_end_info_key_t *key1 = (const struct tcaphash_end_info_key_t *) k1;
const struct tcaphash_end_info_key_t *key2 = (const struct tcaphash_end_info_key_t *) k2;
if (key1->hashKey == key2->hashKey) {
if ( (key1->pc_hash == key2->pc_hash) && (key1->tid == key2->tid) )
return TRUE;
}
return FALSE;
}
static guint
tcaphash_end_calchash(gconstpointer k)
{
const struct tcaphash_end_info_key_t *key = (const struct tcaphash_end_info_key_t *) k;
guint hashkey;
hashkey = key->tid;
return hashkey;
}
static gint
tcaphash_ansi_equal(gconstpointer k1, gconstpointer k2)
{
const struct tcaphash_ansi_info_key_t *key1 = (const struct tcaphash_ansi_info_key_t *) k1;
const struct tcaphash_ansi_info_key_t *key2 = (const struct tcaphash_ansi_info_key_t *) k2;
if (key1->hashKey == key2->hashKey) {
if ( ( (key1->opc_hash == key2->opc_hash) &&
(key1->dpc_hash == key2->dpc_hash) &&
(key1->tid == key2->tid) )
||
( (key1->opc_hash == key2->dpc_hash) &&
(key1->dpc_hash == key2->opc_hash) &&
(key1->tid == key2->tid) )
)
return TRUE;
}
return FALSE;
}
static guint
tcaphash_ansi_calchash(gconstpointer k)
{
const struct tcaphash_ansi_info_key_t *key = (const struct tcaphash_ansi_info_key_t *) k;
guint hashkey;
hashkey = key->tid;
return hashkey;
}
static void
update_tcaphash_begincall(struct tcaphash_begincall_t *p_tcaphash_begincall,
packet_info *pinfo)
{
p_tcaphash_begincall->context->first_frame = pinfo->num;
p_tcaphash_begincall->context->last_frame = 0;
p_tcaphash_begincall->context->responded = FALSE;
p_tcaphash_begincall->context->begin_time = pinfo->abs_ts;
}
static struct tcaphash_begincall_t *
append_tcaphash_begincall(struct tcaphash_begincall_t *prev_begincall,
struct tcaphash_context_t *p_tcaphash_context,
packet_info *pinfo)
{
struct tcaphash_begincall_t *p_new_tcaphash_begincall = NULL;
p_new_tcaphash_begincall = wmem_new0(wmem_file_scope(), struct tcaphash_begincall_t);
p_new_tcaphash_begincall->context=p_tcaphash_context;
p_tcaphash_context->begincall=p_new_tcaphash_begincall;
p_new_tcaphash_begincall->beginkey=prev_begincall->beginkey;
p_new_tcaphash_begincall->context->first_frame = pinfo->num;
p_new_tcaphash_begincall->next_begincall=NULL;
p_new_tcaphash_begincall->previous_begincall=prev_begincall;
p_new_tcaphash_begincall->father=FALSE;
#ifdef DEBUG_TCAPSRT
dbg(10,"+B%d ", p_new_tcaphash_begincall->context->session_id);
#endif
prev_begincall->next_begincall = p_new_tcaphash_begincall;
if (prev_begincall->context->last_frame == 0) {
#ifdef DEBUG_TCAPSRT
dbg(10,"last ");
#endif
prev_begincall->context->last_frame = pinfo->num-1;
}
return p_new_tcaphash_begincall;
}
static void
update_tcaphash_ansicall(struct tcaphash_ansicall_t *p_tcaphash_ansicall,
packet_info *pinfo)
{
p_tcaphash_ansicall->context->first_frame = pinfo->num;
p_tcaphash_ansicall->context->last_frame = 0;
p_tcaphash_ansicall->context->responded = FALSE;
p_tcaphash_ansicall->context->begin_time = pinfo->abs_ts;
}
static struct tcaphash_ansicall_t *
append_tcaphash_ansicall(struct tcaphash_ansicall_t *prev_ansicall,
struct tcaphash_context_t *p_tcaphash_context,
packet_info *pinfo)
{
struct tcaphash_ansicall_t *p_new_tcaphash_ansicall = NULL;
p_new_tcaphash_ansicall = wmem_new0(wmem_file_scope(), struct tcaphash_ansicall_t);
p_new_tcaphash_ansicall->context=p_tcaphash_context;
p_tcaphash_context->ansicall=p_new_tcaphash_ansicall;
p_new_tcaphash_ansicall->ansikey=prev_ansicall->ansikey;
p_new_tcaphash_ansicall->context->first_frame = pinfo->num;
p_new_tcaphash_ansicall->next_ansicall=NULL;
p_new_tcaphash_ansicall->previous_ansicall=prev_ansicall;
p_new_tcaphash_ansicall->father=FALSE;
#ifdef DEBUG_TCAPSRT
dbg(10,"+A%d ", p_new_tcaphash_ansicall->context->session_id);
#endif
prev_ansicall->next_ansicall = p_new_tcaphash_ansicall;
if (prev_ansicall->context->last_frame == 0) {
#ifdef DEBUG_TCAPSRT
dbg(10,"last ");
#endif
prev_ansicall->context->last_frame = pinfo->num-1;
}
return p_new_tcaphash_ansicall;
}
static struct tcaphash_contcall_t *
append_tcaphash_contcall(struct tcaphash_contcall_t *prev_contcall,
struct tcaphash_context_t *p_tcaphash_context)
{
struct tcaphash_contcall_t *p_new_tcaphash_contcall = NULL;
p_new_tcaphash_contcall = wmem_new0(wmem_file_scope(), struct tcaphash_contcall_t);
p_new_tcaphash_contcall->context=p_tcaphash_context;
p_tcaphash_context->contcall=p_new_tcaphash_contcall;
p_new_tcaphash_contcall->contkey=prev_contcall->contkey;
p_new_tcaphash_contcall->next_contcall=NULL;
p_new_tcaphash_contcall->previous_contcall=prev_contcall;
p_new_tcaphash_contcall->father=FALSE;
#ifdef DEBUG_TCAPSRT
dbg(10,"+C%d ", p_new_tcaphash_contcall->context->session_id);
#endif
prev_contcall->next_contcall = p_new_tcaphash_contcall;
return p_new_tcaphash_contcall;
}
static struct tcaphash_endcall_t *
append_tcaphash_endcall(struct tcaphash_endcall_t *prev_endcall,
struct tcaphash_context_t *p_tcaphash_context)
{
struct tcaphash_endcall_t *p_new_tcaphash_endcall = NULL;
p_new_tcaphash_endcall = wmem_new0(wmem_file_scope(), struct tcaphash_endcall_t);
p_new_tcaphash_endcall->context=p_tcaphash_context;
p_tcaphash_context->endcall=p_new_tcaphash_endcall;
p_new_tcaphash_endcall->endkey=prev_endcall->endkey;
p_new_tcaphash_endcall->next_endcall=NULL;
p_new_tcaphash_endcall->previous_endcall=prev_endcall;
p_new_tcaphash_endcall->father=FALSE;
#ifdef DEBUG_TCAPSRT
dbg(10,"+E%d ", p_new_tcaphash_endcall->context->session_id);
#endif
prev_endcall->next_endcall = p_new_tcaphash_endcall;
return p_new_tcaphash_endcall;
}
static struct tcaphash_begincall_t *
find_tcaphash_begin(struct tcaphash_begin_info_key_t *p_tcaphash_begin_key,
packet_info *pinfo, gboolean isBegin)
{
struct tcaphash_begincall_t *p_tcaphash_begincall = NULL;
p_tcaphash_begincall = (struct tcaphash_begincall_t *)g_hash_table_lookup(tcaphash_begin, p_tcaphash_begin_key);
if(p_tcaphash_begincall) {
do {
if ( p_tcaphash_begincall->context ) {
if ( ( isBegin &&
pinfo->num == p_tcaphash_begincall->context->first_frame )
||
( !isBegin &&
pinfo->num >= p_tcaphash_begincall->context->first_frame &&
( p_tcaphash_begincall->context->last_frame?pinfo->num <= p_tcaphash_begincall->context->last_frame:1 )
)
) {
#ifdef DEBUG_TCAPSRT
dbg(10,"B%d ", p_tcaphash_begincall->context->session_id);
#endif
return p_tcaphash_begincall;
}
#ifdef DEBUG_TCAPSRT
dbg(60,"[B%d] ", p_tcaphash_begincall->context->session_id);
#endif
}
if(p_tcaphash_begincall->next_begincall == NULL) {
#ifdef DEBUG_TCAPSRT
dbg(23,"End of Blist ");
#endif
break;
}
p_tcaphash_begincall = p_tcaphash_begincall->next_begincall;
} while (p_tcaphash_begincall != NULL) ;
} else {
#ifdef DEBUG_TCAPSRT
dbg(23,"Not in Bhash ");
#endif
}
return NULL;
}
static struct tcaphash_contcall_t *
find_tcaphash_cont(struct tcaphash_cont_info_key_t *p_tcaphash_cont_key,
packet_info *pinfo)
{
struct tcaphash_contcall_t *p_tcaphash_contcall = NULL;
p_tcaphash_contcall = (struct tcaphash_contcall_t *)g_hash_table_lookup(tcaphash_cont, p_tcaphash_cont_key);
if(p_tcaphash_contcall) {
do {
if ( p_tcaphash_contcall->context ) {
if (pinfo->num >= p_tcaphash_contcall->context->first_frame &&
(p_tcaphash_contcall->context->last_frame?pinfo->num <= p_tcaphash_contcall->context->last_frame:1) ) {
#ifdef DEBUG_TCAPSRT
dbg(10,"C%d ", p_tcaphash_contcall->context->session_id);
#endif
return p_tcaphash_contcall;
}
#ifdef DEBUG_TCAPSRT
dbg(60,"[C%d] ", p_tcaphash_contcall->context->session_id);
#endif
}
if(p_tcaphash_contcall->next_contcall == NULL) {
#ifdef DEBUG_TCAPSRT
dbg(23,"End of Clist ");
#endif
break;
}
p_tcaphash_contcall = p_tcaphash_contcall->next_contcall;
} while (p_tcaphash_contcall != NULL) ;
} else {
#ifdef DEBUG_TCAPSRT
dbg(23,"Not in Chash ");
#endif
}
return NULL;
}
static struct tcaphash_endcall_t *
find_tcaphash_end(struct tcaphash_end_info_key_t *p_tcaphash_end_key,
packet_info *pinfo, gboolean isEnd)
{
struct tcaphash_endcall_t *p_tcaphash_endcall = NULL;
p_tcaphash_endcall = (struct tcaphash_endcall_t *)g_hash_table_lookup(tcaphash_end, p_tcaphash_end_key);
if(p_tcaphash_endcall) {
do {
if ( p_tcaphash_endcall->context ) {
if ( ( isEnd &&
(p_tcaphash_endcall->context->last_frame?pinfo->num == p_tcaphash_endcall->context->last_frame:1)
)
||
( !isEnd &&
pinfo->num >= p_tcaphash_endcall->context->first_frame &&
(p_tcaphash_endcall->context->last_frame?pinfo->num <= p_tcaphash_endcall->context->last_frame:1)
)
) {
#ifdef DEBUG_TCAPSRT
dbg(10,"E%d ", p_tcaphash_endcall->context->session_id);
#endif
return p_tcaphash_endcall;
}
#ifdef DEBUG_TCAPSRT
dbg(60,"[E%d] ", p_tcaphash_endcall->context->session_id);
#endif
}
if(p_tcaphash_endcall->next_endcall == NULL) {
#ifdef DEBUG_TCAPSRT
dbg(23,"End of Elist ");
#endif
break;
}
p_tcaphash_endcall = p_tcaphash_endcall->next_endcall;
} while (p_tcaphash_endcall != NULL) ;
} else {
#ifdef DEBUG_TCAPSRT
dbg(23,"Not in Ehash ");
#endif
}
return NULL;
}
static struct tcaphash_context_t *
new_tcaphash_context(struct tcaphash_context_key_t *p_tcaphash_context_key,
packet_info *pinfo)
{
struct tcaphash_context_key_t *p_new_tcaphash_context_key;
struct tcaphash_context_t *p_new_tcaphash_context = NULL;
p_new_tcaphash_context_key = wmem_new(wmem_file_scope(), struct tcaphash_context_key_t);
p_new_tcaphash_context_key->session_id = p_tcaphash_context_key->session_id;
p_new_tcaphash_context = wmem_new0(wmem_file_scope(), struct tcaphash_context_t);
p_new_tcaphash_context->key = p_new_tcaphash_context_key;
p_new_tcaphash_context->session_id = p_tcaphash_context_key->session_id;
p_new_tcaphash_context->first_frame = pinfo->num;
#ifdef DEBUG_TCAPSRT
dbg(10,"S%d ", p_new_tcaphash_context->session_id);
#endif
g_hash_table_insert(tcaphash_context, p_new_tcaphash_context_key, p_new_tcaphash_context);
return p_new_tcaphash_context;
}
static struct tcaphash_begincall_t *
new_tcaphash_begin(struct tcaphash_begin_info_key_t *p_tcaphash_begin_key,
struct tcaphash_context_t *p_tcaphash_context)
{
struct tcaphash_begin_info_key_t *p_new_tcaphash_begin_key;
struct tcaphash_begincall_t *p_new_tcaphash_begincall = NULL;
p_new_tcaphash_begin_key = wmem_new(wmem_file_scope(), struct tcaphash_begin_info_key_t);
p_new_tcaphash_begin_key->hashKey = p_tcaphash_begin_key->hashKey;
p_new_tcaphash_begin_key->tid = p_tcaphash_begin_key->tid;
p_new_tcaphash_begin_key->pc_hash = p_tcaphash_begin_key->pc_hash;
p_new_tcaphash_begincall = wmem_new0(wmem_file_scope(), struct tcaphash_begincall_t);
p_new_tcaphash_begincall->beginkey=p_new_tcaphash_begin_key;
p_new_tcaphash_begincall->context=p_tcaphash_context;
p_tcaphash_context->begincall=p_new_tcaphash_begincall;
p_new_tcaphash_begincall->father=TRUE;
p_new_tcaphash_begincall->next_begincall=NULL;
p_new_tcaphash_begincall->previous_begincall=NULL;
#ifdef DEBUG_TCAPSRT
dbg(10,"B%d ", p_new_tcaphash_begincall->context->session_id);
#endif
g_hash_table_insert(tcaphash_begin, p_new_tcaphash_begin_key, p_new_tcaphash_begincall);
return p_new_tcaphash_begincall;
}
static struct tcaphash_contcall_t *
new_tcaphash_cont(struct tcaphash_cont_info_key_t *p_tcaphash_cont_key,
struct tcaphash_context_t *p_tcaphash_context)
{
struct tcaphash_cont_info_key_t *p_new_tcaphash_cont_key;
struct tcaphash_contcall_t *p_new_tcaphash_contcall = NULL;
p_new_tcaphash_cont_key = wmem_new(wmem_file_scope(), struct tcaphash_cont_info_key_t);
p_new_tcaphash_cont_key->hashKey = p_tcaphash_cont_key->hashKey;
p_new_tcaphash_cont_key->src_tid = p_tcaphash_cont_key->src_tid;
p_new_tcaphash_cont_key->dst_tid = p_tcaphash_cont_key->dst_tid;
p_new_tcaphash_cont_key->opc_hash = p_tcaphash_cont_key->opc_hash;
p_new_tcaphash_cont_key->dpc_hash = p_tcaphash_cont_key->dpc_hash;
p_new_tcaphash_contcall = wmem_new0(wmem_file_scope(), struct tcaphash_contcall_t);
p_new_tcaphash_contcall->contkey=p_new_tcaphash_cont_key;
p_new_tcaphash_contcall->context=p_tcaphash_context;
p_tcaphash_context->contcall=p_new_tcaphash_contcall;
p_new_tcaphash_contcall->father=TRUE;
p_new_tcaphash_contcall->next_contcall=NULL;
p_new_tcaphash_contcall->previous_contcall=NULL;
#ifdef DEBUG_TCAPSRT
dbg(10,"C%d ", p_new_tcaphash_contcall->context->session_id);
#endif
g_hash_table_insert(tcaphash_cont, p_new_tcaphash_cont_key, p_new_tcaphash_contcall);
return p_new_tcaphash_contcall;
}
static struct tcaphash_endcall_t *
new_tcaphash_end(struct tcaphash_end_info_key_t *p_tcaphash_end_key,
struct tcaphash_context_t *p_tcaphash_context)
{
struct tcaphash_end_info_key_t *p_new_tcaphash_end_key;
struct tcaphash_endcall_t *p_new_tcaphash_endcall = NULL;
p_new_tcaphash_end_key = wmem_new(wmem_file_scope(), struct tcaphash_end_info_key_t);
p_new_tcaphash_end_key->hashKey = p_tcaphash_end_key->hashKey;
p_new_tcaphash_end_key->tid = p_tcaphash_end_key->tid;
p_new_tcaphash_end_key->pc_hash = p_tcaphash_end_key->pc_hash;
p_new_tcaphash_endcall = wmem_new0(wmem_file_scope(), struct tcaphash_endcall_t);
p_new_tcaphash_endcall->endkey=p_new_tcaphash_end_key;
p_new_tcaphash_endcall->context=p_tcaphash_context;
p_tcaphash_context->endcall=p_new_tcaphash_endcall;
p_new_tcaphash_endcall->father=TRUE;
p_new_tcaphash_endcall->next_endcall=NULL;
p_new_tcaphash_endcall->previous_endcall=NULL;
#ifdef DEBUG_TCAPSRT
dbg(10,"E%d ", p_new_tcaphash_endcall->context->session_id);
#endif
g_hash_table_insert(tcaphash_end, p_new_tcaphash_end_key, p_new_tcaphash_endcall);
return p_new_tcaphash_endcall;
}
static struct tcaphash_ansicall_t *
new_tcaphash_ansi(struct tcaphash_ansi_info_key_t *p_tcaphash_ansi_key,
struct tcaphash_context_t *p_tcaphash_context)
{
struct tcaphash_ansi_info_key_t *p_new_tcaphash_ansi_key;
struct tcaphash_ansicall_t *p_new_tcaphash_ansicall = NULL;
p_new_tcaphash_ansi_key = wmem_new(wmem_file_scope(), struct tcaphash_ansi_info_key_t);
p_new_tcaphash_ansi_key->hashKey = p_tcaphash_ansi_key->hashKey;
p_new_tcaphash_ansi_key->tid = p_tcaphash_ansi_key->tid;
p_new_tcaphash_ansi_key->opc_hash = p_tcaphash_ansi_key->opc_hash;
p_new_tcaphash_ansi_key->dpc_hash = p_tcaphash_ansi_key->dpc_hash;
p_new_tcaphash_ansicall = wmem_new0(wmem_file_scope(), struct tcaphash_ansicall_t);
p_new_tcaphash_ansicall->ansikey=p_new_tcaphash_ansi_key;
p_new_tcaphash_ansicall->context=p_tcaphash_context;
p_tcaphash_context->ansicall=p_new_tcaphash_ansicall;
p_new_tcaphash_ansicall->father=TRUE;
p_new_tcaphash_ansicall->next_ansicall=NULL;
p_new_tcaphash_ansicall->previous_ansicall=NULL;
#ifdef DEBUG_TCAPSRT
dbg(10,"A%d ", p_new_tcaphash_ansicall->context->session_id);
#endif
g_hash_table_insert(tcaphash_ansi, p_new_tcaphash_ansi_key, p_new_tcaphash_ansicall);
return p_new_tcaphash_ansicall;
}
static struct tcaphash_contcall_t *
create_tcaphash_cont(struct tcaphash_cont_info_key_t *p_tcaphash_cont_key,
struct tcaphash_context_t *p_tcaphash_context)
{
struct tcaphash_contcall_t *p_tcaphash_contcall1 = NULL;
struct tcaphash_contcall_t *p_tcaphash_contcall = NULL;
p_tcaphash_contcall1 = (struct tcaphash_contcall_t *)
g_hash_table_lookup(tcaphash_cont, p_tcaphash_cont_key);
if (p_tcaphash_contcall1) {
do {
if (!p_tcaphash_contcall1->next_contcall) {
p_tcaphash_contcall=append_tcaphash_contcall(p_tcaphash_contcall1,
p_tcaphash_context);
break;
}
p_tcaphash_contcall1 = p_tcaphash_contcall1->next_contcall;
} while (p_tcaphash_contcall1 != NULL );
} else {
p_tcaphash_contcall = new_tcaphash_cont(p_tcaphash_cont_key,
p_tcaphash_context);
}
return p_tcaphash_contcall;
}
static struct tcaphash_endcall_t *
create_tcaphash_end(struct tcaphash_end_info_key_t *p_tcaphash_end_key,
struct tcaphash_context_t *p_tcaphash_context)
{
struct tcaphash_endcall_t *p_tcaphash_endcall1 = NULL;
struct tcaphash_endcall_t *p_tcaphash_endcall = NULL;
p_tcaphash_endcall1 = (struct tcaphash_endcall_t *)
g_hash_table_lookup(tcaphash_end, p_tcaphash_end_key);
if (p_tcaphash_endcall1) {
do {
if (!p_tcaphash_endcall1->next_endcall) {
p_tcaphash_endcall=append_tcaphash_endcall(p_tcaphash_endcall1,
p_tcaphash_context);
break;
}
p_tcaphash_endcall1 = p_tcaphash_endcall1->next_endcall;
} while (p_tcaphash_endcall1 != NULL );
} else {
p_tcaphash_endcall = new_tcaphash_end(p_tcaphash_end_key,
p_tcaphash_context);
}
return p_tcaphash_endcall;
}
void
tcapsrt_init_routine(void)
{
if (tcaphash_context != NULL) {
#ifdef DEBUG_TCAPSRT
dbg(16,"Destroy hash_context \n");
#endif
g_hash_table_destroy(tcaphash_context);
}
if (tcaphash_begin != NULL) {
#ifdef DEBUG_TCAPSRT
dbg(16,"Destroy hash_begin \n");
#endif
g_hash_table_destroy(tcaphash_begin);
}
if (tcaphash_cont != NULL) {
#ifdef DEBUG_TCAPSRT
dbg(16,"Destroy hash_cont \n");
#endif
g_hash_table_destroy(tcaphash_cont);
}
if (tcaphash_end != NULL) {
#ifdef DEBUG_TCAPSRT
dbg(16,"Destroy hash_end \n");
#endif
g_hash_table_destroy(tcaphash_end);
}
if (tcaphash_ansi != NULL) {
#ifdef DEBUG_TCAPSRT
dbg(16,"Destroy hash_ansi \n");
#endif
g_hash_table_destroy(tcaphash_ansi);
}
#ifdef DEBUG_TCAPSRT
dbg(16,"Create hash \n");
#endif
tcaphash_context = g_hash_table_new(tcaphash_context_calchash, tcaphash_context_equal);
tcaphash_begin = g_hash_table_new(tcaphash_begin_calchash, tcaphash_begin_equal);
tcaphash_cont = g_hash_table_new(tcaphash_cont_calchash, tcaphash_cont_equal);
tcaphash_end = g_hash_table_new(tcaphash_end_calchash, tcaphash_end_equal);
tcaphash_ansi = g_hash_table_new(tcaphash_ansi_calchash, tcaphash_ansi_equal);
tcapsrt_global_SessionId=1;
gtcap_DisplaySRT=gtcap_PersistentSRT || gtcap_HandleSRT&gtcap_StatSRT;
}
static struct tcaphash_context_t *
tcaphash_begin_matching(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
struct tcapsrt_info_t *p_tcapsrt_info)
{
struct tcaphash_context_t *p_tcaphash_context=NULL;
struct tcaphash_context_key_t tcaphash_context_key;
struct tcaphash_begincall_t *p_tcaphash_begincall, *p_new_tcaphash_begincall=NULL;
struct tcaphash_begin_info_key_t tcaphash_begin_key;
proto_item *pi;
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
#ifdef DEBUG_TCAPSRT
dbg(51,"src %s srcTid %lx dst %s ", address_to_str(wmem_packet_scope(), &pinfo->src), p_tcapsrt_info->src_tid, address_to_str(wmem_packet_scope(), &pinfo->dst));
#endif
tcaphash_begin_key.tid = p_tcapsrt_info->src_tid;
if (pinfo->src.type == ss7pc_address_type && pinfo->dst.type == ss7pc_address_type)
{
tcaphash_begin_key.pc_hash = mtp3_pc_hash((const mtp3_addr_pc_t *)pinfo->src.data);
} else {
tcaphash_begin_key.pc_hash = g_str_hash(address_to_str(wmem_packet_scope(), &pinfo->src));
}
tcaphash_begin_key.hashKey=tcaphash_begin_calchash(&tcaphash_begin_key);
#ifdef DEBUG_TCAPSRT
dbg(10,"\n Hbegin #%u ", pinfo->num);
dbg(11,"key %lx ",tcaphash_begin_key.hashKey);
dbg(51,"addr %s ", address_to_str(wmem_packet_scope(), &pinfo->src));
dbg(51,"Tid %lx \n",tcaphash_begin_key.tid);
#endif
p_tcaphash_begincall = (struct tcaphash_begincall_t *)
g_hash_table_lookup(tcaphash_begin, &tcaphash_begin_key);
if (p_tcaphash_begincall) {
do {
if (pinfo->num == p_tcaphash_begincall->context->first_frame) {
#ifdef DEBUG_TCAPSRT
dbg(22,"Already seen ");
#endif
p_tcaphash_context=p_tcaphash_begincall->context;
break;
}
if (!p_tcaphash_begincall->next_begincall) {
if ( ( p_tcaphash_begincall->context->last_frame != 0
&& pinfo->num > p_tcaphash_begincall->context->first_frame
&& (guint) pinfo->abs_ts.secs > (guint)(p_tcaphash_begincall->context->begin_time.secs + gtcap_RepetitionTimeout)
) ||
( p_tcaphash_begincall->context->last_frame == 0
&& pinfo->num > p_tcaphash_begincall->context->first_frame
&& (guint)pinfo->abs_ts.secs > (guint)(p_tcaphash_begincall->context->begin_time.secs + gtcap_LostTimeout)
)
)
{
#ifdef DEBUG_TCAPSRT
dbg(12,"(timeout) Append key %lx ",tcaphash_begin_key.hashKey);
dbg(12,"Frame %u rsp %u ",pinfo->num,p_tcaphash_begincall->context->last_frame );
#endif
tcaphash_context_key.session_id = tcapsrt_global_SessionId++;
p_tcaphash_context = new_tcaphash_context(&tcaphash_context_key, pinfo);
p_new_tcaphash_begincall = append_tcaphash_begincall(p_tcaphash_begincall,
p_tcaphash_context,
pinfo);
#ifdef DEBUG_TCAPSRT
dbg(12,"Update key %lx ",tcaphash_begin_key.hashKey);
#endif
update_tcaphash_begincall(p_new_tcaphash_begincall, pinfo);
} else {
if ( p_tcaphash_begincall->context->closed) {
#ifdef DEBUG_TCAPSRT
dbg(12,"(closed) Append key %lu ",tcaphash_begin_key.hashKey);
dbg(12,"Frame %u rsp %u ",pinfo->num,p_tcaphash_begincall->context->last_frame );
#endif
tcaphash_context_key.session_id = tcapsrt_global_SessionId++;
p_tcaphash_context = new_tcaphash_context(&tcaphash_context_key, pinfo);
p_new_tcaphash_begincall = append_tcaphash_begincall(p_tcaphash_begincall,
p_tcaphash_context,
pinfo);
#ifdef DEBUG_TCAPSRT
dbg(12,"Update key %lu ",tcaphash_begin_key.hashKey);
#endif
update_tcaphash_begincall(p_new_tcaphash_begincall, pinfo);
} else {
#ifdef DEBUG_TCAPSRT
dbg(21,"Display_duplicate %d ",p_tcaphash_begincall->context->first_frame);
#endif
p_tcaphash_context=p_tcaphash_begincall->context;
if (gtcap_DisplaySRT && tree) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, -1, ett_tcap_stat, &stat_item, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
pi = proto_tree_add_uint_format(stat_tree, hf_tcapsrt_Duplicate, tvb, 0, 0,
p_tcaphash_context->first_frame,
"Duplicate with session %u in frame %u",
p_tcaphash_context->session_id,p_tcaphash_context->first_frame);
PROTO_ITEM_SET_GENERATED(pi);
}
return p_tcaphash_context;
}
}
break;
}
p_tcaphash_begincall = p_tcaphash_begincall->next_begincall;
} while (p_tcaphash_begincall != NULL );
} else {
#ifdef DEBUG_TCAPSRT
dbg(10,"New key %lx ",tcaphash_begin_key.hashKey);
#endif
tcaphash_context_key.session_id = tcapsrt_global_SessionId++;
p_tcaphash_context = new_tcaphash_context(&tcaphash_context_key, pinfo);
p_tcaphash_begincall = new_tcaphash_begin(&tcaphash_begin_key, p_tcaphash_context);
#ifdef DEBUG_TCAPSRT
dbg(11,"Update key %lx ",tcaphash_begin_key.hashKey);
dbg(11,"Frame reqlink #%u ", pinfo->num);
#endif
update_tcaphash_begincall(p_tcaphash_begincall, pinfo);
}
if ( gtcap_DisplaySRT && tree &&
p_tcaphash_context &&
p_tcaphash_context->session_id) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, 0, ett_tcap_stat, &stat_item, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
pi = proto_tree_add_uint(stat_tree, hf_tcapsrt_SessionId, tvb, 0,0, p_tcaphash_context->session_id);
PROTO_ITEM_SET_GENERATED(pi);
if( p_tcaphash_context->last_frame != 0 ){
#ifdef DEBUG_TCAPSRT
dbg(20,"Display_frameRsplink %d ",p_tcaphash_context->last_frame);
#endif
pi = proto_tree_add_uint_format(stat_tree, hf_tcapsrt_BeginSession, tvb, 0, 0,
p_tcaphash_context->last_frame,
"End of session in frame %u",
p_tcaphash_context->last_frame);
PROTO_ITEM_SET_GENERATED(pi);
}
}
return p_tcaphash_context;
}
static struct tcaphash_context_t *
tcaphash_cont_matching(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
struct tcapsrt_info_t *p_tcapsrt_info)
{
struct tcaphash_context_t *p_tcaphash_context=NULL;
struct tcaphash_contcall_t *p_tcaphash_contcall;
struct tcaphash_cont_info_key_t tcaphash_cont_key;
struct tcaphash_begin_info_key_t tcaphash_begin_key;
struct tcaphash_begincall_t *p_tcaphash_begincall;
struct tcaphash_end_info_key_t tcaphash_end_key;
proto_item *pi;
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
#ifdef DEBUG_TCAPSRT
dbg(51,"src %s srcTid %lx dst %s dstTid %lx ", address_to_str(wmem_packet_scope(), &pinfo->src), p_tcapsrt_info->src_tid, address_to_str(wmem_packet_scope(), &pinfo->dst), p_tcapsrt_info->dst_tid);
dbg(10,"\n Hcont #%u ", pinfo->num);
#endif
tcaphash_cont_key.src_tid = p_tcapsrt_info->src_tid;
tcaphash_cont_key.dst_tid = p_tcapsrt_info->dst_tid;
if (pinfo->src.type == ss7pc_address_type && pinfo->dst.type == ss7pc_address_type)
{
tcaphash_cont_key.opc_hash = mtp3_pc_hash((const mtp3_addr_pc_t *)pinfo->src.data);
tcaphash_cont_key.dpc_hash = mtp3_pc_hash((const mtp3_addr_pc_t *)pinfo->dst.data);
} else {
tcaphash_cont_key.opc_hash = g_str_hash(address_to_str(wmem_packet_scope(), &pinfo->src));
tcaphash_cont_key.dpc_hash = g_str_hash(address_to_str(wmem_packet_scope(), &pinfo->dst));
}
tcaphash_cont_key.hashKey=tcaphash_cont_calchash(&tcaphash_cont_key);
#ifdef DEBUG_TCAPSRT
dbg(11,"Ckey %lx ", tcaphash_cont_key.hashKey);
dbg(51,"addr %s %s ", address_to_str(wmem_packet_scope(), &pinfo->src), address_to_str(wmem_packet_scope(), &pinfo->dst));
dbg(51,"Tid %lx %lx \n",tcaphash_cont_key.src_tid, tcaphash_cont_key.dst_tid);
#endif
p_tcaphash_contcall = find_tcaphash_cont(&tcaphash_cont_key, pinfo);
if(p_tcaphash_contcall) {
#ifdef DEBUG_TCAPSRT
dbg(12,"CFound ");
#endif
p_tcaphash_context=p_tcaphash_contcall->context;
} else {
#ifdef DEBUG_TCAPSRT
dbg(12,"CnotFound ");
#endif
tcaphash_begin_key.tid = p_tcapsrt_info->dst_tid;
if (pinfo->src.type == ss7pc_address_type && pinfo->dst.type == ss7pc_address_type)
{
tcaphash_begin_key.pc_hash = mtp3_pc_hash((const mtp3_addr_pc_t *)pinfo->dst.data);
} else {
tcaphash_begin_key.pc_hash = g_str_hash(address_to_str(wmem_packet_scope(), &pinfo->dst));
}
tcaphash_begin_key.hashKey=tcaphash_begin_calchash(&tcaphash_begin_key);
#ifdef DEBUG_TCAPSRT
dbg(11,"Bkey %lx ", tcaphash_begin_key.hashKey);
dbg(51,"addr %s ", address_to_str(wmem_packet_scope(), &pinfo->dst));
dbg(51,"Tid %lx \n",tcaphash_begin_key.tid);
#endif
p_tcaphash_begincall = find_tcaphash_begin(&tcaphash_begin_key, pinfo, FALSE);
if(!p_tcaphash_begincall){
#ifdef DEBUG_TCAPSRT
dbg(12,"BNotFound trying stid,src");
#endif
tcaphash_begin_key.tid = p_tcapsrt_info->src_tid;
if (pinfo->src.type == ss7pc_address_type && pinfo->dst.type == ss7pc_address_type)
{
tcaphash_begin_key.pc_hash = mtp3_pc_hash((const mtp3_addr_pc_t *)pinfo->src.data);
} else {
tcaphash_begin_key.pc_hash = g_str_hash(address_to_str(wmem_packet_scope(), &pinfo->src));
}
tcaphash_begin_key.hashKey=tcaphash_begin_calchash(&tcaphash_begin_key);
#ifdef DEBUG_TCAPSRT
dbg(11,"Bkey %lx ", tcaphash_begin_key.hashKey);
dbg(51,"addr %s ", address_to_str(wmem_packet_scope(), &pinfo->src));
dbg(51,"Tid %lx \n",tcaphash_begin_key.tid);
#endif
p_tcaphash_begincall = find_tcaphash_begin(&tcaphash_begin_key, pinfo,FALSE);
}
if(p_tcaphash_begincall &&
!p_tcaphash_begincall->context->contcall ) {
#ifdef DEBUG_TCAPSRT
dbg(12,"BFound \n");
#endif
p_tcaphash_context=p_tcaphash_begincall->context;
p_tcaphash_context->responded=TRUE;
#ifdef DEBUG_TCAPSRT
dbg(10,"New Ckey %lx ",tcaphash_cont_key.hashKey);
dbg(11,"Frame reqlink #%u \n", pinfo->num);
#endif
create_tcaphash_cont(&tcaphash_cont_key,
p_tcaphash_begincall->context);
tcaphash_end_key.tid = p_tcapsrt_info->src_tid;
if (pinfo->src.type == ss7pc_address_type && pinfo->dst.type == ss7pc_address_type)
{
tcaphash_end_key.pc_hash = mtp3_pc_hash((const mtp3_addr_pc_t *)pinfo->src.data);
} else {
tcaphash_end_key.pc_hash = g_str_hash(address_to_str(wmem_packet_scope(), &pinfo->src));
}
tcaphash_end_key.hashKey=tcaphash_end_calchash(&tcaphash_end_key);
#ifdef DEBUG_TCAPSRT
dbg(10,"New Ekey %lx ",tcaphash_end_key.hashKey);
dbg(51,"addr %s ", address_to_str(wmem_packet_scope(), &pinfo->src));
dbg(51,"Tid %lx ",tcaphash_end_key.tid);
dbg(11,"Frame reqlink #%u ", pinfo->num);
#endif
create_tcaphash_end(&tcaphash_end_key,
p_tcaphash_begincall->context);
} else {
#ifdef DEBUG_TCAPSRT
dbg(12,"BnotFound ");
#endif
}
}
if (gtcap_DisplaySRT && tree &&
p_tcaphash_context &&
p_tcaphash_context->session_id) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, -1, ett_tcap_stat, &stat_item, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
pi = proto_tree_add_uint(stat_tree, hf_tcapsrt_SessionId, tvb, 0,0, p_tcaphash_context->session_id);
PROTO_ITEM_SET_GENERATED(pi);
}
return p_tcaphash_context;
}
static struct tcaphash_context_t *
tcaphash_end_matching(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
struct tcapsrt_info_t *p_tcapsrt_info)
{
struct tcaphash_context_t *p_tcaphash_context=NULL;
struct tcaphash_end_info_key_t tcaphash_end_key;
struct tcaphash_endcall_t *p_tcaphash_endcall=NULL;
struct tcaphash_begin_info_key_t tcaphash_begin_key;
struct tcaphash_begincall_t *p_tcaphash_begincall=NULL;
proto_item *pi;
nstime_t delta;
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
#ifdef DEBUG_TCAPSRT
dbg(51,"src %s dst %s dstTid %lx ", address_to_str(wmem_packet_scope(), &pinfo->src), address_to_str(wmem_packet_scope(), &pinfo->dst), p_tcapsrt_info->dst_tid);
dbg(10,"\n Hend #%u ", pinfo->num);
#endif
tcaphash_end_key.tid = p_tcapsrt_info->dst_tid;
if (pinfo->src.type == ss7pc_address_type && pinfo->dst.type == ss7pc_address_type)
{
tcaphash_end_key.pc_hash = mtp3_pc_hash((const mtp3_addr_pc_t *)pinfo->dst.data);
} else {
tcaphash_end_key.pc_hash = g_str_hash(address_to_str(wmem_packet_scope(), &pinfo->dst));
}
tcaphash_end_key.hashKey=tcaphash_end_calchash(&tcaphash_end_key);
#ifdef DEBUG_TCAPSRT
dbg(11,"Ekey %lx ",tcaphash_end_key.hashKey);
dbg(11,"addr %s ", address_to_str(wmem_packet_scope(), &pinfo->dst));
dbg(51,"Tid %lx ",tcaphash_end_key.tid);
#endif
p_tcaphash_endcall = find_tcaphash_end(&tcaphash_end_key, pinfo,TRUE);
if(!p_tcaphash_endcall) {
#ifdef DEBUG_TCAPSRT
dbg(12,"EnotFound ");
#endif
tcaphash_begin_key.tid = p_tcapsrt_info->dst_tid;
if (pinfo->src.type == ss7pc_address_type && pinfo->dst.type == ss7pc_address_type)
{
tcaphash_begin_key.pc_hash = mtp3_pc_hash((const mtp3_addr_pc_t *)pinfo->dst.data);
} else {
tcaphash_begin_key.pc_hash = g_str_hash(address_to_str(wmem_packet_scope(), &pinfo->dst));
}
tcaphash_begin_key.hashKey=tcaphash_begin_calchash(&tcaphash_begin_key);
#ifdef DEBUG_TCAPSRT
dbg(11,"Bkey %lx ", tcaphash_begin_key.hashKey);
dbg(51,"addr %s ", address_to_str(wmem_packet_scope(), &pinfo->dst));
dbg(51,"Tid %lx ",tcaphash_begin_key.tid);
#endif
p_tcaphash_begincall = find_tcaphash_begin(&tcaphash_begin_key, pinfo,FALSE);
if(!p_tcaphash_begincall) {
#ifdef DEBUG_TCAPSRT
dbg(12,"BnotFound ");
#endif
}
}
if (p_tcaphash_endcall) {
p_tcaphash_context=p_tcaphash_endcall->context;
} else if (p_tcaphash_begincall) {
p_tcaphash_context=p_tcaphash_begincall->context;
}
if (p_tcaphash_context) {
#ifdef DEBUG_TCAPSRT
dbg(12,"Found, req=%d ",p_tcaphash_context->first_frame);
#endif
if (gtcap_DisplaySRT && tree) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, -1, ett_tcap_stat, &stat_item, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
pi = proto_tree_add_uint(stat_tree, hf_tcapsrt_SessionId, tvb, 0,0, p_tcaphash_context->session_id);
PROTO_ITEM_SET_GENERATED(pi);
}
#ifdef DEBUG_TCAPSRT
dbg(20,"Display framereqlink %d ",p_tcaphash_context->first_frame);
#endif
if (gtcap_DisplaySRT && stat_tree) {
pi = proto_tree_add_uint_format(stat_tree, hf_tcapsrt_EndSession, tvb, 0, 0,
p_tcaphash_context->first_frame,
"Begin of session in frame %u",
p_tcaphash_context->first_frame);
PROTO_ITEM_SET_GENERATED(pi);
nstime_delta(&delta, &pinfo->abs_ts, &p_tcaphash_context->begin_time);
pi = proto_tree_add_time(stat_tree, hf_tcapsrt_SessionTime, tvb, 0, 0, &delta);
PROTO_ITEM_SET_GENERATED(pi);
}
tcapsrt_close(p_tcaphash_context,pinfo);
} else {
#ifdef DEBUG_TCAPSRT
dbg(12,"Context notFound ");
#endif
}
return p_tcaphash_context;
}
static struct tcaphash_context_t *
tcaphash_ansi_matching(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
struct tcapsrt_info_t *p_tcapsrt_info)
{
struct tcaphash_context_t *p_tcaphash_context=NULL;
struct tcaphash_context_key_t tcaphash_context_key;
struct tcaphash_ansicall_t *p_tcaphash_ansicall, *p_new_tcaphash_ansicall;
struct tcaphash_ansi_info_key_t tcaphash_ansi_key;
proto_item *pi;
nstime_t delta;
gboolean isResponse=FALSE;
proto_tree * stat_tree=NULL;
proto_item * stat_item=NULL;
tcaphash_ansi_key.tid = p_tcapsrt_info->src_tid;
if (pinfo->src.type == ss7pc_address_type && pinfo->dst.type == ss7pc_address_type)
{
tcaphash_ansi_key.opc_hash = mtp3_pc_hash((const mtp3_addr_pc_t *)pinfo->src.data);
tcaphash_ansi_key.dpc_hash = mtp3_pc_hash((const mtp3_addr_pc_t *)pinfo->dst.data);
} else {
tcaphash_ansi_key.opc_hash = g_str_hash(address_to_str(wmem_packet_scope(), &pinfo->src));
tcaphash_ansi_key.dpc_hash = g_str_hash(address_to_str(wmem_packet_scope(), &pinfo->dst));
}
tcaphash_ansi_key.hashKey=tcaphash_ansi_calchash(&tcaphash_ansi_key);
#ifdef DEBUG_TCAPSRT
dbg(10,"\n Hansi #%u ", pinfo->num);
dbg(11,"key %lx ",tcaphash_ansi_key.hashKey);
dbg(51,"PC %s %s ",address_to_str(wmem_packet_scope(), &pinfo->src), address_to_str(wmem_packet_scope(), &pinfo->dst));
dbg(51,"Tid %lx ",tcaphash_ansi_key.tid);
#endif
p_tcaphash_ansicall = (struct tcaphash_ansicall_t *)
g_hash_table_lookup(tcaphash_ansi, &tcaphash_ansi_key);
if (p_tcaphash_ansicall) {
do {
if (pinfo->num == p_tcaphash_ansicall->context->first_frame) {
#ifdef DEBUG_TCAPSRT
dbg(22,"Request already seen ");
#endif
isResponse=FALSE;
p_tcaphash_context=p_tcaphash_ansicall->context;
break;
}
if (pinfo->num == p_tcaphash_ansicall->context->last_frame) {
#ifdef DEBUG_TCAPSRT
dbg(22,"Response already seen ");
#endif
isResponse=TRUE;
p_tcaphash_context=p_tcaphash_ansicall->context;
break;
}
if ( pinfo->num > p_tcaphash_ansicall->context->first_frame &&
p_tcaphash_ansicall->context->last_frame==0 ) {
#ifdef DEBUG_TCAPSRT
dbg(12,"Update key %lx ",tcaphash_ansi_key.hashKey);
#endif
p_tcaphash_ansicall->context->last_frame = pinfo->num;
p_tcaphash_ansicall->context->responded = TRUE;
p_tcaphash_ansicall->context->closed = TRUE;
p_tcaphash_context=p_tcaphash_ansicall->context;
isResponse=TRUE;
if (gtcap_DisplaySRT && tree) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, -1, ett_tcap_stat, &stat_item, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
pi = proto_tree_add_uint(stat_tree, hf_tcapsrt_SessionId, tvb, 0,0, p_tcaphash_context->session_id);
PROTO_ITEM_SET_GENERATED(pi);
#ifdef DEBUG_TCAPSRT
dbg(20,"Display framereqlink %d ",p_tcaphash_context->first_frame);
#endif
pi = proto_tree_add_uint_format(stat_tree, hf_tcapsrt_EndSession, tvb, 0, 0,
p_tcaphash_context->first_frame,
"Begin of session in frame %u",
p_tcaphash_context->first_frame);
PROTO_ITEM_SET_GENERATED(pi);
nstime_delta(&delta, &pinfo->abs_ts, &p_tcaphash_context->begin_time);
pi = proto_tree_add_time(stat_tree, hf_tcapsrt_SessionTime, tvb, 0, 0, &delta);
PROTO_ITEM_SET_GENERATED(pi);
}
break;
}
if (!p_tcaphash_ansicall->next_ansicall) {
if ( ( p_tcaphash_ansicall->context->last_frame != 0
&& pinfo->num > p_tcaphash_ansicall->context->first_frame
&& (guint) pinfo->abs_ts.secs > (guint)(p_tcaphash_ansicall->context->begin_time.secs + gtcap_RepetitionTimeout)
) ||
( p_tcaphash_ansicall->context->last_frame == 0
&& pinfo->num > p_tcaphash_ansicall->context->first_frame
&& (guint)pinfo->abs_ts.secs > (guint)(p_tcaphash_ansicall->context->begin_time.secs + gtcap_LostTimeout)
)
)
{
#ifdef DEBUG_TCAPSRT
dbg(12,"(timeout) Append key %lx ",tcaphash_ansi_key.hashKey);
dbg(12,"Frame %u rsp %u ",pinfo->num,p_tcaphash_ansicall->context->last_frame );
#endif
tcaphash_context_key.session_id = tcapsrt_global_SessionId++;
p_tcaphash_context = new_tcaphash_context(&tcaphash_context_key, pinfo);
p_new_tcaphash_ansicall = append_tcaphash_ansicall(p_tcaphash_ansicall,
p_tcaphash_context,
pinfo);
#ifdef DEBUG_TCAPSRT
dbg(12,"Update key %lx ",tcaphash_ansi_key.hashKey);
#endif
update_tcaphash_ansicall(p_new_tcaphash_ansicall, pinfo);
p_tcaphash_ansicall=p_new_tcaphash_ansicall;
} else {
if ( p_tcaphash_ansicall->context->closed) {
#ifdef DEBUG_TCAPSRT
dbg(12,"(closed) Append key %lu ",tcaphash_ansi_key.hashKey);
dbg(12,"Frame %u rsp %u ",pinfo->num,p_tcaphash_ansicall->context->last_frame );
#endif
tcaphash_context_key.session_id = tcapsrt_global_SessionId++;
p_tcaphash_context = new_tcaphash_context(&tcaphash_context_key, pinfo);
p_new_tcaphash_ansicall = append_tcaphash_ansicall(p_tcaphash_ansicall,
p_tcaphash_context,
pinfo);
#ifdef DEBUG_TCAPSRT
dbg(12,"Update key %lu ",tcaphash_ansi_key.hashKey);
#endif
update_tcaphash_ansicall(p_new_tcaphash_ansicall, pinfo);
p_tcaphash_ansicall=p_new_tcaphash_ansicall;
} else {
p_tcaphash_context=p_tcaphash_ansicall->context;
#ifdef DEBUG_TCAPSRT
dbg(12,"Found, req=%d ",p_tcaphash_context->first_frame);
#endif
if (gtcap_DisplaySRT && tree) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, -1, ett_tcap_stat, &stat_item, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
pi = proto_tree_add_uint(stat_tree, hf_tcapsrt_SessionId, tvb, 0,0, p_tcaphash_context->session_id);
PROTO_ITEM_SET_GENERATED(pi);
#ifdef DEBUG_TCAPSRT
dbg(20,"Display framereqlink %d ",p_tcaphash_context->first_frame);
#endif
pi = proto_tree_add_uint_format(stat_tree, hf_tcapsrt_EndSession, tvb, 0, 0,
p_tcaphash_context->first_frame,
"Begin of session in frame %u",
p_tcaphash_context->first_frame);
PROTO_ITEM_SET_GENERATED(pi);
nstime_delta(&delta, &pinfo->abs_ts, &p_tcaphash_context->begin_time);
pi = proto_tree_add_time(stat_tree, hf_tcapsrt_SessionTime, tvb, 0, 0, &delta);
PROTO_ITEM_SET_GENERATED(pi);
}
p_tcaphash_context=p_tcaphash_ansicall->context;
}
}
break;
}
p_tcaphash_ansicall = p_tcaphash_ansicall->next_ansicall;
} while (p_tcaphash_ansicall != NULL );
} else {
#ifdef DEBUG_TCAPSRT
dbg(10,"New key %lx ",tcaphash_ansi_key.hashKey);
#endif
tcaphash_context_key.session_id = tcapsrt_global_SessionId++;
p_tcaphash_context = new_tcaphash_context(&tcaphash_context_key, pinfo);
p_tcaphash_ansicall = new_tcaphash_ansi(&tcaphash_ansi_key, p_tcaphash_context);
#ifdef DEBUG_TCAPSRT
dbg(11,"Update key %lx ",tcaphash_ansi_key.hashKey);
dbg(11,"Frame reqlink #%u ", pinfo->num);
#endif
update_tcaphash_ansicall(p_tcaphash_ansicall, pinfo);
}
if ( gtcap_DisplaySRT && tree &&
p_tcaphash_context &&
p_tcaphash_context->session_id) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, -1, ett_tcap_stat, &stat_item, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
pi = proto_tree_add_uint(stat_tree, hf_tcapsrt_SessionId, tvb, 0,0, p_tcaphash_context->session_id);
PROTO_ITEM_SET_GENERATED(pi);
}
if( gtcap_DisplaySRT && stat_tree &&
p_tcaphash_ansicall->context->last_frame != 0){
if (!isResponse) {
#ifdef DEBUG_TCAPSRT
dbg(20,"Display_frameRsplink %d ",p_tcaphash_ansicall->context->last_frame);
#endif
pi = proto_tree_add_uint_format(stat_tree, hf_tcapsrt_BeginSession, tvb, 0, 0,
p_tcaphash_ansicall->context->last_frame,
"End of session in frame %u",
p_tcaphash_ansicall->context->last_frame);
PROTO_ITEM_SET_GENERATED(pi);
} else {
#ifdef DEBUG_TCAPSRT
dbg(20,"Display framereqlink %d ",p_tcaphash_context->first_frame);
#endif
if (gtcap_DisplaySRT) {
pi = proto_tree_add_uint_format(stat_tree, hf_tcapsrt_EndSession, tvb, 0, 0,
p_tcaphash_context->first_frame,
"Begin of session in frame %u",
p_tcaphash_context->first_frame);
PROTO_ITEM_SET_GENERATED(pi);
nstime_delta(&delta, &pinfo->abs_ts, &p_tcaphash_context->begin_time);
pi = proto_tree_add_time(stat_tree, hf_tcapsrt_SessionTime, tvb, 0, 0, &delta);
PROTO_ITEM_SET_GENERATED(pi);
}
}
}
return p_tcaphash_context;
}
struct tcaphash_context_t *
tcapsrt_call_matching(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
struct tcapsrt_info_t *p_tcapsrt_info)
{
struct tcaphash_context_t *tcap_context=NULL;
if(pinfo == NULL || pinfo->num == 0) {
return NULL;
}
switch (p_tcapsrt_info->ope) {
case TC_BEGIN:
#ifdef DEBUG_TCAPSRT
dbg(1,"\nTC_BEGIN ");
#endif
tcap_context=tcaphash_begin_matching(tvb, pinfo, tree, p_tcapsrt_info);
break;
case TC_CONT:
#ifdef DEBUG_TCAPSRT
dbg(1,"\nTC_CONT ");
#endif
tcap_context=tcaphash_cont_matching(tvb, pinfo, tree, p_tcapsrt_info);
break;
case TC_ABORT:
#ifdef DEBUG_TCAPSRT
dbg(1,"\nTC_ABORT ");
#endif
tcap_context=tcaphash_end_matching(tvb, pinfo, tree, p_tcapsrt_info);
break;
case TC_END:
#ifdef DEBUG_TCAPSRT
dbg(1,"\nTC_END ");
#endif
tcap_context=tcaphash_end_matching(tvb, pinfo, tree, p_tcapsrt_info);
break;
case TC_ANSI_ALL:
case TC_ANSI_ABORT:
#ifdef DEBUG_TCAPSRT
dbg(1,"\nTC_ANSI ");
#endif
tcap_context=tcaphash_ansi_matching(tvb, pinfo, tree, p_tcapsrt_info);
break;
default:
#ifdef DEBUG_TCAPSRT
dbg(1,"\nUnknown %d ", p_tcapsrt_info->ope);
#endif
break;
}
#ifdef DEBUG_TCAPSRT
if (tcap_context)
dbg(1,"session %d ", tcap_context->session_id);
#endif
return tcap_context;
}
struct tcapsrt_info_t *
tcapsrt_razinfo(void)
{
struct tcapsrt_info_t *p_tcapsrt_info ;
tcapsrt_global_current++;
if(tcapsrt_global_current==MAX_TCAP_INSTANCE){
tcapsrt_global_current=0;
}
p_tcapsrt_info=&tcapsrt_global_info[tcapsrt_global_current];
memset(p_tcapsrt_info,0,sizeof(struct tcapsrt_info_t));
return p_tcapsrt_info;
}
void
tcapsrt_close(struct tcaphash_context_t *p_tcaphash_context,
packet_info *pinfo)
{
#ifdef DEBUG_TCAPSRT
dbg(60,"Force close ");
#endif
if (p_tcaphash_context) {
p_tcaphash_context->responded=TRUE;
p_tcaphash_context->last_frame = pinfo->num;
p_tcaphash_context->end_time = pinfo->abs_ts;
p_tcaphash_context->closed=TRUE;
if (p_tcaphash_context->endcall
&& !gtcap_PersistentSRT) {
if (p_tcaphash_context->endcall->next_endcall) {
if (p_tcaphash_context->endcall->previous_endcall ) {
#ifdef DEBUG_TCAPSRT
dbg(20,"deplace Ehash ");
#endif
p_tcaphash_context->endcall->previous_endcall->next_endcall
= p_tcaphash_context->endcall->next_endcall;
p_tcaphash_context->endcall->next_endcall->previous_endcall
= p_tcaphash_context->endcall->previous_endcall;
g_hash_table_remove(tcaphash_end, p_tcaphash_context->endcall->endkey);
} else {
#ifdef DEBUG_TCAPSRT
dbg(20,"father Ehash ");
#endif
}
} else if (!gtcap_PersistentSRT) {
#ifdef DEBUG_TCAPSRT
dbg(20,"remove Ehash ");
#endif
g_hash_table_remove(tcaphash_end, p_tcaphash_context->endcall->endkey);
}
}
if (p_tcaphash_context->contcall
&& !gtcap_PersistentSRT) {
if (p_tcaphash_context->contcall->next_contcall) {
if (p_tcaphash_context->contcall->previous_contcall ) {
#ifdef DEBUG_TCAPSRT
dbg(20,"deplace Chash ");
#endif
p_tcaphash_context->contcall->previous_contcall->next_contcall
= p_tcaphash_context->contcall->next_contcall;
p_tcaphash_context->contcall->next_contcall->previous_contcall
= p_tcaphash_context->contcall->previous_contcall;
g_hash_table_remove(tcaphash_cont, p_tcaphash_context->contcall->contkey);
} else {
#ifdef DEBUG_TCAPSRT
dbg(20,"father Chash ");
#endif
}
} else if (!gtcap_PersistentSRT) {
#ifdef DEBUG_TCAPSRT
dbg(20,"remove Chash ");
#endif
g_hash_table_remove(tcaphash_cont, p_tcaphash_context->contcall->contkey);
}
}
if (p_tcaphash_context->begincall
&& !gtcap_PersistentSRT) {
if (p_tcaphash_context->begincall->next_begincall) {
if (p_tcaphash_context->begincall->previous_begincall ) {
#ifdef DEBUG_TCAPSRT
dbg(20,"deplace Bhash ");
#endif
p_tcaphash_context->begincall->previous_begincall->next_begincall
= p_tcaphash_context->begincall->next_begincall;
p_tcaphash_context->begincall->next_begincall->previous_begincall
= p_tcaphash_context->begincall->previous_begincall;
g_hash_table_remove(tcaphash_begin, p_tcaphash_context->begincall->beginkey);
} else {
#ifdef DEBUG_TCAPSRT
dbg(20,"father Bhash ");
#endif
}
} else if (!gtcap_PersistentSRT) {
#ifdef DEBUG_TCAPSRT
dbg(20,"remove Bhash ");
#endif
g_hash_table_remove(tcaphash_begin, p_tcaphash_context->begincall->beginkey);
}
}
if (p_tcaphash_context->ansicall
&& !gtcap_PersistentSRT) {
if (p_tcaphash_context->ansicall->next_ansicall) {
if (p_tcaphash_context->ansicall->previous_ansicall ) {
#ifdef DEBUG_TCAPSRT
dbg(20,"deplace Ahash ");
#endif
p_tcaphash_context->ansicall->previous_ansicall->next_ansicall
= p_tcaphash_context->ansicall->next_ansicall;
p_tcaphash_context->ansicall->next_ansicall->previous_ansicall
= p_tcaphash_context->ansicall->previous_ansicall;
g_hash_table_remove(tcaphash_ansi, p_tcaphash_context->ansicall->ansikey);
} else {
#ifdef DEBUG_TCAPSRT
dbg(20,"father Ahash ");
#endif
}
} else if (!gtcap_PersistentSRT) {
#ifdef DEBUG_TCAPSRT
dbg(20,"remove Ahash ");
#endif
g_hash_table_remove(tcaphash_ansi, p_tcaphash_context->ansicall->ansikey);
}
}
if (!gtcap_PersistentSRT) {
#ifdef DEBUG_TCAPSRT
dbg(20,"remove context ");
#endif
g_hash_table_remove(tcaphash_context, p_tcaphash_context->key);
}
} else {
#ifdef DEBUG_TCAPSRT
dbg(20,"No context to remove ");
#endif
}
}
static int
dissect_tcap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
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
switch (tag){
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 22:
return call_dissector(ansi_tcap_handle, tvb, pinfo, parent_tree);
default:
return tvb_captured_length(tvb);
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
asn1_ctx.value_ptr = &tcap_private;
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
return tvb_captured_length(tvb);
}
void
proto_reg_handoff_tcap(void)
{
data_handle = find_dissector("data");
ansi_tcap_handle = find_dissector_add_dependency("ansi_tcap", proto_tcap);
ber_oid_dissector_table = find_dissector_table("ber.oid");
ss7pc_address_type = address_type_get_by_name("AT_SS7PC");
#line 1 "./asn1/tcap/packet-tcap-dis-tab.c"
register_ber_oid_dissector("0.0.17.773.1.1.1", dissect_DialoguePDU_PDU, proto_tcap, "id-as-dialogue");
register_ber_oid_dissector("0.0.17.773.1.2.1", dissect_UniDialoguePDU_PDU, proto_tcap, "id-as-uniDialogue");
#line 1982 "./asn1/tcap/packet-tcap-template.c"
}
void
proto_register_tcap(void)
{
static hf_register_info hf[] = {
{ &hf_tcap_tag,
{ "Tag",
"tcap.msgtype",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_tcap_length,
{ "Length",
"tcap.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_tcap_data,
{ "Data",
"tcap.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tcap_tid,
{ "Transaction Id",
"tcap.tid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tcap_constructor_eoc,
{ "CONSTRUCTOR EOC",
"tcap.constructor_eoc",
FT_UINT16, BASE_HEX, NULL, 0,
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
#line 1 "./asn1/tcap/packet-tcap-hfarr.c"
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
#line 2055 "./asn1/tcap/packet-tcap-template.c"
};
static gint *ett[] = {
&ett_tcap,
&ett_param,
&ett_otid,
&ett_dtid,
&ett_tcap_stat,
#line 1 "./asn1/tcap/packet-tcap-ettarr.c"
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
#line 2065 "./asn1/tcap/packet-tcap-template.c"
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
register_cleanup_routine(&cleanup_tcap);
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
static void init_tcap(void)
{
ssn_range = range_copy(global_ssn_range);
range_foreach(ssn_range, range_add_callback);
tcapsrt_init_routine();
}
static void cleanup_tcap(void)
{
range_foreach(ssn_range, range_delete_callback);
g_free(ssn_range);
}
static int
dissect_tcap_param(asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset)
{
gint tag_offset, saved_offset, len_offset;
tvbuff_t *next_tvb;
proto_tree *subtree;
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
subtree = proto_tree_add_subtree(tree, tvb, saved_offset,
len + (len_offset - saved_offset), ett_param, NULL,
"CONSTRUCTOR");
proto_tree_add_uint_format(subtree, hf_tcap_tag, tvb,
saved_offset, tag_length, tag,
"CONSTRUCTOR Tag");
proto_tree_add_uint(subtree, hf_tcap_tag, tvb, saved_offset,
tag_length, ber_class);
proto_tree_add_uint(subtree, hf_tcap_length, tvb, tag_offset,
len_length, len);
if (len-(2*ind_field))
{
next_tvb = tvb_new_subset_length(tvb, offset, len-(2*ind_field));
dissect_tcap_param(actx, subtree,next_tvb,0);
}
if (ind_field)
proto_tree_add_item(subtree, hf_tcap_constructor_eoc, tvb, offset+len-2, 2, ENC_BIG_ENDIAN);
offset += len;
}
else
{
subtree = proto_tree_add_subtree_format(tree, tvb, saved_offset,
len + (len_offset - saved_offset), ett_param, NULL,
"Parameter (0x%.2x)", tag);
proto_tree_add_uint(subtree, hf_tcap_tag, tvb, saved_offset,
tag_length, tag);
proto_tree_add_uint(subtree, hf_tcap_length, tvb,
saved_offset+tag_length, len_length, len);
if (len)
{
next_tvb = tvb_new_subset_length(tvb, offset, len);
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
} else {
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
if (is_subdissector) {
call_dissector_with_data(subdissector_handle, tvb, actx->pinfo, tree, actx->value_ptr);
col_set_fence(actx->pinfo->cinfo, COL_INFO);
}
return offset;
}
void
call_tcap_dissector(dissector_handle_t handle, tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree)
{
requested_subdissector_handle = handle;
TRY {
dissect_tcap(tvb, pinfo, tree, NULL);
} CATCH_ALL {
requested_subdissector_handle = NULL;
RETHROW;
} ENDTRY;
requested_subdissector_handle = NULL;
}
