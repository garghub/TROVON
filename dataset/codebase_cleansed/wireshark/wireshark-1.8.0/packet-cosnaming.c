static void decode_ex_CosNaming_NamingContext_NotFound(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
guint32 u_octet4_loop_NotFound_rest_of_name;
guint32 i_NotFound_rest_of_name;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"NotFound_why = %u (%s)",u_octet4,val_to_str(u_octet4,CosNaming_NamingContext_NotFoundReason,"Unknown Enum Value"));
}
u_octet4_loop_NotFound_rest_of_name = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of NotFound_rest_of_name = %u",u_octet4_loop_NotFound_rest_of_name);
}
for (i_NotFound_rest_of_name=0; i_NotFound_rest_of_name < u_octet4_loop_NotFound_rest_of_name; i_NotFound_rest_of_name++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
}
static void decode_ex_CosNaming_NamingContext_CannotProceed(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_CannotProceed_rest_of_name;
guint32 i_CannotProceed_rest_of_name;
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
u_octet4_loop_CannotProceed_rest_of_name = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of CannotProceed_rest_of_name = %u",u_octet4_loop_CannotProceed_rest_of_name);
}
for (i_CannotProceed_rest_of_name=0; i_CannotProceed_rest_of_name < u_octet4_loop_CannotProceed_rest_of_name; i_CannotProceed_rest_of_name++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
}
static gboolean decode_user_exception(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *ptree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
proto_tree *tree _U_;
if (!header->exception_id)
return FALSE;
if (strcmp(header->exception_id, user_exception_CosNaming_NamingContext_NotFound) == 0) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_ex_CosNaming_NamingContext_NotFound(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(header->exception_id, user_exception_CosNaming_NamingContext_CannotProceed) == 0) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_ex_CosNaming_NamingContext_CannotProceed(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
return FALSE;
}
static void decode_CosNaming_NamingContext_bind(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_n;
guint32 i_n;
switch(header->message_type) {
case Request:
u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
}
for (i_n=0; i_n < u_octet4_loop_n; i_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
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
static void decode_CosNaming_NamingContext_rebind(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_n;
guint32 i_n;
switch(header->message_type) {
case Request:
u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
}
for (i_n=0; i_n < u_octet4_loop_n; i_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
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
static void decode_CosNaming_NamingContext_bind_context(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_n;
guint32 i_n;
switch(header->message_type) {
case Request:
u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
}
for (i_n=0; i_n < u_octet4_loop_n; i_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
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
static void decode_CosNaming_NamingContext_rebind_context(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_n;
guint32 i_n;
switch(header->message_type) {
case Request:
u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
}
for (i_n=0; i_n < u_octet4_loop_n; i_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
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
static void decode_CosNaming_NamingContext_resolve(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_n;
guint32 i_n;
switch(header->message_type) {
case Request:
u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
}
for (i_n=0; i_n < u_octet4_loop_n; i_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
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
static void decode_CosNaming_NamingContext_unbind(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_n;
guint32 i_n;
switch(header->message_type) {
case Request:
u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
}
for (i_n=0; i_n < u_octet4_loop_n; i_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
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
static void decode_CosNaming_NamingContext_new_context(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
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
static void decode_CosNaming_NamingContext_bind_new_context(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_n;
guint32 i_n;
switch(header->message_type) {
case Request:
u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
}
for (i_n=0; i_n < u_octet4_loop_n; i_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
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
static void decode_CosNaming_NamingContext_destroy(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
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
static void decode_CosNaming_NamingContext_list(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
guint32 u_octet4_loop_bl;
guint32 i_bl;
switch(header->message_type) {
case Request:
u_octet4 = get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"how_many = %u",u_octet4);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_bl = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of bl = %u",u_octet4_loop_bl);
}
for (i_bl=0; i_bl < u_octet4_loop_bl; i_bl++) {
decode_CosNaming_Binding_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
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
static void decode_CosNaming_BindingIterator_next_one(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint8 u_octet1;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet1 = get_CDR_boolean(tvb,offset);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-1,1,"Operation_Return_Value = %u",u_octet1);
}
decode_CosNaming_Binding_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_CosNaming_BindingIterator_next_n(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
guint8 u_octet1;
guint32 u_octet4_loop_bl;
guint32 i_bl;
switch(header->message_type) {
case Request:
u_octet4 = get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"how_many = %u",u_octet4);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet1 = get_CDR_boolean(tvb,offset);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-1,1,"Operation_Return_Value = %u",u_octet1);
}
u_octet4_loop_bl = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of bl = %u",u_octet4_loop_bl);
}
for (i_bl=0; i_bl < u_octet4_loop_bl; i_bl++) {
decode_CosNaming_Binding_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_CosNaming_BindingIterator_destroy(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
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
static void decode_CosNaming_NameComponent_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"NameComponent_id (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"NameComponent_kind (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
static void decode_CosNaming_Binding_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_Binding_binding_name;
guint32 i_Binding_binding_name;
guint32 u_octet4;
u_octet4_loop_Binding_binding_name = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of Binding_binding_name = %u",u_octet4_loop_Binding_binding_name);
}
for (i_Binding_binding_name=0; i_Binding_binding_name < u_octet4_loop_Binding_binding_name; i_Binding_binding_name++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"Binding_binding_type = %u (%s)",u_octet4,val_to_str(u_octet4,CosNaming_BindingType,"Unknown Enum Value"));
}
}
static proto_tree *start_dissecting(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset) {
proto_item *ti = NULL;
proto_tree *tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "COSNAMING");
if (ptree) {
ti = proto_tree_add_item(ptree, proto_cosnaming, tvb, *offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_cosnaming);
}
return tree;
}
static gboolean dissect_cosnaming(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset, MessageHeader *header, gchar *operation, gchar *idlname) {
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
if (strcmp(operation, CosNaming_NamingContext_bind_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_bind(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosNaming_NamingContext_rebind_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_rebind(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosNaming_NamingContext_bind_context_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_bind_context(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosNaming_NamingContext_rebind_context_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_rebind_context(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosNaming_NamingContext_resolve_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_resolve(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosNaming_NamingContext_unbind_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_unbind(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosNaming_NamingContext_new_context_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_new_context(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosNaming_NamingContext_bind_new_context_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_bind_new_context(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosNaming_NamingContext_destroy_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_destroy(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosNaming_NamingContext_list_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_list(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosNaming_BindingIterator_next_one_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/BindingIterator") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_BindingIterator_next_one(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosNaming_BindingIterator_next_n_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/BindingIterator") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_BindingIterator_next_n(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, CosNaming_BindingIterator_destroy_op) == 0
&& (!idlname || strcmp(idlname, "CosNaming/BindingIterator") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_BindingIterator_destroy(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
void proto_register_giop_cosnaming(void) {
static hf_register_info hf[] = {
{&hf_operationrequest, {"Request_Operation","COSNAMING.Request_Operation",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
};
static gint *ett[] = {
&ett_cosnaming,
};
proto_cosnaming = proto_register_protocol("Cosnaming Dissector Using GIOP API" , "COSNAMING", "giop-cosnaming" );
proto_register_field_array(proto_cosnaming, hf, array_length(hf));
proto_register_subtree_array(ett,array_length(ett));
}
void proto_reg_handoff_giop_cosnaming(void) {
register_giop_user_module(dissect_cosnaming, "COSNAMING", "CosNaming/BindingIterator", proto_cosnaming );
register_giop_user_module(dissect_cosnaming, "COSNAMING", "CosNaming/NamingContext", proto_cosnaming );
register_giop_user(dissect_cosnaming, "COSNAMING" ,proto_cosnaming);
}
