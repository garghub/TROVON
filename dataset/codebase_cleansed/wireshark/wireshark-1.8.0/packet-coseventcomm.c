static gboolean decode_user_exception(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *ptree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
proto_tree *tree _U_;
if (!header->exception_id)
return FALSE;
return FALSE;
}
static void decode_CosEventComm_PushConsumer_push(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
switch(header->message_type) {
case Request:
get_CDR_any(tvb,tree,offset,stream_is_big_endian, boundary, header);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
g_warning("Unknown Exception ");
break;
}
break;
default:
g_warning("Unknown GIOP Message");
break;
}
}
static void decode_CosEventComm_PushConsumer_disconnect_push_consumer(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
g_warning("Unknown Exception ");
break;
}
break;
default:
g_warning("Unknown GIOP Message");
break;
}
}
static void decode_CosEventComm_PushSupplier_disconnect_push_supplier(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
g_warning("Unknown Exception ");
break;
}
break;
default:
g_warning("Unknown GIOP Message");
break;
}
}
static void decode_CosEventComm_PullSupplier_pull(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
get_CDR_any(tvb,tree,offset,stream_is_big_endian, boundary, header);
break;
case USER_EXCEPTION:
break;
default:
g_warning("Unknown Exception ");
break;
}
break;
default:
g_warning("Unknown GIOP Message");
break;
}
}
static void decode_CosEventComm_PullSupplier_try_pull(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint8 u_octet1;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
get_CDR_any(tvb,tree,offset,stream_is_big_endian, boundary, header);
u_octet1 = get_CDR_boolean(tvb,offset);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-1,1,"has_event = %u",u_octet1);
}
break;
case USER_EXCEPTION:
break;
default:
g_warning("Unknown Exception ");
break;
}
break;
default:
g_warning("Unknown GIOP Message");
break;
}
}
static void decode_CosEventComm_PullSupplier_disconnect_pull_supplier(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
g_warning("Unknown Exception ");
break;
}
break;
default:
g_warning("Unknown GIOP Message");
break;
}
}
static void decode_CosEventComm_PullConsumer_disconnect_pull_consumer(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
g_warning("Unknown Exception ");
break;
}
break;
default:
g_warning("Unknown GIOP Message");
break;
}
}
static proto_tree *start_dissecting(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset) {
proto_item *ti = NULL;
proto_tree *tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "COSEVENTCOMM");
if (ptree) {
ti = proto_tree_add_item(ptree, proto_coseventcomm, tvb, *offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_coseventcomm);
}
return tree;
}
static gboolean dissect_coseventcomm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset, MessageHeader *header, gchar *operation, gchar *idlname) {
gboolean stream_is_big_endian;
proto_tree *tree _U_;
#define process_RequestOperation(){ \
proto_item *pi; \
if(header->message_type == Reply){ col_append_fstr(pinfo->cinfo, COL_INFO, " op = %s",operation); }; \
pi=proto_tree_add_string_format_value(ptree,hf_operationrequest,tvb,0,0,operation," %s",operation);PROTO_ITEM_SET_GENERATED(pi); \
};
stream_is_big_endian = is_big_endian(header);
if ((header->message_type == Reply) && (header->rep_status == USER_EXCEPTION)) {
return decode_user_exception(tvb, pinfo, ptree, offset, header, operation, stream_is_big_endian);
}
switch(header->message_type) {
case Request:
case Reply:
if (strcmp(operation, CosEventComm_PushConsumer_push_op) == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PushConsumer") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PushConsumer_push(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosEventComm_PushConsumer_disconnect_push_consumer_op) == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PushConsumer") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PushConsumer_disconnect_push_consumer(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosEventComm_PushSupplier_disconnect_push_supplier_op) == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PushSupplier") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PushSupplier_disconnect_push_supplier(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosEventComm_PullSupplier_pull_op) == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PullSupplier") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PullSupplier_pull(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosEventComm_PullSupplier_try_pull_op) == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PullSupplier") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PullSupplier_try_pull(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosEventComm_PullSupplier_disconnect_pull_supplier_op) == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PullSupplier") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PullSupplier_disconnect_pull_supplier(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosEventComm_PullConsumer_disconnect_pull_consumer_op) == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PullConsumer") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PullConsumer_disconnect_pull_consumer(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
break;
case CancelRequest:
case LocateRequest:
case LocateReply:
case CloseConnection:
case MessageError:
case Fragment:
return FALSE;
default:
return FALSE;
}
return FALSE;
}
void proto_register_giop_coseventcomm(void) {
static hf_register_info hf[] = {
{&hf_operationrequest, {"Request_Operation","COSEVENTCOMM.Request_Operation",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
};
static gint *ett[] = {
&ett_coseventcomm,
};
proto_coseventcomm = proto_register_protocol("Coseventcomm Dissector Using GIOP API" , "COSEVENTCOMM", "giop-coseventcomm" );
proto_register_field_array(proto_coseventcomm, hf, array_length(hf));
proto_register_subtree_array(ett,array_length(ett));
}
void proto_reg_handoff_giop_coseventcomm(void) {
register_giop_user_module(dissect_coseventcomm, "COSEVENTCOMM", "CosEventComm/PullConsumer", proto_coseventcomm );
register_giop_user_module(dissect_coseventcomm, "COSEVENTCOMM", "CosEventComm/PullSupplier", proto_coseventcomm );
register_giop_user_module(dissect_coseventcomm, "COSEVENTCOMM", "CosEventComm/PushConsumer", proto_coseventcomm );
register_giop_user_module(dissect_coseventcomm, "COSEVENTCOMM", "CosEventComm/PushSupplier", proto_coseventcomm );
register_giop_user(dissect_coseventcomm, "COSEVENTCOMM" ,proto_coseventcomm);
}
