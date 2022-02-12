static gboolean
decode_user_exception(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *ptree _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree *tree _U_;
if (!header->exception_id)
return FALSE;
return FALSE;
}
static void
decode_CosEventComm_PushConsumer_push(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, int *offset, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian)
{
switch(header->message_type) {
case Request:
get_CDR_any(tvb, pinfo, tree, item, offset, stream_is_big_endian, boundary, header);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosEventComm_PushConsumer_disconnect_push_consumer(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, proto_item *item, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
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
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosEventComm_PushSupplier_disconnect_push_supplier(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, proto_item *item, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
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
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosEventComm_PullSupplier_pull(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, int *offset, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
get_CDR_any(tvb, pinfo, tree, item, offset, stream_is_big_endian, boundary, header);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosEventComm_PullSupplier_try_pull(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, int *offset, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
get_CDR_any(tvb, pinfo, tree, item, offset, stream_is_big_endian, boundary, header);
proto_tree_add_boolean(tree, hf_CosEventComm_PullSupplier_try_pull_has_event, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosEventComm_PullSupplier_disconnect_pull_supplier(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, proto_item *item, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
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
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosEventComm_PullConsumer_disconnect_pull_consumer(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, proto_item *item, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
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
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static proto_tree *
start_dissecting(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset)
{
proto_item *ti = NULL;
proto_tree *tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "COSEVENTCOMM");
if (ptree) {
ti = proto_tree_add_item(ptree, proto_coseventcomm, tvb, *offset, tvb_reported_length_remaining(tvb, *offset), ENC_NA);
tree = proto_item_add_subtree(ti, ett_coseventcomm);
}
return tree;
}
static proto_item*
process_RequestOperation(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, MessageHeader *header, const gchar *operation)
{
proto_item *pi;
if(header->message_type == Reply) {
col_append_fstr(pinfo->cinfo, COL_INFO, " op = %s",operation);
}
pi=proto_tree_add_string(ptree, hf_operationrequest, tvb, 0, 0, operation);
PROTO_ITEM_SET_GENERATED(pi);
return pi;
}
static gboolean
dissect_coseventcomm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset, MessageHeader *header, const gchar *operation, gchar *idlname)
{
proto_item *item;
proto_tree *tree;
gboolean stream_is_big_endian = is_big_endian(header);
if ((header->message_type == Reply) && (header->rep_status == USER_EXCEPTION)) {
return decode_user_exception(tvb, pinfo, ptree, offset, header, operation, stream_is_big_endian);
}
switch(header->message_type) {
case Request:
case Reply:
if (strcmp(operation, "push") == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PushConsumer") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PushConsumer_push(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "disconnect_push_consumer") == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PushConsumer") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PushConsumer_disconnect_push_consumer(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "disconnect_push_supplier") == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PushSupplier") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PushSupplier_disconnect_push_supplier(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "pull") == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PullSupplier") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PullSupplier_pull(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "try_pull") == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PullSupplier") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PullSupplier_try_pull(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "disconnect_pull_supplier") == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PullSupplier") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PullSupplier_disconnect_pull_supplier(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "disconnect_pull_consumer") == 0
&& (!idlname || strcmp(idlname, "CosEventComm/PullConsumer") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosEventComm_PullConsumer_disconnect_pull_consumer(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
void proto_register_giop_coseventcomm(void)
{
static hf_register_info hf[] = {
{&hf_operationrequest, {"Request_Operation","giop-coseventcomm.Request_Operation",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_CosEventComm_PullSupplier_try_pull_has_event, {"has_event","giop-coseventcomm.PullSupplier.try_pull.has_event",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
};
static ei_register_info ei[] = {
{ &ei_coseventcomm_unknown_giop_msg, { "giop-coseventcomm.unknown_giop_msg", PI_PROTOCOL, PI_WARN, "Unknown GIOP message", EXPFILL }},
{ &ei_coseventcomm_unknown_exception, { "giop-coseventcomm.unknown_exception", PI_PROTOCOL, PI_WARN, "Unknown exception", EXPFILL }},
{ &ei_coseventcomm_unknown_reply_status, { "giop-coseventcomm.unknown_reply_status", PI_PROTOCOL, PI_WARN, "Unknown reply status", EXPFILL }},
};
static gint *ett[] = {
&ett_coseventcomm,
};
expert_module_t* expert_coseventcomm;
proto_coseventcomm = proto_register_protocol("Coseventcomm Dissector Using GIOP API" , "COSEVENTCOMM", "giop-coseventcomm" );
proto_register_field_array(proto_coseventcomm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_coseventcomm = expert_register_protocol(proto_coseventcomm);
expert_register_field_array(expert_coseventcomm, ei, array_length(ei));
}
void proto_reg_handoff_giop_coseventcomm(void)
{
register_giop_user_module(dissect_coseventcomm, "COSEVENTCOMM", "CosEventComm/PullConsumer", proto_coseventcomm );
register_giop_user_module(dissect_coseventcomm, "COSEVENTCOMM", "CosEventComm/PullSupplier", proto_coseventcomm );
register_giop_user_module(dissect_coseventcomm, "COSEVENTCOMM", "CosEventComm/PushConsumer", proto_coseventcomm );
register_giop_user_module(dissect_coseventcomm, "COSEVENTCOMM", "CosEventComm/PushSupplier", proto_coseventcomm );
register_giop_user(dissect_coseventcomm, "COSEVENTCOMM" ,proto_coseventcomm);
}
