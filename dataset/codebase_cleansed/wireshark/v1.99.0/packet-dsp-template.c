static int
dissect_dsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
int offset = 0;
int old_offset;
proto_item *item;
proto_tree *tree;
struct SESSION_DATA_STRUCTURE* session;
int (*dsp_dissector)(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) = NULL;
const char *dsp_op_name;
asn1_ctx_t asn1_ctx;
if (data == NULL)
return 0;
session = (struct SESSION_DATA_STRUCTURE*)data;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
item = proto_tree_add_item(parent_tree, proto_dsp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dsp);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DAP");
col_clear(pinfo->cinfo, COL_INFO);
asn1_ctx.private_data = session;
switch(session->ros_op & ROS_OP_MASK) {
case (ROS_OP_BIND | ROS_OP_ARGUMENT):
dsp_dissector = dissect_dsp_DSASystemBindArgument;
dsp_op_name = "System-Bind-Argument";
break;
case (ROS_OP_BIND | ROS_OP_RESULT):
dsp_dissector = dissect_dsp_DSASystemBindResult;
dsp_op_name = "System-Bind-Result";
break;
case (ROS_OP_BIND | ROS_OP_ERROR):
dsp_dissector = dissect_dsp_DSASystemBindError;
dsp_op_name = "System-Bind-Error";
break;
case (ROS_OP_INVOKE | ROS_OP_ARGUMENT):
switch(session->ros_op & ROS_OP_OPCODE_MASK) {
case 1:
dsp_dissector = dissect_dsp_ChainedReadArgument;
dsp_op_name = "Chained-Read-Argument";
break;
case 2:
dsp_dissector = dissect_dsp_ChainedCompareArgument;
dsp_op_name = "Chained-Compare-Argument";
break;
case 3:
dsp_dissector = dissect_dsp_ChainedAbandonArgument;
dsp_op_name = "Chained-Abandon-Argument";
break;
case 4:
dsp_dissector = dissect_dsp_ChainedListArgument;
dsp_op_name = "Chained-List-Argument";
break;
case 5:
dsp_dissector = dissect_dsp_ChainedSearchArgument;
dsp_op_name = "Chained-Search-Argument";
break;
case 6:
dsp_dissector = dissect_dsp_ChainedAddEntryArgument;
dsp_op_name = "Chained-Add-Entry-Argument";
break;
case 7:
dsp_dissector = dissect_dsp_ChainedRemoveEntryArgument;
dsp_op_name = "Chained-Remove-Entry-Argument";
break;
case 8:
dsp_dissector = dissect_dsp_ChainedModifyEntryArgument;
dsp_op_name = "ChainedModify-Entry-Argument";
break;
case 9:
dsp_dissector = dissect_dsp_ChainedModifyDNArgument;
dsp_op_name = "ChainedModify-DN-Argument";
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_dsp_unsupported_opcode, tvb, offset, -1,
"Unsupported DSP opcode (%d)", session->ros_op & ROS_OP_OPCODE_MASK);
break;
}
break;
case (ROS_OP_INVOKE | ROS_OP_RESULT):
switch(session->ros_op & ROS_OP_OPCODE_MASK) {
case 1:
dsp_dissector = dissect_dsp_ChainedReadResult;
dsp_op_name = "Chained-Read-Result";
break;
case 2:
dsp_dissector = dissect_dsp_ChainedCompareResult;
dsp_op_name = "Chained-Compare-Result";
break;
case 3:
dsp_dissector = dissect_dsp_ChainedAbandonResult;
dsp_op_name = "Chained-Abandon-Result";
break;
case 4:
dsp_dissector = dissect_dsp_ChainedListResult;
dsp_op_name = "Chained-List-Result";
break;
case 5:
dsp_dissector = dissect_dsp_ChainedSearchResult;
dsp_op_name = "Chained-Search-Result";
break;
case 6:
dsp_dissector = dissect_dsp_ChainedAddEntryResult;
dsp_op_name = "Chained-Add-Entry-Result";
break;
case 7:
dsp_dissector = dissect_dsp_ChainedRemoveEntryResult;
dsp_op_name = "Chained-Remove-Entry-Result";
break;
case 8:
dsp_dissector = dissect_dsp_ChainedModifyEntryResult;
dsp_op_name = "Chained-Modify-Entry-Result";
break;
case 9:
dsp_dissector = dissect_dsp_ChainedModifyDNResult;
dsp_op_name = "ChainedModify-DN-Result";
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_dsp_unsupported_opcode, tvb, offset, -1);
break;
}
break;
case (ROS_OP_INVOKE | ROS_OP_ERROR):
switch(session->ros_op & ROS_OP_OPCODE_MASK) {
case 1:
dsp_dissector = dissect_dap_AttributeError;
dsp_op_name = "Attribute-Error";
break;
case 2:
dsp_dissector = dissect_dap_NameError;
dsp_op_name = "Name-Error";
break;
case 3:
dsp_dissector = dissect_dap_ServiceError;
dsp_op_name = "Service-Error";
break;
case 4:
dsp_dissector = dissect_dap_Referral;
dsp_op_name = "Referral";
break;
case 5:
dsp_dissector = dissect_dap_Abandoned;
dsp_op_name = "Abandoned";
break;
case 6:
dsp_dissector = dissect_dap_SecurityError;
dsp_op_name = "Security-Error";
break;
case 7:
dsp_dissector = dissect_dap_AbandonFailedError;
dsp_op_name = "Abandon-Failed-Error";
break;
case 8:
dsp_dissector = dissect_dap_UpdateError;
dsp_op_name = "Update-Error";
break;
case 9:
dsp_dissector = dissect_dsp_DSAReferral;
dsp_op_name = "DSA-Referral";
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_dsp_unsupported_errcode, tvb, offset, -1);
break;
}
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_dsp_unsupported_pdu, tvb, offset, -1);
return tvb_captured_length(tvb);
}
if(dsp_dissector) {
col_set_str(pinfo->cinfo, COL_INFO, dsp_op_name);
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset=offset;
offset=(*dsp_dissector)(FALSE, tvb, offset, &asn1_ctx, tree, -1);
if(offset == old_offset){
proto_tree_add_expert(tree, pinfo, &ei_dsp_zero_pdu, tvb, offset, -1);
break;
}
}
}
return tvb_captured_length(tvb);
}
void proto_register_dsp(void) {
static hf_register_info hf[] =
{
#include "packet-dsp-hfarr.c"
};
static gint *ett[] = {
&ett_dsp,
#include "packet-dsp-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_dsp_unsupported_opcode, { "dsp.unsupported_opcode", PI_UNDECODED, PI_WARN, "Unsupported DSP opcode", EXPFILL }},
{ &ei_dsp_unsupported_errcode, { "dsp.unsupported_errcode", PI_UNDECODED, PI_WARN, "Unsupported DSP errcode", EXPFILL }},
{ &ei_dsp_unsupported_pdu, { "dsp.unsupported_pdu", PI_UNDECODED, PI_WARN, "Unsupported DSP PDU", EXPFILL }},
{ &ei_dsp_zero_pdu, { "dsp.zero_pdu", PI_PROTOCOL, PI_ERROR, "Internal error, zero-byte DSP PDU", EXPFILL }},
};
module_t *dsp_module;
expert_module_t* expert_dsp;
proto_dsp = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("dsp", dissect_dsp, proto_dsp);
proto_register_field_array(proto_dsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dsp = expert_register_protocol(proto_dsp);
expert_register_field_array(expert_dsp, ei, array_length(ei));
dsp_module = prefs_register_protocol_subtree("OSI/X.500", proto_dsp, prefs_register_dsp);
prefs_register_uint_preference(dsp_module, "tcp.port", "DSP TCP Port",
"Set the port for DSP operations (if other"
" than the default of 102)",
10, &global_dsp_tcp_port);
}
void proto_reg_handoff_dsp(void) {
dissector_handle_t dsp_handle;
#include "packet-dsp-dis-tab.c"
oid_add_from_string("id-ac-directory-system","2.5.3.2");
tpkt_handle = find_dissector("tpkt");
dsp_handle = find_dissector("dsp");
register_ros_oid_dissector_handle("2.5.9.2", dsp_handle, 0, "id-as-directory-system", FALSE);
}
static void
prefs_register_dsp(void)
{
static guint tcp_port = 0;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_delete_uint("tcp.port", tcp_port, tpkt_handle);
tcp_port = global_dsp_tcp_port;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_add_uint("tcp.port", global_dsp_tcp_port, tpkt_handle);
}
