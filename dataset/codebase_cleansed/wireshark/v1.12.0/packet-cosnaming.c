static void
decode_ex_CosNaming_NamingContext_NotFound(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_item *item _U_;
guint32 u_octet4;
guint32 u_octet4_loop_CosNaming_NamingContext_NotFound_rest_of_name;
guint32 i_CosNaming_NamingContext_NotFound_rest_of_name;
(void)item;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_NamingContext_NotFound_why, tvb, *offset-4, 4, u_octet4);
u_octet4_loop_CosNaming_NamingContext_NotFound_rest_of_name = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_NamingContext_NotFound_rest_of_name_loop, tvb,*offset-4, 4, u_octet4_loop_CosNaming_NamingContext_NotFound_rest_of_name);
for (i_CosNaming_NamingContext_NotFound_rest_of_name=0; i_CosNaming_NamingContext_NotFound_rest_of_name < u_octet4_loop_CosNaming_NamingContext_NotFound_rest_of_name; i_CosNaming_NamingContext_NotFound_rest_of_name++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
}
static void
decode_ex_CosNaming_NamingContext_CannotProceed(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_item *item _U_;
guint32 u_octet4_loop_CosNaming_NamingContext_CannotProceed_rest_of_name;
guint32 i_CosNaming_NamingContext_CannotProceed_rest_of_name;
(void)item;
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
u_octet4_loop_CosNaming_NamingContext_CannotProceed_rest_of_name = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_NamingContext_CannotProceed_rest_of_name_loop, tvb,*offset-4, 4, u_octet4_loop_CosNaming_NamingContext_CannotProceed_rest_of_name);
for (i_CosNaming_NamingContext_CannotProceed_rest_of_name=0; i_CosNaming_NamingContext_CannotProceed_rest_of_name < u_octet4_loop_CosNaming_NamingContext_CannotProceed_rest_of_name; i_CosNaming_NamingContext_CannotProceed_rest_of_name++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
}
static gboolean
decode_user_exception(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *ptree _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree *tree _U_;
if (!header->exception_id)
return FALSE;
if (strcmp(header->exception_id, "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0") == 0) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_ex_CosNaming_NamingContext_NotFound(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(header->exception_id, "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0") == 0) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_ex_CosNaming_NamingContext_CannotProceed(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
return FALSE;
}
static void
decode_CosNaming_NamingContext_bind(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_CosNaming_NamingContext_bind_n;
guint32 i_CosNaming_NamingContext_bind_n;
(void)item;
switch(header->message_type) {
case Request:
u_octet4_loop_CosNaming_NamingContext_bind_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_NamingContext_bind_n_loop, tvb,*offset-4, 4, u_octet4_loop_CosNaming_NamingContext_bind_n);
for (i_CosNaming_NamingContext_bind_n=0; i_CosNaming_NamingContext_bind_n < u_octet4_loop_CosNaming_NamingContext_bind_n; i_CosNaming_NamingContext_bind_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_NamingContext_rebind(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_CosNaming_NamingContext_rebind_n;
guint32 i_CosNaming_NamingContext_rebind_n;
(void)item;
switch(header->message_type) {
case Request:
u_octet4_loop_CosNaming_NamingContext_rebind_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_NamingContext_rebind_n_loop, tvb,*offset-4, 4, u_octet4_loop_CosNaming_NamingContext_rebind_n);
for (i_CosNaming_NamingContext_rebind_n=0; i_CosNaming_NamingContext_rebind_n < u_octet4_loop_CosNaming_NamingContext_rebind_n; i_CosNaming_NamingContext_rebind_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_NamingContext_bind_context(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_CosNaming_NamingContext_bind_context_n;
guint32 i_CosNaming_NamingContext_bind_context_n;
(void)item;
switch(header->message_type) {
case Request:
u_octet4_loop_CosNaming_NamingContext_bind_context_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_NamingContext_bind_context_n_loop, tvb,*offset-4, 4, u_octet4_loop_CosNaming_NamingContext_bind_context_n);
for (i_CosNaming_NamingContext_bind_context_n=0; i_CosNaming_NamingContext_bind_context_n < u_octet4_loop_CosNaming_NamingContext_bind_context_n; i_CosNaming_NamingContext_bind_context_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_NamingContext_rebind_context(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_CosNaming_NamingContext_rebind_context_n;
guint32 i_CosNaming_NamingContext_rebind_context_n;
(void)item;
switch(header->message_type) {
case Request:
u_octet4_loop_CosNaming_NamingContext_rebind_context_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_NamingContext_rebind_context_n_loop, tvb,*offset-4, 4, u_octet4_loop_CosNaming_NamingContext_rebind_context_n);
for (i_CosNaming_NamingContext_rebind_context_n=0; i_CosNaming_NamingContext_rebind_context_n < u_octet4_loop_CosNaming_NamingContext_rebind_context_n; i_CosNaming_NamingContext_rebind_context_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_NamingContext_resolve(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_CosNaming_NamingContext_resolve_n;
guint32 i_CosNaming_NamingContext_resolve_n;
(void)item;
switch(header->message_type) {
case Request:
u_octet4_loop_CosNaming_NamingContext_resolve_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_NamingContext_resolve_n_loop, tvb,*offset-4, 4, u_octet4_loop_CosNaming_NamingContext_resolve_n);
for (i_CosNaming_NamingContext_resolve_n=0; i_CosNaming_NamingContext_resolve_n < u_octet4_loop_CosNaming_NamingContext_resolve_n; i_CosNaming_NamingContext_resolve_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_NamingContext_unbind(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_CosNaming_NamingContext_unbind_n;
guint32 i_CosNaming_NamingContext_unbind_n;
(void)item;
switch(header->message_type) {
case Request:
u_octet4_loop_CosNaming_NamingContext_unbind_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_NamingContext_unbind_n_loop, tvb,*offset-4, 4, u_octet4_loop_CosNaming_NamingContext_unbind_n);
for (i_CosNaming_NamingContext_unbind_n=0; i_CosNaming_NamingContext_unbind_n < u_octet4_loop_CosNaming_NamingContext_unbind_n; i_CosNaming_NamingContext_unbind_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_NamingContext_new_context(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
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
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_NamingContext_bind_new_context(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_CosNaming_NamingContext_bind_new_context_n;
guint32 i_CosNaming_NamingContext_bind_new_context_n;
(void)item;
switch(header->message_type) {
case Request:
u_octet4_loop_CosNaming_NamingContext_bind_new_context_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_NamingContext_bind_new_context_n_loop, tvb,*offset-4, 4, u_octet4_loop_CosNaming_NamingContext_bind_new_context_n);
for (i_CosNaming_NamingContext_bind_new_context_n=0; i_CosNaming_NamingContext_bind_new_context_n < u_octet4_loop_CosNaming_NamingContext_bind_new_context_n; i_CosNaming_NamingContext_bind_new_context_n++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_NamingContext_destroy(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
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
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_NamingContext_list(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_CosNaming_NamingContext_list_bl;
guint32 i_CosNaming_NamingContext_list_bl;
(void)item;
switch(header->message_type) {
case Request:
proto_tree_add_uint(tree, hf_CosNaming_NamingContext_list_how_many, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_CosNaming_NamingContext_list_bl = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_NamingContext_list_bl_loop, tvb,*offset-4, 4, u_octet4_loop_CosNaming_NamingContext_list_bl);
for (i_CosNaming_NamingContext_list_bl=0; i_CosNaming_NamingContext_list_bl < u_octet4_loop_CosNaming_NamingContext_list_bl; i_CosNaming_NamingContext_list_bl++) {
decode_CosNaming_Binding_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_BindingIterator_next_one(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
proto_tree_add_boolean(tree, hf_CosNaming_BindingIterator_next_one_return, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
decode_CosNaming_Binding_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_BindingIterator_next_n(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_CosNaming_BindingIterator_next_n_bl;
guint32 i_CosNaming_BindingIterator_next_n_bl;
(void)item;
switch(header->message_type) {
case Request:
proto_tree_add_uint(tree, hf_CosNaming_BindingIterator_next_n_how_many, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
proto_tree_add_boolean(tree, hf_CosNaming_BindingIterator_next_n_return, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
u_octet4_loop_CosNaming_BindingIterator_next_n_bl = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_BindingIterator_next_n_bl_loop, tvb,*offset-4, 4, u_octet4_loop_CosNaming_BindingIterator_next_n_bl);
for (i_CosNaming_BindingIterator_next_n_bl=0; i_CosNaming_BindingIterator_next_n_bl < u_octet4_loop_CosNaming_BindingIterator_next_n_bl; i_CosNaming_BindingIterator_next_n_bl++) {
decode_CosNaming_Binding_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_BindingIterator_destroy(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
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
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_cosnaming_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CosNaming_NameComponent_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_CosNaming_NameComponent_id);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_CosNaming_NameComponent_kind);
}
static void
decode_CosNaming_Binding_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_CosNaming_Binding_binding_name;
guint32 i_CosNaming_Binding_binding_name;
guint32 u_octet4;
(void)item;
u_octet4_loop_CosNaming_Binding_binding_name = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_Binding_binding_name_loop, tvb,*offset-4, 4, u_octet4_loop_CosNaming_Binding_binding_name);
for (i_CosNaming_Binding_binding_name=0; i_CosNaming_Binding_binding_name < u_octet4_loop_CosNaming_Binding_binding_name; i_CosNaming_Binding_binding_name++) {
decode_CosNaming_NameComponent_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
item = proto_tree_add_uint(tree, hf_CosNaming_Binding_binding_type, tvb, *offset-4, 4, u_octet4);
}
static proto_tree *
start_dissecting(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset)
{
proto_item *ti = NULL;
proto_tree *tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "COSNAMING");
if (ptree) {
ti = proto_tree_add_item(ptree, proto_cosnaming, tvb, *offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_cosnaming);
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
dissect_cosnaming(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset, MessageHeader *header, const gchar *operation, gchar *idlname)
{
proto_item *item _U_;
proto_tree *tree _U_;
gboolean stream_is_big_endian = is_big_endian(header);
if ((header->message_type == Reply) && (header->rep_status == USER_EXCEPTION)) {
return decode_user_exception(tvb, pinfo, ptree, offset, header, operation, stream_is_big_endian);
}
switch(header->message_type) {
case Request:
case Reply:
if (strcmp(operation, "bind") == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_bind(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "rebind") == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_rebind(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "bind_context") == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_bind_context(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "rebind_context") == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_rebind_context(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "resolve") == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_resolve(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "unbind") == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_unbind(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "new_context") == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_new_context(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "bind_new_context") == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_bind_new_context(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "destroy") == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_destroy(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "list") == 0
&& (!idlname || strcmp(idlname, "CosNaming/NamingContext") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_NamingContext_list(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "next_one") == 0
&& (!idlname || strcmp(idlname, "CosNaming/BindingIterator") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_BindingIterator_next_one(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "next_n") == 0
&& (!idlname || strcmp(idlname, "CosNaming/BindingIterator") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_BindingIterator_next_n(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "destroy") == 0
&& (!idlname || strcmp(idlname, "CosNaming/BindingIterator") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CosNaming_BindingIterator_destroy(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
void proto_register_giop_cosnaming(void)
{
static hf_register_info hf[] = {
{&hf_operationrequest, {"Request_Operation","giop-cosnaming.Request_Operation",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_NamingContext_bind_n_loop, {"Seq length of n","giop-cosnaming.NamingContext.bind.n.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_NamingContext_rebind_n_loop, {"Seq length of n","giop-cosnaming.NamingContext.rebind.n.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_NamingContext_bind_context_n_loop, {"Seq length of n","giop-cosnaming.NamingContext.bind_context.n.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_NamingContext_rebind_context_n_loop, {"Seq length of n","giop-cosnaming.NamingContext.rebind_context.n.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_NamingContext_resolve_n_loop, {"Seq length of n","giop-cosnaming.NamingContext.resolve.n.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_NamingContext_unbind_n_loop, {"Seq length of n","giop-cosnaming.NamingContext.unbind.n.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_NamingContext_bind_new_context_n_loop, {"Seq length of n","giop-cosnaming.NamingContext.bind_new_context.n.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_NamingContext_list_how_many, {"how_many","giop-cosnaming.NamingContext.list.how_many",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_NamingContext_list_bl_loop, {"Seq length of bl","giop-cosnaming.NamingContext.list.bl.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_BindingIterator_next_one_return, {"Return value","giop-cosnaming.BindingIterator.next_one.return",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
{&hf_CosNaming_BindingIterator_next_n_return, {"Return value","giop-cosnaming.BindingIterator.next_n.return",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
{&hf_CosNaming_BindingIterator_next_n_how_many, {"how_many","giop-cosnaming.BindingIterator.next_n.how_many",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_BindingIterator_next_n_bl_loop, {"Seq length of bl","giop-cosnaming.BindingIterator.next_n.bl.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_NameComponent_id, {"NameComponent_id","giop-cosnaming.NameComponent.id",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_NameComponent_kind, {"NameComponent_kind","giop-cosnaming.NameComponent.kind",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_Binding_binding_name_loop, {"Seq length of Binding_binding_name","giop-cosnaming.Binding.binding_name.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_Binding_binding_type, {"Binding_binding_type","giop-cosnaming.Binding.binding_type",FT_UINT32,BASE_DEC,VALS(CosNaming_BindingType),0x0,NULL,HFILL}},
{&hf_CosNaming_NamingContext_NotFound_why, {"NotFound_why","giop-cosnaming.NamingContext.NotFound_why",FT_UINT32,BASE_DEC,VALS(CosNaming_NamingContext_NotFoundReason),0x0,NULL,HFILL}},
{&hf_CosNaming_NamingContext_NotFound_rest_of_name_loop, {"Seq length of NotFound_rest_of_name","giop-cosnaming.NamingContext.NotFound_rest_of_name.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_CosNaming_NamingContext_CannotProceed_rest_of_name_loop, {"Seq length of CannotProceed_rest_of_name","giop-cosnaming.NamingContext.CannotProceed_rest_of_name.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
};
static ei_register_info ei[] = {
{ &ei_cosnaming_unknown_giop_msg, { "giop-cosnaming.unknown_giop_msg", PI_PROTOCOL, PI_WARN, "Unknown GIOP message", EXPFILL }},
{ &ei_cosnaming_unknown_exception, { "giop-cosnaming.unknown_exception", PI_PROTOCOL, PI_WARN, "Unknown exception", EXPFILL }},
{ &ei_cosnaming_unknown_reply_status, { "giop-cosnaming.unknown_reply_status", PI_PROTOCOL, PI_WARN, "Unknown reply status", EXPFILL }},
};
static gint *ett[] = {
&ett_cosnaming,
};
expert_module_t* expert_cosnaming;
proto_cosnaming = proto_register_protocol("Cosnaming Dissector Using GIOP API" , "COSNAMING", "giop-cosnaming" );
proto_register_field_array(proto_cosnaming, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_cosnaming = expert_register_protocol(proto_cosnaming);
expert_register_field_array(expert_cosnaming, ei, array_length(ei));
}
void proto_reg_handoff_giop_cosnaming(void)
{
register_giop_user_module(dissect_cosnaming, "COSNAMING", "CosNaming/BindingIterator", proto_cosnaming );
register_giop_user_module(dissect_cosnaming, "COSNAMING", "CosNaming/NamingContext", proto_cosnaming );
register_giop_user(dissect_cosnaming, "COSNAMING" ,proto_cosnaming);
}
