void p1_initialize_content_globals (proto_tree *tree, gboolean report_unknown_cont_type)
{
top_tree = tree;
content_type_id = NULL;
report_unknown_content_type = report_unknown_cont_type;
}
char* p1_get_last_oraddress (void)
{
return oraddress;
}
void
dissect_p1_mts_apdu (tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
p1_initialize_content_globals (parent_tree, TRUE);
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_p1, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_p1);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "P1");
col_set_str(pinfo->cinfo, COL_INFO, "Transfer");
dissect_p1_MTS_APDU (FALSE, tvb, 0, &asn1_ctx, tree, hf_p1_MTS_APDU_PDU);
p1_initialize_content_globals (NULL, FALSE);
}
static void
dissect_p1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
int old_offset;
proto_item *item=NULL;
proto_tree *tree=NULL;
int (*p1_dissector)(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) = NULL;
char *p1_op_name;
int hf_p1_index = -1;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
p1_initialize_content_globals (parent_tree, TRUE);
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
item = proto_tree_add_item(parent_tree, proto_p1, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_p1);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "P1");
col_clear(pinfo->cinfo, COL_INFO);
switch(session->ros_op & ROS_OP_MASK) {
case (ROS_OP_BIND | ROS_OP_ARGUMENT):
p1_dissector = dissect_p1_MTABindArgument;
p1_op_name = "Bind-Argument";
hf_p1_index = hf_p1_MTABindArgument_PDU;
break;
case (ROS_OP_BIND | ROS_OP_RESULT):
p1_dissector = dissect_p1_MTABindResult;
p1_op_name = "Bind-Result";
hf_p1_index = hf_p1_MTABindResult_PDU;
break;
case (ROS_OP_BIND | ROS_OP_ERROR):
p1_dissector = dissect_p1_MTABindError;
p1_op_name = "Bind-Error";
hf_p1_index = hf_p1_MTABindError_PDU;
break;
case (ROS_OP_INVOKE | ROS_OP_ARGUMENT):
p1_dissector = dissect_p1_MTS_APDU;
p1_op_name = "Transfer";
hf_p1_index = hf_p1_MTS_APDU_PDU;
break;
default:
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported P1 PDU");
return;
}
if (check_col(pinfo->cinfo, COL_INFO))
col_set_str(pinfo->cinfo, COL_INFO, p1_op_name);
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset=offset;
offset=(*p1_dissector)(FALSE, tvb, offset, &asn1_ctx , tree, hf_p1_index);
if(offset == old_offset){
proto_tree_add_text(tree, tvb, offset, -1,"Internal error, zero-byte P1 PDU");
break;
}
}
p1_initialize_content_globals (NULL, FALSE);
}
void proto_register_p1(void) {
static hf_register_info hf[] =
{
{ &hf_p1_MTABindArgument_PDU,
{ "MTABindArgument", "p1.MTABindArgument",
FT_UINT32, BASE_DEC, VALS(p1_MTABindArgument_vals), 0,
"p1.MTABindArgument", HFILL }},
{ &hf_p1_MTABindResult_PDU,
{ "MTABindResult", "p1.MTABindResult",
FT_UINT32, BASE_DEC, VALS(p1_MTABindResult_vals), 0,
"p1.MTABindResult", HFILL }},
{ &hf_p1_MTABindError_PDU,
{ "MTABindError", "p1.MTABindError",
FT_UINT32, BASE_DEC, VALS(p1_MTABindError_vals), 0,
"p1.MTABindError", HFILL }},
{ &hf_p1_MTS_APDU_PDU,
{ "MTS-APDU", "p1.MTS_APDU",
FT_UINT32, BASE_DEC, VALS(p1_MTS_APDU_vals), 0,
"p1.MTS_APDU", HFILL }},
#include "packet-p1-hfarr.c"
};
static gint *ett[] = {
&ett_p1,
&ett_p3,
&ett_p1_content_unknown,
&ett_p1_bilateral_information,
&ett_p1_additional_information,
&ett_p1_unknown_standard_extension,
&ett_p1_unknown_extension_attribute_type,
&ett_p1_unknown_tokendata_type,
#include "packet-p1-ettarr.c"
};
module_t *p1_module;
proto_p1 = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("p1", dissect_p1, proto_p1);
proto_p3 = proto_register_protocol("X.411 Message Access Service", "P3", "p3");
proto_register_field_array(proto_p1, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
p1_extension_dissector_table = register_dissector_table("p1.extension", "P1-EXTENSION", FT_UINT32, BASE_DEC);
p1_extension_attribute_dissector_table = register_dissector_table("p1.extension-attribute", "P1-EXTENSION-ATTRIBUTE", FT_UINT32, BASE_DEC);
p1_tokendata_dissector_table = register_dissector_table("p1.tokendata", "P1-TOKENDATA", FT_UINT32, BASE_DEC);
p1_module = prefs_register_protocol_subtree("OSI/X.400", proto_p1, prefs_register_p1);
prefs_register_uint_preference(p1_module, "tcp.port", "P1 TCP Port",
"Set the port for P1 operations (if other"
" than the default of 102)",
10, &global_p1_tcp_port);
register_ber_syntax_dissector("P1 Message", proto_p1, dissect_p1_mts_apdu);
}
void proto_reg_handoff_p1(void) {
dissector_handle_t p1_handle;
#include "packet-p1-dis-tab.c"
oid_add_from_string("id-ac-mts-transfer","2.6.0.1.6");
p1_handle = find_dissector("p1");
register_rtse_oid_dissector_handle("2.6.0.2.12", p1_handle, 0, "id-as-mta-rtse", TRUE);
register_rtse_oid_dissector_handle("2.6.0.2.7", p1_handle, 0, "id-as-mtse", FALSE);
register_rtse_oid_dissector_handle("applicationProtocol.1", p1_handle, 0, "mts-transfer-protocol-1984", FALSE);
register_rtse_oid_dissector_handle("applicationProtocol.12", p1_handle, 0, "mta-transfer-protocol", FALSE);
tpkt_handle = find_dissector("tpkt");
oid_add_from_string("id-ac-mts-access-88", id_ac_mts_access_88);
oid_add_from_string("id-ac-mts-forced-access-88", id_ac_mts_forced_access_88);
oid_add_from_string("id-ac-mts-access-94", id_ac_mts_access_94);
oid_add_from_string("id-ac-mts-forced-access-94", id_ac_mts_forced_access_94);
register_ros_protocol_info(id_as_msse, &p3_ros_info, 0, "id-as-msse", FALSE);
register_ros_protocol_info(id_as_mdse_88, &p3_ros_info, 0, "id-as-mdse-88", FALSE);
register_ros_protocol_info(id_as_mdse_94, &p3_ros_info, 0, "id-as-mdse-94", FALSE);
register_ros_protocol_info(id_as_mase_88, &p3_ros_info, 0, "id-as-mase-88", FALSE);
register_ros_protocol_info(id_as_mase_94, &p3_ros_info, 0, "id-as-mase-94", FALSE);
register_ros_protocol_info(id_as_mts, &p3_ros_info, 0, "id-as-mts", FALSE);
}
static void
prefs_register_p1(void)
{
static guint tcp_port = 0;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_delete_uint("tcp.port", tcp_port, tpkt_handle);
tcp_port = global_p1_tcp_port;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_add_uint("tcp.port", tcp_port, tpkt_handle);
}
