void
register_ros_oid_dissector_handle(const char *oid, dissector_handle_t dissector, int proto _U_, const char *name, gboolean uses_rtse)
{
dissector_add_string("ros.oid", oid, dissector);
g_hash_table_insert(oid_table, (gpointer)oid, (gpointer)name);
if(!uses_rtse)
register_ber_oid_dissector_handle(oid, ros_handle, proto, name);
}
void
register_ros_protocol_info(const char *oid, const ros_info_t *rinfo, int proto _U_, const char *name, gboolean uses_rtse)
{
g_hash_table_insert(protocol_table, (gpointer)oid, (gpointer)rinfo);
g_hash_table_insert(oid_table, (gpointer)oid, (gpointer)name);
if(!uses_rtse)
register_ber_oid_dissector_handle(oid, ros_handle, proto, name);
}
static dissector_t ros_lookup_opr_dissector(gint32 opcode_lcl, const ros_opr_t *operations, gboolean argument)
{
if(operations) {
for(;operations->arg_pdu != (dissector_t)(-1); operations++)
if(operations->opcode == opcode_lcl)
return argument ? operations->arg_pdu : operations->res_pdu;
}
return NULL;
}
static dissector_t ros_lookup_err_dissector(gint32 errcode, const ros_err_t *errors)
{
if(errors) {
for(;errors->err_pdu != (dissector_t) (-1); errors++) {
if(errors->errcode == errcode)
return errors->err_pdu;
}
}
return NULL;
}
static int
ros_try_string(const char *oid, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, struct SESSION_DATA_STRUCTURE* session)
{
ros_info_t *rinfo;
gint32 opcode_lcl = 0;
const gchar *opname = NULL;
const gchar *suffix = NULL;
dissector_t opdissector = NULL;
const value_string *lookup;
proto_item *item=NULL;
proto_tree *ros_tree=NULL;
if((session != NULL) && ((rinfo = (ros_info_t*)g_hash_table_lookup(protocol_table, oid)) != NULL)) {
if(tree){
item = proto_tree_add_item(tree, *(rinfo->proto), tvb, 0, -1, ENC_NA);
ros_tree = proto_item_add_subtree(item, *(rinfo->ett_proto));
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, rinfo->name);
if((session->ros_op & ROS_OP_TYPE_MASK) == ROS_OP_BIND) {
if((session->ros_op & ROS_OP_PDU_MASK) == ROS_OP_ERROR)
opcode_lcl = err_ros_bind;
else
opcode_lcl = op_ros_bind;
} else
opcode_lcl = session->ros_op & ROS_OP_OPCODE_MASK;
lookup = rinfo->opr_code_strings;
switch(session->ros_op & ROS_OP_PDU_MASK) {
case ROS_OP_ARGUMENT:
opdissector = ros_lookup_opr_dissector(opcode_lcl, rinfo->opr_code_dissectors, TRUE);
suffix = "_argument";
break;
case ROS_OP_RESULT:
opdissector = ros_lookup_opr_dissector(opcode_lcl, rinfo->opr_code_dissectors, FALSE);
suffix = "_result";
break;
case ROS_OP_ERROR:
opdissector = ros_lookup_err_dissector(opcode_lcl, rinfo->err_code_dissectors);
lookup = rinfo->err_code_strings;
break;
default:
break;
}
if(opdissector) {
opname = val_to_str(opcode_lcl, lookup, "Unknown opcode (%d)");
col_set_str(pinfo->cinfo, COL_INFO, opname);
if(suffix)
col_append_str(pinfo->cinfo, COL_INFO, suffix);
return (*opdissector)(tvb, pinfo, ros_tree, NULL);
}
}
return 0;
}
int
call_ros_oid_callback(const char *oid, tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, struct SESSION_DATA_STRUCTURE* session)
{
tvbuff_t *next_tvb;
int len;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if(((len = ros_try_string(oid, next_tvb, pinfo, tree, session)) == 0) &&
((len = dissector_try_string(ros_oid_dissector_table, oid, next_tvb, pinfo, tree, session)) == 0)) {
proto_item *item;
proto_tree *next_tree;
next_tree = proto_tree_add_subtree_format(tree, next_tvb, 0, -1, ett_ros_unknown, &item,
"ROS: Dissector for OID:%s not implemented. Contact Wireshark developers if you want this supported", oid);
expert_add_info_format(pinfo, item, &ei_ros_dissector_oid_not_implemented,
"ROS: Dissector for OID %s not implemented", oid);
len = dissect_unknown_ber(pinfo, next_tvb, offset, next_tree);
}
offset += len;
return offset;
}
static guint
ros_info_hash_matched(gconstpointer k)
{
const ros_call_response_t *key = (const ros_call_response_t *)k;
return key->invokeId;
}
static gint
ros_info_equal_matched(gconstpointer k1, gconstpointer k2)
{
const ros_call_response_t *key1 = (const ros_call_response_t *)k1;
const ros_call_response_t *key2 = (const ros_call_response_t *)k2;
if( key1->req_frame && key2->req_frame && (key1->req_frame!=key2->req_frame) ){
return 0;
}
return key1->invokeId==key2->invokeId;
}
static guint
ros_info_hash_unmatched(gconstpointer k)
{
const ros_call_response_t *key = (const ros_call_response_t *)k;
return key->invokeId;
}
static gint
ros_info_equal_unmatched(gconstpointer k1, gconstpointer k2)
{
const ros_call_response_t *key1 = (const ros_call_response_t *)k1;
const ros_call_response_t *key2 = (const ros_call_response_t *)k2;
return key1->invokeId==key2->invokeId;
}
static ros_call_response_t *
ros_match_call_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint invokeId, gboolean isInvoke)
{
ros_call_response_t rcr, *rcrp=NULL;
ros_conv_info_t *ros_info = ros_info_items;
rcr.invokeId=invokeId;
rcr.is_request = isInvoke;
if(isInvoke) {
rcr.req_frame=pinfo->num;
rcr.rep_frame=0;
} else {
rcr.req_frame=0;
rcr.rep_frame=pinfo->num;
}
rcrp=(ros_call_response_t *)g_hash_table_lookup(ros_info->matched, &rcr);
if(rcrp) {
rcrp->is_request=rcr.is_request;
} else {
if(isInvoke) {
rcr.invokeId=invokeId;
rcrp=(ros_call_response_t *)g_hash_table_lookup(ros_info->unmatched, &rcr);
if(rcrp){
g_hash_table_remove(ros_info->unmatched, rcrp);
}
if(!rcrp){
rcrp=wmem_new(wmem_file_scope(), ros_call_response_t);
}
rcrp->invokeId=invokeId;
rcrp->req_frame=pinfo->num;
rcrp->req_time=pinfo->abs_ts;
rcrp->rep_frame=0;
rcrp->is_request=TRUE;
g_hash_table_insert(ros_info->unmatched, rcrp, rcrp);
return NULL;
} else {
rcr.invokeId=invokeId;
rcrp=(ros_call_response_t *)g_hash_table_lookup(ros_info->unmatched, &rcr);
if(rcrp){
if(!rcrp->rep_frame){
g_hash_table_remove(ros_info->unmatched, rcrp);
rcrp->rep_frame=pinfo->num;
rcrp->is_request=FALSE;
g_hash_table_insert(ros_info->matched, rcrp, rcrp);
}
}
}
}
if(rcrp){
proto_item *item = NULL;
if(rcrp->is_request){
item=proto_tree_add_uint(tree, hf_ros_response_in, tvb, 0, 0, rcrp->rep_frame);
PROTO_ITEM_SET_GENERATED (item);
} else {
nstime_t ns;
item=proto_tree_add_uint(tree, hf_ros_response_to, tvb, 0, 0, rcrp->req_frame);
PROTO_ITEM_SET_GENERATED (item);
nstime_delta(&ns, &pinfo->abs_ts, &rcrp->req_time);
item=proto_tree_add_time(tree, hf_ros_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED (item);
}
}
return rcrp;
}
static int
dissect_ros(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
int offset = 0;
int old_offset;
proto_item *item;
proto_tree *tree;
proto_tree *next_tree=NULL;
conversation_t *conversation;
ros_conv_info_t *ros_info = NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if (data == NULL)
return 0;
asn1_ctx.private_data = data;
top_tree=parent_tree;
conversation = find_or_create_conversation(pinfo);
ros_info = (ros_conv_info_t *)conversation_get_proto_data(conversation, proto_ros);
if (ros_info == NULL) {
ros_info = (ros_conv_info_t *)g_malloc(sizeof(ros_conv_info_t));
ros_info->matched=g_hash_table_new(ros_info_hash_matched, ros_info_equal_matched);
ros_info->unmatched=g_hash_table_new(ros_info_hash_unmatched, ros_info_equal_unmatched);
conversation_add_proto_data(conversation, proto_ros, ros_info);
ros_info->next = ros_info_items;
ros_info_items = ros_info;
}
item = proto_tree_add_item(parent_tree, proto_ros, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_ros);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ROS");
col_clear(pinfo->cinfo, COL_INFO);
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset=offset;
offset=dissect_ros_ROS(FALSE, tvb, offset, &asn1_ctx , tree, -1);
if(offset == old_offset){
next_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_ros_unknown, &item, "Unknown ROS PDU");
expert_add_info(pinfo, item, &ei_ros_unknown_ros_pdu);
dissect_unknown_ber(pinfo, tvb, offset, next_tree);
break;
}
}
return tvb_captured_length(tvb);
}
static void
ros_cleanup(void)
{
ros_conv_info_t *ros_info;
for (ros_info = ros_info_items; ros_info != NULL; ) {
ros_conv_info_t *last;
g_hash_table_destroy(ros_info->matched);
ros_info->matched=NULL;
g_hash_table_destroy(ros_info->unmatched);
ros_info->unmatched=NULL;
last = ros_info;
ros_info = ros_info->next;
g_free(last);
}
ros_info_items = NULL;
}
void proto_register_ros(void) {
static hf_register_info hf[] =
{
{ &hf_ros_response_in,
{ "Response In", "ros.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this remote operation invocation is in this frame", HFILL }},
{ &hf_ros_response_to,
{ "Response To", "ros.response_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the remote operation invocation in this frame", HFILL }},
{ &hf_ros_time,
{ "Time", "ros.time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the Invoke and the Response", HFILL }},
#include "packet-ros-hfarr.c"
};
static gint *ett[] = {
&ett_ros,
&ett_ros_unknown,
&ett_ros_invoke_argument,
&ett_ros_return_result,
&ett_ros_bind_invoke,
&ett_ros_bind_result,
&ett_ros_bind_error,
&ett_ros_unbind_invoke,
&ett_ros_unbind_result,
&ett_ros_unbind_error,
#include "packet-ros-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_ros_dissector_oid_not_implemented, { "ros.dissector_oid_not_implemented", PI_UNDECODED, PI_WARN, "ROS: Dissector for OID not implemented", EXPFILL }},
{ &ei_ros_unknown_ros_pdu, { "ros.unknown_ros_pdu", PI_UNDECODED, PI_WARN, "Unknown ROS PDU", EXPFILL }},
};
expert_module_t* expert_ros;
proto_ros = proto_register_protocol(PNAME, PSNAME, PFNAME);
ros_handle = register_dissector("ros", dissect_ros, proto_ros);
proto_register_field_array(proto_ros, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ros = expert_register_protocol(proto_ros);
expert_register_field_array(expert_ros, ei, array_length(ei));
ros_oid_dissector_table = register_dissector_table("ros.oid", "ROS OID Dissectors", proto_ros, FT_STRING, BASE_NONE);
oid_table=g_hash_table_new(g_str_hash, g_str_equal);
protocol_table=g_hash_table_new(g_str_hash, g_str_equal);
register_cleanup_routine(ros_cleanup);
}
void proto_reg_handoff_ros(void) {
}
