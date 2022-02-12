static void
decode_ex_UCO_InvalidInputParameter(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_item *item = NULL;
guint32 u_octet4_loop_UCO_InvalidInputParameter_badInputParameters;
guint32 i_UCO_InvalidInputParameter_badInputParameters;
decode_UCO_exception_details_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_UCO_InvalidInputParameter_badInputParameters = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_InvalidInputParameter_badInputParameters_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_InvalidInputParameter_badInputParameters);
for (i_UCO_InvalidInputParameter_badInputParameters=0; i_UCO_InvalidInputParameter_badInputParameters < u_octet4_loop_UCO_InvalidInputParameter_badInputParameters; i_UCO_InvalidInputParameter_badInputParameters++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_InvalidInputParameter_badInputParameters);
}
}
static void
decode_ex_UCO_ProcessingFault(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_item *item = NULL;
decode_UCO_exception_details_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
static void
decode_ex_UCO_SystemFault(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_item *item = NULL;
decode_UCO_exception_details_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
static gboolean
decode_user_exception(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *ptree _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree *tree _U_;
if (!header->exception_id)
return FALSE;
if (strcmp(header->exception_id, "IDL:UCO/InvalidInputParameter:1.0") == 0) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_ex_UCO_InvalidInputParameter(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(header->exception_id, "IDL:UCO/ProcessingFault:1.0") == 0) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_ex_UCO_ProcessingFault(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(header->exception_id, "IDL:UCO/SystemFault:1.0") == 0) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_ex_UCO_SystemFault(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
return FALSE;
}
static void
decode_CB_Callback_notify(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_CB_Callback_notify_theState, tvb, *offset-4, 4, u_octet4);
decode_UCO_RequestDescription_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_CB_Callback_release(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_Library_get_manager_types(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_Library_get_manager_types_return;
guint32 i_GIAS_Library_get_manager_types_return;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_Library_get_manager_types_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Library_get_manager_types_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_Library_get_manager_types_return);
for (i_GIAS_Library_get_manager_types_return=0; i_GIAS_Library_get_manager_types_return < u_octet4_loop_GIAS_Library_get_manager_types_return; i_GIAS_Library_get_manager_types_return++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Library_get_manager_types_return);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_Library_get_manager(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Library_get_manager_manager_type);
decode_GIAS_AccessCriteria_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_Library_get_library_description(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_GIAS_LibraryDescription_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_Library_get_other_libraries(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_Library_get_other_libraries_return;
guint32 i_GIAS_Library_get_other_libraries_return;
switch(header->message_type) {
case Request:
decode_GIAS_AccessCriteria_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_Library_get_other_libraries_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Library_get_other_libraries_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_Library_get_other_libraries_return);
for (i_GIAS_Library_get_other_libraries_return=0; i_GIAS_Library_get_other_libraries_return < u_octet4_loop_GIAS_Library_get_other_libraries_return; i_GIAS_Library_get_other_libraries_return++) {
decode_GIAS_LibraryDescription_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_LibraryManager_get_property_names(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_LibraryManager_get_property_names_return;
guint32 i_GIAS_LibraryManager_get_property_names_return;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_LibraryManager_get_property_names_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_LibraryManager_get_property_names_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_LibraryManager_get_property_names_return);
for (i_GIAS_LibraryManager_get_property_names_return=0; i_GIAS_LibraryManager_get_property_names_return < u_octet4_loop_GIAS_LibraryManager_get_property_names_return; i_GIAS_LibraryManager_get_property_names_return++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_LibraryManager_get_property_names_return);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_LibraryManager_get_property_values(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_LibraryManager_get_property_values_desired_properties;
guint32 i_GIAS_LibraryManager_get_property_values_desired_properties;
guint32 u_octet4_loop_GIAS_LibraryManager_get_property_values_return;
guint32 i_GIAS_LibraryManager_get_property_values_return;
switch(header->message_type) {
case Request:
u_octet4_loop_GIAS_LibraryManager_get_property_values_desired_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_LibraryManager_get_property_values_desired_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_LibraryManager_get_property_values_desired_properties);
for (i_GIAS_LibraryManager_get_property_values_desired_properties=0; i_GIAS_LibraryManager_get_property_values_desired_properties < u_octet4_loop_GIAS_LibraryManager_get_property_values_desired_properties; i_GIAS_LibraryManager_get_property_values_desired_properties++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_LibraryManager_get_property_values_desired_properties);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_LibraryManager_get_property_values_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_LibraryManager_get_property_values_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_LibraryManager_get_property_values_return);
for (i_GIAS_LibraryManager_get_property_values_return=0; i_GIAS_LibraryManager_get_property_values_return < u_octet4_loop_GIAS_LibraryManager_get_property_values_return; i_GIAS_LibraryManager_get_property_values_return++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_LibraryManager_get_libraries(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_LibraryManager_get_libraries_return;
guint32 i_GIAS_LibraryManager_get_libraries_return;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_LibraryManager_get_libraries_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_LibraryManager_get_libraries_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_LibraryManager_get_libraries_return);
for (i_GIAS_LibraryManager_get_libraries_return=0; i_GIAS_LibraryManager_get_libraries_return < u_octet4_loop_GIAS_LibraryManager_get_libraries_return; i_GIAS_LibraryManager_get_libraries_return++) {
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_RequestManager_get_active_requests(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_RequestManager_get_active_requests_return;
guint32 i_GIAS_RequestManager_get_active_requests_return;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_RequestManager_get_active_requests_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_RequestManager_get_active_requests_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_RequestManager_get_active_requests_return);
for (i_GIAS_RequestManager_get_active_requests_return=0; i_GIAS_RequestManager_get_active_requests_return < u_octet4_loop_GIAS_RequestManager_get_active_requests_return; i_GIAS_RequestManager_get_active_requests_return++) {
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_RequestManager_get_default_timeout(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
proto_tree_add_uint(tree, hf_GIAS_RequestManager_get_default_timeout_return, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_RequestManager_set_default_timeout(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
proto_tree_add_uint(tree, hf_GIAS_RequestManager_set_default_timeout_new_default, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_RequestManager_get_timeout(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
proto_tree_add_uint(tree, hf_GIAS_RequestManager_get_timeout_return, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_RequestManager_set_timeout(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_RequestManager_set_timeout_new_lifetime, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_RequestManager_delete_request(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_AccessManager_get_use_modes(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_AccessManager_get_use_modes_return;
guint32 i_GIAS_AccessManager_get_use_modes_return;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_AccessManager_get_use_modes_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_AccessManager_get_use_modes_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_AccessManager_get_use_modes_return);
for (i_GIAS_AccessManager_get_use_modes_return=0; i_GIAS_AccessManager_get_use_modes_return < u_octet4_loop_GIAS_AccessManager_get_use_modes_return; i_GIAS_AccessManager_get_use_modes_return++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_AccessManager_get_use_modes_return);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_AccessManager_is_available(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_AccessManager_is_available_use_mode);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
proto_tree_add_boolean(tree, hf_GIAS_AccessManager_is_available_return, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_AccessManager_query_availability_delay(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_AccessManager_query_availability_delay_availability_requirement, tvb, *offset-4, 4, u_octet4);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_AccessManager_query_availability_delay_use_mode);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
proto_tree_add_uint(tree, hf_GIAS_AccessManager_query_availability_delay_return, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_AccessManager_get_number_of_priorities(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
proto_tree_add_int(tree, hf_GIAS_AccessManager_get_number_of_priorities_return, tvb, *offset-2, 2, get_CDR_short(tvb,offset,stream_is_big_endian, boundary));
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_AccessManager_set_availability(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_AccessManager_set_availability_products;
guint32 i_GIAS_AccessManager_set_availability_products;
guint32 u_octet4;
switch(header->message_type) {
case Request:
u_octet4_loop_GIAS_AccessManager_set_availability_products = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_AccessManager_set_availability_products_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_AccessManager_set_availability_products);
for (i_GIAS_AccessManager_set_availability_products=0; i_GIAS_AccessManager_set_availability_products < u_octet4_loop_GIAS_AccessManager_set_availability_products; i_GIAS_AccessManager_set_availability_products++) {
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
}
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_AccessManager_set_availability_availability_requirement, tvb, *offset-4, 4, u_octet4);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_AccessManager_set_availability_use_mode);
proto_tree_add_int(tree, hf_GIAS_AccessManager_set_availability_priority, tvb, *offset-2, 2, get_CDR_short(tvb,offset,stream_is_big_endian, boundary));
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_QueryOrderMgr_get_event_descriptions(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_QueryOrderMgr_get_event_descriptions_return;
guint32 i_GIAS_QueryOrderMgr_get_event_descriptions_return;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_QueryOrderMgr_get_event_descriptions_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_QueryOrderMgr_get_event_descriptions_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_QueryOrderMgr_get_event_descriptions_return);
for (i_GIAS_QueryOrderMgr_get_event_descriptions_return=0; i_GIAS_QueryOrderMgr_get_event_descriptions_return < u_octet4_loop_GIAS_QueryOrderMgr_get_event_descriptions_return; i_GIAS_QueryOrderMgr_get_event_descriptions_return++) {
decode_GIAS_Event_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_QueryOrderMgr_submit_query_order(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
guint32 u_octet4_loop_GIAS_QueryOrderMgr_submit_query_order_properties;
guint32 i_GIAS_QueryOrderMgr_submit_query_order_properties;
switch(header->message_type) {
case Request:
decode_GIAS_Query_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
decode_GIAS_QueryLifeSpan_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_QueryOrderMgr_submit_query_order_o_type, tvb, *offset-4, 4, u_octet4);
decode_GIAS_QueryOrderContents_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_QueryOrderMgr_submit_query_order_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_QueryOrderMgr_submit_query_order_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_QueryOrderMgr_submit_query_order_properties);
for (i_GIAS_QueryOrderMgr_submit_query_order_properties=0; i_GIAS_QueryOrderMgr_submit_query_order_properties < u_octet4_loop_GIAS_QueryOrderMgr_submit_query_order_properties; i_GIAS_QueryOrderMgr_submit_query_order_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_OrderMgr_get_package_specifications(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_OrderMgr_get_package_specifications_return;
guint32 i_GIAS_OrderMgr_get_package_specifications_return;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_OrderMgr_get_package_specifications_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_OrderMgr_get_package_specifications_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_OrderMgr_get_package_specifications_return);
for (i_GIAS_OrderMgr_get_package_specifications_return=0; i_GIAS_OrderMgr_get_package_specifications_return < u_octet4_loop_GIAS_OrderMgr_get_package_specifications_return; i_GIAS_OrderMgr_get_package_specifications_return++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_OrderMgr_get_package_specifications_return);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_OrderMgr_validate_order(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_OrderMgr_validate_order_properties;
guint32 i_GIAS_OrderMgr_validate_order_properties;
switch(header->message_type) {
case Request:
decode_GIAS_OrderContents_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_OrderMgr_validate_order_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_OrderMgr_validate_order_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_OrderMgr_validate_order_properties);
for (i_GIAS_OrderMgr_validate_order_properties=0; i_GIAS_OrderMgr_validate_order_properties < u_octet4_loop_GIAS_OrderMgr_validate_order_properties; i_GIAS_OrderMgr_validate_order_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_GIAS_ValidationResults_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_OrderMgr_order(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_OrderMgr_order_properties;
guint32 i_GIAS_OrderMgr_order_properties;
switch(header->message_type) {
case Request:
decode_GIAS_OrderContents_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_OrderMgr_order_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_OrderMgr_order_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_OrderMgr_order_properties);
for (i_GIAS_OrderMgr_order_properties=0; i_GIAS_OrderMgr_order_properties < u_octet4_loop_GIAS_OrderMgr_order_properties; i_GIAS_OrderMgr_order_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_DataModelMgr_get_data_model_date(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_DataModelMgr_get_data_model_date_properties;
guint32 i_GIAS_DataModelMgr_get_data_model_date_properties;
switch(header->message_type) {
case Request:
u_octet4_loop_GIAS_DataModelMgr_get_data_model_date_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_data_model_date_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_data_model_date_properties);
for (i_GIAS_DataModelMgr_get_data_model_date_properties=0; i_GIAS_DataModelMgr_get_data_model_date_properties < u_octet4_loop_GIAS_DataModelMgr_get_data_model_date_properties; i_GIAS_DataModelMgr_get_data_model_date_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_UCO_AbsTime_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_DataModelMgr_get_alias_categories(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_DataModelMgr_get_alias_categories_properties;
guint32 i_GIAS_DataModelMgr_get_alias_categories_properties;
guint32 u_octet4_loop_GIAS_DataModelMgr_get_alias_categories_return;
guint32 i_GIAS_DataModelMgr_get_alias_categories_return;
switch(header->message_type) {
case Request:
u_octet4_loop_GIAS_DataModelMgr_get_alias_categories_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_alias_categories_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_alias_categories_properties);
for (i_GIAS_DataModelMgr_get_alias_categories_properties=0; i_GIAS_DataModelMgr_get_alias_categories_properties < u_octet4_loop_GIAS_DataModelMgr_get_alias_categories_properties; i_GIAS_DataModelMgr_get_alias_categories_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_DataModelMgr_get_alias_categories_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_alias_categories_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_alias_categories_return);
for (i_GIAS_DataModelMgr_get_alias_categories_return=0; i_GIAS_DataModelMgr_get_alias_categories_return < u_octet4_loop_GIAS_DataModelMgr_get_alias_categories_return; i_GIAS_DataModelMgr_get_alias_categories_return++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_DataModelMgr_get_alias_categories_return);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_DataModelMgr_get_logical_aliases(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_DataModelMgr_get_logical_aliases_properties;
guint32 i_GIAS_DataModelMgr_get_logical_aliases_properties;
guint32 u_octet4_loop_GIAS_DataModelMgr_get_logical_aliases_return;
guint32 i_GIAS_DataModelMgr_get_logical_aliases_return;
switch(header->message_type) {
case Request:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_DataModelMgr_get_logical_aliases_category);
u_octet4_loop_GIAS_DataModelMgr_get_logical_aliases_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_logical_aliases_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_logical_aliases_properties);
for (i_GIAS_DataModelMgr_get_logical_aliases_properties=0; i_GIAS_DataModelMgr_get_logical_aliases_properties < u_octet4_loop_GIAS_DataModelMgr_get_logical_aliases_properties; i_GIAS_DataModelMgr_get_logical_aliases_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_DataModelMgr_get_logical_aliases_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_logical_aliases_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_logical_aliases_return);
for (i_GIAS_DataModelMgr_get_logical_aliases_return=0; i_GIAS_DataModelMgr_get_logical_aliases_return < u_octet4_loop_GIAS_DataModelMgr_get_logical_aliases_return; i_GIAS_DataModelMgr_get_logical_aliases_return++) {
decode_UCO_NameName_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_DataModelMgr_get_logical_attribute_name(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
guint32 u_octet4_loop_GIAS_DataModelMgr_get_logical_attribute_name_properties;
guint32 i_GIAS_DataModelMgr_get_logical_attribute_name_properties;
switch(header->message_type) {
case Request:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_DataModelMgr_get_logical_attribute_name_view_name);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_logical_attribute_name_attribute_type, tvb, *offset-4, 4, u_octet4);
u_octet4_loop_GIAS_DataModelMgr_get_logical_attribute_name_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_logical_attribute_name_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_logical_attribute_name_properties);
for (i_GIAS_DataModelMgr_get_logical_attribute_name_properties=0; i_GIAS_DataModelMgr_get_logical_attribute_name_properties < u_octet4_loop_GIAS_DataModelMgr_get_logical_attribute_name_properties; i_GIAS_DataModelMgr_get_logical_attribute_name_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_DataModelMgr_get_logical_attribute_name_return);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_DataModelMgr_get_view_names(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_DataModelMgr_get_view_names_properties;
guint32 i_GIAS_DataModelMgr_get_view_names_properties;
guint32 u_octet4_loop_GIAS_DataModelMgr_get_view_names_return;
guint32 i_GIAS_DataModelMgr_get_view_names_return;
switch(header->message_type) {
case Request:
u_octet4_loop_GIAS_DataModelMgr_get_view_names_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_view_names_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_view_names_properties);
for (i_GIAS_DataModelMgr_get_view_names_properties=0; i_GIAS_DataModelMgr_get_view_names_properties < u_octet4_loop_GIAS_DataModelMgr_get_view_names_properties; i_GIAS_DataModelMgr_get_view_names_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_DataModelMgr_get_view_names_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_view_names_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_view_names_return);
for (i_GIAS_DataModelMgr_get_view_names_return=0; i_GIAS_DataModelMgr_get_view_names_return < u_octet4_loop_GIAS_DataModelMgr_get_view_names_return; i_GIAS_DataModelMgr_get_view_names_return++) {
decode_GIAS_View_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_DataModelMgr_get_attributes(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_DataModelMgr_get_attributes_properties;
guint32 i_GIAS_DataModelMgr_get_attributes_properties;
guint32 u_octet4_loop_GIAS_DataModelMgr_get_attributes_return;
guint32 i_GIAS_DataModelMgr_get_attributes_return;
switch(header->message_type) {
case Request:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_DataModelMgr_get_attributes_view_name);
u_octet4_loop_GIAS_DataModelMgr_get_attributes_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_attributes_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_attributes_properties);
for (i_GIAS_DataModelMgr_get_attributes_properties=0; i_GIAS_DataModelMgr_get_attributes_properties < u_octet4_loop_GIAS_DataModelMgr_get_attributes_properties; i_GIAS_DataModelMgr_get_attributes_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_DataModelMgr_get_attributes_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_attributes_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_attributes_return);
for (i_GIAS_DataModelMgr_get_attributes_return=0; i_GIAS_DataModelMgr_get_attributes_return < u_octet4_loop_GIAS_DataModelMgr_get_attributes_return; i_GIAS_DataModelMgr_get_attributes_return++) {
decode_GIAS_AttributeInformation_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_DataModelMgr_get_queryable_attributes(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_DataModelMgr_get_queryable_attributes_properties;
guint32 i_GIAS_DataModelMgr_get_queryable_attributes_properties;
guint32 u_octet4_loop_GIAS_DataModelMgr_get_queryable_attributes_return;
guint32 i_GIAS_DataModelMgr_get_queryable_attributes_return;
switch(header->message_type) {
case Request:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_DataModelMgr_get_queryable_attributes_view_name);
u_octet4_loop_GIAS_DataModelMgr_get_queryable_attributes_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_queryable_attributes_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_queryable_attributes_properties);
for (i_GIAS_DataModelMgr_get_queryable_attributes_properties=0; i_GIAS_DataModelMgr_get_queryable_attributes_properties < u_octet4_loop_GIAS_DataModelMgr_get_queryable_attributes_properties; i_GIAS_DataModelMgr_get_queryable_attributes_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_DataModelMgr_get_queryable_attributes_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_queryable_attributes_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_queryable_attributes_return);
for (i_GIAS_DataModelMgr_get_queryable_attributes_return=0; i_GIAS_DataModelMgr_get_queryable_attributes_return < u_octet4_loop_GIAS_DataModelMgr_get_queryable_attributes_return; i_GIAS_DataModelMgr_get_queryable_attributes_return++) {
decode_GIAS_AttributeInformation_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_DataModelMgr_get_entities(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_DataModelMgr_get_entities_properties;
guint32 i_GIAS_DataModelMgr_get_entities_properties;
switch(header->message_type) {
case Request:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_DataModelMgr_get_entities_view_name);
u_octet4_loop_GIAS_DataModelMgr_get_entities_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_entities_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_entities_properties);
for (i_GIAS_DataModelMgr_get_entities_properties=0; i_GIAS_DataModelMgr_get_entities_properties < u_octet4_loop_GIAS_DataModelMgr_get_entities_properties; i_GIAS_DataModelMgr_get_entities_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_UCO_EntityGraph_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_DataModelMgr_get_entity_attributes(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_DataModelMgr_get_entity_attributes_properties;
guint32 i_GIAS_DataModelMgr_get_entity_attributes_properties;
guint32 u_octet4_loop_GIAS_DataModelMgr_get_entity_attributes_return;
guint32 i_GIAS_DataModelMgr_get_entity_attributes_return;
switch(header->message_type) {
case Request:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_DataModelMgr_get_entity_attributes_aEntity);
u_octet4_loop_GIAS_DataModelMgr_get_entity_attributes_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_entity_attributes_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_entity_attributes_properties);
for (i_GIAS_DataModelMgr_get_entity_attributes_properties=0; i_GIAS_DataModelMgr_get_entity_attributes_properties < u_octet4_loop_GIAS_DataModelMgr_get_entity_attributes_properties; i_GIAS_DataModelMgr_get_entity_attributes_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_DataModelMgr_get_entity_attributes_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_entity_attributes_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_entity_attributes_return);
for (i_GIAS_DataModelMgr_get_entity_attributes_return=0; i_GIAS_DataModelMgr_get_entity_attributes_return < u_octet4_loop_GIAS_DataModelMgr_get_entity_attributes_return; i_GIAS_DataModelMgr_get_entity_attributes_return++) {
decode_GIAS_AttributeInformation_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_DataModelMgr_get_associations(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_DataModelMgr_get_associations_properties;
guint32 i_GIAS_DataModelMgr_get_associations_properties;
guint32 u_octet4_loop_GIAS_DataModelMgr_get_associations_return;
guint32 i_GIAS_DataModelMgr_get_associations_return;
switch(header->message_type) {
case Request:
u_octet4_loop_GIAS_DataModelMgr_get_associations_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_associations_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_associations_properties);
for (i_GIAS_DataModelMgr_get_associations_properties=0; i_GIAS_DataModelMgr_get_associations_properties < u_octet4_loop_GIAS_DataModelMgr_get_associations_properties; i_GIAS_DataModelMgr_get_associations_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_DataModelMgr_get_associations_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_associations_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_associations_return);
for (i_GIAS_DataModelMgr_get_associations_return=0; i_GIAS_DataModelMgr_get_associations_return < u_octet4_loop_GIAS_DataModelMgr_get_associations_return; i_GIAS_DataModelMgr_get_associations_return++) {
decode_GIAS_Association_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_DataModelMgr_get_max_vertices(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_DataModelMgr_get_max_vertices_properties;
guint32 i_GIAS_DataModelMgr_get_max_vertices_properties;
switch(header->message_type) {
case Request:
u_octet4_loop_GIAS_DataModelMgr_get_max_vertices_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_max_vertices_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DataModelMgr_get_max_vertices_properties);
for (i_GIAS_DataModelMgr_get_max_vertices_properties=0; i_GIAS_DataModelMgr_get_max_vertices_properties < u_octet4_loop_GIAS_DataModelMgr_get_max_vertices_properties; i_GIAS_DataModelMgr_get_max_vertices_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
proto_tree_add_uint(tree, hf_GIAS_DataModelMgr_get_max_vertices_return, tvb, *offset-2, 2, get_CDR_ushort(tvb,offset,stream_is_big_endian, boundary));
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_CreationMgr_create(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_CreationMgr_create_new_product;
guint32 i_GIAS_CreationMgr_create_new_product;
guint32 u_octet4_loop_GIAS_CreationMgr_create_related_files;
guint32 i_GIAS_CreationMgr_create_related_files;
guint32 u_octet4_loop_GIAS_CreationMgr_create_properties;
guint32 i_GIAS_CreationMgr_create_properties;
switch(header->message_type) {
case Request:
u_octet4_loop_GIAS_CreationMgr_create_new_product = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CreationMgr_create_new_product_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_CreationMgr_create_new_product);
for (i_GIAS_CreationMgr_create_new_product=0; i_GIAS_CreationMgr_create_new_product < u_octet4_loop_GIAS_CreationMgr_create_new_product; i_GIAS_CreationMgr_create_new_product++) {
decode_UCO_FileLocation_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
u_octet4_loop_GIAS_CreationMgr_create_related_files = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CreationMgr_create_related_files_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_CreationMgr_create_related_files);
for (i_GIAS_CreationMgr_create_related_files=0; i_GIAS_CreationMgr_create_related_files < u_octet4_loop_GIAS_CreationMgr_create_related_files; i_GIAS_CreationMgr_create_related_files++) {
decode_GIAS_RelatedFile_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
decode_UCO_DAG_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_CreationMgr_create_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CreationMgr_create_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_CreationMgr_create_properties);
for (i_GIAS_CreationMgr_create_properties=0; i_GIAS_CreationMgr_create_properties < u_octet4_loop_GIAS_CreationMgr_create_properties; i_GIAS_CreationMgr_create_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_CreationMgr_create_metadata(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_CreationMgr_create_metadata_related_files;
guint32 i_GIAS_CreationMgr_create_metadata_related_files;
guint32 u_octet4_loop_GIAS_CreationMgr_create_metadata_properties;
guint32 i_GIAS_CreationMgr_create_metadata_properties;
switch(header->message_type) {
case Request:
decode_UCO_DAG_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_CreationMgr_create_metadata_view_name);
u_octet4_loop_GIAS_CreationMgr_create_metadata_related_files = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CreationMgr_create_metadata_related_files_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_CreationMgr_create_metadata_related_files);
for (i_GIAS_CreationMgr_create_metadata_related_files=0; i_GIAS_CreationMgr_create_metadata_related_files < u_octet4_loop_GIAS_CreationMgr_create_metadata_related_files; i_GIAS_CreationMgr_create_metadata_related_files++) {
decode_GIAS_RelatedFile_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
u_octet4_loop_GIAS_CreationMgr_create_metadata_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CreationMgr_create_metadata_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_CreationMgr_create_metadata_properties);
for (i_GIAS_CreationMgr_create_metadata_properties=0; i_GIAS_CreationMgr_create_metadata_properties < u_octet4_loop_GIAS_CreationMgr_create_metadata_properties; i_GIAS_CreationMgr_create_metadata_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_CreationMgr_create_association(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_CreationMgr_create_association_view_b_objects;
guint32 i_GIAS_CreationMgr_create_association_view_b_objects;
guint32 u_octet4_loop_GIAS_CreationMgr_create_association_assoc_info;
guint32 i_GIAS_CreationMgr_create_association_assoc_info;
switch(header->message_type) {
case Request:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_CreationMgr_create_association_assoc_name);
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
u_octet4_loop_GIAS_CreationMgr_create_association_view_b_objects = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CreationMgr_create_association_view_b_objects_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_CreationMgr_create_association_view_b_objects);
for (i_GIAS_CreationMgr_create_association_view_b_objects=0; i_GIAS_CreationMgr_create_association_view_b_objects < u_octet4_loop_GIAS_CreationMgr_create_association_view_b_objects; i_GIAS_CreationMgr_create_association_view_b_objects++) {
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
}
u_octet4_loop_GIAS_CreationMgr_create_association_assoc_info = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CreationMgr_create_association_assoc_info_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_CreationMgr_create_association_assoc_info);
for (i_GIAS_CreationMgr_create_association_assoc_info=0; i_GIAS_CreationMgr_create_association_assoc_info < u_octet4_loop_GIAS_CreationMgr_create_association_assoc_info; i_GIAS_CreationMgr_create_association_assoc_info++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_UpdateMgr_set_lock(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_UpdateMgr_update(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_UpdateMgr_update_changes;
guint32 i_GIAS_UpdateMgr_update_changes;
guint32 u_octet4_loop_GIAS_UpdateMgr_update_relfiles;
guint32 i_GIAS_UpdateMgr_update_relfiles;
guint32 u_octet4_loop_GIAS_UpdateMgr_update_properties;
guint32 i_GIAS_UpdateMgr_update_properties;
switch(header->message_type) {
case Request:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_UpdateMgr_update_view);
u_octet4_loop_GIAS_UpdateMgr_update_changes = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_UpdateMgr_update_changes_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_UpdateMgr_update_changes);
for (i_GIAS_UpdateMgr_update_changes=0; i_GIAS_UpdateMgr_update_changes < u_octet4_loop_GIAS_UpdateMgr_update_changes; i_GIAS_UpdateMgr_update_changes++) {
decode_UCO_UpdateDAG_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
u_octet4_loop_GIAS_UpdateMgr_update_relfiles = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_UpdateMgr_update_relfiles_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_UpdateMgr_update_relfiles);
for (i_GIAS_UpdateMgr_update_relfiles=0; i_GIAS_UpdateMgr_update_relfiles < u_octet4_loop_GIAS_UpdateMgr_update_relfiles; i_GIAS_UpdateMgr_update_relfiles++) {
decode_GIAS_RelatedFile_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
u_octet4_loop_GIAS_UpdateMgr_update_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_UpdateMgr_update_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_UpdateMgr_update_properties);
for (i_GIAS_UpdateMgr_update_properties=0; i_GIAS_UpdateMgr_update_properties < u_octet4_loop_GIAS_UpdateMgr_update_properties; i_GIAS_UpdateMgr_update_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_UpdateMgr_update_by_query(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_UpdateMgr_update_by_query_properties;
guint32 i_GIAS_UpdateMgr_update_by_query_properties;
switch(header->message_type) {
case Request:
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
decode_GIAS_Query_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_UpdateMgr_update_by_query_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_UpdateMgr_update_by_query_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_UpdateMgr_update_by_query_properties);
for (i_GIAS_UpdateMgr_update_by_query_properties=0; i_GIAS_UpdateMgr_update_by_query_properties < u_octet4_loop_GIAS_UpdateMgr_update_by_query_properties; i_GIAS_UpdateMgr_update_by_query_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_UpdateMgr_release_lock(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_UpdateMgr_delete_product(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_CatalogMgr_submit_query(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_CatalogMgr_submit_query_result_attributes;
guint32 i_GIAS_CatalogMgr_submit_query_result_attributes;
guint32 u_octet4_loop_GIAS_CatalogMgr_submit_query_sort_attributes;
guint32 i_GIAS_CatalogMgr_submit_query_sort_attributes;
guint32 u_octet4_loop_GIAS_CatalogMgr_submit_query_properties;
guint32 i_GIAS_CatalogMgr_submit_query_properties;
switch(header->message_type) {
case Request:
decode_GIAS_Query_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_CatalogMgr_submit_query_result_attributes = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CatalogMgr_submit_query_result_attributes_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_CatalogMgr_submit_query_result_attributes);
for (i_GIAS_CatalogMgr_submit_query_result_attributes=0; i_GIAS_CatalogMgr_submit_query_result_attributes < u_octet4_loop_GIAS_CatalogMgr_submit_query_result_attributes; i_GIAS_CatalogMgr_submit_query_result_attributes++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_CatalogMgr_submit_query_result_attributes);
}
u_octet4_loop_GIAS_CatalogMgr_submit_query_sort_attributes = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CatalogMgr_submit_query_sort_attributes_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_CatalogMgr_submit_query_sort_attributes);
for (i_GIAS_CatalogMgr_submit_query_sort_attributes=0; i_GIAS_CatalogMgr_submit_query_sort_attributes < u_octet4_loop_GIAS_CatalogMgr_submit_query_sort_attributes; i_GIAS_CatalogMgr_submit_query_sort_attributes++) {
decode_GIAS_SortAttribute_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
u_octet4_loop_GIAS_CatalogMgr_submit_query_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CatalogMgr_submit_query_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_CatalogMgr_submit_query_properties);
for (i_GIAS_CatalogMgr_submit_query_properties=0; i_GIAS_CatalogMgr_submit_query_properties < u_octet4_loop_GIAS_CatalogMgr_submit_query_properties; i_GIAS_CatalogMgr_submit_query_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_CatalogMgr_hit_count(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_CatalogMgr_hit_count_properties;
guint32 i_GIAS_CatalogMgr_hit_count_properties;
switch(header->message_type) {
case Request:
decode_GIAS_Query_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_CatalogMgr_hit_count_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CatalogMgr_hit_count_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_CatalogMgr_hit_count_properties);
for (i_GIAS_CatalogMgr_hit_count_properties=0; i_GIAS_CatalogMgr_hit_count_properties < u_octet4_loop_GIAS_CatalogMgr_hit_count_properties; i_GIAS_CatalogMgr_hit_count_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_StandingQueryMgr_get_event_descriptions(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_StandingQueryMgr_get_event_descriptions_return;
guint32 i_GIAS_StandingQueryMgr_get_event_descriptions_return;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_StandingQueryMgr_get_event_descriptions_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_StandingQueryMgr_get_event_descriptions_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_StandingQueryMgr_get_event_descriptions_return);
for (i_GIAS_StandingQueryMgr_get_event_descriptions_return=0; i_GIAS_StandingQueryMgr_get_event_descriptions_return < u_octet4_loop_GIAS_StandingQueryMgr_get_event_descriptions_return; i_GIAS_StandingQueryMgr_get_event_descriptions_return++) {
decode_GIAS_Event_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_StandingQueryMgr_submit_standing_query(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_StandingQueryMgr_submit_standing_query_result_attributes;
guint32 i_GIAS_StandingQueryMgr_submit_standing_query_result_attributes;
guint32 u_octet4_loop_GIAS_StandingQueryMgr_submit_standing_query_sort_attributes;
guint32 i_GIAS_StandingQueryMgr_submit_standing_query_sort_attributes;
guint32 u_octet4_loop_GIAS_StandingQueryMgr_submit_standing_query_properties;
guint32 i_GIAS_StandingQueryMgr_submit_standing_query_properties;
switch(header->message_type) {
case Request:
decode_GIAS_Query_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_StandingQueryMgr_submit_standing_query_result_attributes = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_StandingQueryMgr_submit_standing_query_result_attributes_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_StandingQueryMgr_submit_standing_query_result_attributes);
for (i_GIAS_StandingQueryMgr_submit_standing_query_result_attributes=0; i_GIAS_StandingQueryMgr_submit_standing_query_result_attributes < u_octet4_loop_GIAS_StandingQueryMgr_submit_standing_query_result_attributes; i_GIAS_StandingQueryMgr_submit_standing_query_result_attributes++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_StandingQueryMgr_submit_standing_query_result_attributes);
}
u_octet4_loop_GIAS_StandingQueryMgr_submit_standing_query_sort_attributes = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_StandingQueryMgr_submit_standing_query_sort_attributes_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_StandingQueryMgr_submit_standing_query_sort_attributes);
for (i_GIAS_StandingQueryMgr_submit_standing_query_sort_attributes=0; i_GIAS_StandingQueryMgr_submit_standing_query_sort_attributes < u_octet4_loop_GIAS_StandingQueryMgr_submit_standing_query_sort_attributes; i_GIAS_StandingQueryMgr_submit_standing_query_sort_attributes++) {
decode_GIAS_SortAttribute_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
decode_GIAS_QueryLifeSpan_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_StandingQueryMgr_submit_standing_query_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_StandingQueryMgr_submit_standing_query_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_StandingQueryMgr_submit_standing_query_properties);
for (i_GIAS_StandingQueryMgr_submit_standing_query_properties=0; i_GIAS_StandingQueryMgr_submit_standing_query_properties < u_octet4_loop_GIAS_StandingQueryMgr_submit_standing_query_properties; i_GIAS_StandingQueryMgr_submit_standing_query_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_ProductMgr_get_parameters(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_ProductMgr_get_parameters_desired_parameters;
guint32 i_GIAS_ProductMgr_get_parameters_desired_parameters;
guint32 u_octet4_loop_GIAS_ProductMgr_get_parameters_properties;
guint32 i_GIAS_ProductMgr_get_parameters_properties;
switch(header->message_type) {
case Request:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
u_octet4_loop_GIAS_ProductMgr_get_parameters_desired_parameters = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_ProductMgr_get_parameters_desired_parameters_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_ProductMgr_get_parameters_desired_parameters);
for (i_GIAS_ProductMgr_get_parameters_desired_parameters=0; i_GIAS_ProductMgr_get_parameters_desired_parameters < u_octet4_loop_GIAS_ProductMgr_get_parameters_desired_parameters; i_GIAS_ProductMgr_get_parameters_desired_parameters++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_ProductMgr_get_parameters_desired_parameters);
}
u_octet4_loop_GIAS_ProductMgr_get_parameters_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_ProductMgr_get_parameters_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_ProductMgr_get_parameters_properties);
for (i_GIAS_ProductMgr_get_parameters_properties=0; i_GIAS_ProductMgr_get_parameters_properties < u_octet4_loop_GIAS_ProductMgr_get_parameters_properties; i_GIAS_ProductMgr_get_parameters_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_ProductMgr_get_related_file_types(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_ProductMgr_get_related_file_types_return;
guint32 i_GIAS_ProductMgr_get_related_file_types_return;
switch(header->message_type) {
case Request:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_GIAS_ProductMgr_get_related_file_types_return = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_ProductMgr_get_related_file_types_return_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_ProductMgr_get_related_file_types_return);
for (i_GIAS_ProductMgr_get_related_file_types_return=0; i_GIAS_ProductMgr_get_related_file_types_return < u_octet4_loop_GIAS_ProductMgr_get_related_file_types_return; i_GIAS_ProductMgr_get_related_file_types_return++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_ProductMgr_get_related_file_types_return);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_ProductMgr_get_related_files(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_ProductMgr_get_related_files_products;
guint32 i_GIAS_ProductMgr_get_related_files_products;
guint32 u_octet4_loop_GIAS_ProductMgr_get_related_files_properties;
guint32 i_GIAS_ProductMgr_get_related_files_properties;
switch(header->message_type) {
case Request:
u_octet4_loop_GIAS_ProductMgr_get_related_files_products = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_ProductMgr_get_related_files_products_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_ProductMgr_get_related_files_products);
for (i_GIAS_ProductMgr_get_related_files_products=0; i_GIAS_ProductMgr_get_related_files_products < u_octet4_loop_GIAS_ProductMgr_get_related_files_products; i_GIAS_ProductMgr_get_related_files_products++) {
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
}
decode_UCO_FileLocation_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_ProductMgr_get_related_files_type);
u_octet4_loop_GIAS_ProductMgr_get_related_files_properties = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_ProductMgr_get_related_files_properties_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_ProductMgr_get_related_files_properties);
for (i_GIAS_ProductMgr_get_related_files_properties=0; i_GIAS_ProductMgr_get_related_files_properties < u_octet4_loop_GIAS_ProductMgr_get_related_files_properties; i_GIAS_ProductMgr_get_related_files_properties++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_IngestMgr_bulk_pull(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_IngestMgr_bulk_pull_property_list;
guint32 i_GIAS_IngestMgr_bulk_pull_property_list;
switch(header->message_type) {
case Request:
decode_UCO_FileLocation_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_IngestMgr_bulk_pull_property_list = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_IngestMgr_bulk_pull_property_list_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_IngestMgr_bulk_pull_property_list);
for (i_GIAS_IngestMgr_bulk_pull_property_list=0; i_GIAS_IngestMgr_bulk_pull_property_list < u_octet4_loop_GIAS_IngestMgr_bulk_pull_property_list; i_GIAS_IngestMgr_bulk_pull_property_list++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_IngestMgr_bulk_push(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_IngestMgr_bulk_push_property_list;
guint32 i_GIAS_IngestMgr_bulk_push_property_list;
switch(header->message_type) {
case Request:
decode_GIAS_Query_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
decode_UCO_FileLocation_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_IngestMgr_bulk_push_property_list = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_IngestMgr_bulk_push_property_list_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_IngestMgr_bulk_push_property_list);
for (i_GIAS_IngestMgr_bulk_push_property_list=0; i_GIAS_IngestMgr_bulk_push_property_list < u_octet4_loop_GIAS_IngestMgr_bulk_push_property_list; i_GIAS_IngestMgr_bulk_push_property_list++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_Request_get_request_description(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_UCO_RequestDescription_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_Request_set_user_info(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Request_set_user_info_message);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_Request_get_status(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_UCO_Status_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_Request_get_remaining_delay(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_GIAS_DelayEstimate_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_Request_cancel(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_Request_register_callback(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Request_register_callback_return);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_Request_free_callback(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Request_free_callback_id);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_Request_get_request_manager(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_OrderRequest_complete(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_OrderRequest_complete_return, tvb, *offset-4, 4, u_octet4);
decode_GIAS_DeliveryManifest_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitQueryOrderRequest_pause(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitQueryOrderRequest_resume(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitQueryOrderRequest_complete_list(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
guint32 u_octet4_loop_GIAS_SubmitQueryOrderRequest_complete_list_prods;
guint32 i_GIAS_SubmitQueryOrderRequest_complete_list_prods;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitQueryOrderRequest_complete_list_return, tvb, *offset-4, 4, u_octet4);
u_octet4_loop_GIAS_SubmitQueryOrderRequest_complete_list_prods = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitQueryOrderRequest_complete_list_prods_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_SubmitQueryOrderRequest_complete_list_prods);
for (i_GIAS_SubmitQueryOrderRequest_complete_list_prods=0; i_GIAS_SubmitQueryOrderRequest_complete_list_prods < u_octet4_loop_GIAS_SubmitQueryOrderRequest_complete_list_prods; i_GIAS_SubmitQueryOrderRequest_complete_list_prods++) {
decode_GIAS_DeliveryManifest_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitQueryOrderRequest_complete(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitQueryOrderRequest_complete_return, tvb, *offset-4, 4, u_octet4);
decode_GIAS_DeliveryManifest_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_CreateRequest_complete(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
guint32 u_octet4_loop_GIAS_CreateRequest_complete_new_products;
guint32 i_GIAS_CreateRequest_complete_new_products;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CreateRequest_complete_return, tvb, *offset-4, 4, u_octet4);
u_octet4_loop_GIAS_CreateRequest_complete_new_products = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CreateRequest_complete_new_products_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_CreateRequest_complete_new_products);
for (i_GIAS_CreateRequest_complete_new_products=0; i_GIAS_CreateRequest_complete_new_products < u_octet4_loop_GIAS_CreateRequest_complete_new_products; i_GIAS_CreateRequest_complete_new_products++) {
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_CreateMetaDataRequest_complete(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CreateMetaDataRequest_complete_return, tvb, *offset-4, 4, u_octet4);
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_UpdateRequest_complete(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_UpdateRequest_complete_return, tvb, *offset-4, 4, u_octet4);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitQueryRequest_set_number_of_hits(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
proto_tree_add_uint(tree, hf_GIAS_SubmitQueryRequest_set_number_of_hits_hits, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitQueryRequest_complete_DAG_results(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
guint32 u_octet4_loop_GIAS_SubmitQueryRequest_complete_DAG_results_results;
guint32 i_GIAS_SubmitQueryRequest_complete_DAG_results_results;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitQueryRequest_complete_DAG_results_return, tvb, *offset-4, 4, u_octet4);
u_octet4_loop_GIAS_SubmitQueryRequest_complete_DAG_results_results = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitQueryRequest_complete_DAG_results_results_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_SubmitQueryRequest_complete_DAG_results_results);
for (i_GIAS_SubmitQueryRequest_complete_DAG_results_results=0; i_GIAS_SubmitQueryRequest_complete_DAG_results_results < u_octet4_loop_GIAS_SubmitQueryRequest_complete_DAG_results_results; i_GIAS_SubmitQueryRequest_complete_DAG_results_results++) {
decode_UCO_DAG_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitQueryRequest_complete_stringDAG_results(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
guint32 u_octet4_loop_GIAS_SubmitQueryRequest_complete_stringDAG_results_results;
guint32 i_GIAS_SubmitQueryRequest_complete_stringDAG_results_results;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitQueryRequest_complete_stringDAG_results_return, tvb, *offset-4, 4, u_octet4);
u_octet4_loop_GIAS_SubmitQueryRequest_complete_stringDAG_results_results = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitQueryRequest_complete_stringDAG_results_results_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_SubmitQueryRequest_complete_stringDAG_results_results);
for (i_GIAS_SubmitQueryRequest_complete_stringDAG_results_results=0; i_GIAS_SubmitQueryRequest_complete_stringDAG_results_results < u_octet4_loop_GIAS_SubmitQueryRequest_complete_stringDAG_results_results; i_GIAS_SubmitQueryRequest_complete_stringDAG_results_results++) {
decode_UCO_StringDAG_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitQueryRequest_complete_XML_results(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitQueryRequest_complete_XML_results_return, tvb, *offset-4, 4, u_octet4);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_SubmitQueryRequest_complete_XML_results_results);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_set_number_of_hits(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
proto_tree_add_uint(tree, hf_GIAS_SubmitStandingQueryRequest_set_number_of_hits_hits, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_get_number_of_hits(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
proto_tree_add_uint(tree, hf_GIAS_SubmitStandingQueryRequest_get_number_of_hits_return, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_get_number_of_hits_in_interval(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
proto_tree_add_uint(tree, hf_GIAS_SubmitStandingQueryRequest_get_number_of_hits_in_interval_interval, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
proto_tree_add_uint(tree, hf_GIAS_SubmitStandingQueryRequest_get_number_of_hits_in_interval_return, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_get_number_of_intervals(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
proto_tree_add_uint(tree, hf_GIAS_SubmitStandingQueryRequest_get_number_of_intervals_return, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_clear_all(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_clear_intervals(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
proto_tree_add_uint(tree, hf_GIAS_SubmitStandingQueryRequest_clear_intervals_num_intervals, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_clear_before(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
decode_UCO_Time_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_pause(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_resume(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
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
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_get_time_last_executed(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_UCO_AbsTime_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_get_time_next_execution(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_UCO_AbsTime_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_complete_DAG_results(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
guint32 u_octet4_loop_GIAS_SubmitStandingQueryRequest_complete_DAG_results_results;
guint32 i_GIAS_SubmitStandingQueryRequest_complete_DAG_results_results;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitStandingQueryRequest_complete_DAG_results_return, tvb, *offset-4, 4, u_octet4);
u_octet4_loop_GIAS_SubmitStandingQueryRequest_complete_DAG_results_results = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitStandingQueryRequest_complete_DAG_results_results_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_SubmitStandingQueryRequest_complete_DAG_results_results);
for (i_GIAS_SubmitStandingQueryRequest_complete_DAG_results_results=0; i_GIAS_SubmitStandingQueryRequest_complete_DAG_results_results < u_octet4_loop_GIAS_SubmitStandingQueryRequest_complete_DAG_results_results; i_GIAS_SubmitStandingQueryRequest_complete_DAG_results_results++) {
decode_UCO_DAG_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
guint32 u_octet4_loop_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results_results;
guint32 i_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results_results;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results_return, tvb, *offset-4, 4, u_octet4);
u_octet4_loop_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results_results = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results_results_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results_results);
for (i_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results_results=0; i_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results_results < u_octet4_loop_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results_results; i_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results_results++) {
decode_UCO_StringDAG_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SubmitStandingQueryRequest_complete_XML_results(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SubmitStandingQueryRequest_complete_XML_results_return, tvb, *offset-4, 4, u_octet4);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_SubmitStandingQueryRequest_complete_XML_results_results);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_SetAvailabilityRequest_complete(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SetAvailabilityRequest_complete_return, tvb, *offset-4, 4, u_octet4);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_HitCountRequest_complete(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_HitCountRequest_complete_return, tvb, *offset-4, 4, u_octet4);
proto_tree_add_uint(tree, hf_GIAS_HitCountRequest_complete_number_of_hits, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_GetParametersRequest_complete(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_GetParametersRequest_complete_return, tvb, *offset-4, 4, u_octet4);
decode_UCO_DAG_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_GetParametersRequest_complete_StringDAG(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_GetParametersRequest_complete_StringDAG_return, tvb, *offset-4, 4, u_octet4);
decode_UCO_StringDAG_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_IngestRequest_complete(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_IngestRequest_complete_return, tvb, *offset-4, 4, u_octet4);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_GetRelatedFilesRequest_complete(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
guint32 u_octet4_loop_GIAS_GetRelatedFilesRequest_complete_locations;
guint32 i_GIAS_GetRelatedFilesRequest_complete_locations;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_GetRelatedFilesRequest_complete_return, tvb, *offset-4, 4, u_octet4);
u_octet4_loop_GIAS_GetRelatedFilesRequest_complete_locations = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_GetRelatedFilesRequest_complete_locations_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_GetRelatedFilesRequest_complete_locations);
for (i_GIAS_GetRelatedFilesRequest_complete_locations=0; i_GIAS_GetRelatedFilesRequest_complete_locations < u_octet4_loop_GIAS_GetRelatedFilesRequest_complete_locations; i_GIAS_GetRelatedFilesRequest_complete_locations++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_GetRelatedFilesRequest_complete_locations);
}
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_CreateAssociationRequest_complete(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_CreateAssociationRequest_complete_return, tvb, *offset-4, 4, u_octet4);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_GIAS_UpdateByQueryRequest_complete(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_UpdateByQueryRequest_complete_return, tvb, *offset-4, 4, u_octet4);
break;
case USER_EXCEPTION:
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_exception, "Unknown exception %d", header->rep_status);
break;
}
break;
default:
expert_add_info_format(pinfo, item, &ei_gias_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
break;
}
}
static void
decode_UCO_NameName_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_NameName_name1);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_NameName_name2);
}
static void
decode_UCO_NameValue_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_NameValue_aname);
get_CDR_any(tvb, pinfo, tree, item, offset, stream_is_big_endian, boundary, header);
}
static void
decode_UCO_Ratio_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_double(tree, hf_UCO_Ratio_numerator, tvb, *offset-8, 8, get_CDR_double(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_double(tree, hf_UCO_Ratio_denominator, tvb, *offset-8, 8, get_CDR_double(tvb,offset,stream_is_big_endian, boundary));
}
static void
decode_UCO_FileLocation_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_FileLocation_user_name);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_FileLocation_password);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_FileLocation_host_name);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_FileLocation_path_name);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_FileLocation_file_name);
}
static void
decode_UCO_DirectAccessLocation_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_DirectAccessLocation_access_protocol, tvb, *offset-4, 4, u_octet4);
decode_UCO_FileLocation_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
static void
decode_UCO_Date_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_uint(tree, hf_UCO_Date_year, tvb, *offset-2, 2, get_CDR_ushort(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_uint(tree, hf_UCO_Date_month, tvb, *offset-2, 2, get_CDR_ushort(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_uint(tree, hf_UCO_Date_day, tvb, *offset-2, 2, get_CDR_ushort(tvb,offset,stream_is_big_endian, boundary));
}
static void
decode_UCO_Time_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_uint(tree, hf_UCO_Time_hour, tvb, *offset-2, 2, get_CDR_ushort(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_uint(tree, hf_UCO_Time_minute, tvb, *offset-2, 2, get_CDR_ushort(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_float(tree, hf_UCO_Time_second, tvb, *offset-4, 4, get_CDR_float(tvb,offset,stream_is_big_endian, boundary));
}
static void
decode_UCO_AbsTime_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
decode_UCO_Date_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
decode_UCO_Time_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
static void
decode_UCO_Node_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
proto_tree_add_uint(tree, hf_UCO_Node_id, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_Node_node_type, tvb, *offset-4, 4, u_octet4);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_Node_attribute_name);
get_CDR_any(tvb, pinfo, tree, item, offset, stream_is_big_endian, boundary, header);
}
static void
decode_UCO_Edge_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_uint(tree, hf_UCO_Edge_start_node, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_uint(tree, hf_UCO_Edge_end_node, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_Edge_relationship_type);
}
static void
decode_UCO_DAG_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_UCO_DAG_nodes;
guint32 i_UCO_DAG_nodes;
guint32 u_octet4_loop_UCO_DAG_edges;
guint32 i_UCO_DAG_edges;
u_octet4_loop_UCO_DAG_nodes = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_DAG_nodes_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_DAG_nodes);
for (i_UCO_DAG_nodes=0; i_UCO_DAG_nodes < u_octet4_loop_UCO_DAG_nodes; i_UCO_DAG_nodes++) {
decode_UCO_Node_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
u_octet4_loop_UCO_DAG_edges = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_DAG_edges_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_DAG_edges);
for (i_UCO_DAG_edges=0; i_UCO_DAG_edges < u_octet4_loop_UCO_DAG_edges; i_UCO_DAG_edges++) {
decode_UCO_Edge_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
}
static void
decode_UCO_StringNode_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
proto_tree_add_uint(tree, hf_UCO_StringNode_id, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_StringNode_node_type, tvb, *offset-4, 4, u_octet4);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_StringNode_attribute_name);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_StringNode_value);
}
static void
decode_UCO_StringDAG_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_UCO_StringDAG_nodes;
guint32 i_UCO_StringDAG_nodes;
guint32 u_octet4_loop_UCO_StringDAG_edges;
guint32 i_UCO_StringDAG_edges;
get_CDR_any(tvb, pinfo, tree, item, offset, stream_is_big_endian, boundary, header);
u_octet4_loop_UCO_StringDAG_nodes = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_StringDAG_nodes_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_StringDAG_nodes);
for (i_UCO_StringDAG_nodes=0; i_UCO_StringDAG_nodes < u_octet4_loop_UCO_StringDAG_nodes; i_UCO_StringDAG_nodes++) {
decode_UCO_StringNode_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
u_octet4_loop_UCO_StringDAG_edges = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_StringDAG_edges_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_StringDAG_edges);
for (i_UCO_StringDAG_edges=0; i_UCO_StringDAG_edges < u_octet4_loop_UCO_StringDAG_edges; i_UCO_StringDAG_edges++) {
decode_UCO_Edge_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
}
static void
decode_UCO_Change_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
proto_tree_add_uint(tree, hf_UCO_Change_changed_node, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_Change_change_type, tvb, *offset-4, 4, u_octet4);
}
static void
decode_UCO_UpdateDAG_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_UCO_UpdateDAG_changes;
guint32 i_UCO_UpdateDAG_changes;
decode_UCO_DAG_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_UCO_UpdateDAG_changes = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_UpdateDAG_changes_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_UpdateDAG_changes);
for (i_UCO_UpdateDAG_changes=0; i_UCO_UpdateDAG_changes < u_octet4_loop_UCO_UpdateDAG_changes; i_UCO_UpdateDAG_changes++) {
decode_UCO_Change_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
}
static void
decode_UCO_RequestDescription_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_UCO_RequestDescription_request_details;
guint32 i_UCO_RequestDescription_request_details;
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_RequestDescription_user_info);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_RequestDescription_request_type);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_RequestDescription_request_info);
u_octet4_loop_UCO_RequestDescription_request_details = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_RequestDescription_request_details_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_RequestDescription_request_details);
for (i_UCO_RequestDescription_request_details=0; i_UCO_RequestDescription_request_details < u_octet4_loop_UCO_RequestDescription_request_details; i_UCO_RequestDescription_request_details++) {
decode_UCO_NameValue_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
}
static void
decode_UCO_Coordinate2d_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_double(tree, hf_UCO_Coordinate2d_x, tvb, *offset-8, 8, get_CDR_double(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_double(tree, hf_UCO_Coordinate2d_y, tvb, *offset-8, 8, get_CDR_double(tvb,offset,stream_is_big_endian, boundary));
}
static void
decode_UCO_Coordinate3d_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_double(tree, hf_UCO_Coordinate3d_x, tvb, *offset-8, 8, get_CDR_double(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_double(tree, hf_UCO_Coordinate3d_y, tvb, *offset-8, 8, get_CDR_double(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_double(tree, hf_UCO_Coordinate3d_z, tvb, *offset-8, 8, get_CDR_double(tvb,offset,stream_is_big_endian, boundary));
}
static void
decode_UCO_LinearDimension_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_double(tree, hf_UCO_LinearDimension_dimension, tvb, *offset-8, 8, get_CDR_double(tvb,offset,stream_is_big_endian, boundary));
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_LinearDimension_reference_system);
}
static void
decode_UCO_Circle_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
decode_UCO_Coordinate2d_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
decode_UCO_LinearDimension_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
static void
decode_UCO_Ellipse_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
decode_UCO_Coordinate2d_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
decode_UCO_LinearDimension_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
decode_UCO_LinearDimension_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
proto_tree_add_double(tree, hf_UCO_Ellipse_north_angle, tvb, *offset-8, 8, get_CDR_double(tvb,offset,stream_is_big_endian, boundary));
}
static void
decode_UCO_Rectangle_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
decode_UCO_Coordinate2d_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
decode_UCO_Coordinate2d_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
static void
decode_UCO_SimpleGSImage_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_uint(tree, hf_UCO_SimpleGSImage_width, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_uint(tree, hf_UCO_SimpleGSImage_height, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
decode_UCO_Buffer_un(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
static void
decode_UCO_SimpleCImage_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_uint(tree, hf_UCO_SimpleCImage_width, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_uint(tree, hf_UCO_SimpleCImage_height, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
decode_UCO_Buffer_un(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
decode_UCO_Buffer_un(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
decode_UCO_Buffer_un(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
static void
decode_UCO_CompressedImage_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_UCO_CompressedImage_data;
const gchar * binary_seq_UCO_CompressedImage_data;
gchar * text_seq_UCO_CompressedImage_data;
proto_tree_add_uint(tree, hf_UCO_CompressedImage_width, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_uint(tree, hf_UCO_CompressedImage_height, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_CompressedImage_compression_form);
u_octet4_loop_UCO_CompressedImage_data = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_CompressedImage_data_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_CompressedImage_data);
if (u_octet4_loop_UCO_CompressedImage_data > 0 && tree) {
get_CDR_octet_seq(tvb, &binary_seq_UCO_CompressedImage_data, offset,
u_octet4_loop_UCO_CompressedImage_data);
text_seq_UCO_CompressedImage_data = make_printable_string(binary_seq_UCO_CompressedImage_data,
u_octet4_loop_UCO_CompressedImage_data);
proto_tree_add_bytes_format_value(tree, hf_UCO_CompressedImage_data, tvb, *offset - u_octet4_loop_UCO_CompressedImage_data,
u_octet4_loop_UCO_CompressedImage_data, binary_seq_UCO_CompressedImage_data, "%s", text_seq_UCO_CompressedImage_data);
}
}
static void
decode_UCO_Status_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_Status_completion_state, tvb, *offset-4, 4, u_octet4);
proto_tree_add_boolean(tree, hf_UCO_Status_warning, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_Status_status_message);
}
static void
decode_UCO_EntityNode_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_uint(tree, hf_UCO_EntityNode_id, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_EntityNode_entity_name);
}
static void
decode_UCO_EntityRelationship_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
proto_tree_add_uint(tree, hf_UCO_EntityRelationship_start_node, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_uint(tree, hf_UCO_EntityRelationship_end_node, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_EntityRelationship_start_to_end_card, tvb, *offset-4, 4, u_octet4);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_EntityRelationship_end_to_start_card, tvb, *offset-4, 4, u_octet4);
}
static void
decode_UCO_EntityGraph_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_UCO_EntityGraph_nodes;
guint32 i_UCO_EntityGraph_nodes;
guint32 u_octet4_loop_UCO_EntityGraph_relationship;
guint32 i_UCO_EntityGraph_relationship;
u_octet4_loop_UCO_EntityGraph_nodes = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_EntityGraph_nodes_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_EntityGraph_nodes);
for (i_UCO_EntityGraph_nodes=0; i_UCO_EntityGraph_nodes < u_octet4_loop_UCO_EntityGraph_nodes; i_UCO_EntityGraph_nodes++) {
decode_UCO_EntityNode_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
u_octet4_loop_UCO_EntityGraph_relationship = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_EntityGraph_relationship_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_EntityGraph_relationship);
for (i_UCO_EntityGraph_relationship=0; i_UCO_EntityGraph_relationship < u_octet4_loop_UCO_EntityGraph_relationship; i_UCO_EntityGraph_relationship++) {
decode_UCO_EntityRelationship_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
}
static void
decode_UCO_exception_details_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_exception_details_exception_name);
proto_tree_add_boolean(tree, hf_UCO_exception_details_standard_exception_name, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_UCO_exception_details_exception_desc);
}
static void
decode_GIAS_ImageSpec_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_ImageSpec_rrds;
guint32 i_GIAS_ImageSpec_rrds;
guint32 u_octet4;
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_ImageSpec_imgform);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_ImageSpec_imageid);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_ImageSpec_comp);
proto_tree_add_int(tree, hf_GIAS_ImageSpec_bpp, tvb, *offset-2, 2, get_CDR_short(tvb,offset,stream_is_big_endian, boundary));
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_ImageSpec_algo);
u_octet4_loop_GIAS_ImageSpec_rrds = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_ImageSpec_rrds_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_ImageSpec_rrds);
for (i_GIAS_ImageSpec_rrds=0; i_GIAS_ImageSpec_rrds < u_octet4_loop_GIAS_ImageSpec_rrds; i_GIAS_ImageSpec_rrds++) {
proto_tree_add_int(tree, hf_GIAS_ImageSpec_rrds, tvb, *offset-2, 2, get_CDR_short(tvb,offset,stream_is_big_endian, boundary));
}
decode_UCO_Rectangle_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_ImageSpec_geo_region_type, tvb, *offset-4, 4, u_octet4);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_ImageSpec_encoding, tvb, *offset-4, 4, u_octet4);
}
static void
decode_GIAS_AlterationSpec_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_AlterationSpec_pf);
get_CDR_any(tvb, pinfo, tree, item, offset, stream_is_big_endian, boundary, header);
decode_UCO_Rectangle_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_AlterationSpec_geo_region_type, tvb, *offset-4, 4, u_octet4);
}
static void
decode_GIAS_PackagingSpec_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_PackagingSpec_package_identifier);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_PackagingSpec_packaging_format_and_compression);
}
static void
decode_GIAS_TailoringSpec_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_TailoringSpec_specs;
guint32 i_GIAS_TailoringSpec_specs;
u_octet4_loop_GIAS_TailoringSpec_specs = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_TailoringSpec_specs_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_TailoringSpec_specs);
for (i_GIAS_TailoringSpec_specs=0; i_GIAS_TailoringSpec_specs < u_octet4_loop_GIAS_TailoringSpec_specs; i_GIAS_TailoringSpec_specs++) {
decode_UCO_NameName_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
}
static void
decode_GIAS_MediaType_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_MediaType_media_type);
proto_tree_add_uint(tree, hf_GIAS_MediaType_quantity, tvb, *offset-2, 2, get_CDR_ushort(tvb,offset,stream_is_big_endian, boundary));
}
static void
decode_GIAS_PhysicalDelivery_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_PhysicalDelivery_address);
}
static void
decode_GIAS_ValidationResults_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_boolean(tree, hf_GIAS_ValidationResults_valid, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
proto_tree_add_boolean(tree, hf_GIAS_ValidationResults_warning, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_ValidationResults_details);
}
static void
decode_GIAS_RelatedFile_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_RelatedFile_file_type);
decode_UCO_FileLocation_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
static void
decode_GIAS_View_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_View_sub_views;
guint32 i_GIAS_View_sub_views;
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_View_view_name);
proto_tree_add_boolean(tree, hf_GIAS_View_orderable, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
u_octet4_loop_GIAS_View_sub_views = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_View_sub_views_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_View_sub_views);
for (i_GIAS_View_sub_views=0; i_GIAS_View_sub_views < u_octet4_loop_GIAS_View_sub_views; i_GIAS_View_sub_views++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_View_sub_views);
}
}
static void
decode_GIAS_DateRange_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
decode_UCO_AbsTime_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
decode_UCO_AbsTime_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
static void
decode_GIAS_IntegerRange_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_int(tree, hf_GIAS_IntegerRange_lower_bound, tvb, *offset-4, 4, get_CDR_long(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_int(tree, hf_GIAS_IntegerRange_upper_bound, tvb, *offset-4, 4, get_CDR_long(tvb,offset,stream_is_big_endian, boundary));
}
static void
decode_GIAS_FloatingPointRange_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_double(tree, hf_GIAS_FloatingPointRange_lower_bound, tvb, *offset-8, 8, get_CDR_double(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_double(tree, hf_GIAS_FloatingPointRange_upper_bound, tvb, *offset-8, 8, get_CDR_double(tvb,offset,stream_is_big_endian, boundary));
}
static void
decode_GIAS_AttributeInformation_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_AttributeInformation_attribute_name);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_AttributeInformation_attribute_type, tvb, *offset-4, 4, u_octet4);
decode_GIAS_Domain_un(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_AttributeInformation_attribute_units);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_AttributeInformation_attribute_reference);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_AttributeInformation_mode, tvb, *offset-4, 4, u_octet4);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_AttributeInformation_description);
proto_tree_add_boolean(tree, hf_GIAS_AttributeInformation_sortable, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
proto_tree_add_boolean(tree, hf_GIAS_AttributeInformation_updateable, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
}
static void
decode_GIAS_Association_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
guint32 u_octet4_loop_GIAS_Association_attribute_info;
guint32 i_GIAS_Association_attribute_info;
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Association_name);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Association_view_a);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Association_view_b);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Association_description);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Association_card, tvb, *offset-4, 4, u_octet4);
u_octet4_loop_GIAS_Association_attribute_info = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Association_attribute_info_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_Association_attribute_info);
for (i_GIAS_Association_attribute_info=0; i_GIAS_Association_attribute_info < u_octet4_loop_GIAS_Association_attribute_info; i_GIAS_Association_attribute_info++) {
decode_GIAS_AttributeInformation_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
}
static void
decode_GIAS_LibraryDescription_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_LibraryDescription_library_name);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_LibraryDescription_library_description);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_LibraryDescription_library_version_number);
}
static void
decode_GIAS_Query_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Query_view);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Query_bqs_query);
}
static void
decode_GIAS_Event_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Event_event_name);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Event_event_type, tvb, *offset-4, 4, u_octet4);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Event_event_description);
}
static void
decode_GIAS_DayEventTime_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DayEventTime_day_event, tvb, *offset-4, 4, u_octet4);
decode_UCO_Time_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
static void
decode_GIAS_QueryLifeSpan_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_QueryLifeSpan_frequency;
guint32 i_GIAS_QueryLifeSpan_frequency;
decode_GIAS_LifeEvent_un(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
decode_GIAS_LifeEvent_un(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_QueryLifeSpan_frequency = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_QueryLifeSpan_frequency_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_QueryLifeSpan_frequency);
for (i_GIAS_QueryLifeSpan_frequency=0; i_GIAS_QueryLifeSpan_frequency < u_octet4_loop_GIAS_QueryLifeSpan_frequency; i_GIAS_QueryLifeSpan_frequency++) {
decode_GIAS_LifeEvent_un(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
}
static void
decode_GIAS_SortAttribute_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_SortAttribute_attribute_name);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_SortAttribute_sort_polarity, tvb, *offset-4, 4, u_octet4);
}
static void
decode_GIAS_DelayEstimate_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_tree_add_uint(tree, hf_GIAS_DelayEstimate_time_delay, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
proto_tree_add_boolean(tree, hf_GIAS_DelayEstimate_valid_time_delay, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
}
static void
decode_GIAS_ProductDetails_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_ProductDetails_mTypes;
guint32 i_GIAS_ProductDetails_mTypes;
guint32 u_octet4_loop_GIAS_ProductDetails_benums;
guint32 i_GIAS_ProductDetails_benums;
u_octet4_loop_GIAS_ProductDetails_mTypes = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_ProductDetails_mTypes_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_ProductDetails_mTypes);
for (i_GIAS_ProductDetails_mTypes=0; i_GIAS_ProductDetails_mTypes < u_octet4_loop_GIAS_ProductDetails_mTypes; i_GIAS_ProductDetails_mTypes++) {
decode_GIAS_MediaType_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
u_octet4_loop_GIAS_ProductDetails_benums = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_ProductDetails_benums_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_ProductDetails_benums);
for (i_GIAS_ProductDetails_benums=0; i_GIAS_ProductDetails_benums < u_octet4_loop_GIAS_ProductDetails_benums; i_GIAS_ProductDetails_benums++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_ProductDetails_benums);
}
decode_GIAS_AlterationSpec_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_ProductDetails_info_system_name);
}
static void
decode_GIAS_DeliveryDetails_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
decode_GIAS_Destination_un(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_DeliveryDetails_receiver);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_DeliveryDetails_shipmentMode);
}
static void
decode_GIAS_OrderContents_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_OrderContents_prod_list;
guint32 i_GIAS_OrderContents_prod_list;
guint32 u_octet4_loop_GIAS_OrderContents_del_list;
guint32 i_GIAS_OrderContents_del_list;
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_OrderContents_originator);
decode_GIAS_TailoringSpec_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
decode_GIAS_PackagingSpec_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
decode_UCO_AbsTime_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_OrderContents_operatorNote);
proto_tree_add_int(tree, hf_GIAS_OrderContents_orderPriority, tvb, *offset-2, 2, get_CDR_short(tvb,offset,stream_is_big_endian, boundary));
u_octet4_loop_GIAS_OrderContents_prod_list = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_OrderContents_prod_list_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_OrderContents_prod_list);
for (i_GIAS_OrderContents_prod_list=0; i_GIAS_OrderContents_prod_list < u_octet4_loop_GIAS_OrderContents_prod_list; i_GIAS_OrderContents_prod_list++) {
decode_GIAS_ProductDetails_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
u_octet4_loop_GIAS_OrderContents_del_list = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_OrderContents_del_list_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_OrderContents_del_list);
for (i_GIAS_OrderContents_del_list=0; i_GIAS_OrderContents_del_list < u_octet4_loop_GIAS_OrderContents_del_list; i_GIAS_OrderContents_del_list++) {
decode_GIAS_DeliveryDetails_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
}
static void
decode_GIAS_QueryOrderContents_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_QueryOrderContents_del_list;
guint32 i_GIAS_QueryOrderContents_del_list;
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_QueryOrderContents_originator);
decode_GIAS_TailoringSpec_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
decode_GIAS_PackagingSpec_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_QueryOrderContents_operatorNote);
proto_tree_add_int(tree, hf_GIAS_QueryOrderContents_orderPriority, tvb, *offset-2, 2, get_CDR_short(tvb,offset,stream_is_big_endian, boundary));
decode_GIAS_AlterationSpec_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
u_octet4_loop_GIAS_QueryOrderContents_del_list = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_QueryOrderContents_del_list_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_QueryOrderContents_del_list);
for (i_GIAS_QueryOrderContents_del_list=0; i_GIAS_QueryOrderContents_del_list < u_octet4_loop_GIAS_QueryOrderContents_del_list; i_GIAS_QueryOrderContents_del_list++) {
decode_GIAS_DeliveryDetails_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
}
static void
decode_GIAS_AccessCriteria_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_AccessCriteria_userID);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_AccessCriteria_password);
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_AccessCriteria_licenseKey);
}
static void
decode_GIAS_PackageElement_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_PackageElement_files;
guint32 i_GIAS_PackageElement_files;
get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);
u_octet4_loop_GIAS_PackageElement_files = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_PackageElement_files_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_PackageElement_files);
for (i_GIAS_PackageElement_files=0; i_GIAS_PackageElement_files < u_octet4_loop_GIAS_PackageElement_files; i_GIAS_PackageElement_files++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_PackageElement_files);
}
}
static void
decode_GIAS_DeliveryManifest_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4_loop_GIAS_DeliveryManifest_elements;
guint32 i_GIAS_DeliveryManifest_elements;
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_DeliveryManifest_package_name);
u_octet4_loop_GIAS_DeliveryManifest_elements = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_DeliveryManifest_elements_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_DeliveryManifest_elements);
for (i_GIAS_DeliveryManifest_elements=0; i_GIAS_DeliveryManifest_elements < u_octet4_loop_GIAS_DeliveryManifest_elements; i_GIAS_DeliveryManifest_elements++) {
decode_GIAS_PackageElement_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
}
static void
decode_UCO_Buffer_un(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
guint32 u_octet4;
gint32 disc_s_Buffer;
guint32 u_octet4_loop_UCO_Buffer_octet_buffer;
const gchar * binary_seq_UCO_Buffer_octet_buffer;
gchar * text_seq_UCO_Buffer_octet_buffer;
guint32 u_octet4_loop_UCO_Buffer_char_buffer;
guint32 i_UCO_Buffer_char_buffer;
guint32 u_octet4_loop_UCO_Buffer_ushort_buffer;
guint32 i_UCO_Buffer_ushort_buffer;
guint32 u_octet4_loop_UCO_Buffer_short_buffer;
guint32 i_UCO_Buffer_short_buffer;
guint32 u_octet4_loop_UCO_Buffer_ulong_buffer;
guint32 i_UCO_Buffer_ulong_buffer;
guint32 u_octet4_loop_UCO_Buffer_long_buffer;
guint32 i_UCO_Buffer_long_buffer;
guint32 u_octet4_loop_UCO_Buffer_float_buffer;
guint32 i_UCO_Buffer_float_buffer;
guint32 u_octet4_loop_UCO_Buffer_double_buffer;
guint32 i_UCO_Buffer_double_buffer;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_Buffer_Buffer, tvb, *offset-4, 4, u_octet4);
disc_s_Buffer = (gint32) u_octet4;
if (disc_s_Buffer == 0 ) {
u_octet4_loop_UCO_Buffer_octet_buffer = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_Buffer_octet_buffer_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_Buffer_octet_buffer);
if (u_octet4_loop_UCO_Buffer_octet_buffer > 0 && tree) {
get_CDR_octet_seq(tvb, &binary_seq_UCO_Buffer_octet_buffer, offset,
u_octet4_loop_UCO_Buffer_octet_buffer);
text_seq_UCO_Buffer_octet_buffer = make_printable_string(binary_seq_UCO_Buffer_octet_buffer,
u_octet4_loop_UCO_Buffer_octet_buffer);
proto_tree_add_bytes_format_value(tree, hf_UCO_Buffer_octet_buffer, tvb, *offset - u_octet4_loop_UCO_Buffer_octet_buffer,
u_octet4_loop_UCO_Buffer_octet_buffer, binary_seq_UCO_Buffer_octet_buffer, "%s", text_seq_UCO_Buffer_octet_buffer);
}
return;
}
if (disc_s_Buffer == 1 ) {
u_octet4_loop_UCO_Buffer_char_buffer = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_Buffer_char_buffer_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_Buffer_char_buffer);
for (i_UCO_Buffer_char_buffer=0; i_UCO_Buffer_char_buffer < u_octet4_loop_UCO_Buffer_char_buffer; i_UCO_Buffer_char_buffer++) {
proto_tree_add_uint(tree, hf_UCO_Buffer_char_buffer, tvb, *offset-1, 1, get_CDR_char(tvb,offset));
}
return;
}
if (disc_s_Buffer == 3 ) {
u_octet4_loop_UCO_Buffer_ushort_buffer = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_Buffer_ushort_buffer_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_Buffer_ushort_buffer);
for (i_UCO_Buffer_ushort_buffer=0; i_UCO_Buffer_ushort_buffer < u_octet4_loop_UCO_Buffer_ushort_buffer; i_UCO_Buffer_ushort_buffer++) {
proto_tree_add_uint(tree, hf_UCO_Buffer_ushort_buffer, tvb, *offset-2, 2, get_CDR_ushort(tvb,offset,stream_is_big_endian, boundary));
}
return;
}
if (disc_s_Buffer == 2 ) {
u_octet4_loop_UCO_Buffer_short_buffer = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_Buffer_short_buffer_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_Buffer_short_buffer);
for (i_UCO_Buffer_short_buffer=0; i_UCO_Buffer_short_buffer < u_octet4_loop_UCO_Buffer_short_buffer; i_UCO_Buffer_short_buffer++) {
proto_tree_add_int(tree, hf_UCO_Buffer_short_buffer, tvb, *offset-2, 2, get_CDR_short(tvb,offset,stream_is_big_endian, boundary));
}
return;
}
if (disc_s_Buffer == 5 ) {
u_octet4_loop_UCO_Buffer_ulong_buffer = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_Buffer_ulong_buffer_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_Buffer_ulong_buffer);
for (i_UCO_Buffer_ulong_buffer=0; i_UCO_Buffer_ulong_buffer < u_octet4_loop_UCO_Buffer_ulong_buffer; i_UCO_Buffer_ulong_buffer++) {
proto_tree_add_uint(tree, hf_UCO_Buffer_ulong_buffer, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
}
return;
}
if (disc_s_Buffer == 4 ) {
u_octet4_loop_UCO_Buffer_long_buffer = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_Buffer_long_buffer_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_Buffer_long_buffer);
for (i_UCO_Buffer_long_buffer=0; i_UCO_Buffer_long_buffer < u_octet4_loop_UCO_Buffer_long_buffer; i_UCO_Buffer_long_buffer++) {
proto_tree_add_int(tree, hf_UCO_Buffer_long_buffer, tvb, *offset-4, 4, get_CDR_long(tvb,offset,stream_is_big_endian, boundary));
}
return;
}
if (disc_s_Buffer == 6 ) {
u_octet4_loop_UCO_Buffer_float_buffer = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_Buffer_float_buffer_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_Buffer_float_buffer);
for (i_UCO_Buffer_float_buffer=0; i_UCO_Buffer_float_buffer < u_octet4_loop_UCO_Buffer_float_buffer; i_UCO_Buffer_float_buffer++) {
proto_tree_add_float(tree, hf_UCO_Buffer_float_buffer, tvb, *offset-4, 4, get_CDR_float(tvb,offset,stream_is_big_endian, boundary));
}
return;
}
if (disc_s_Buffer == 7 ) {
u_octet4_loop_UCO_Buffer_double_buffer = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_UCO_Buffer_double_buffer_loop, tvb,*offset-4, 4, u_octet4_loop_UCO_Buffer_double_buffer);
for (i_UCO_Buffer_double_buffer=0; i_UCO_Buffer_double_buffer < u_octet4_loop_UCO_Buffer_double_buffer; i_UCO_Buffer_double_buffer++) {
proto_tree_add_double(tree, hf_UCO_Buffer_double_buffer, tvb, *offset-8, 8, get_CDR_double(tvb,offset,stream_is_big_endian, boundary));
}
return;
}
}
static void
decode_GIAS_Destination_un(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_item* item = NULL;
guint32 u_octet4;
gint32 disc_s_Destination;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Destination_Destination, tvb, *offset-4, 4, u_octet4);
disc_s_Destination = (gint32) u_octet4;
if (disc_s_Destination == 0 ) {
decode_UCO_FileLocation_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return;
}
if (disc_s_Destination == 1 ) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Destination_e_dest);
return;
}
if (disc_s_Destination == 2 ) {
decode_GIAS_PhysicalDelivery_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return;
}
}
static void
decode_GIAS_Domain_un(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_item* item = NULL;
guint32 u_octet4;
gint32 disc_s_Domain;
guint32 u_octet4_loop_GIAS_Domain_is;
guint32 i_GIAS_Domain_is;
guint32 u_octet4_loop_GIAS_Domain_fps;
guint32 i_GIAS_Domain_fps;
guint32 u_octet4_loop_GIAS_Domain_l;
guint32 i_GIAS_Domain_l;
guint32 u_octet4_loop_GIAS_Domain_ol;
guint32 i_GIAS_Domain_ol;
guint32 u_octet4_loop_GIAS_Domain_gs;
guint32 i_GIAS_Domain_gs;
guint32 u_octet4_loop_GIAS_Domain_bd;
const gchar * binary_seq_GIAS_Domain_bd;
gchar * text_seq_GIAS_Domain_bd;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Domain_Domain, tvb, *offset-4, 4, u_octet4);
disc_s_Domain = (gint32) u_octet4;
if (disc_s_Domain == 0 ) {
decode_GIAS_DateRange_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return;
}
if (disc_s_Domain == 1 ) {
proto_tree_add_uint(tree, hf_GIAS_Domain_t, tvb, *offset-4, 4, get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary));
return;
}
if (disc_s_Domain == 2 ) {
decode_GIAS_IntegerRange_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return;
}
if (disc_s_Domain == 9 ) {
u_octet4_loop_GIAS_Domain_is = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Domain_is_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_Domain_is);
for (i_GIAS_Domain_is=0; i_GIAS_Domain_is < u_octet4_loop_GIAS_Domain_is; i_GIAS_Domain_is++) {
decode_GIAS_IntegerRange_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
return;
}
if (disc_s_Domain == 3 ) {
decode_GIAS_FloatingPointRange_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return;
}
if (disc_s_Domain == 10 ) {
u_octet4_loop_GIAS_Domain_fps = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Domain_fps_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_Domain_fps);
for (i_GIAS_Domain_fps=0; i_GIAS_Domain_fps < u_octet4_loop_GIAS_Domain_fps; i_GIAS_Domain_fps++) {
decode_GIAS_FloatingPointRange_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
return;
}
if (disc_s_Domain == 4 ) {
u_octet4_loop_GIAS_Domain_l = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Domain_l_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_Domain_l);
for (i_GIAS_Domain_l=0; i_GIAS_Domain_l < u_octet4_loop_GIAS_Domain_l; i_GIAS_Domain_l++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Domain_l);
}
return;
}
if (disc_s_Domain == 5 ) {
u_octet4_loop_GIAS_Domain_ol = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Domain_ol_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_Domain_ol);
for (i_GIAS_Domain_ol=0; i_GIAS_Domain_ol < u_octet4_loop_GIAS_Domain_ol; i_GIAS_Domain_ol++) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_Domain_ol);
}
return;
}
if (disc_s_Domain == 6 ) {
decode_GIAS_IntegerRange_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return;
}
if (disc_s_Domain == 7 ) {
decode_GIAS_FloatingPointRange_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return;
}
if (disc_s_Domain == 8 ) {
decode_UCO_Rectangle_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return;
}
if (disc_s_Domain == 11 ) {
u_octet4_loop_GIAS_Domain_gs = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Domain_gs_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_Domain_gs);
for (i_GIAS_Domain_gs=0; i_GIAS_Domain_gs < u_octet4_loop_GIAS_Domain_gs; i_GIAS_Domain_gs++) {
decode_UCO_Rectangle_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
}
return;
}
if (disc_s_Domain == 12 ) {
u_octet4_loop_GIAS_Domain_bd = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_Domain_bd_loop, tvb,*offset-4, 4, u_octet4_loop_GIAS_Domain_bd);
if (u_octet4_loop_GIAS_Domain_bd > 0 && tree) {
get_CDR_octet_seq(tvb, &binary_seq_GIAS_Domain_bd, offset,
u_octet4_loop_GIAS_Domain_bd);
text_seq_GIAS_Domain_bd = make_printable_string(binary_seq_GIAS_Domain_bd,
u_octet4_loop_GIAS_Domain_bd);
proto_tree_add_bytes_format_value(tree, hf_GIAS_Domain_bd, tvb, *offset - u_octet4_loop_GIAS_Domain_bd,
u_octet4_loop_GIAS_Domain_bd, binary_seq_GIAS_Domain_bd, "%s", text_seq_GIAS_Domain_bd);
}
return;
}
if (disc_s_Domain == 13 ) {
proto_tree_add_boolean(tree, hf_GIAS_Domain_bv, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));
return;
}
}
static void
decode_GIAS_LifeEvent_un(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
proto_item* item = NULL;
guint32 u_octet4;
gint32 disc_s_LifeEvent;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_GIAS_LifeEvent_LifeEvent, tvb, *offset-4, 4, u_octet4);
disc_s_LifeEvent = (gint32) u_octet4;
if (disc_s_LifeEvent == 0 ) {
decode_UCO_AbsTime_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return;
}
if (disc_s_LifeEvent == 1 ) {
decode_GIAS_DayEventTime_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return;
}
if (disc_s_LifeEvent == 2 ) {
giop_add_CDR_string(tree, tvb, offset, stream_is_big_endian, boundary, hf_GIAS_LifeEvent_ev);
return;
}
if (disc_s_LifeEvent == 3 ) {
decode_UCO_Time_st(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return;
}
}
static proto_tree *
start_dissecting(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset)
{
proto_item *ti = NULL;
proto_tree *tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GIAS");
if (ptree) {
ti = proto_tree_add_item(ptree, proto_gias, tvb, *offset, tvb_reported_length_remaining(tvb, *offset), ENC_NA);
tree = proto_item_add_subtree(ti, ett_gias);
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
dissect_gias(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset, MessageHeader *header, const gchar *operation, gchar *idlname)
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
if (strcmp(operation, "notify") == 0
&& (!idlname || strcmp(idlname, "CB/Callback") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CB_Callback_notify(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "release") == 0
&& (!idlname || strcmp(idlname, "CB/Callback") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_CB_Callback_release(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_manager_types") == 0
&& (!idlname || strcmp(idlname, "GIAS/Library") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_Library_get_manager_types(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_manager") == 0
&& (!idlname || strcmp(idlname, "GIAS/Library") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_Library_get_manager(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_library_description") == 0
&& (!idlname || strcmp(idlname, "GIAS/Library") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_Library_get_library_description(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_other_libraries") == 0
&& (!idlname || strcmp(idlname, "GIAS/Library") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_Library_get_other_libraries(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_property_names") == 0
&& (!idlname || strcmp(idlname, "GIAS/LibraryManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_LibraryManager_get_property_names(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_property_values") == 0
&& (!idlname || strcmp(idlname, "GIAS/LibraryManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_LibraryManager_get_property_values(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_libraries") == 0
&& (!idlname || strcmp(idlname, "GIAS/LibraryManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_LibraryManager_get_libraries(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_active_requests") == 0
&& (!idlname || strcmp(idlname, "GIAS/RequestManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_RequestManager_get_active_requests(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_default_timeout") == 0
&& (!idlname || strcmp(idlname, "GIAS/RequestManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_RequestManager_get_default_timeout(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "set_default_timeout") == 0
&& (!idlname || strcmp(idlname, "GIAS/RequestManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_RequestManager_set_default_timeout(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_timeout") == 0
&& (!idlname || strcmp(idlname, "GIAS/RequestManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_RequestManager_get_timeout(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "set_timeout") == 0
&& (!idlname || strcmp(idlname, "GIAS/RequestManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_RequestManager_set_timeout(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "delete_request") == 0
&& (!idlname || strcmp(idlname, "GIAS/RequestManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_RequestManager_delete_request(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_use_modes") == 0
&& (!idlname || strcmp(idlname, "GIAS/AccessManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_AccessManager_get_use_modes(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "is_available") == 0
&& (!idlname || strcmp(idlname, "GIAS/AccessManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_AccessManager_is_available(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "query_availability_delay") == 0
&& (!idlname || strcmp(idlname, "GIAS/AccessManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_AccessManager_query_availability_delay(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_number_of_priorities") == 0
&& (!idlname || strcmp(idlname, "GIAS/AccessManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_AccessManager_get_number_of_priorities(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "set_availability") == 0
&& (!idlname || strcmp(idlname, "GIAS/AccessManager") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_AccessManager_set_availability(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_event_descriptions") == 0
&& (!idlname || strcmp(idlname, "GIAS/QueryOrderMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_QueryOrderMgr_get_event_descriptions(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "submit_query_order") == 0
&& (!idlname || strcmp(idlname, "GIAS/QueryOrderMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_QueryOrderMgr_submit_query_order(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_package_specifications") == 0
&& (!idlname || strcmp(idlname, "GIAS/OrderMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_OrderMgr_get_package_specifications(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "validate_order") == 0
&& (!idlname || strcmp(idlname, "GIAS/OrderMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_OrderMgr_validate_order(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "order") == 0
&& (!idlname || strcmp(idlname, "GIAS/OrderMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_OrderMgr_order(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_data_model_date") == 0
&& (!idlname || strcmp(idlname, "GIAS/DataModelMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_DataModelMgr_get_data_model_date(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_alias_categories") == 0
&& (!idlname || strcmp(idlname, "GIAS/DataModelMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_DataModelMgr_get_alias_categories(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_logical_aliases") == 0
&& (!idlname || strcmp(idlname, "GIAS/DataModelMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_DataModelMgr_get_logical_aliases(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_logical_attribute_name") == 0
&& (!idlname || strcmp(idlname, "GIAS/DataModelMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_DataModelMgr_get_logical_attribute_name(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_view_names") == 0
&& (!idlname || strcmp(idlname, "GIAS/DataModelMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_DataModelMgr_get_view_names(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_attributes") == 0
&& (!idlname || strcmp(idlname, "GIAS/DataModelMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_DataModelMgr_get_attributes(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_queryable_attributes") == 0
&& (!idlname || strcmp(idlname, "GIAS/DataModelMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_DataModelMgr_get_queryable_attributes(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_entities") == 0
&& (!idlname || strcmp(idlname, "GIAS/DataModelMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_DataModelMgr_get_entities(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_entity_attributes") == 0
&& (!idlname || strcmp(idlname, "GIAS/DataModelMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_DataModelMgr_get_entity_attributes(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_associations") == 0
&& (!idlname || strcmp(idlname, "GIAS/DataModelMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_DataModelMgr_get_associations(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_max_vertices") == 0
&& (!idlname || strcmp(idlname, "GIAS/DataModelMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_DataModelMgr_get_max_vertices(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "create") == 0
&& (!idlname || strcmp(idlname, "GIAS/CreationMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_CreationMgr_create(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "create_metadata") == 0
&& (!idlname || strcmp(idlname, "GIAS/CreationMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_CreationMgr_create_metadata(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "create_association") == 0
&& (!idlname || strcmp(idlname, "GIAS/CreationMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_CreationMgr_create_association(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "set_lock") == 0
&& (!idlname || strcmp(idlname, "GIAS/UpdateMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_UpdateMgr_set_lock(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "update") == 0
&& (!idlname || strcmp(idlname, "GIAS/UpdateMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_UpdateMgr_update(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "update_by_query") == 0
&& (!idlname || strcmp(idlname, "GIAS/UpdateMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_UpdateMgr_update_by_query(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "release_lock") == 0
&& (!idlname || strcmp(idlname, "GIAS/UpdateMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_UpdateMgr_release_lock(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "delete_product") == 0
&& (!idlname || strcmp(idlname, "GIAS/UpdateMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_UpdateMgr_delete_product(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "submit_query") == 0
&& (!idlname || strcmp(idlname, "GIAS/CatalogMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_CatalogMgr_submit_query(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "hit_count") == 0
&& (!idlname || strcmp(idlname, "GIAS/CatalogMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_CatalogMgr_hit_count(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_event_descriptions") == 0
&& (!idlname || strcmp(idlname, "GIAS/StandingQueryMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_StandingQueryMgr_get_event_descriptions(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "submit_standing_query") == 0
&& (!idlname || strcmp(idlname, "GIAS/StandingQueryMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_StandingQueryMgr_submit_standing_query(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_parameters") == 0
&& (!idlname || strcmp(idlname, "GIAS/ProductMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_ProductMgr_get_parameters(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_related_file_types") == 0
&& (!idlname || strcmp(idlname, "GIAS/ProductMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_ProductMgr_get_related_file_types(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_related_files") == 0
&& (!idlname || strcmp(idlname, "GIAS/ProductMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_ProductMgr_get_related_files(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "bulk_pull") == 0
&& (!idlname || strcmp(idlname, "GIAS/IngestMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_IngestMgr_bulk_pull(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "bulk_push") == 0
&& (!idlname || strcmp(idlname, "GIAS/IngestMgr") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_IngestMgr_bulk_push(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_request_description") == 0
&& (!idlname || strcmp(idlname, "GIAS/Request") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_Request_get_request_description(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "set_user_info") == 0
&& (!idlname || strcmp(idlname, "GIAS/Request") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_Request_set_user_info(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_status") == 0
&& (!idlname || strcmp(idlname, "GIAS/Request") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_Request_get_status(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_remaining_delay") == 0
&& (!idlname || strcmp(idlname, "GIAS/Request") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_Request_get_remaining_delay(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "cancel") == 0
&& (!idlname || strcmp(idlname, "GIAS/Request") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_Request_cancel(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "register_callback") == 0
&& (!idlname || strcmp(idlname, "GIAS/Request") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_Request_register_callback(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "free_callback") == 0
&& (!idlname || strcmp(idlname, "GIAS/Request") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_Request_free_callback(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_request_manager") == 0
&& (!idlname || strcmp(idlname, "GIAS/Request") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_Request_get_request_manager(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete") == 0
&& (!idlname || strcmp(idlname, "GIAS/OrderRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_OrderRequest_complete(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "pause") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitQueryOrderRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitQueryOrderRequest_pause(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "resume") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitQueryOrderRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitQueryOrderRequest_resume(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete_list") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitQueryOrderRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitQueryOrderRequest_complete_list(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitQueryOrderRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitQueryOrderRequest_complete(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete") == 0
&& (!idlname || strcmp(idlname, "GIAS/CreateRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_CreateRequest_complete(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete") == 0
&& (!idlname || strcmp(idlname, "GIAS/CreateMetaDataRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_CreateMetaDataRequest_complete(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete") == 0
&& (!idlname || strcmp(idlname, "GIAS/UpdateRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_UpdateRequest_complete(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "set_number_of_hits") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitQueryRequest_set_number_of_hits(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete_DAG_results") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitQueryRequest_complete_DAG_results(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete_stringDAG_results") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitQueryRequest_complete_stringDAG_results(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete_XML_results") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitQueryRequest_complete_XML_results(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "set_number_of_hits") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_set_number_of_hits(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_number_of_hits") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_get_number_of_hits(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_number_of_hits_in_interval") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_get_number_of_hits_in_interval(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_number_of_intervals") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_get_number_of_intervals(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "clear_all") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_clear_all(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "clear_intervals") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_clear_intervals(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "clear_before") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_clear_before(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "pause") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_pause(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "resume") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_resume(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_time_last_executed") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_get_time_last_executed(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "get_time_next_execution") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_get_time_next_execution(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete_DAG_results") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_complete_DAG_results(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete_stringDAG_results") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete_XML_results") == 0
&& (!idlname || strcmp(idlname, "GIAS/SubmitStandingQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SubmitStandingQueryRequest_complete_XML_results(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete") == 0
&& (!idlname || strcmp(idlname, "GIAS/SetAvailabilityRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_SetAvailabilityRequest_complete(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete") == 0
&& (!idlname || strcmp(idlname, "GIAS/HitCountRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_HitCountRequest_complete(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete") == 0
&& (!idlname || strcmp(idlname, "GIAS/GetParametersRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_GetParametersRequest_complete(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete_StringDAG") == 0
&& (!idlname || strcmp(idlname, "GIAS/GetParametersRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_GetParametersRequest_complete_StringDAG(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete") == 0
&& (!idlname || strcmp(idlname, "GIAS/IngestRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_IngestRequest_complete(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete") == 0
&& (!idlname || strcmp(idlname, "GIAS/GetRelatedFilesRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_GetRelatedFilesRequest_complete(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete") == 0
&& (!idlname || strcmp(idlname, "GIAS/CreateAssociationRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_CreateAssociationRequest_complete(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, "complete") == 0
&& (!idlname || strcmp(idlname, "GIAS/UpdateByQueryRequest") == 0)) {
item = process_RequestOperation(tvb, pinfo, ptree, header, operation);
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_GIAS_UpdateByQueryRequest_complete(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
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
void proto_register_giop_gias(void)
{
static hf_register_info hf[] = {
{&hf_operationrequest, {"Request_Operation","giop-gias.Request_Operation",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_CB_Callback_notify_theState, {"theState","giop-gias.Callback.notify.theState",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_Library_get_manager_types_return_loop, {"Seq length of ManagerTypeList","giop-gias.Library.get_manager_types.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Library_get_manager_types_return, {"ManagerTypeList","giop-gias.Library.get_manager_types.return",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Library_get_manager_manager_type, {"manager_type","giop-gias.Library.get_manager.manager_type",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Library_get_other_libraries_return_loop, {"Seq length of LibraryDescriptionList","giop-gias.Library.get_other_libraries.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_LibraryManager_get_property_names_return_loop, {"Seq length of NameList","giop-gias.LibraryManager.get_property_names.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_LibraryManager_get_property_names_return, {"NameList","giop-gias.LibraryManager.get_property_names.return",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_LibraryManager_get_property_values_return_loop, {"Seq length of PropertyList","giop-gias.LibraryManager.get_property_values.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_LibraryManager_get_property_values_desired_properties_loop, {"Seq length of desired_properties","giop-gias.LibraryManager.get_property_values.desired_properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_LibraryManager_get_property_values_desired_properties, {"desired_properties","giop-gias.LibraryManager.get_property_values.desired_properties",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_LibraryManager_get_libraries_return_loop, {"Seq length of LibraryList","giop-gias.LibraryManager.get_libraries.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_RequestManager_get_active_requests_return_loop, {"Seq length of RequestList","giop-gias.RequestManager.get_active_requests.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_RequestManager_get_default_timeout_return, {"Return value","giop-gias.RequestManager.get_default_timeout.return",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_RequestManager_set_default_timeout_new_default, {"new_default","giop-gias.RequestManager.set_default_timeout.new_default",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_RequestManager_get_timeout_return, {"Return value","giop-gias.RequestManager.get_timeout.return",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_RequestManager_set_timeout_new_lifetime, {"new_lifetime","giop-gias.RequestManager.set_timeout.new_lifetime",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AccessManager_get_use_modes_return_loop, {"Seq length of UseModeList","giop-gias.AccessManager.get_use_modes.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AccessManager_get_use_modes_return, {"UseModeList","giop-gias.AccessManager.get_use_modes.return",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AccessManager_is_available_return, {"Return value","giop-gias.AccessManager.is_available.return",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
{&hf_GIAS_AccessManager_is_available_use_mode, {"use_mode","giop-gias.AccessManager.is_available.use_mode",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AccessManager_query_availability_delay_return, {"Return value","giop-gias.AccessManager.query_availability_delay.return",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AccessManager_query_availability_delay_availability_requirement, {"availability_requirement","giop-gias.AccessManager.query_availability_delay.availability_requirement",FT_UINT32,BASE_DEC,VALS(GIAS_AvailabilityRequirement),0x0,NULL,HFILL}},
{&hf_GIAS_AccessManager_query_availability_delay_use_mode, {"use_mode","giop-gias.AccessManager.query_availability_delay.use_mode",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AccessManager_get_number_of_priorities_return, {"Return value","giop-gias.AccessManager.get_number_of_priorities.return",FT_INT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AccessManager_set_availability_products_loop, {"Seq length of products","giop-gias.AccessManager.set_availability.products.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AccessManager_set_availability_availability_requirement, {"availability_requirement","giop-gias.AccessManager.set_availability.availability_requirement",FT_UINT32,BASE_DEC,VALS(GIAS_AvailabilityRequirement),0x0,NULL,HFILL}},
{&hf_GIAS_AccessManager_set_availability_use_mode, {"use_mode","giop-gias.AccessManager.set_availability.use_mode",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AccessManager_set_availability_priority, {"priority","giop-gias.AccessManager.set_availability.priority",FT_INT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_QueryOrderMgr_get_event_descriptions_return_loop, {"Seq length of EventList","giop-gias.QueryOrderMgr.get_event_descriptions.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_QueryOrderMgr_submit_query_order_o_type, {"o_type","giop-gias.QueryOrderMgr.submit_query_order.o_type",FT_UINT32,BASE_DEC,VALS(GIAS_OrderType),0x0,NULL,HFILL}},
{&hf_GIAS_QueryOrderMgr_submit_query_order_properties_loop, {"Seq length of properties","giop-gias.QueryOrderMgr.submit_query_order.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_OrderMgr_get_package_specifications_return_loop, {"Seq length of NameList","giop-gias.OrderMgr.get_package_specifications.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_OrderMgr_get_package_specifications_return, {"NameList","giop-gias.OrderMgr.get_package_specifications.return",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_OrderMgr_validate_order_properties_loop, {"Seq length of properties","giop-gias.OrderMgr.validate_order.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_OrderMgr_order_properties_loop, {"Seq length of properties","giop-gias.OrderMgr.order.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_data_model_date_properties_loop, {"Seq length of properties","giop-gias.DataModelMgr.get_data_model_date.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_alias_categories_return_loop, {"Seq length of NameList","giop-gias.DataModelMgr.get_alias_categories.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_alias_categories_return, {"NameList","giop-gias.DataModelMgr.get_alias_categories.return",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_alias_categories_properties_loop, {"Seq length of properties","giop-gias.DataModelMgr.get_alias_categories.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_logical_aliases_return_loop, {"Seq length of NameNameList","giop-gias.DataModelMgr.get_logical_aliases.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_logical_aliases_category, {"category","giop-gias.DataModelMgr.get_logical_aliases.category",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_logical_aliases_properties_loop, {"Seq length of properties","giop-gias.DataModelMgr.get_logical_aliases.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_logical_attribute_name_return, {"Return value","giop-gias.DataModelMgr.get_logical_attribute_name.return",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_logical_attribute_name_view_name, {"view_name","giop-gias.DataModelMgr.get_logical_attribute_name.view_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_logical_attribute_name_attribute_type, {"attribute_type","giop-gias.DataModelMgr.get_logical_attribute_name.attribute_type",FT_UINT32,BASE_DEC,VALS(GIAS_ConceptualAttributeType),0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_logical_attribute_name_properties_loop, {"Seq length of properties","giop-gias.DataModelMgr.get_logical_attribute_name.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_view_names_return_loop, {"Seq length of ViewList","giop-gias.DataModelMgr.get_view_names.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_view_names_properties_loop, {"Seq length of properties","giop-gias.DataModelMgr.get_view_names.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_attributes_return_loop, {"Seq length of AttributeInformationList","giop-gias.DataModelMgr.get_attributes.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_attributes_view_name, {"view_name","giop-gias.DataModelMgr.get_attributes.view_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_attributes_properties_loop, {"Seq length of properties","giop-gias.DataModelMgr.get_attributes.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_queryable_attributes_return_loop, {"Seq length of AttributeInformationList","giop-gias.DataModelMgr.get_queryable_attributes.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_queryable_attributes_view_name, {"view_name","giop-gias.DataModelMgr.get_queryable_attributes.view_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_queryable_attributes_properties_loop, {"Seq length of properties","giop-gias.DataModelMgr.get_queryable_attributes.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_entities_view_name, {"view_name","giop-gias.DataModelMgr.get_entities.view_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_entities_properties_loop, {"Seq length of properties","giop-gias.DataModelMgr.get_entities.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_entity_attributes_return_loop, {"Seq length of AttributeInformationList","giop-gias.DataModelMgr.get_entity_attributes.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_entity_attributes_aEntity, {"aEntity","giop-gias.DataModelMgr.get_entity_attributes.aEntity",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_entity_attributes_properties_loop, {"Seq length of properties","giop-gias.DataModelMgr.get_entity_attributes.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_associations_return_loop, {"Seq length of AssociationList","giop-gias.DataModelMgr.get_associations.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_associations_properties_loop, {"Seq length of properties","giop-gias.DataModelMgr.get_associations.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_max_vertices_return, {"Return value","giop-gias.DataModelMgr.get_max_vertices.return",FT_UINT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DataModelMgr_get_max_vertices_properties_loop, {"Seq length of properties","giop-gias.DataModelMgr.get_max_vertices.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CreationMgr_create_new_product_loop, {"Seq length of new_product","giop-gias.CreationMgr.create.new_product.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CreationMgr_create_related_files_loop, {"Seq length of related_files","giop-gias.CreationMgr.create.related_files.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CreationMgr_create_properties_loop, {"Seq length of properties","giop-gias.CreationMgr.create.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CreationMgr_create_metadata_view_name, {"view_name","giop-gias.CreationMgr.create_metadata.view_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CreationMgr_create_metadata_related_files_loop, {"Seq length of related_files","giop-gias.CreationMgr.create_metadata.related_files.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CreationMgr_create_metadata_properties_loop, {"Seq length of properties","giop-gias.CreationMgr.create_metadata.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CreationMgr_create_association_assoc_name, {"assoc_name","giop-gias.CreationMgr.create_association.assoc_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CreationMgr_create_association_view_b_objects_loop, {"Seq length of view_b_objects","giop-gias.CreationMgr.create_association.view_b_objects.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CreationMgr_create_association_assoc_info_loop, {"Seq length of assoc_info","giop-gias.CreationMgr.create_association.assoc_info.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_UpdateMgr_update_view, {"view","giop-gias.UpdateMgr.update.view",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_UpdateMgr_update_changes_loop, {"Seq length of changes","giop-gias.UpdateMgr.update.changes.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_UpdateMgr_update_relfiles_loop, {"Seq length of relfiles","giop-gias.UpdateMgr.update.relfiles.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_UpdateMgr_update_properties_loop, {"Seq length of properties","giop-gias.UpdateMgr.update.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_UpdateMgr_update_by_query_properties_loop, {"Seq length of properties","giop-gias.UpdateMgr.update_by_query.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CatalogMgr_submit_query_result_attributes_loop, {"Seq length of result_attributes","giop-gias.CatalogMgr.submit_query.result_attributes.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CatalogMgr_submit_query_result_attributes, {"result_attributes","giop-gias.CatalogMgr.submit_query.result_attributes",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CatalogMgr_submit_query_sort_attributes_loop, {"Seq length of sort_attributes","giop-gias.CatalogMgr.submit_query.sort_attributes.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CatalogMgr_submit_query_properties_loop, {"Seq length of properties","giop-gias.CatalogMgr.submit_query.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CatalogMgr_hit_count_properties_loop, {"Seq length of properties","giop-gias.CatalogMgr.hit_count.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_StandingQueryMgr_get_event_descriptions_return_loop, {"Seq length of EventList","giop-gias.StandingQueryMgr.get_event_descriptions.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_StandingQueryMgr_submit_standing_query_result_attributes_loop, {"Seq length of result_attributes","giop-gias.StandingQueryMgr.submit_standing_query.result_attributes.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_StandingQueryMgr_submit_standing_query_result_attributes, {"result_attributes","giop-gias.StandingQueryMgr.submit_standing_query.result_attributes",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_StandingQueryMgr_submit_standing_query_sort_attributes_loop, {"Seq length of sort_attributes","giop-gias.StandingQueryMgr.submit_standing_query.sort_attributes.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_StandingQueryMgr_submit_standing_query_properties_loop, {"Seq length of properties","giop-gias.StandingQueryMgr.submit_standing_query.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ProductMgr_get_parameters_desired_parameters_loop, {"Seq length of desired_parameters","giop-gias.ProductMgr.get_parameters.desired_parameters.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ProductMgr_get_parameters_desired_parameters, {"desired_parameters","giop-gias.ProductMgr.get_parameters.desired_parameters",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ProductMgr_get_parameters_properties_loop, {"Seq length of properties","giop-gias.ProductMgr.get_parameters.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ProductMgr_get_related_file_types_return_loop, {"Seq length of RelatedFileTypeList","giop-gias.ProductMgr.get_related_file_types.return.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ProductMgr_get_related_file_types_return, {"RelatedFileTypeList","giop-gias.ProductMgr.get_related_file_types.return",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ProductMgr_get_related_files_products_loop, {"Seq length of products","giop-gias.ProductMgr.get_related_files.products.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ProductMgr_get_related_files_type, {"type","giop-gias.ProductMgr.get_related_files.type",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ProductMgr_get_related_files_properties_loop, {"Seq length of properties","giop-gias.ProductMgr.get_related_files.properties.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_IngestMgr_bulk_pull_property_list_loop, {"Seq length of property_list","giop-gias.IngestMgr.bulk_pull.property_list.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_IngestMgr_bulk_push_property_list_loop, {"Seq length of property_list","giop-gias.IngestMgr.bulk_push.property_list.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Request_set_user_info_message, {"message","giop-gias.Request.set_user_info.message",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Request_register_callback_return, {"CallbackID","giop-gias.Request.register_callback.return",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Request_free_callback_id, {"id","giop-gias.Request.free_callback.id",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_OrderRequest_complete_return, {"Return value","giop-gias.OrderRequest.complete.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_SubmitQueryOrderRequest_complete_list_return, {"Return value","giop-gias.SubmitQueryOrderRequest.complete_list.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_SubmitQueryOrderRequest_complete_list_prods_loop, {"Seq length of prods","giop-gias.SubmitQueryOrderRequest.complete_list.prods.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitQueryOrderRequest_complete_return, {"Return value","giop-gias.SubmitQueryOrderRequest.complete.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_CreateRequest_complete_return, {"Return value","giop-gias.CreateRequest.complete.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_CreateRequest_complete_new_products_loop, {"Seq length of new_products","giop-gias.CreateRequest.complete.new_products.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CreateMetaDataRequest_complete_return, {"Return value","giop-gias.CreateMetaDataRequest.complete.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_UpdateRequest_complete_return, {"Return value","giop-gias.UpdateRequest.complete.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_SubmitQueryRequest_set_number_of_hits_hits, {"hits","giop-gias.SubmitQueryRequest.set_number_of_hits.hits",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitQueryRequest_complete_DAG_results_return, {"Return value","giop-gias.SubmitQueryRequest.complete_DAG_results.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_SubmitQueryRequest_complete_DAG_results_results_loop, {"Seq length of results","giop-gias.SubmitQueryRequest.complete_DAG_results.results.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitQueryRequest_complete_stringDAG_results_return, {"Return value","giop-gias.SubmitQueryRequest.complete_stringDAG_results.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_SubmitQueryRequest_complete_stringDAG_results_results_loop, {"Seq length of results","giop-gias.SubmitQueryRequest.complete_stringDAG_results.results.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitQueryRequest_complete_XML_results_return, {"Return value","giop-gias.SubmitQueryRequest.complete_XML_results.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_SubmitQueryRequest_complete_XML_results_results, {"results","giop-gias.SubmitQueryRequest.complete_XML_results.results",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitStandingQueryRequest_set_number_of_hits_hits, {"hits","giop-gias.SubmitStandingQueryRequest.set_number_of_hits.hits",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitStandingQueryRequest_get_number_of_hits_return, {"Return value","giop-gias.SubmitStandingQueryRequest.get_number_of_hits.return",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitStandingQueryRequest_get_number_of_hits_in_interval_return, {"Return value","giop-gias.SubmitStandingQueryRequest.get_number_of_hits_in_interval.return",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitStandingQueryRequest_get_number_of_hits_in_interval_interval, {"interval","giop-gias.SubmitStandingQueryRequest.get_number_of_hits_in_interval.interval",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitStandingQueryRequest_get_number_of_intervals_return, {"Return value","giop-gias.SubmitStandingQueryRequest.get_number_of_intervals.return",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitStandingQueryRequest_clear_intervals_num_intervals, {"num_intervals","giop-gias.SubmitStandingQueryRequest.clear_intervals.num_intervals",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitStandingQueryRequest_complete_DAG_results_return, {"Return value","giop-gias.SubmitStandingQueryRequest.complete_DAG_results.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_SubmitStandingQueryRequest_complete_DAG_results_results_loop, {"Seq length of results","giop-gias.SubmitStandingQueryRequest.complete_DAG_results.results.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results_return, {"Return value","giop-gias.SubmitStandingQueryRequest.complete_stringDAG_results.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_SubmitStandingQueryRequest_complete_stringDAG_results_results_loop, {"Seq length of results","giop-gias.SubmitStandingQueryRequest.complete_stringDAG_results.results.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SubmitStandingQueryRequest_complete_XML_results_return, {"Return value","giop-gias.SubmitStandingQueryRequest.complete_XML_results.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_SubmitStandingQueryRequest_complete_XML_results_results, {"results","giop-gias.SubmitStandingQueryRequest.complete_XML_results.results",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SetAvailabilityRequest_complete_return, {"Return value","giop-gias.SetAvailabilityRequest.complete.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_HitCountRequest_complete_return, {"Return value","giop-gias.HitCountRequest.complete.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_HitCountRequest_complete_number_of_hits, {"number_of_hits","giop-gias.HitCountRequest.complete.number_of_hits",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_GetParametersRequest_complete_return, {"Return value","giop-gias.GetParametersRequest.complete.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_GetParametersRequest_complete_StringDAG_return, {"Return value","giop-gias.GetParametersRequest.complete_StringDAG.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_IngestRequest_complete_return, {"Return value","giop-gias.IngestRequest.complete.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_GetRelatedFilesRequest_complete_return, {"Return value","giop-gias.GetRelatedFilesRequest.complete.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_GetRelatedFilesRequest_complete_locations_loop, {"Seq length of locations","giop-gias.GetRelatedFilesRequest.complete.locations.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_GetRelatedFilesRequest_complete_locations, {"locations","giop-gias.GetRelatedFilesRequest.complete.locations",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_CreateAssociationRequest_complete_return, {"Return value","giop-gias.CreateAssociationRequest.complete.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_GIAS_UpdateByQueryRequest_complete_return, {"Return value","giop-gias.UpdateByQueryRequest.complete.return",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_UCO_NameName_name1, {"NameName_name1","giop-gias.NameName.name1",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_NameName_name2, {"NameName_name2","giop-gias.NameName.name2",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_NameValue_aname, {"NameValue_aname","giop-gias.NameValue.aname",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Ratio_numerator, {"Ratio_numerator","giop-gias.Ratio.numerator",FT_DOUBLE,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Ratio_denominator, {"Ratio_denominator","giop-gias.Ratio.denominator",FT_DOUBLE,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_FileLocation_user_name, {"FileLocation_user_name","giop-gias.FileLocation.user_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_FileLocation_password, {"FileLocation_password","giop-gias.FileLocation.password",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_FileLocation_host_name, {"FileLocation_host_name","giop-gias.FileLocation.host_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_FileLocation_path_name, {"FileLocation_path_name","giop-gias.FileLocation.path_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_FileLocation_file_name, {"FileLocation_file_name","giop-gias.FileLocation.file_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_DirectAccessLocation_access_protocol, {"DirectAccessLocation_access_protocol","giop-gias.DirectAccessLocation.access_protocol",FT_UINT32,BASE_DEC,VALS(UCO_Protocol),0x0,NULL,HFILL}},
{&hf_UCO_Date_year, {"Date_year","giop-gias.Date.year",FT_UINT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Date_month, {"Date_month","giop-gias.Date.month",FT_UINT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Date_day, {"Date_day","giop-gias.Date.day",FT_UINT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Time_hour, {"Time_hour","giop-gias.Time.hour",FT_UINT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Time_minute, {"Time_minute","giop-gias.Time.minute",FT_UINT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Time_second, {"Time_second","giop-gias.Time.second",FT_FLOAT,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Node_id, {"Node_id","giop-gias.Node.id",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Node_node_type, {"Node_node_type","giop-gias.Node.node_type",FT_UINT32,BASE_DEC,VALS(UCO_NodeType),0x0,NULL,HFILL}},
{&hf_UCO_Node_attribute_name, {"Node_attribute_name","giop-gias.Node.attribute_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Edge_start_node, {"Edge_start_node","giop-gias.Edge.start_node",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Edge_end_node, {"Edge_end_node","giop-gias.Edge.end_node",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Edge_relationship_type, {"Edge_relationship_type","giop-gias.Edge.relationship_type",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_DAG_nodes_loop, {"Seq length of DAG_nodes","giop-gias.DAG.nodes.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_DAG_edges_loop, {"Seq length of DAG_edges","giop-gias.DAG.edges.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_StringNode_id, {"StringNode_id","giop-gias.StringNode.id",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_StringNode_node_type, {"StringNode_node_type","giop-gias.StringNode.node_type",FT_UINT32,BASE_DEC,VALS(UCO_NodeType),0x0,NULL,HFILL}},
{&hf_UCO_StringNode_attribute_name, {"StringNode_attribute_name","giop-gias.StringNode.attribute_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_StringNode_value, {"StringNode_value","giop-gias.StringNode.value",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_StringDAG_nodes_loop, {"Seq length of StringDAG_nodes","giop-gias.StringDAG.nodes.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_StringDAG_edges_loop, {"Seq length of StringDAG_edges","giop-gias.StringDAG.edges.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Change_changed_node, {"Change_changed_node","giop-gias.Change.changed_node",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Change_change_type, {"Change_change_type","giop-gias.Change.change_type",FT_UINT32,BASE_DEC,VALS(UCO_ChangeType),0x0,NULL,HFILL}},
{&hf_UCO_UpdateDAG_changes_loop, {"Seq length of UpdateDAG_changes","giop-gias.UpdateDAG.changes.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_RequestDescription_user_info, {"RequestDescription_user_info","giop-gias.RequestDescription.user_info",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_RequestDescription_request_type, {"RequestDescription_request_type","giop-gias.RequestDescription.request_type",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_RequestDescription_request_info, {"RequestDescription_request_info","giop-gias.RequestDescription.request_info",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_RequestDescription_request_details_loop, {"Seq length of RequestDescription_request_details","giop-gias.RequestDescription.request_details.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Coordinate2d_x, {"Coordinate2d_x","giop-gias.Coordinate2d.x",FT_DOUBLE,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Coordinate2d_y, {"Coordinate2d_y","giop-gias.Coordinate2d.y",FT_DOUBLE,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Coordinate3d_x, {"Coordinate3d_x","giop-gias.Coordinate3d.x",FT_DOUBLE,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Coordinate3d_y, {"Coordinate3d_y","giop-gias.Coordinate3d.y",FT_DOUBLE,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Coordinate3d_z, {"Coordinate3d_z","giop-gias.Coordinate3d.z",FT_DOUBLE,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_LinearDimension_dimension, {"LinearDimension_dimension","giop-gias.LinearDimension.dimension",FT_DOUBLE,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_LinearDimension_reference_system, {"LinearDimension_reference_system","giop-gias.LinearDimension.reference_system",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Ellipse_north_angle, {"Ellipse_north_angle","giop-gias.Ellipse.north_angle",FT_DOUBLE,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_SimpleGSImage_width, {"SimpleGSImage_width","giop-gias.SimpleGSImage.width",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_SimpleGSImage_height, {"SimpleGSImage_height","giop-gias.SimpleGSImage.height",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_SimpleCImage_width, {"SimpleCImage_width","giop-gias.SimpleCImage.width",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_SimpleCImage_height, {"SimpleCImage_height","giop-gias.SimpleCImage.height",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_CompressedImage_width, {"CompressedImage_width","giop-gias.CompressedImage.width",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_CompressedImage_height, {"CompressedImage_height","giop-gias.CompressedImage.height",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_CompressedImage_compression_form, {"CompressedImage_compression_form","giop-gias.CompressedImage.compression_form",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_CompressedImage_data_loop, {"Seq length of CompressedImage_data","giop-gias.CompressedImage.data.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_CompressedImage_data, {"CompressedImage_data","giop-gias.CompressedImage.data",FT_BYTES,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Status_completion_state, {"Status_completion_state","giop-gias.Status.completion_state",FT_UINT32,BASE_DEC,VALS(UCO_State),0x0,NULL,HFILL}},
{&hf_UCO_Status_warning, {"Status_warning","giop-gias.Status.warning",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
{&hf_UCO_Status_status_message, {"Status_status_message","giop-gias.Status.status_message",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_EntityNode_id, {"EntityNode_id","giop-gias.EntityNode.id",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_EntityNode_entity_name, {"EntityNode_entity_name","giop-gias.EntityNode.entity_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_EntityRelationship_start_node, {"EntityRelationship_start_node","giop-gias.EntityRelationship.start_node",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_EntityRelationship_end_node, {"EntityRelationship_end_node","giop-gias.EntityRelationship.end_node",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_EntityRelationship_start_to_end_card, {"EntityRelationship_start_to_end_card","giop-gias.EntityRelationship.start_to_end_card",FT_UINT32,BASE_DEC,VALS(UCO_Cardinality),0x0,NULL,HFILL}},
{&hf_UCO_EntityRelationship_end_to_start_card, {"EntityRelationship_end_to_start_card","giop-gias.EntityRelationship.end_to_start_card",FT_UINT32,BASE_DEC,VALS(UCO_Cardinality),0x0,NULL,HFILL}},
{&hf_UCO_EntityGraph_nodes_loop, {"Seq length of EntityGraph_nodes","giop-gias.EntityGraph.nodes.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_EntityGraph_relationship_loop, {"Seq length of EntityGraph_relationship","giop-gias.EntityGraph.relationship.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_exception_details_exception_name, {"exception_details_exception_name","giop-gias.exception_details.exception_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_exception_details_standard_exception_name, {"exception_details_standard_exception_name","giop-gias.exception_details.standard_exception_name",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
{&hf_UCO_exception_details_exception_desc, {"exception_details_exception_desc","giop-gias.exception_details.exception_desc",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ImageSpec_imgform, {"ImageSpec_imgform","giop-gias.ImageSpec.imgform",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ImageSpec_imageid, {"ImageSpec_imageid","giop-gias.ImageSpec.imageid",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ImageSpec_comp, {"ImageSpec_comp","giop-gias.ImageSpec.comp",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ImageSpec_bpp, {"ImageSpec_bpp","giop-gias.ImageSpec.bpp",FT_INT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ImageSpec_algo, {"ImageSpec_algo","giop-gias.ImageSpec.algo",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ImageSpec_rrds_loop, {"Seq length of ImageSpec_rrds","giop-gias.ImageSpec.rrds.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ImageSpec_rrds, {"ImageSpec_rrds","giop-gias.ImageSpec.rrds",FT_INT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ImageSpec_geo_region_type, {"ImageSpec_geo_region_type","giop-gias.ImageSpec.geo_region_type",FT_UINT32,BASE_DEC,VALS(GIAS_GeoRegionType),0x0,NULL,HFILL}},
{&hf_GIAS_ImageSpec_encoding, {"ImageSpec_encoding","giop-gias.ImageSpec.encoding",FT_UINT32,BASE_DEC,VALS(GIAS_SupportDataEncoding),0x0,NULL,HFILL}},
{&hf_GIAS_AlterationSpec_pf, {"AlterationSpec_pf","giop-gias.AlterationSpec.pf",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AlterationSpec_geo_region_type, {"AlterationSpec_geo_region_type","giop-gias.AlterationSpec.geo_region_type",FT_UINT32,BASE_DEC,VALS(GIAS_GeoRegionType),0x0,NULL,HFILL}},
{&hf_GIAS_PackagingSpec_package_identifier, {"PackagingSpec_package_identifier","giop-gias.PackagingSpec.package_identifier",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_PackagingSpec_packaging_format_and_compression, {"PackagingSpec_packaging_format_and_compression","giop-gias.PackagingSpec.packaging_format_and_compression",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_TailoringSpec_specs_loop, {"Seq length of TailoringSpec_specs","giop-gias.TailoringSpec.specs.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_MediaType_media_type, {"MediaType_media_type","giop-gias.MediaType.media_type",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_MediaType_quantity, {"MediaType_quantity","giop-gias.MediaType.quantity",FT_UINT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_PhysicalDelivery_address, {"PhysicalDelivery_address","giop-gias.PhysicalDelivery.address",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ValidationResults_valid, {"ValidationResults_valid","giop-gias.ValidationResults.valid",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
{&hf_GIAS_ValidationResults_warning, {"ValidationResults_warning","giop-gias.ValidationResults.warning",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
{&hf_GIAS_ValidationResults_details, {"ValidationResults_details","giop-gias.ValidationResults.details",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_RelatedFile_file_type, {"RelatedFile_file_type","giop-gias.RelatedFile.file_type",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_View_view_name, {"View_view_name","giop-gias.View.view_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_View_orderable, {"View_orderable","giop-gias.View.orderable",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
{&hf_GIAS_View_sub_views_loop, {"Seq length of View_sub_views","giop-gias.View.sub_views.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_View_sub_views, {"View_sub_views","giop-gias.View.sub_views",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_IntegerRange_lower_bound, {"IntegerRange_lower_bound","giop-gias.IntegerRange.lower_bound",FT_INT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_IntegerRange_upper_bound, {"IntegerRange_upper_bound","giop-gias.IntegerRange.upper_bound",FT_INT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_FloatingPointRange_lower_bound, {"FloatingPointRange_lower_bound","giop-gias.FloatingPointRange.lower_bound",FT_DOUBLE,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_FloatingPointRange_upper_bound, {"FloatingPointRange_upper_bound","giop-gias.FloatingPointRange.upper_bound",FT_DOUBLE,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AttributeInformation_attribute_name, {"AttributeInformation_attribute_name","giop-gias.AttributeInformation.attribute_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AttributeInformation_attribute_type, {"AttributeInformation_attribute_type","giop-gias.AttributeInformation.attribute_type",FT_UINT32,BASE_DEC,VALS(GIAS_AttributeType),0x0,NULL,HFILL}},
{&hf_GIAS_AttributeInformation_attribute_units, {"AttributeInformation_attribute_units","giop-gias.AttributeInformation.attribute_units",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AttributeInformation_attribute_reference, {"AttributeInformation_attribute_reference","giop-gias.AttributeInformation.attribute_reference",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AttributeInformation_mode, {"AttributeInformation_mode","giop-gias.AttributeInformation.mode",FT_UINT32,BASE_DEC,VALS(GIAS_RequirementMode),0x0,NULL,HFILL}},
{&hf_GIAS_AttributeInformation_description, {"AttributeInformation_description","giop-gias.AttributeInformation.description",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AttributeInformation_sortable, {"AttributeInformation_sortable","giop-gias.AttributeInformation.sortable",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
{&hf_GIAS_AttributeInformation_updateable, {"AttributeInformation_updateable","giop-gias.AttributeInformation.updateable",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
{&hf_GIAS_Association_name, {"Association_name","giop-gias.Association.name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Association_view_a, {"Association_view_a","giop-gias.Association.view_a",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Association_view_b, {"Association_view_b","giop-gias.Association.view_b",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Association_description, {"Association_description","giop-gias.Association.description",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Association_card, {"Association_card","giop-gias.Association.card",FT_UINT32,BASE_DEC,VALS(UCO_Cardinality),0x0,NULL,HFILL}},
{&hf_GIAS_Association_attribute_info_loop, {"Seq length of Association_attribute_info","giop-gias.Association.attribute_info.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_LibraryDescription_library_name, {"LibraryDescription_library_name","giop-gias.LibraryDescription.library_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_LibraryDescription_library_description, {"LibraryDescription_library_description","giop-gias.LibraryDescription.library_description",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_LibraryDescription_library_version_number, {"LibraryDescription_library_version_number","giop-gias.LibraryDescription.library_version_number",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Query_view, {"Query_view","giop-gias.Query.view",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Query_bqs_query, {"Query_bqs_query","giop-gias.Query.bqs_query",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Event_event_name, {"Event_event_name","giop-gias.Event.event_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Event_event_type, {"Event_event_type","giop-gias.Event.event_type",FT_UINT32,BASE_DEC,VALS(GIAS_NamedEventType),0x0,NULL,HFILL}},
{&hf_GIAS_Event_event_description, {"Event_event_description","giop-gias.Event.event_description",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DayEventTime_day_event, {"DayEventTime_day_event","giop-gias.DayEventTime.day_event",FT_UINT32,BASE_DEC,VALS(GIAS_DayEvent),0x0,NULL,HFILL}},
{&hf_GIAS_QueryLifeSpan_frequency_loop, {"Seq length of QueryLifeSpan_frequency","giop-gias.QueryLifeSpan.frequency.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SortAttribute_attribute_name, {"SortAttribute_attribute_name","giop-gias.SortAttribute.attribute_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_SortAttribute_sort_polarity, {"SortAttribute_sort_polarity","giop-gias.SortAttribute.sort_polarity",FT_UINT32,BASE_DEC,VALS(GIAS_Polarity),0x0,NULL,HFILL}},
{&hf_GIAS_DelayEstimate_time_delay, {"DelayEstimate_time_delay","giop-gias.DelayEstimate.time_delay",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DelayEstimate_valid_time_delay, {"DelayEstimate_valid_time_delay","giop-gias.DelayEstimate.valid_time_delay",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
{&hf_GIAS_ProductDetails_mTypes_loop, {"Seq length of ProductDetails_mTypes","giop-gias.ProductDetails.mTypes.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ProductDetails_benums_loop, {"Seq length of ProductDetails_benums","giop-gias.ProductDetails.benums.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ProductDetails_benums, {"ProductDetails_benums","giop-gias.ProductDetails.benums",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_ProductDetails_info_system_name, {"ProductDetails_info_system_name","giop-gias.ProductDetails.info_system_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DeliveryDetails_receiver, {"DeliveryDetails_receiver","giop-gias.DeliveryDetails.receiver",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DeliveryDetails_shipmentMode, {"DeliveryDetails_shipmentMode","giop-gias.DeliveryDetails.shipmentMode",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_OrderContents_originator, {"OrderContents_originator","giop-gias.OrderContents.originator",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_OrderContents_operatorNote, {"OrderContents_operatorNote","giop-gias.OrderContents.operatorNote",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_OrderContents_orderPriority, {"OrderContents_orderPriority","giop-gias.OrderContents.orderPriority",FT_INT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_OrderContents_prod_list_loop, {"Seq length of OrderContents_prod_list","giop-gias.OrderContents.prod_list.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_OrderContents_del_list_loop, {"Seq length of OrderContents_del_list","giop-gias.OrderContents.del_list.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_QueryOrderContents_originator, {"QueryOrderContents_originator","giop-gias.QueryOrderContents.originator",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_QueryOrderContents_operatorNote, {"QueryOrderContents_operatorNote","giop-gias.QueryOrderContents.operatorNote",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_QueryOrderContents_orderPriority, {"QueryOrderContents_orderPriority","giop-gias.QueryOrderContents.orderPriority",FT_INT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_QueryOrderContents_del_list_loop, {"Seq length of QueryOrderContents_del_list","giop-gias.QueryOrderContents.del_list.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AccessCriteria_userID, {"AccessCriteria_userID","giop-gias.AccessCriteria.userID",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AccessCriteria_password, {"AccessCriteria_password","giop-gias.AccessCriteria.password",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_AccessCriteria_licenseKey, {"AccessCriteria_licenseKey","giop-gias.AccessCriteria.licenseKey",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_PackageElement_files_loop, {"Seq length of PackageElement_files","giop-gias.PackageElement.files.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_PackageElement_files, {"PackageElement_files","giop-gias.PackageElement.files",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DeliveryManifest_package_name, {"DeliveryManifest_package_name","giop-gias.DeliveryManifest.package_name",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_DeliveryManifest_elements_loop, {"Seq length of DeliveryManifest_elements","giop-gias.DeliveryManifest.elements.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_InvalidInputParameter_badInputParameters_loop, {"Seq length of InvalidInputParameter_badInputParameters","giop-gias.InvalidInputParamete.InvalidInputParameter_badInputParameters.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_InvalidInputParameter_badInputParameters, {"InvalidInputParameter_badInputParameters","giop-gias.InvalidInputParamete.InvalidInputParameter_badInputParameters",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_Buffer, {"Buffer","giop-gias.UCO.Buffer",FT_UINT32,BASE_DEC,VALS(UCO_BufferType),0x0,NULL,HFILL}},
{&hf_UCO_Buffer_octet_buffer_loop, {"Seq length of Buffer_octet_buffer","giop-gias.UCO.Buffer.octet_buffer.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_octet_buffer, {"Buffer_octet_buffer","giop-gias.UCO.Buffer.octet_buffer",FT_BYTES,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_char_buffer_loop, {"Seq length of Buffer_char_buffer","giop-gias.UCO.Buffer.char_buffer.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_char_buffer, {"Buffer_char_buffer","giop-gias.UCO.Buffer.char_buffer",FT_UINT8,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_ushort_buffer_loop, {"Seq length of Buffer_ushort_buffer","giop-gias.UCO.Buffer.ushort_buffer.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_ushort_buffer, {"Buffer_ushort_buffer","giop-gias.UCO.Buffer.ushort_buffer",FT_UINT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_short_buffer_loop, {"Seq length of Buffer_short_buffer","giop-gias.UCO.Buffer.short_buffer.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_short_buffer, {"Buffer_short_buffer","giop-gias.UCO.Buffer.short_buffer",FT_INT16,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_ulong_buffer_loop, {"Seq length of Buffer_ulong_buffer","giop-gias.UCO.Buffer.ulong_buffer.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_ulong_buffer, {"Buffer_ulong_buffer","giop-gias.UCO.Buffer.ulong_buffer",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_long_buffer_loop, {"Seq length of Buffer_long_buffer","giop-gias.UCO.Buffer.long_buffer.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_long_buffer, {"Buffer_long_buffer","giop-gias.UCO.Buffer.long_buffer",FT_INT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_float_buffer_loop, {"Seq length of Buffer_float_buffer","giop-gias.UCO.Buffer.float_buffer.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_float_buffer, {"Buffer_float_buffer","giop-gias.UCO.Buffer.float_buffer",FT_FLOAT,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_double_buffer_loop, {"Seq length of Buffer_double_buffer","giop-gias.UCO.Buffer.double_buffer.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_UCO_Buffer_double_buffer, {"Buffer_double_buffer","giop-gias.UCO.Buffer.double_buffer",FT_DOUBLE,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Destination_Destination, {"Destination","giop-gias.GIAS.Destination",FT_UINT32,BASE_DEC,VALS(GIAS_DestinationType),0x0,NULL,HFILL}},
{&hf_GIAS_Destination_e_dest, {"Destination_e_dest","giop-gias.GIAS.Destination.e_dest",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Domain_Domain, {"Domain","giop-gias.GIAS.Domain",FT_UINT32,BASE_DEC,VALS(GIAS_DomainType),0x0,NULL,HFILL}},
{&hf_GIAS_Domain_t, {"Domain_t","giop-gias.GIAS.Domain.t",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Domain_is_loop, {"Seq length of Domain_is","giop-gias.GIAS.Domain.is.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Domain_fps_loop, {"Seq length of Domain_fps","giop-gias.GIAS.Domain.fps.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Domain_l_loop, {"Seq length of Domain_l","giop-gias.GIAS.Domain.l.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Domain_l, {"Domain_l","giop-gias.GIAS.Domain.l",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Domain_ol_loop, {"Seq length of Domain_ol","giop-gias.GIAS.Domain.ol.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Domain_ol, {"Domain_ol","giop-gias.GIAS.Domain.ol",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Domain_gs_loop, {"Seq length of Domain_gs","giop-gias.GIAS.Domain.gs.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Domain_bd_loop, {"Seq length of Domain_bd","giop-gias.GIAS.Domain.bd.size",FT_UINT32,BASE_DEC,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Domain_bd, {"Domain_bd","giop-gias.GIAS.Domain.bd",FT_BYTES,BASE_NONE,NULL,0x0,NULL,HFILL}},
{&hf_GIAS_Domain_bv, {"Domain_bv","giop-gias.GIAS.Domain.bv",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
{&hf_GIAS_LifeEvent_LifeEvent, {"LifeEvent","giop-gias.GIAS.LifeEvent",FT_UINT32,BASE_DEC,VALS(GIAS_LifeEventType),0x0,NULL,HFILL}},
{&hf_GIAS_LifeEvent_ev, {"LifeEvent_ev","giop-gias.GIAS.LifeEvent.ev",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
};
static ei_register_info ei[] = {
{ &ei_gias_unknown_giop_msg, { "giop-gias.unknown_giop_msg", PI_PROTOCOL, PI_WARN, "Unknown GIOP message", EXPFILL }},
{ &ei_gias_unknown_exception, { "giop-gias.unknown_exception", PI_PROTOCOL, PI_WARN, "Unknown exception", EXPFILL }},
{ &ei_gias_unknown_reply_status, { "giop-gias.unknown_reply_status", PI_PROTOCOL, PI_WARN, "Unknown reply status", EXPFILL }},
};
static gint *ett[] = {
&ett_gias,
};
expert_module_t* expert_gias;
proto_gias = proto_register_protocol("Gias Dissector Using GIOP API" , "GIAS", "giop-gias" );
proto_register_field_array(proto_gias, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_gias = expert_register_protocol(proto_gias);
expert_register_field_array(expert_gias, ei, array_length(ei));
}
void proto_reg_handoff_giop_gias(void)
{
register_giop_user_module(dissect_gias, "GIAS", "CB/Callback", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/AccessManager", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/CatalogMgr", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/CreateAssociationRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/CreateMetaDataRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/CreateRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/CreationMgr", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/DataModelMgr", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/GetParametersRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/GetRelatedFilesRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/HitCountRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/IngestMgr", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/IngestRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/Library", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/LibraryManager", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/OrderMgr", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/OrderRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/ProductMgr", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/QueryOrderMgr", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/Request", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/RequestManager", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/SetAvailabilityRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/StandingQueryMgr", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/SubmitQueryOrderRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/SubmitQueryRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/SubmitStandingQueryRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/UpdateByQueryRequest", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/UpdateMgr", proto_gias );
register_giop_user_module(dissect_gias, "GIAS", "GIAS/UpdateRequest", proto_gias );
register_giop_user(dissect_gias, "GIAS" ,proto_gias);
}
