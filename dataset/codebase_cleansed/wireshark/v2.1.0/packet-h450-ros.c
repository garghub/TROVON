static int
argument_cb(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_) {
arg_next_tvb = tvb;
return tvb_captured_length(tvb);
}
static int
result_cb(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_) {
res_next_tvb = tvb;
return tvb_captured_length(tvb);
}
static int
error_cb(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_) {
err_next_tvb = tvb;
return tvb_captured_length(tvb);
}
static int
dissect_h450_ros_T_local(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, &actx->rose_ctx->d.code_local);
return offset;
}
static int
dissect_h450_ros_T_global(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier_str(tvb, offset, actx, tree, hf_index, &actx->rose_ctx->d.code_global);
return offset;
}
static int
dissect_h450_ros_Code(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h450_ros_Code, Code_choice,
&actx->rose_ctx->d.code);
#line 39 "./asn1/h450-ros/h450-ros.cnf"
actx->rose_ctx->d.code_item = actx->created_item;
return offset;
}
static int
dissect_h450_ros_InvokeId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h450_ros_T_invokeIdConstrained(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 67 "./asn1/h450-ros/h450-ros.cnf"
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, TRUE);
return offset;
}
static int
dissect_h450_ros_InvokeArgument(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, argument_cb);
return offset;
}
static int
dissect_h450_ros_Invoke(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 6 "./asn1/ros/ros-inv.cnf"
dissector_handle_t arg_handle = NULL;
const gchar *descr = "";
arg_next_tvb = NULL;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h450_ros_Invoke, Invoke_sequence);
#line 11 "./asn1/ros/ros-inv.cnf"
actx->rose_ctx->d.pdu = 1;
if ((actx->rose_ctx->d.code == 0) && actx->rose_ctx->arg_local_dissector_table) {
arg_handle = dissector_get_uint_handle(actx->rose_ctx->arg_local_dissector_table, actx->rose_ctx->d.code_local);
} else if ((actx->rose_ctx->d.code == 1) && actx->rose_ctx->arg_global_dissector_table) {
arg_handle = dissector_get_string_handle(actx->rose_ctx->arg_global_dissector_table, actx->rose_ctx->d.code_global);
} else {
arg_handle = NULL;
}
if (!arg_handle ||
!proto_is_protocol_enabled(find_protocol_by_id(dissector_handle_get_protocol_index(arg_handle)))) {
if (actx->rose_ctx->d.code == 0)
descr = wmem_strdup_printf(wmem_packet_scope(), "INV: %d", actx->rose_ctx->d.code_local);
else if (actx->rose_ctx->d.code == 1)
descr = wmem_strdup_printf(wmem_packet_scope(), "INV: %s", actx->rose_ctx->d.code_global);
} else {
descr = wmem_strdup(wmem_packet_scope(), "INV:");
}
if (actx->rose_ctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), actx->rose_ctx->apdu_depth), " %s", descr);
if (actx->rose_ctx->fillin_info)
col_append_str(actx->pinfo->cinfo, COL_INFO, descr);
if (actx->rose_ctx->fillin_ptr)
g_strlcat(actx->rose_ctx->fillin_ptr, descr, actx->rose_ctx->fillin_buf_size);
if (!arg_next_tvb) {
arg_next_tvb = tvb_new_subset(tvb, (actx->encoding==ASN1_ENC_PER)?offset>>3:offset, 0, 0);
}
call_dissector_with_data((arg_handle)?arg_handle:data_handle, arg_next_tvb, actx->pinfo, tree, actx->rose_ctx);
if (!arg_handle) {
expert_add_info_format(actx->pinfo, tree, &ei_ros_undecoded, "Undecoded %s", descr);
}
return offset;
}
static int
dissect_h450_ros_ResultArgument(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, result_cb);
return offset;
}
static int
dissect_h450_ros_T_result(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h450_ros_T_result, T_result_sequence);
return offset;
}
static int
dissect_h450_ros_ReturnResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 6 "./asn1/ros/ros-res.cnf"
dissector_handle_t res_handle = NULL;
const gchar *descr = "";
actx->rose_ctx->d.code = -1;
res_next_tvb = NULL;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h450_ros_ReturnResult, ReturnResult_sequence);
#line 12 "./asn1/ros/ros-res.cnf"
actx->rose_ctx->d.pdu = 2;
if ((actx->rose_ctx->d.code == 0) && actx->rose_ctx->res_local_dissector_table) {
res_handle = dissector_get_uint_handle(actx->rose_ctx->res_local_dissector_table, actx->rose_ctx->d.code_local);
} else if ((actx->rose_ctx->d.code == 1) && actx->rose_ctx->res_global_dissector_table) {
res_handle = dissector_get_string_handle(actx->rose_ctx->res_global_dissector_table, actx->rose_ctx->d.code_global);
} else {
res_handle = NULL;
}
if (!res_handle ||
!proto_is_protocol_enabled(find_protocol_by_id(dissector_handle_get_protocol_index(res_handle)))) {
if (actx->rose_ctx->d.code == 0)
descr = wmem_strdup_printf(wmem_packet_scope(), "RES: %d", actx->rose_ctx->d.code_local);
else if (actx->rose_ctx->d.code == 1)
descr = wmem_strdup_printf(wmem_packet_scope(), "RES: %s", actx->rose_ctx->d.code_global);
} else {
descr = wmem_strdup(wmem_packet_scope(), "RES:");
}
if (actx->rose_ctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), actx->rose_ctx->apdu_depth), " %s", descr);
if (actx->rose_ctx->fillin_info)
col_append_str(actx->pinfo->cinfo, COL_INFO, descr);
if (actx->rose_ctx->fillin_ptr)
g_strlcat(actx->rose_ctx->fillin_ptr, descr, actx->rose_ctx->fillin_buf_size);
if (actx->rose_ctx->d.code != -1) {
if (!res_next_tvb) {
res_next_tvb = tvb_new_subset(tvb, (actx->encoding==ASN1_ENC_PER)?offset>>3:offset, 0, 0);
}
call_dissector_with_data((res_handle)?res_handle:data_handle, res_next_tvb, actx->pinfo, tree, actx->rose_ctx);
if (!res_handle) {
expert_add_info_format(actx->pinfo, tree, &ei_ros_undecoded, "Undecoded %s", descr);
}
}
return offset;
}
static int
dissect_h450_ros_T_parameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, error_cb);
return offset;
}
static int
dissect_h450_ros_ReturnError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 6 "./asn1/ros/ros-err.cnf"
dissector_handle_t err_handle = NULL;
const gchar *descr = "";
err_next_tvb = NULL;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h450_ros_ReturnError, ReturnError_sequence);
#line 11 "./asn1/ros/ros-err.cnf"
actx->rose_ctx->d.pdu = 3;
if ((actx->rose_ctx->d.code == 0) && actx->rose_ctx->err_local_dissector_table) {
err_handle = dissector_get_uint_handle(actx->rose_ctx->err_local_dissector_table, actx->rose_ctx->d.code_local);
} else if ((actx->rose_ctx->d.code == 1) && actx->rose_ctx->err_global_dissector_table) {
err_handle = dissector_get_string_handle(actx->rose_ctx->err_global_dissector_table, actx->rose_ctx->d.code_global);
} else {
err_handle = NULL;
}
if (!err_handle ||
!proto_is_protocol_enabled(find_protocol_by_id(dissector_handle_get_protocol_index(err_handle)))) {
if (actx->rose_ctx->d.code == 0)
descr = wmem_strdup_printf(wmem_packet_scope(), "ERR: %d", actx->rose_ctx->d.code_local);
else if (actx->rose_ctx->d.code == 1)
descr = wmem_strdup_printf(wmem_packet_scope(), "ERR: %s", actx->rose_ctx->d.code_global);
} else {
descr = wmem_strdup(wmem_packet_scope(), "ERR:");
}
if (actx->rose_ctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), actx->rose_ctx->apdu_depth), " %s", descr);
if (actx->rose_ctx->fillin_info)
col_append_str(actx->pinfo->cinfo, COL_INFO, descr);
if (actx->rose_ctx->fillin_ptr)
g_strlcat(actx->rose_ctx->fillin_ptr, descr, actx->rose_ctx->fillin_buf_size);
if (!err_next_tvb) {
err_next_tvb = tvb_new_subset(tvb, (actx->encoding==ASN1_ENC_PER)?offset>>3:offset, 0, 0);
}
call_dissector_with_data((err_handle)?err_handle:data_handle, err_next_tvb, actx->pinfo, tree, actx->rose_ctx);
if (!err_handle) {
expert_add_info_format(actx->pinfo, tree, &ei_ros_undecoded, "Undecoded %s", descr);
}
return offset;
}
static int
dissect_h450_ros_GeneralProblem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, &problem_val);
#line 50 "./asn1/h450-ros/h450-ros.cnf"
g_strlcpy(problem_str, val_to_str_const(problem_val, VALS(h450_ros_GeneralProblem_vals), ""), 64);
problem_str[64-1] = '\0';
return offset;
}
static int
dissect_h450_ros_InvokeProblem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, &problem_val);
#line 53 "./asn1/h450-ros/h450-ros.cnf"
g_strlcpy(problem_str, val_to_str_const(problem_val, VALS(h450_ros_InvokeProblem_vals), ""), 64);
problem_str[64-1] = '\0';
return offset;
}
static int
dissect_h450_ros_ReturnResultProblem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, &problem_val);
#line 56 "./asn1/h450-ros/h450-ros.cnf"
g_strlcpy(problem_str, val_to_str_const(problem_val, VALS(h450_ros_ReturnResultProblem_vals), ""), 64);
problem_str[64-1] = '\0';
return offset;
}
static int
dissect_h450_ros_ReturnErrorProblem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, &problem_val);
#line 59 "./asn1/h450-ros/h450-ros.cnf"
g_strlcpy(problem_str, val_to_str_const(problem_val, VALS(h450_ros_ReturnErrorProblem_vals), ""), 64);
problem_str[64-1] = '\0';
return offset;
}
static int
dissect_h450_ros_T_problem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h450_ros_T_problem, T_problem_choice,
NULL);
return offset;
}
static int
dissect_h450_ros_Reject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 6 "./asn1/ros/ros-rej.cnf"
const gchar *descr = "";
problem_str[0] = '\0';
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h450_ros_Reject, Reject_sequence);
#line 10 "./asn1/ros/ros-rej.cnf"
descr = wmem_strdup_printf(wmem_packet_scope(), "REJ: %s", problem_str);
if (actx->rose_ctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), actx->rose_ctx->apdu_depth), " %s", descr);
if (actx->rose_ctx->fillin_info)
col_append_str(actx->pinfo->cinfo, COL_INFO, descr);
if (actx->rose_ctx->fillin_ptr)
g_strlcat(actx->rose_ctx->fillin_ptr, descr, actx->rose_ctx->fillin_buf_size);
return offset;
}
int
dissect_h450_ros_ROS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 28 "./asn1/h450-ros/h450-ros.cnf"
DISSECTOR_ASSERT(actx->rose_ctx);
rose_ctx_clean_data(actx->rose_ctx);
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h450_ros_ROS, ROS_choice,
NULL);
return offset;
}
void proto_register_h450_ros(void) {
static hf_register_info hf[] = {
#line 1 "./asn1/h450-ros/packet-h450-ros-hfarr.c"
{ &hf_h450_ros_local,
{ "local", "h450.ros.local",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h450_ros_global,
{ "global", "h450.ros.global",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h450_ros_invoke,
{ "invoke", "h450.ros.invoke_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h450_ros_returnResult,
{ "returnResult", "h450.ros.returnResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h450_ros_returnError,
{ "returnError", "h450.ros.returnError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h450_ros_reject,
{ "reject", "h450.ros.reject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h450_ros_invokeIdConstrained,
{ "invokeId", "h450.ros.invokeId",
FT_INT32, BASE_DEC, NULL, 0,
"T_invokeIdConstrained", HFILL }},
{ &hf_h450_ros_linkedId,
{ "linkedId", "h450.ros.linkedId",
FT_INT32, BASE_DEC, NULL, 0,
"InvokeId", HFILL }},
{ &hf_h450_ros_opcode,
{ "opcode", "h450.ros.opcode",
FT_UINT32, BASE_DEC, VALS(h450_ros_Code_vals), 0,
"Code", HFILL }},
{ &hf_h450_ros_argument,
{ "argument", "h450.ros.argument",
FT_BYTES, BASE_NONE, NULL, 0,
"InvokeArgument", HFILL }},
{ &hf_h450_ros_invokeId,
{ "invokeId", "h450.ros.invokeId",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h450_ros_result,
{ "result", "h450.ros.result_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h450_ros_resultArgument,
{ "result", "h450.ros.result",
FT_BYTES, BASE_NONE, NULL, 0,
"ResultArgument", HFILL }},
{ &hf_h450_ros_errcode,
{ "errcode", "h450.ros.errcode",
FT_UINT32, BASE_DEC, VALS(h450_ros_Code_vals), 0,
"Code", HFILL }},
{ &hf_h450_ros_parameter,
{ "parameter", "h450.ros.parameter",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h450_ros_problem,
{ "problem", "h450.ros.problem",
FT_UINT32, BASE_DEC, VALS(h450_ros_T_problem_vals), 0,
NULL, HFILL }},
{ &hf_h450_ros_general,
{ "general", "h450.ros.general",
FT_INT32, BASE_DEC, VALS(h450_ros_GeneralProblem_vals), 0,
"GeneralProblem", HFILL }},
{ &hf_h450_ros_invokeProblem,
{ "invoke", "h450.ros.invoke",
FT_INT32, BASE_DEC, VALS(h450_ros_InvokeProblem_vals), 0,
"InvokeProblem", HFILL }},
{ &hf_h450_ros_returnResultProblem,
{ "returnResult", "h450.ros.returnResult",
FT_INT32, BASE_DEC, VALS(h450_ros_ReturnResultProblem_vals), 0,
"ReturnResultProblem", HFILL }},
{ &hf_h450_ros_returnErrorProblem,
{ "returnError", "h450.ros.returnError",
FT_INT32, BASE_DEC, VALS(h450_ros_ReturnErrorProblem_vals), 0,
"ReturnErrorProblem", HFILL }},
#line 86 "./asn1/h450-ros/packet-h450-ros-template.c"
};
static gint *ett[] = {
#line 1 "./asn1/h450-ros/packet-h450-ros-ettarr.c"
&ett_h450_ros_Code,
&ett_h450_ros_ROS,
&ett_h450_ros_Invoke,
&ett_h450_ros_ReturnResult,
&ett_h450_ros_T_result,
&ett_h450_ros_ReturnError,
&ett_h450_ros_Reject,
&ett_h450_ros_T_problem,
#line 91 "./asn1/h450-ros/packet-h450-ros-template.c"
};
static ei_register_info ei[] = {
{ &ei_ros_undecoded, { "h450.ros.undecoded", PI_UNDECODED, PI_WARN, "Undecoded", EXPFILL }},
};
expert_module_t* expert_h450_ros;
proto_h450_ros = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_set_cant_toggle(proto_h450_ros);
proto_register_field_array(proto_h450_ros, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_h450_ros = expert_register_protocol(proto_h450_ros);
expert_register_field_array(expert_h450_ros, ei, array_length(ei));
}
void proto_reg_handoff_h450_ros(void) {
data_handle = find_dissector("data");
}
