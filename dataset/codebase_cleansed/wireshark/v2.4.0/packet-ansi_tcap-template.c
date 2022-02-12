static void ansi_tcap_ctx_init(struct ansi_tcap_private_t *a_tcap_ctx) {
memset(a_tcap_ctx, '\0', sizeof(*a_tcap_ctx));
a_tcap_ctx->signature = ANSI_TCAP_CTX_SIGNATURE;
a_tcap_ctx->oid_is_present = FALSE;
a_tcap_ctx->TransactionID_str = NULL;
}
static void
save_invoke_data(packet_info *pinfo, proto_tree *tree _U_, tvbuff_t *tvb _U_){
struct ansi_tcap_invokedata_t *ansi_tcap_saved_invokedata;
gchar *src, *dst;
char *buf;
src = address_to_str(wmem_packet_scope(), &(pinfo->src));
dst = address_to_str(wmem_packet_scope(), &(pinfo->dst));
if ((!pinfo->fd->flags.visited)&&(ansi_tcap_private.TransactionID_str)){
switch(ansi_tcap_response_matching_type){
case ANSI_TCAP_TID_ONLY:
buf = wmem_strdup(wmem_packet_scope(), ansi_tcap_private.TransactionID_str);
break;
case ANSI_TCAP_TID_AND_SOURCE:
buf = wmem_strdup_printf(wmem_packet_scope(), "%s%s",ansi_tcap_private.TransactionID_str,src);
break;
case ANSI_TCAP_TID_SOURCE_AND_DEST:
default:
buf = wmem_strdup_printf(wmem_packet_scope(), "%s%s%s",ansi_tcap_private.TransactionID_str,src,dst);
break;
}
ansi_tcap_saved_invokedata = (struct ansi_tcap_invokedata_t *)wmem_map_lookup(TransactionId_table,buf);
if(ansi_tcap_saved_invokedata)
return;
ansi_tcap_saved_invokedata = wmem_new(wmem_file_scope(), struct ansi_tcap_invokedata_t);
ansi_tcap_saved_invokedata->OperationCode = ansi_tcap_private.d.OperationCode;
ansi_tcap_saved_invokedata->OperationCode_national = ansi_tcap_private.d.OperationCode_national;
ansi_tcap_saved_invokedata->OperationCode_private = ansi_tcap_private.d.OperationCode_private;
wmem_map_insert(TransactionId_table,
wmem_strdup(wmem_file_scope(), buf),
ansi_tcap_saved_invokedata);
}
}
static gboolean
find_saved_invokedata(packet_info *pinfo, proto_tree *tree _U_, tvbuff_t *tvb _U_){
struct ansi_tcap_invokedata_t *ansi_tcap_saved_invokedata;
gchar *src, *dst;
char *buf;
if (!ansi_tcap_private.TransactionID_str) {
return FALSE;
}
src = address_to_str(wmem_packet_scope(), &(pinfo->src));
dst = address_to_str(wmem_packet_scope(), &(pinfo->dst));
buf = (char *)wmem_alloc(wmem_packet_scope(), MAX_TID_STR_LEN);
buf[0] = '\0';
switch(ansi_tcap_response_matching_type){
case ANSI_TCAP_TID_ONLY:
g_snprintf(buf,MAX_TID_STR_LEN,"%s",ansi_tcap_private.TransactionID_str);
break;
case ANSI_TCAP_TID_AND_SOURCE:
g_snprintf(buf,MAX_TID_STR_LEN,"%s%s",ansi_tcap_private.TransactionID_str,dst);
break;
case ANSI_TCAP_TID_SOURCE_AND_DEST:
default:
g_snprintf(buf,MAX_TID_STR_LEN,"%s%s%s",ansi_tcap_private.TransactionID_str,dst,src);
break;
}
ansi_tcap_saved_invokedata = (struct ansi_tcap_invokedata_t *)wmem_map_lookup(TransactionId_table, buf);
if(ansi_tcap_saved_invokedata){
ansi_tcap_private.d.OperationCode = ansi_tcap_saved_invokedata->OperationCode;
ansi_tcap_private.d.OperationCode_national = ansi_tcap_saved_invokedata->OperationCode_national;
ansi_tcap_private.d.OperationCode_private = ansi_tcap_saved_invokedata->OperationCode_private;
return TRUE;
}
return FALSE;
}
static gboolean
find_tcap_subdissector(tvbuff_t *tvb, asn1_ctx_t *actx, proto_tree *tree){
proto_item *item;
if(ansi_tcap_private.d.pdu == 1){
save_invoke_data(actx->pinfo, tree, tvb);
}else{
if(find_saved_invokedata(actx->pinfo, tree, tvb)){
if(ansi_tcap_private.d.OperationCode == 0){
item = proto_tree_add_int(tree, hf_ansi_tcap_national, tvb, 0, 0, ansi_tcap_private.d.OperationCode_national);
}else{
item = proto_tree_add_int(tree, hf_ansi_tcap_private, tvb, 0, 0, ansi_tcap_private.d.OperationCode_private);
}
PROTO_ITEM_SET_GENERATED(item);
ansi_tcap_private.d.OperationCode_item = item;
}
}
if(ansi_tcap_private.d.OperationCode == 0){
guint8 family = (ansi_tcap_private.d.OperationCode_national & 0x7f00)>>8;
guint8 specifier = (guint8)(ansi_tcap_private.d.OperationCode_national & 0xff);
if(!dissector_try_uint(ansi_tcap_national_opcode_table, ansi_tcap_private.d.OperationCode_national, tvb, actx->pinfo, tcap_top_tree)){
proto_tree_add_expert_format(tree, actx->pinfo, &ei_ansi_tcap_dissector_not_implemented, tvb, 0, -1,
"Dissector for ANSI TCAP NATIONAL code:0x%x(Family %u, Specifier %u) \n"
"not implemented. Contact Wireshark developers if you want this supported(Spec required)",
ansi_tcap_private.d.OperationCode_national, family, specifier);
return FALSE;
}
return TRUE;
}else if(ansi_tcap_private.d.OperationCode == 1){
if((ansi_tcap_private.d.OperationCode_private & 0x0900) != 0x0900){
proto_tree_add_expert_format(tree, actx->pinfo, &ei_ansi_tcap_dissector_not_implemented, tvb, 0, -1,
"Dissector for ANSI TCAP PRIVATE code:%u not implemented.\n"
"Contact Wireshark developers if you want this supported(Spec required)",
ansi_tcap_private.d.OperationCode_private);
return FALSE;
}
}
call_dissector_with_data(ansi_map_handle, tvb, actx->pinfo, tcap_top_tree, &ansi_tcap_private);
return TRUE;
}
static int
dissect_ansi_tcap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
#if 0
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
gint offset = 0;
struct tcaphash_context_t * p_tcap_context;
dissector_handle_t subdissector_handle;
#endif
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
ansi_tcap_ctx_init(&ansi_tcap_private);
tcap_top_tree = parent_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ANSI TCAP");
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_ansi_tcap, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_tcap);
tcap_stat_item=item;
tcap_stat_tree=tree;
}
cur_oid = NULL;
tcapext_oid = NULL;
gp_tcapsrt_info=tcapsrt_razinfo();
tcap_subdissector_used=FALSE;
gp_tcap_context=NULL;
dissect_ansi_tcap_PackageType(FALSE, tvb, 0, &asn1_ctx, tree, -1);
#if 0
if (g_ansi_tcap_HandleSRT && !tcap_subdissector_used ) {
if (gtcap_DisplaySRT && tree) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, 0, ett_ansi_tcap_stat, &stat_item, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
}
p_tcap_context=tcapsrt_call_matching(tvb, pinfo, stat_tree, gp_tcapsrt_info);
ansi_tcap_private.context=p_tcap_context;
if ( p_tcap_context && cur_oid && !p_tcap_context->oid_present ) {
g_strlcpy(p_tcap_context->oid, cur_oid, sizeof(p_tcap_context->oid));
if ( (subdissector_handle = dissector_get_string_handle(ber_oid_dissector_table, cur_oid)) ) {
p_tcap_context->subdissector_handle=subdissector_handle;
p_tcap_context->oid_present=TRUE;
}
}
if (g_ansi_tcap_HandleSRT && p_tcap_context && p_tcap_context->callback) {
(p_tcap_context->callback)(tvb, pinfo, stat_tree, p_tcap_context);
}
}
#endif
return tvb_captured_length(tvb);
}
void
proto_reg_handoff_ansi_tcap(void)
{
ansi_map_handle = find_dissector_add_dependency("ansi_map", proto_ansi_tcap);
ber_oid_dissector_table = find_dissector_table("ber.oid");
}
void
proto_register_ansi_tcap(void)
{
module_t *ansi_tcap_module;
static hf_register_info hf[] = {
{ &hf_ansi_tcapsrt_SessionId,
{ "Session Id",
"ansi_tcap.srt.session_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ansi_tcapsrt_BeginSession,
{ "Begin Session",
"ansi_tcap.srt.begin",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT Begin of Session", HFILL }
},
{ &hf_ansi_tcapsrt_EndSession,
{ "End Session",
"ansi_tcap.srt.end",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT End of Session", HFILL }
},
{ &hf_ansi_tcapsrt_SessionTime,
{ "Session duration",
"ansi_tcap.srt.sessiontime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Duration of the TCAP session", HFILL }
},
{ &hf_ansi_tcapsrt_Duplicate,
{ "Request Duplicate",
"ansi_tcap.srt.duplicate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ansi_tcap_bit_h,
{ "Require Reply", "ansi_tcap.req_rep",
FT_BOOLEAN, 16, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_ansi_tcap_op_family,
{ "Family",
"ansi_tcap.op_family",
FT_UINT16, BASE_DEC, VALS(ansi_tcap_national_op_code_family_vals), 0x7f00,
NULL, HFILL }
},
{ &hf_ansi_tcap_op_specifier,
{ "Specifier",
"ansi_tcap.op_specifier",
FT_UINT16, BASE_DEC, NULL, 0x00ff,
NULL, HFILL }
},
#include "packet-ansi_tcap-hfarr.c"
};
static gint *ett[] = {
&ett_tcap,
&ett_param,
&ett_otid,
&ett_dtid,
&ett_ansi_tcap_stat,
&ett_ansi_tcap_op_code_nat,
#include "packet-ansi_tcap-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_ansi_tcap_dissector_not_implemented, { "ansi_tcap.dissector_not_implemented", PI_UNDECODED, PI_WARN, "Dissector not implemented", EXPFILL }},
};
expert_module_t* expert_ansi_tcap;
static const enum_val_t ansi_tcap_response_matching_type_values[] = {
{"Only Transaction ID will be used in Invoke/response matching", "Transaction ID only", ANSI_TCAP_TID_ONLY},
{"Transaction ID and Source will be used in Invoke/response matching", "Transaction ID and Source", ANSI_TCAP_TID_AND_SOURCE},
{"Transaction ID Source and Destination will be used in Invoke/response matching", "Transaction ID Source and Destination", ANSI_TCAP_TID_SOURCE_AND_DEST},
{NULL, NULL, -1}
};
proto_ansi_tcap = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("ansi_tcap", dissect_ansi_tcap, proto_ansi_tcap);
ansi_tcap_national_opcode_table = register_dissector_table("ansi_tcap.nat.opcode", "ANSI TCAP National Opcodes", proto_ansi_tcap, FT_UINT16, BASE_DEC);
proto_register_field_array(proto_ansi_tcap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ansi_tcap = expert_register_protocol(proto_ansi_tcap);
expert_register_field_array(expert_ansi_tcap, ei, array_length(ei));
ansi_tcap_module = prefs_register_protocol(proto_ansi_tcap, proto_reg_handoff_ansi_tcap);
prefs_register_enum_preference(ansi_tcap_module, "transaction.matchtype",
"Type of matching invoke/response",
"Type of matching invoke/response, risk of mismatch if loose matching chosen",
&ansi_tcap_response_matching_type, ansi_tcap_response_matching_type_values, FALSE);
TransactionId_table = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), wmem_str_hash, g_str_equal);
}
