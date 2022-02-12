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
static new_dissector_t ros_lookup_opr_dissector(gint32 opcode_lcl, const ros_opr_t *operations, gboolean argument)
{
if(operations) {
for(;operations->arg_pdu != (new_dissector_t)(-1); operations++)
if(operations->opcode == opcode_lcl)
return argument ? operations->arg_pdu : operations->res_pdu;
}
return NULL;
}
static new_dissector_t ros_lookup_err_dissector(gint32 errcode, const ros_err_t *errors)
{
if(errors) {
for(;errors->err_pdu != (new_dissector_t) (-1); errors++) {
if(errors->errcode == errcode)
return errors->err_pdu;
}
}
return NULL;
}
static gboolean ros_try_string(const char *oid, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
ros_info_t *rinfo;
gint32 opcode_lcl = 0;
const gchar *opname = NULL;
const gchar *suffix = NULL;
new_dissector_t opdissector = NULL;
const value_string *lookup;
proto_item *item=NULL;
proto_tree *ros_tree=NULL;
struct SESSION_DATA_STRUCTURE* session = NULL;
session = ( (struct SESSION_DATA_STRUCTURE*)(pinfo->private_data) );
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
if (check_col(pinfo->cinfo, COL_INFO)) {
col_set_str(pinfo->cinfo, COL_INFO, opname);
if(suffix)
col_append_str(pinfo->cinfo, COL_INFO, suffix);
}
(*opdissector)(tvb, pinfo, ros_tree);
return TRUE;
}
}
return FALSE;
}
int
call_ros_oid_callback(const char *oid, tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset(tvb, offset, tvb_length_remaining(tvb, offset), tvb_reported_length_remaining(tvb, offset));
if(!ros_try_string(oid, next_tvb, pinfo, tree) &&
!dissector_try_string(ros_oid_dissector_table, oid, next_tvb, pinfo, tree)){
proto_item *item=proto_tree_add_text(tree, next_tvb, 0, tvb_length_remaining(tvb, offset), "ROS: Dissector for OID:%s not implemented. Contact Wireshark developers if you want this supported", oid);
proto_tree *next_tree=proto_item_add_subtree(item, ett_ros_unknown);
expert_add_info_format (pinfo, item, PI_UNDECODED, PI_WARN,
"ROS: Dissector for OID %s not implemented", oid);
dissect_unknown_ber(pinfo, next_tvb, offset, next_tree);
}
offset+=tvb_length_remaining(tvb, offset);
return offset;
}
static guint
ros_info_hash_matched(gconstpointer k)
{
const ros_call_response_t *key = k;
return key->invokeId;
}
static gint
ros_info_equal_matched(gconstpointer k1, gconstpointer k2)
{
const ros_call_response_t *key1 = k1;
const ros_call_response_t *key2 = k2;
if( key1->req_frame && key2->req_frame && (key1->req_frame!=key2->req_frame) ){
return 0;
}
return key1->invokeId==key2->invokeId;
}
static guint
ros_info_hash_unmatched(gconstpointer k)
{
const ros_call_response_t *key = k;
return key->invokeId;
}
static gint
ros_info_equal_unmatched(gconstpointer k1, gconstpointer k2)
{
const ros_call_response_t *key1 = k1;
const ros_call_response_t *key2 = k2;
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
rcr.req_frame=pinfo->fd->num;
rcr.rep_frame=0;
} else {
rcr.req_frame=0;
rcr.rep_frame=pinfo->fd->num;
}
rcrp=g_hash_table_lookup(ros_info->matched, &rcr);
if(rcrp) {
rcrp->is_request=rcr.is_request;
} else {
if(isInvoke) {
rcr.invokeId=invokeId;
rcrp=g_hash_table_lookup(ros_info->unmatched, &rcr);
if(rcrp){
g_hash_table_remove(ros_info->unmatched, rcrp);
}
if(!rcrp){
rcrp=se_alloc(sizeof(ros_call_response_t));
}
rcrp->invokeId=invokeId;
rcrp->req_frame=pinfo->fd->num;
rcrp->req_time=pinfo->fd->abs_ts;
rcrp->rep_frame=0;
rcrp->is_request=TRUE;
g_hash_table_insert(ros_info->unmatched, rcrp, rcrp);
return NULL;
} else {
rcr.invokeId=invokeId;
rcrp=g_hash_table_lookup(ros_info->unmatched, &rcr);
if(rcrp){
if(!rcrp->rep_frame){
g_hash_table_remove(ros_info->unmatched, rcrp);
rcrp->rep_frame=pinfo->fd->num;
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
nstime_delta(&ns, &pinfo->fd->abs_ts, &rcrp->req_time);
item=proto_tree_add_time(tree, hf_ros_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED (item);
}
}
return rcrp;
}
static int
dissect_ros_T_present(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&invokeid);
return offset;
}
static int
dissect_ros_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
int
dissect_ros_InvokeId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
InvokeId_choice, hf_index, ett_ros_InvokeId,
NULL);
return offset;
}
static int
dissect_ros_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ros_OperationCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&opcode);
return offset;
}
static int
dissect_ros_T_argument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 30 "../../asn1/ros/ros.cnf"
char *oid;
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE *)actx->pinfo->private_data;
proto_tree_add_text(tree, tvb, offset,-1, "invoke argument");
ros_match_call_response(tvb, actx->pinfo, tree, invokeid, TRUE);
if(session && session->pres_ctx_id && (oid = find_oid_by_pres_ctx_id(actx->pinfo, session->pres_ctx_id))) {
session->ros_op = (ROS_OP_INVOKE | ROS_OP_ARGUMENT);
session->ros_op |= opcode;
offset = call_ros_oid_callback(oid, tvb, offset, actx->pinfo, top_tree);
}
return offset;
}
static int
dissect_ros_Invoke(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Invoke_sequence, hf_index, ett_ros_Invoke);
return offset;
}
static int
dissect_ros_OperationResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 47 "../../asn1/ros/ros.cnf"
char *oid;
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE *)actx->pinfo->private_data;
proto_tree_add_text(tree, tvb, offset,-1, "return result");
ros_match_call_response(tvb, actx->pinfo, tree, invokeid, FALSE);
if(session && session->pres_ctx_id && (oid = find_oid_by_pres_ctx_id(actx->pinfo, session->pres_ctx_id))) {
session->ros_op = (ROS_OP_INVOKE | ROS_OP_RESULT);
session->ros_op |= opcode;
offset = call_ros_oid_callback(oid, tvb, offset, actx->pinfo, top_tree);
}
return offset;
}
static int
dissect_ros_T_result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_result_sequence, hf_index, ett_ros_T_result);
return offset;
}
static int
dissect_ros_ReturnResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReturnResult_sequence, hf_index, ett_ros_ReturnResult);
return offset;
}
static int
dissect_ros_ErrorCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&opcode);
return offset;
}
static int
dissect_ros_T_parameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 64 "../../asn1/ros/ros.cnf"
char *oid;
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE *)actx->pinfo->private_data;
proto_tree_add_text(tree, tvb, offset,-1, "return result");
ros_match_call_response(tvb, actx->pinfo, tree, invokeid, FALSE);
if(session && session->pres_ctx_id && (oid = find_oid_by_pres_ctx_id(actx->pinfo, session->pres_ctx_id))) {
session->ros_op = (ROS_OP_INVOKE | ROS_OP_ERROR);
session->ros_op |= opcode;
offset = call_ros_oid_callback(oid, tvb, offset, actx->pinfo, top_tree);
}
return offset;
}
static int
dissect_ros_ReturnError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReturnError_sequence, hf_index, ett_ros_ReturnError);
return offset;
}
static int
dissect_ros_GeneralProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 169 "../../asn1/ros/ros.cnf"
guint32 problem;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&problem);
if (check_col(actx->pinfo->cinfo, COL_INFO)) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(problem, ros_GeneralProblem_vals, "GeneralProblem(%d)"));
}
return offset;
}
static int
dissect_ros_InvokeProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 181 "../../asn1/ros/ros.cnf"
guint32 problem;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&problem);
if (check_col(actx->pinfo->cinfo, COL_INFO)) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(problem, ros_InvokeProblem_vals, "InvokeProblem(%d)"));
}
return offset;
}
static int
dissect_ros_ReturnResultProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 193 "../../asn1/ros/ros.cnf"
guint32 problem;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&problem);
if (check_col(actx->pinfo->cinfo, COL_INFO)) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(problem, ros_ReturnResultProblem_vals, "ReturnResultProblem(%d)"));
}
return offset;
}
static int
dissect_ros_ReturnErrorProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 205 "../../asn1/ros/ros.cnf"
guint32 problem;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&problem);
if (check_col(actx->pinfo->cinfo, COL_INFO)) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(problem, ros_ReturnErrorProblem_vals, "ReturnErrorProblem(%d)"));
}
return offset;
}
static int
dissect_ros_T_problem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_problem_choice, hf_index, ett_ros_T_problem,
NULL);
return offset;
}
static int
dissect_ros_Reject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Reject_sequence, hf_index, ett_ros_Reject);
return offset;
}
static int
dissect_ros_T_reject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 161 "../../asn1/ros/ros.cnf"
if(check_col(actx->pinfo->cinfo, COL_INFO))
col_set_str(actx->pinfo->cinfo, COL_INFO, "Reject");
offset = dissect_ros_Reject(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ros_T_bind_invoke(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 81 "../../asn1/ros/ros.cnf"
char *oid;
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE *)actx->pinfo->private_data;
proto_tree_add_text(tree, tvb, offset,-1, "bind-invoke");
if(session && session->pres_ctx_id && (oid = find_oid_by_pres_ctx_id(actx->pinfo, session->pres_ctx_id))) {
session->ros_op = (ROS_OP_BIND | ROS_OP_ARGUMENT);
offset = call_ros_oid_callback(oid, tvb, offset, actx->pinfo, top_tree);
}
return offset;
}
static int
dissect_ros_T_bind_result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 94 "../../asn1/ros/ros.cnf"
char *oid;
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE *)actx->pinfo->private_data;
proto_tree_add_text(tree, tvb, offset,-1, "bind-result");
if(session && session->pres_ctx_id && (oid = find_oid_by_pres_ctx_id(actx->pinfo, session->pres_ctx_id))) {
session->ros_op = (ROS_OP_BIND | ROS_OP_RESULT);
offset = call_ros_oid_callback(oid, tvb, offset, actx->pinfo, top_tree);
}
return offset;
}
static int
dissect_ros_T_bind_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 107 "../../asn1/ros/ros.cnf"
char *oid;
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE *)actx->pinfo->private_data;
proto_tree_add_text(tree, tvb, offset,-1, "bind-error");
if(session && session->pres_ctx_id && (oid = find_oid_by_pres_ctx_id(actx->pinfo, session->pres_ctx_id))) {
session->ros_op = (ROS_OP_BIND | ROS_OP_ERROR);
offset = call_ros_oid_callback(oid, tvb, offset, actx->pinfo, top_tree);
}
return offset;
}
static int
dissect_ros_T_unbind_invoke(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 121 "../../asn1/ros/ros.cnf"
char *oid;
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE *)actx->pinfo->private_data;
proto_tree_add_text(tree, tvb, offset,-1, "unbind-invoke");
if(session && session->pres_ctx_id && (oid = find_oid_by_pres_ctx_id(actx->pinfo, session->pres_ctx_id))) {
session->ros_op = (ROS_OP_UNBIND | ROS_OP_ARGUMENT);
offset = call_ros_oid_callback(oid, tvb, offset, actx->pinfo, top_tree);
}
return offset;
}
static int
dissect_ros_T_unbind_result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 135 "../../asn1/ros/ros.cnf"
char *oid;
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE *)actx->pinfo->private_data;
proto_tree_add_text(tree, tvb, offset,-1, "unbind-result");
if(session && session->pres_ctx_id && (oid = find_oid_by_pres_ctx_id(actx->pinfo, session->pres_ctx_id))) {
session->ros_op = (ROS_OP_UNBIND | ROS_OP_RESULT);
offset = call_ros_oid_callback(oid, tvb, offset, actx->pinfo, top_tree);
}
return offset;
}
static int
dissect_ros_T_unbind_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 148 "../../asn1/ros/ros.cnf"
char *oid;
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE *)actx->pinfo->private_data;
proto_tree_add_text(tree, tvb, offset,-1, "unbind-error");
if(session && session->pres_ctx_id && (oid = find_oid_by_pres_ctx_id(actx->pinfo, session->pres_ctx_id))) {
session->ros_op = (ROS_OP_UNBIND | ROS_OP_ERROR);
offset = call_ros_oid_callback(oid, tvb, offset, actx->pinfo, top_tree);
}
return offset;
}
int
dissect_ros_ROS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ROS_choice, hf_index, ett_ros_ROS,
NULL);
return offset;
}
static int
dissect_ros_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
int
dissect_ros_Code(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Code_choice, hf_index, ett_ros_Code,
NULL);
return offset;
}
static void
dissect_ros(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
int old_offset;
proto_item *item=NULL;
proto_tree *tree=NULL;
proto_tree *next_tree=NULL;
conversation_t *conversation;
ros_conv_info_t *ros_info = NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
top_tree=parent_tree;
if( !pinfo->private_data ){
if(parent_tree){
proto_tree_add_text(parent_tree, tvb, offset, -1,
"Internal error:can't get application context from ACSE dissector.");
}
return ;
}
conversation = find_or_create_conversation(pinfo);
ros_info = conversation_get_proto_data(conversation, proto_ros);
if (ros_info == NULL) {
ros_info = g_malloc(sizeof(ros_conv_info_t));
ros_info->matched=g_hash_table_new(ros_info_hash_matched, ros_info_equal_matched);
ros_info->unmatched=g_hash_table_new(ros_info_hash_unmatched, ros_info_equal_unmatched);
conversation_add_proto_data(conversation, proto_ros, ros_info);
ros_info->next = ros_info_items;
ros_info_items = ros_info;
}
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_ros, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_ros);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ROS");
col_clear(pinfo->cinfo, COL_INFO);
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset=offset;
offset=dissect_ros_ROS(FALSE, tvb, offset, &asn1_ctx , tree, -1);
if(offset == old_offset){
item = proto_tree_add_text(tree, tvb, offset, -1,"Unknown ROS PDU");
if(item){
expert_add_info_format (pinfo, item, PI_UNDECODED, PI_WARN, "Unknown ROS PDU");
next_tree=proto_item_add_subtree(item, ett_ros_unknown);
dissect_unknown_ber(pinfo, tvb, offset, next_tree);
}
break;
}
}
}
static void
ros_reinit(void)
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
#line 1 "../../asn1/ros/packet-ros-hfarr.c"
{ &hf_ros_invoke,
{ "invoke", "ros.invoke",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_returnResult,
{ "returnResult", "ros.returnResult",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_returnError,
{ "returnError", "ros.returnError",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_reject,
{ "reject", "ros.reject",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_bind_invoke,
{ "bind-invoke", "ros.bind_invoke",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_bind_result,
{ "bind-result", "ros.bind_result",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_bind_error,
{ "bind-error", "ros.bind_error",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_unbind_invoke,
{ "unbind-invoke", "ros.unbind_invoke",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_unbind_result,
{ "unbind-result", "ros.unbind_result",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_unbind_error,
{ "unbind-error", "ros.unbind_error",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_invokeId,
{ "invokeId", "ros.invokeId",
FT_UINT32, BASE_DEC, VALS(ros_InvokeId_vals), 0,
NULL, HFILL }},
{ &hf_ros_linkedId,
{ "linkedId", "ros.linkedId",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ros_opcode,
{ "opcode", "ros.opcode",
FT_INT32, BASE_DEC, NULL, 0,
"OperationCode", HFILL }},
{ &hf_ros_argument,
{ "argument", "ros.argument",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_result,
{ "result", "ros.result",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_operationResult,
{ "result", "ros.result",
FT_NONE, BASE_NONE, NULL, 0,
"OperationResult", HFILL }},
{ &hf_ros_errcode,
{ "errcode", "ros.errcode",
FT_INT32, BASE_DEC, NULL, 0,
"ErrorCode", HFILL }},
{ &hf_ros_parameter,
{ "parameter", "ros.parameter",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_problem,
{ "problem", "ros.problem",
FT_UINT32, BASE_DEC, VALS(ros_T_problem_vals), 0,
NULL, HFILL }},
{ &hf_ros_general,
{ "general", "ros.general",
FT_INT32, BASE_DEC, VALS(ros_GeneralProblem_vals), 0,
"GeneralProblem", HFILL }},
{ &hf_ros_invokeProblem,
{ "invoke", "ros.invoke",
FT_INT32, BASE_DEC, VALS(ros_InvokeProblem_vals), 0,
"InvokeProblem", HFILL }},
{ &hf_ros_rejectResult,
{ "returnResult", "ros.returnResult",
FT_INT32, BASE_DEC, VALS(ros_ReturnResultProblem_vals), 0,
"ReturnResultProblem", HFILL }},
{ &hf_ros_rejectError,
{ "returnError", "ros.returnError",
FT_INT32, BASE_DEC, VALS(ros_ReturnErrorProblem_vals), 0,
"ReturnErrorProblem", HFILL }},
{ &hf_ros_present,
{ "present", "ros.present",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ros_absent,
{ "absent", "ros.absent",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ros_local,
{ "local", "ros.local",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ros_global,
{ "global", "ros.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
#line 490 "../../asn1/ros/packet-ros-template.c"
};
static gint *ett[] = {
&ett_ros,
&ett_ros_unknown,
#line 1 "../../asn1/ros/packet-ros-ettarr.c"
&ett_ros_ROS,
&ett_ros_Invoke,
&ett_ros_ReturnResult,
&ett_ros_T_result,
&ett_ros_ReturnError,
&ett_ros_Reject,
&ett_ros_T_problem,
&ett_ros_InvokeId,
&ett_ros_Code,
#line 497 "../../asn1/ros/packet-ros-template.c"
};
proto_ros = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("ros", dissect_ros, proto_ros);
proto_register_field_array(proto_ros, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ros_oid_dissector_table = register_dissector_table("ros.oid", "ROS OID Dissectors", FT_STRING, BASE_NONE);
oid_table=g_hash_table_new(g_str_hash, g_str_equal);
protocol_table=g_hash_table_new(g_str_hash, g_str_equal);
ros_handle = find_dissector("ros");
register_init_routine(ros_reinit);
}
void proto_reg_handoff_ros(void) {
}
