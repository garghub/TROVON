static int call_idmp_oid_callback(tvbuff_t *tvb, int offset, packet_info *pinfo, int op, proto_tree *tree, struct SESSION_DATA_STRUCTURE *session)
{
if(session != NULL) {
if((!saved_protocolID) && (op == (ROS_OP_BIND | ROS_OP_RESULT))) {
saved_protocolID = wmem_strdup(wmem_file_scope(), protocolID);
}
session->ros_op = op;
offset = call_ros_oid_callback(saved_protocolID ? saved_protocolID : protocolID, tvb, offset, pinfo, tree, session);
}
return offset;
}
static int
dissect_idmp_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &protocolID);
return offset;
}
static int
dissect_idmp_Bind_argument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
struct SESSION_DATA_STRUCTURE *session = (struct SESSION_DATA_STRUCTURE*)actx->private_data;
return call_idmp_oid_callback(tvb, offset, actx->pinfo, (ROS_OP_BIND | ROS_OP_ARGUMENT), top_tree, session);
return offset;
}
static int
dissect_idmp_IdmBind(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IdmBind_sequence, hf_index, ett_idmp_IdmBind);
return offset;
}
static int
dissect_idmp_Bind_result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
struct SESSION_DATA_STRUCTURE *session = (struct SESSION_DATA_STRUCTURE*)actx->private_data;
return call_idmp_oid_callback(tvb, offset, actx->pinfo, (ROS_OP_BIND | ROS_OP_RESULT), top_tree, session);
return offset;
}
static int
dissect_idmp_IdmBindResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IdmBindResult_sequence, hf_index, ett_idmp_IdmBindResult);
return offset;
}
static int
dissect_idmp_Bind_errcode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
return offset;
}
static int
dissect_idmp_T_aETitleError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_idmp_Bind_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
struct SESSION_DATA_STRUCTURE *session = (struct SESSION_DATA_STRUCTURE*)actx->private_data;
return call_idmp_oid_callback(tvb, offset, actx->pinfo, (ROS_OP_BIND| ROS_OP_ERROR), top_tree, session);
return offset;
}
static int
dissect_idmp_IdmBindError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IdmBindError_sequence, hf_index, ett_idmp_IdmBindError);
return offset;
}
static int
dissect_idmp_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_idmp_T_local(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&opcode);
return offset;
}
static int
dissect_idmp_Code(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Code_choice, hf_index, ett_idmp_Code,
NULL);
return offset;
}
static int
dissect_idmp_T_argument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
struct SESSION_DATA_STRUCTURE *session = (struct SESSION_DATA_STRUCTURE*)actx->private_data;
return call_idmp_oid_callback(tvb, offset, actx->pinfo, (ROS_OP_INVOKE | ROS_OP_ARGUMENT | opcode), top_tree, session);
return offset;
}
static int
dissect_idmp_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Request_sequence, hf_index, ett_idmp_Request);
return offset;
}
static int
dissect_idmp_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_idmp_InvokeId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
InvokeId_choice, hf_index, ett_idmp_InvokeId,
NULL);
return offset;
}
static int
dissect_idmp_T_result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
struct SESSION_DATA_STRUCTURE *session = (struct SESSION_DATA_STRUCTURE*)actx->private_data;
return call_idmp_oid_callback(tvb, offset, actx->pinfo, (ROS_OP_INVOKE | ROS_OP_RESULT | opcode), top_tree, session);
return offset;
}
static int
dissect_idmp_IdmResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IdmResult_sequence, hf_index, ett_idmp_IdmResult);
return offset;
}
static int
dissect_idmp_T_errcode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
return offset;
}
static int
dissect_idmp_T_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
return offset;
}
static int
dissect_idmp_Error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Error_sequence, hf_index, ett_idmp_Error);
return offset;
}
static int
dissect_idmp_T_reason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_idmp_IdmReject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IdmReject_sequence, hf_index, ett_idmp_IdmReject);
return offset;
}
static int
dissect_idmp_Unbind(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_idmp_Abort(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_idmp_StartTLS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_idmp_TLSResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_idmp_IDM_PDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IDM_PDU_choice, hf_index, ett_idmp_IDM_PDU,
NULL);
return offset;
}
void
register_idmp_protocol_info(const char *oid, const ros_info_t *rinfo, int proto _U_, const char *name)
{
register_ros_protocol_info(oid, rinfo, proto, name, FALSE);
}
static int dissect_idmp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
int offset = 0;
proto_item *item;
proto_tree *tree;
asn1_ctx_t asn1_ctx;
struct SESSION_DATA_STRUCTURE session;
gboolean idmp_final;
guint32 idmp_length;
fragment_head *fd_head;
conversation_t *conv;
guint32 dst_ref = 0;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
conv = find_conversation (pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
if (conv) {
dst_ref = conv->index;
}
top_tree=parent_tree;
item = proto_tree_add_item(parent_tree, proto_idmp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_idmp);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IDMP");
proto_tree_add_item(tree, hf_idmp_version, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_idmp_final, tvb, offset, 1, ENC_BIG_ENDIAN);
idmp_final = tvb_get_guint8(tvb, offset); offset++;
proto_tree_add_item(tree, hf_idmp_length, tvb, offset, 4, ENC_BIG_ENDIAN);
idmp_length = tvb_get_ntohl(tvb, offset); offset += 4;
asn1_ctx.private_data = &session;
if(idmp_reassemble) {
pinfo->fragmented = !idmp_final;
col_append_fstr(pinfo->cinfo, COL_INFO, " [%sIDMP fragment, %u byte%s]",
idmp_final ? "Final " : "" ,
idmp_length, plurality(idmp_length, "", "s"));
fd_head = fragment_add_seq_next(&idmp_reassembly_table, tvb, offset,
pinfo, dst_ref, NULL,
idmp_length, !idmp_final);
if(fd_head && fd_head->next) {
proto_tree_add_item(tree, hf_idmp_segment_data, tvb, offset, (idmp_length) ? -1 : 0, ENC_NA);
if (idmp_final) {
tvb = process_reassembled_data (tvb, offset, pinfo,
"Reassembled IDMP", fd_head, &idmp_frag_items, NULL, tree);
offset = 0;
} else if (pinfo->num != fd_head->reassembled_in) {
proto_tree_add_uint (tree, hf_idmp_reassembled_in,
tvb, 0, 0, fd_head->reassembled_in);
}
}
} else {
if(!idmp_final) {
col_append_fstr(pinfo->cinfo, COL_INFO, " [IDMP fragment, %u byte%s, IDMP reassembly not enabled]",
idmp_length, plurality(idmp_length, "", "s"));
proto_tree_add_bytes_format_value(tree, hf_idmp_segment_data, tvb, offset, (idmp_length) ? -1 : 0,
NULL, "(IDMP reassembly not enabled)");
}
}
if(idmp_final) {
asn1_ctx.private_data = &session;
dissect_idmp_IDM_PDU(FALSE, tvb, offset, &asn1_ctx, tree, hf_idmp_PDU);
}
return tvb_captured_length(tvb);
}
static guint get_idmp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint32 len;
len = tvb_get_ntohl(tvb, offset + 2);
return len + 6;
}
static int dissect_idmp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, parent_tree, idmp_desegment, 0, get_idmp_pdu_len, dissect_idmp, data);
return tvb_captured_length(tvb);
}
static void idmp_reassemble_init (void)
{
reassembly_table_init (&idmp_reassembly_table,
&addresses_reassembly_table_functions);
}
static void idmp_reassemble_cleanup(void)
{
reassembly_table_destroy(&idmp_reassembly_table);
saved_protocolID = NULL;
}
void proto_register_idmp(void)
{
static hf_register_info hf[] = {
{ &hf_idmp_version,
{ "version", "idmp.version",
FT_INT8, BASE_DEC, NULL, 0,
"idmp.INTEGER", HFILL }},
{ &hf_idmp_final,
{ "final", "idmp.final",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"idmp.BOOLEAN", HFILL }},
{ &hf_idmp_length,
{ "length", "idmp.length",
FT_INT32, BASE_DEC, NULL, 0,
"idmp.INTEGER", HFILL }},
{ &hf_idmp_PDU,
{ "IDM-PDU", "idmp.pdu",
FT_UINT32, BASE_DEC, VALS(idmp_IDM_PDU_vals), 0,
"idmp.PDU", HFILL }},
{ &hf_idmp_fragments,
{ "IDMP fragments", "idmp.fragments", FT_NONE, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_idmp_fragment,
{ "IDMP fragment", "idmp.fragment", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_idmp_fragment_overlap,
{ "IDMP fragment overlap", "idmp.fragment.overlap", FT_BOOLEAN,
BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_idmp_fragment_overlap_conflicts,
{ "IDMP fragment overlapping with conflicting data",
"idmp.fragment.overlap.conflicts", FT_BOOLEAN, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_idmp_fragment_multiple_tails,
{ "IDMP has multiple tail fragments",
"idmp.fragment.multiple_tails", FT_BOOLEAN, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_idmp_fragment_too_long_fragment,
{ "IDMP fragment too long", "idmp.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_idmp_fragment_error,
{ "IDMP defragmentation error", "idmp.fragment.error", FT_FRAMENUM,
BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_idmp_fragment_count,
{ "IDMP fragment count", "idmp.fragment.count", FT_UINT32, BASE_DEC,
NULL, 0x00, NULL, HFILL } },
{ &hf_idmp_reassembled_in,
{ "Reassembled IDMP in frame", "idmp.reassembled.in", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, "This IDMP packet is reassembled in this frame", HFILL } },
{ &hf_idmp_reassembled_length,
{ "Reassembled IDMP length", "idmp.reassembled.length", FT_UINT32, BASE_DEC,
NULL, 0x00, "The total length of the reassembled payload", HFILL } },
{ &hf_idmp_segment_data,
{ "IDMP segment data", "idmp.segment_data", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
#line 1 "./asn1/idmp/packet-idmp-hfarr.c"
{ &hf_idmp_bind,
{ "bind", "idmp.bind_element",
FT_NONE, BASE_NONE, NULL, 0,
"IdmBind", HFILL }},
{ &hf_idmp_bindResult,
{ "bindResult", "idmp.bindResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"IdmBindResult", HFILL }},
{ &hf_idmp_bindError,
{ "bindError", "idmp.bindError_element",
FT_NONE, BASE_NONE, NULL, 0,
"IdmBindError", HFILL }},
{ &hf_idmp_request,
{ "request", "idmp.request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_idmp_idm_result,
{ "result", "idmp.result_element",
FT_NONE, BASE_NONE, NULL, 0,
"IdmResult", HFILL }},
{ &hf_idmp_idm_error,
{ "error", "idmp.error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_idmp_reject,
{ "reject", "idmp.reject_element",
FT_NONE, BASE_NONE, NULL, 0,
"IdmReject", HFILL }},
{ &hf_idmp_unbind,
{ "unbind", "idmp.unbind_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_idmp_abort,
{ "abort", "idmp.abort",
FT_UINT32, BASE_DEC, VALS(idmp_Abort_vals), 0,
NULL, HFILL }},
{ &hf_idmp_startTLS,
{ "startTLS", "idmp.startTLS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_idmp_tLSResponse,
{ "tLSResponse", "idmp.tLSResponse",
FT_UINT32, BASE_DEC, VALS(idmp_TLSResponse_vals), 0,
NULL, HFILL }},
{ &hf_idmp_protocolID,
{ "protocolID", "idmp.protocolID",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_idmp_callingAETitle,
{ "callingAETitle", "idmp.callingAETitle",
FT_UINT32, BASE_DEC, VALS(x509ce_GeneralName_vals), 0,
"GeneralName", HFILL }},
{ &hf_idmp_calledAETitle,
{ "calledAETitle", "idmp.calledAETitle",
FT_UINT32, BASE_DEC, VALS(x509ce_GeneralName_vals), 0,
"GeneralName", HFILL }},
{ &hf_idmp_bind_argument,
{ "argument", "idmp.argument_element",
FT_NONE, BASE_NONE, NULL, 0,
"Bind_argument", HFILL }},
{ &hf_idmp_respondingAETitle,
{ "respondingAETitle", "idmp.respondingAETitle",
FT_UINT32, BASE_DEC, VALS(x509ce_GeneralName_vals), 0,
"GeneralName", HFILL }},
{ &hf_idmp_bind_result,
{ "result", "idmp.result_element",
FT_NONE, BASE_NONE, NULL, 0,
"Bind_result", HFILL }},
{ &hf_idmp_bind_errcode,
{ "errcode", "idmp.errcode_element",
FT_NONE, BASE_NONE, NULL, 0,
"Bind_errcode", HFILL }},
{ &hf_idmp_aETitleError,
{ "aETitleError", "idmp.aETitleError",
FT_UINT32, BASE_DEC, VALS(idmp_T_aETitleError_vals), 0,
NULL, HFILL }},
{ &hf_idmp_bind_error,
{ "error", "idmp.error_element",
FT_NONE, BASE_NONE, NULL, 0,
"Bind_error", HFILL }},
{ &hf_idmp_invokeID,
{ "invokeID", "idmp.invokeID",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_idmp_opcode,
{ "opcode", "idmp.opcode",
FT_UINT32, BASE_DEC, VALS(idmp_Code_vals), 0,
"Code", HFILL }},
{ &hf_idmp_argument,
{ "argument", "idmp.argument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_idmp_idm_invokeID,
{ "invokeID", "idmp.invokeID",
FT_UINT32, BASE_DEC, VALS(idmp_InvokeId_vals), 0,
NULL, HFILL }},
{ &hf_idmp_result,
{ "result", "idmp.result_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_idmp_errcode,
{ "errcode", "idmp.errcode_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_idmp_error,
{ "error", "idmp.error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_idmp_reason,
{ "reason", "idmp.reason",
FT_UINT32, BASE_DEC, VALS(idmp_T_reason_vals), 0,
NULL, HFILL }},
{ &hf_idmp_local,
{ "local", "idmp.local",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_idmp_global,
{ "global", "idmp.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_idmp_present,
{ "present", "idmp.present",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_idmp_absent,
{ "absent", "idmp.absent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 321 "./asn1/idmp/packet-idmp-template.c"
};
static gint *ett[] = {
&ett_idmp,
&ett_idmp_fragment,
&ett_idmp_fragments,
#line 1 "./asn1/idmp/packet-idmp-ettarr.c"
&ett_idmp_IDM_PDU,
&ett_idmp_IdmBind,
&ett_idmp_IdmBindResult,
&ett_idmp_IdmBindError,
&ett_idmp_Request,
&ett_idmp_IdmResult,
&ett_idmp_Error,
&ett_idmp_IdmReject,
&ett_idmp_Code,
&ett_idmp_InvokeId,
#line 329 "./asn1/idmp/packet-idmp-template.c"
};
module_t *idmp_module;
proto_idmp = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_idmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("idmp", dissect_idmp_tcp, proto_idmp);
register_init_routine (&idmp_reassemble_init);
register_cleanup_routine (&idmp_reassemble_cleanup);
idmp_module = prefs_register_protocol_subtree("OSI/X.500", proto_idmp, prefs_register_idmp);
prefs_register_bool_preference(idmp_module, "desegment_idmp_messages",
"Reassemble IDMP messages spanning multiple TCP segments",
"Whether the IDMP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&idmp_desegment);
prefs_register_bool_preference(idmp_module, "reassemble",
"Reassemble segmented IDMP datagrams",
"Whether segmented IDMP datagrams should be reassembled."
" To use this option, you must also enable"
" \"Allow subdissectors to reassemble TCP streams\""
" in the TCP protocol settings.", &idmp_reassemble);
prefs_register_uint_preference(idmp_module, "tcp.port", "IDMP TCP Port",
"Set the port for Internet Directly Mapped Protocol requests/responses",
10, &global_idmp_tcp_port);
}
void proto_reg_handoff_idm(void) {
idmp_handle = find_dissector(PFNAME);
}
static void
prefs_register_idmp(void)
{
if(idmp_handle)
dissector_delete_uint("tcp.port", tcp_port, idmp_handle);
tcp_port = global_idmp_tcp_port;
if((tcp_port > 0) && idmp_handle)
dissector_add_uint("tcp.port", global_idmp_tcp_port, idmp_handle);
}
