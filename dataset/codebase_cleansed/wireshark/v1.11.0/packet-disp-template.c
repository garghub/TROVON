static void
dissect_disp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
int old_offset;
proto_item *item=NULL;
proto_tree *tree=NULL;
int (*disp_dissector)(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) = NULL;
const char *disp_op_name;
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
item = proto_tree_add_item(parent_tree, proto_disp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_disp);
}
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
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported DISP opcode (%d)",
session->ros_op & ROS_OP_OPCODE_MASK);
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
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported DISP opcode (%d)",
session->ros_op & ROS_OP_OPCODE_MASK);
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
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported DISP errcode (%d)",
session->ros_op & ROS_OP_OPCODE_MASK);
break;
}
break;
default:
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported DISP PDU");
return;
}
if(disp_dissector) {
col_set_str(pinfo->cinfo, COL_INFO, disp_op_name);
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset=offset;
offset=(*disp_dissector)(FALSE, tvb, offset, &asn1_ctx, tree, -1);
if(offset == old_offset){
proto_tree_add_text(tree, tvb, offset, -1,"Internal error, zero-byte DISP PDU");
break;
}
}
}
}
void proto_register_disp(void) {
static hf_register_info hf[] =
{
#include "packet-disp-hfarr.c"
};
static gint *ett[] = {
&ett_disp,
#include "packet-disp-ettarr.c"
};
module_t *disp_module;
proto_disp = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("disp", dissect_disp, proto_disp);
proto_register_field_array(proto_disp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
disp_module = prefs_register_protocol_subtree("OSI/X.500", proto_disp, prefs_register_disp);
prefs_register_uint_preference(disp_module, "tcp.port", "DISP TCP Port",
"Set the port for DISP operations (if other"
" than the default of 102)",
10, &global_disp_tcp_port);
}
void proto_reg_handoff_disp(void) {
dissector_handle_t disp_handle;
#include "packet-disp-dis-tab.c"
oid_add_from_string("id-ac-shadow-consumer-initiated","2.5.3.4");
oid_add_from_string("id-ac-shadow-supplier-initiated","2.5.3.5");
oid_add_from_string("id-ac-reliable-shadow-consumer-initiated","2.5.3.6");
oid_add_from_string("id-ac-reliable-shadow-supplier-initiated","2.5.3.7");
disp_handle = find_dissector("disp");
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
