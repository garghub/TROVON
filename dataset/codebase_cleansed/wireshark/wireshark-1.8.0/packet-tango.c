static void decode_ex_Tango_DevFailed(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_DevFailed_errors;
guint32 i_DevFailed_errors;
u_octet4_loop_DevFailed_errors = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevFailed_errors = %u",u_octet4_loop_DevFailed_errors);
}
for (i_DevFailed_errors=0; i_DevFailed_errors < u_octet4_loop_DevFailed_errors; i_DevFailed_errors++) {
decode_Tango_DevError_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
}
static void decode_ex_Tango_MultiDevFailed(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_MultiDevFailed_errors;
guint32 i_MultiDevFailed_errors;
u_octet4_loop_MultiDevFailed_errors = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of MultiDevFailed_errors = %u",u_octet4_loop_MultiDevFailed_errors);
}
for (i_MultiDevFailed_errors=0; i_MultiDevFailed_errors < u_octet4_loop_MultiDevFailed_errors; i_MultiDevFailed_errors++) {
decode_Tango_NamedDevError_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
}
static gboolean decode_user_exception(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *ptree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
proto_tree *tree _U_;
if (!header->exception_id)
return FALSE;
if (strcmp(header->exception_id, user_exception_Tango_DevFailed) == 0) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_ex_Tango_DevFailed(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(header->exception_id, user_exception_Tango_MultiDevFailed) == 0) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_ex_Tango_MultiDevFailed(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
return FALSE;
}
static void decode_get_Tango_Device_name_at(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
static void decode_get_Tango_Device_description_at(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"description (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
static void decode_get_Tango_Device_state_at(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"state = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_DevState,"Unknown Enum Value"));
}
}
static void decode_get_Tango_Device_status_at(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"status (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
static void decode_get_Tango_Device_adm_name_at(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"adm_name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
static void decode_Tango_Device_command_inout(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
switch(header->message_type) {
case Request:
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"command (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
get_CDR_any(tvb,tree,offset,stream_is_big_endian, boundary, header);
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
static void decode_Tango_Device_get_attribute_config(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_names;
guint32 i_names;
guint32 u_octet4;
gchar *seq = NULL;
guint32 u_octet4_loop_AttributeConfigList;
guint32 i_AttributeConfigList;
switch(header->message_type) {
case Request:
u_octet4_loop_names = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of names = %u",u_octet4_loop_names);
}
for (i_names=0; i_names < u_octet4_loop_names; i_names++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"names (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_AttributeConfigList = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of AttributeConfigList = %u",u_octet4_loop_AttributeConfigList);
}
for (i_AttributeConfigList=0; i_AttributeConfigList < u_octet4_loop_AttributeConfigList; i_AttributeConfigList++) {
decode_Tango_AttributeConfig_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_set_attribute_config(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_new_conf;
guint32 i_new_conf;
switch(header->message_type) {
case Request:
u_octet4_loop_new_conf = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of new_conf = %u",u_octet4_loop_new_conf);
}
for (i_new_conf=0; i_new_conf < u_octet4_loop_new_conf; i_new_conf++) {
decode_Tango_AttributeConfig_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_read_attributes(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_names;
guint32 i_names;
guint32 u_octet4;
gchar *seq = NULL;
guint32 u_octet4_loop_AttributeValueList;
guint32 i_AttributeValueList;
switch(header->message_type) {
case Request:
u_octet4_loop_names = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of names = %u",u_octet4_loop_names);
}
for (i_names=0; i_names < u_octet4_loop_names; i_names++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"names (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_AttributeValueList = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of AttributeValueList = %u",u_octet4_loop_AttributeValueList);
}
for (i_AttributeValueList=0; i_AttributeValueList < u_octet4_loop_AttributeValueList; i_AttributeValueList++) {
decode_Tango_AttributeValue_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_write_attributes(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_values;
guint32 i_values;
switch(header->message_type) {
case Request:
u_octet4_loop_values = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of values = %u",u_octet4_loop_values);
}
for (i_values=0; i_values < u_octet4_loop_values; i_values++) {
decode_Tango_AttributeValue_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_ping(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
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
static void decode_Tango_Device_black_box(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
gint32 s_octet4;
guint32 u_octet4_loop_DevVarStringArray;
guint32 i_DevVarStringArray;
guint32 u_octet4;
gchar *seq = NULL;
switch(header->message_type) {
case Request:
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"n = %i",s_octet4);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_DevVarStringArray = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevVarStringArray = %u",u_octet4_loop_DevVarStringArray);
}
for (i_DevVarStringArray=0; i_DevVarStringArray < u_octet4_loop_DevVarStringArray; i_DevVarStringArray++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevVarStringArray (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
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
static void decode_Tango_Device_info(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_Tango_DevInfo_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_command_list_query(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_DevCmdInfoList;
guint32 i_DevCmdInfoList;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_DevCmdInfoList = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevCmdInfoList = %u",u_octet4_loop_DevCmdInfoList);
}
for (i_DevCmdInfoList=0; i_DevCmdInfoList < u_octet4_loop_DevCmdInfoList; i_DevCmdInfoList++) {
decode_Tango_DevCmdInfo_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_command_query(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
switch(header->message_type) {
case Request:
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"command (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_Tango_DevCmdInfo_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_2_command_inout_2(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
switch(header->message_type) {
case Request:
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"command (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
get_CDR_any(tvb,tree,offset,stream_is_big_endian, boundary, header);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"source = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_DevSource,"Unknown Enum Value"));
}
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
static void decode_Tango_Device_2_read_attributes_2(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_names;
guint32 i_names;
guint32 u_octet4;
gchar *seq = NULL;
guint32 u_octet4_loop_AttributeValueList;
guint32 i_AttributeValueList;
switch(header->message_type) {
case Request:
u_octet4_loop_names = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of names = %u",u_octet4_loop_names);
}
for (i_names=0; i_names < u_octet4_loop_names; i_names++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"names (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"source = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_DevSource,"Unknown Enum Value"));
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_AttributeValueList = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of AttributeValueList = %u",u_octet4_loop_AttributeValueList);
}
for (i_AttributeValueList=0; i_AttributeValueList < u_octet4_loop_AttributeValueList; i_AttributeValueList++) {
decode_Tango_AttributeValue_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_2_get_attribute_config_2(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_names;
guint32 i_names;
guint32 u_octet4;
gchar *seq = NULL;
guint32 u_octet4_loop_AttributeConfigList_2;
guint32 i_AttributeConfigList_2;
switch(header->message_type) {
case Request:
u_octet4_loop_names = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of names = %u",u_octet4_loop_names);
}
for (i_names=0; i_names < u_octet4_loop_names; i_names++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"names (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_AttributeConfigList_2 = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of AttributeConfigList_2 = %u",u_octet4_loop_AttributeConfigList_2);
}
for (i_AttributeConfigList_2=0; i_AttributeConfigList_2 < u_octet4_loop_AttributeConfigList_2; i_AttributeConfigList_2++) {
decode_Tango_AttributeConfig_2_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_2_command_list_query_2(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_DevCmdInfoList_2;
guint32 i_DevCmdInfoList_2;
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_DevCmdInfoList_2 = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevCmdInfoList_2 = %u",u_octet4_loop_DevCmdInfoList_2);
}
for (i_DevCmdInfoList_2=0; i_DevCmdInfoList_2 < u_octet4_loop_DevCmdInfoList_2; i_DevCmdInfoList_2++) {
decode_Tango_DevCmdInfo_2_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_2_command_query_2(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
switch(header->message_type) {
case Request:
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"command (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_Tango_DevCmdInfo_2_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_2_command_inout_history_2(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
gint32 s_octet4;
guint32 u_octet4_loop_DevCmdHistoryList;
guint32 i_DevCmdHistoryList;
switch(header->message_type) {
case Request:
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"command (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"n = %i",s_octet4);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_DevCmdHistoryList = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevCmdHistoryList = %u",u_octet4_loop_DevCmdHistoryList);
}
for (i_DevCmdHistoryList=0; i_DevCmdHistoryList < u_octet4_loop_DevCmdHistoryList; i_DevCmdHistoryList++) {
decode_Tango_DevCmdHistory_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_2_read_attribute_history_2(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
gint32 s_octet4;
guint32 u_octet4_loop_DevAttrHistoryList;
guint32 i_DevAttrHistoryList;
switch(header->message_type) {
case Request:
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"n = %i",s_octet4);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_DevAttrHistoryList = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevAttrHistoryList = %u",u_octet4_loop_DevAttrHistoryList);
}
for (i_DevAttrHistoryList=0; i_DevAttrHistoryList < u_octet4_loop_DevAttrHistoryList; i_DevAttrHistoryList++) {
decode_Tango_DevAttrHistory_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_3_read_attributes_3(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_names;
guint32 i_names;
guint32 u_octet4;
gchar *seq = NULL;
guint32 u_octet4_loop_AttributeValueList_3;
guint32 i_AttributeValueList_3;
switch(header->message_type) {
case Request:
u_octet4_loop_names = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of names = %u",u_octet4_loop_names);
}
for (i_names=0; i_names < u_octet4_loop_names; i_names++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"names (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"source = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_DevSource,"Unknown Enum Value"));
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_AttributeValueList_3 = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of AttributeValueList_3 = %u",u_octet4_loop_AttributeValueList_3);
}
for (i_AttributeValueList_3=0; i_AttributeValueList_3 < u_octet4_loop_AttributeValueList_3; i_AttributeValueList_3++) {
decode_Tango_AttributeValue_3_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_3_write_attributes_3(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_values;
guint32 i_values;
switch(header->message_type) {
case Request:
u_octet4_loop_values = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of values = %u",u_octet4_loop_values);
}
for (i_values=0; i_values < u_octet4_loop_values; i_values++) {
decode_Tango_AttributeValue_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_3_read_attribute_history_3(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
gint32 s_octet4;
guint32 u_octet4_loop_DevAttrHistoryList_3;
guint32 i_DevAttrHistoryList_3;
switch(header->message_type) {
case Request:
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"n = %i",s_octet4);
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_DevAttrHistoryList_3 = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevAttrHistoryList_3 = %u",u_octet4_loop_DevAttrHistoryList_3);
}
for (i_DevAttrHistoryList_3=0; i_DevAttrHistoryList_3 < u_octet4_loop_DevAttrHistoryList_3; i_DevAttrHistoryList_3++) {
decode_Tango_DevAttrHistory_3_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_3_info_3(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
switch(header->message_type) {
case Request:
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
decode_Tango_DevInfo_3_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_3_get_attribute_config_3(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_names;
guint32 i_names;
guint32 u_octet4;
gchar *seq = NULL;
guint32 u_octet4_loop_AttributeConfigList_3;
guint32 i_AttributeConfigList_3;
switch(header->message_type) {
case Request:
u_octet4_loop_names = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of names = %u",u_octet4_loop_names);
}
for (i_names=0; i_names < u_octet4_loop_names; i_names++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"names (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
break;
case Reply:
switch(header->rep_status) {
case NO_EXCEPTION:
u_octet4_loop_AttributeConfigList_3 = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of AttributeConfigList_3 = %u",u_octet4_loop_AttributeConfigList_3);
}
for (i_AttributeConfigList_3=0; i_AttributeConfigList_3 < u_octet4_loop_AttributeConfigList_3; i_AttributeConfigList_3++) {
decode_Tango_AttributeConfig_3_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_Device_3_set_attribute_config_3(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_new_conf;
guint32 i_new_conf;
switch(header->message_type) {
case Request:
u_octet4_loop_new_conf = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of new_conf = %u",u_octet4_loop_new_conf);
}
for (i_new_conf=0; i_new_conf < u_octet4_loop_new_conf; i_new_conf++) {
decode_Tango_AttributeConfig_3_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
static void decode_Tango_DevVarLongStringArray_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_DevVarLongStringArray_lvalue;
guint32 i_DevVarLongStringArray_lvalue;
gint32 s_octet4;
guint32 u_octet4_loop_DevVarLongStringArray_svalue;
guint32 i_DevVarLongStringArray_svalue;
guint32 u_octet4;
gchar *seq = NULL;
u_octet4_loop_DevVarLongStringArray_lvalue = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevVarLongStringArray_lvalue = %u",u_octet4_loop_DevVarLongStringArray_lvalue);
}
for (i_DevVarLongStringArray_lvalue=0; i_DevVarLongStringArray_lvalue < u_octet4_loop_DevVarLongStringArray_lvalue; i_DevVarLongStringArray_lvalue++) {
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"DevVarLongStringArray_lvalue = %i",s_octet4);
}
}
u_octet4_loop_DevVarLongStringArray_svalue = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevVarLongStringArray_svalue = %u",u_octet4_loop_DevVarLongStringArray_svalue);
}
for (i_DevVarLongStringArray_svalue=0; i_DevVarLongStringArray_svalue < u_octet4_loop_DevVarLongStringArray_svalue; i_DevVarLongStringArray_svalue++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevVarLongStringArray_svalue (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
}
static void decode_Tango_DevVarDoubleStringArray_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4_loop_DevVarDoubleStringArray_dvalue;
guint32 i_DevVarDoubleStringArray_dvalue;
gdouble my_double;
guint32 u_octet4_loop_DevVarDoubleStringArray_svalue;
guint32 i_DevVarDoubleStringArray_svalue;
guint32 u_octet4;
gchar *seq = NULL;
u_octet4_loop_DevVarDoubleStringArray_dvalue = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevVarDoubleStringArray_dvalue = %u",u_octet4_loop_DevVarDoubleStringArray_dvalue);
}
for (i_DevVarDoubleStringArray_dvalue=0; i_DevVarDoubleStringArray_dvalue < u_octet4_loop_DevVarDoubleStringArray_dvalue; i_DevVarDoubleStringArray_dvalue++) {
my_double = get_CDR_double(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-8,8,"DevVarDoubleStringArray_dvalue = %.15e",my_double);
}
}
u_octet4_loop_DevVarDoubleStringArray_svalue = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevVarDoubleStringArray_svalue = %u",u_octet4_loop_DevVarDoubleStringArray_svalue);
}
for (i_DevVarDoubleStringArray_svalue=0; i_DevVarDoubleStringArray_svalue < u_octet4_loop_DevVarDoubleStringArray_svalue; i_DevVarDoubleStringArray_svalue++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevVarDoubleStringArray_svalue (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
}
static void decode_Tango_TimeVal_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
gint32 s_octet4;
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"TimeVal_tv_sec = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"TimeVal_tv_usec = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"TimeVal_tv_nsec = %i",s_octet4);
}
}
static void decode_Tango_DevCmdInfo_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
gint32 s_octet4;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevCmdInfo_cmd_name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"DevCmdInfo_cmd_tag = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"DevCmdInfo_in_type = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"DevCmdInfo_out_type = %i",s_octet4);
}
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevCmdInfo_in_type_desc (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevCmdInfo_out_type_desc (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
static void decode_Tango_DevCmdInfo_2_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
gint32 s_octet4;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevCmdInfo_2_cmd_name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"DevCmdInfo_2_level = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_DispLevel,"Unknown Enum Value"));
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"DevCmdInfo_2_cmd_tag = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"DevCmdInfo_2_in_type = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"DevCmdInfo_2_out_type = %i",s_octet4);
}
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevCmdInfo_2_in_type_desc (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevCmdInfo_2_out_type_desc (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
static void decode_Tango_DevError_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevError_reason (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"DevError_severity = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_ErrSeverity,"Unknown Enum Value"));
}
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevError_desc (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevError_origin (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
static void decode_Tango_NamedDevError_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
gint32 s_octet4;
guint32 u_octet4_loop_NamedDevError_err_list;
guint32 i_NamedDevError_err_list;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"NamedDevError_name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"NamedDevError_index_in_call = %i",s_octet4);
}
u_octet4_loop_NamedDevError_err_list = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of NamedDevError_err_list = %u",u_octet4_loop_NamedDevError_err_list);
}
for (i_NamedDevError_err_list=0; i_NamedDevError_err_list < u_octet4_loop_NamedDevError_err_list; i_NamedDevError_err_list++) {
decode_Tango_DevError_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
}
static void decode_Tango_AttributeConfig_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
gint32 s_octet4;
guint32 u_octet4_loop_AttributeConfig_extensions;
guint32 i_AttributeConfig_extensions;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_writable = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_AttrWriteType,"Unknown Enum Value"));
}
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_data_format = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_AttrDataFormat,"Unknown Enum Value"));
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_data_type = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_max_dim_x = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_max_dim_y = %i",s_octet4);
}
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_description (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_label (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_unit (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_standard_unit (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_display_unit (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_format (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_min_value (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_max_value (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_min_alarm (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_max_alarm (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_writable_attr_name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4_loop_AttributeConfig_extensions = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of AttributeConfig_extensions = %u",u_octet4_loop_AttributeConfig_extensions);
}
for (i_AttributeConfig_extensions=0; i_AttributeConfig_extensions < u_octet4_loop_AttributeConfig_extensions; i_AttributeConfig_extensions++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_extensions (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
}
static void decode_Tango_AttributeConfig_2_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
gint32 s_octet4;
guint32 u_octet4_loop_AttributeConfig_2_extensions;
guint32 i_AttributeConfig_2_extensions;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_2_writable = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_AttrWriteType,"Unknown Enum Value"));
}
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_2_data_format = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_AttrDataFormat,"Unknown Enum Value"));
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_2_data_type = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_2_max_dim_x = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_2_max_dim_y = %i",s_octet4);
}
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_description (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_label (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_unit (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_standard_unit (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_display_unit (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_format (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_min_value (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_max_value (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_min_alarm (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_max_alarm (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_writable_attr_name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_2_level = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_DispLevel,"Unknown Enum Value"));
}
u_octet4_loop_AttributeConfig_2_extensions = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of AttributeConfig_2_extensions = %u",u_octet4_loop_AttributeConfig_2_extensions);
}
for (i_AttributeConfig_2_extensions=0; i_AttributeConfig_2_extensions < u_octet4_loop_AttributeConfig_2_extensions; i_AttributeConfig_2_extensions++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_2_extensions (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
}
static void decode_Tango_AttributeValue_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
gint32 s_octet4;
get_CDR_any(tvb,tree,offset,stream_is_big_endian, boundary, header);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeValue_quality = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_AttrQuality,"Unknown Enum Value"));
}
decode_Tango_TimeVal_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeValue_name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeValue_dim_x = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeValue_dim_y = %i",s_octet4);
}
}
static void decode_Tango_AttributeDim_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
gint32 s_octet4;
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeDim_dim_x = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeDim_dim_y = %i",s_octet4);
}
}
static void decode_Tango_AttributeValue_3_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
guint32 u_octet4_loop_AttributeValue_3_err_list;
guint32 i_AttributeValue_3_err_list;
get_CDR_any(tvb,tree,offset,stream_is_big_endian, boundary, header);
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeValue_3_quality = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_AttrQuality,"Unknown Enum Value"));
}
decode_Tango_TimeVal_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeValue_3_name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
decode_Tango_AttributeDim_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
decode_Tango_AttributeDim_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
u_octet4_loop_AttributeValue_3_err_list = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of AttributeValue_3_err_list = %u",u_octet4_loop_AttributeValue_3_err_list);
}
for (i_AttributeValue_3_err_list=0; i_AttributeValue_3_err_list < u_octet4_loop_AttributeValue_3_err_list; i_AttributeValue_3_err_list++) {
decode_Tango_DevError_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
}
static void decode_Tango_ChangeEventProp_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
guint32 u_octet4_loop_ChangeEventProp_extensions;
guint32 i_ChangeEventProp_extensions;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"ChangeEventProp_rel_change (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"ChangeEventProp_abs_change (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4_loop_ChangeEventProp_extensions = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of ChangeEventProp_extensions = %u",u_octet4_loop_ChangeEventProp_extensions);
}
for (i_ChangeEventProp_extensions=0; i_ChangeEventProp_extensions < u_octet4_loop_ChangeEventProp_extensions; i_ChangeEventProp_extensions++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"ChangeEventProp_extensions (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
}
static void decode_Tango_PeriodicEventProp_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
guint32 u_octet4_loop_PeriodicEventProp_extensions;
guint32 i_PeriodicEventProp_extensions;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"PeriodicEventProp_period (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4_loop_PeriodicEventProp_extensions = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of PeriodicEventProp_extensions = %u",u_octet4_loop_PeriodicEventProp_extensions);
}
for (i_PeriodicEventProp_extensions=0; i_PeriodicEventProp_extensions < u_octet4_loop_PeriodicEventProp_extensions; i_PeriodicEventProp_extensions++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"PeriodicEventProp_extensions (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
}
static void decode_Tango_ArchiveEventProp_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
guint32 u_octet4_loop_ArchiveEventProp_extensions;
guint32 i_ArchiveEventProp_extensions;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"ArchiveEventProp_rel_change (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"ArchiveEventProp_abs_change (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"ArchiveEventProp_period (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4_loop_ArchiveEventProp_extensions = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of ArchiveEventProp_extensions = %u",u_octet4_loop_ArchiveEventProp_extensions);
}
for (i_ArchiveEventProp_extensions=0; i_ArchiveEventProp_extensions < u_octet4_loop_ArchiveEventProp_extensions; i_ArchiveEventProp_extensions++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"ArchiveEventProp_extensions (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
}
static void decode_Tango_EventProperties_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
decode_Tango_ChangeEventProp_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
decode_Tango_PeriodicEventProp_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
decode_Tango_ArchiveEventProp_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
static void decode_Tango_AttributeAlarm_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
guint32 u_octet4_loop_AttributeAlarm_extensions;
guint32 i_AttributeAlarm_extensions;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeAlarm_min_alarm (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeAlarm_max_alarm (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeAlarm_min_warning (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeAlarm_max_warning (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeAlarm_delta_t (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeAlarm_delta_val (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4_loop_AttributeAlarm_extensions = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of AttributeAlarm_extensions = %u",u_octet4_loop_AttributeAlarm_extensions);
}
for (i_AttributeAlarm_extensions=0; i_AttributeAlarm_extensions < u_octet4_loop_AttributeAlarm_extensions; i_AttributeAlarm_extensions++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeAlarm_extensions (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
}
static void decode_Tango_AttributeConfig_3_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
gint32 s_octet4;
guint32 u_octet4_loop_AttributeConfig_3_extensions;
guint32 i_AttributeConfig_3_extensions;
guint32 u_octet4_loop_AttributeConfig_3_sys_extensions;
guint32 i_AttributeConfig_3_sys_extensions;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_3_name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_3_writable = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_AttrWriteType,"Unknown Enum Value"));
}
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_3_data_format = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_AttrDataFormat,"Unknown Enum Value"));
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_3_data_type = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_3_max_dim_x = %i",s_octet4);
}
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_3_max_dim_y = %i",s_octet4);
}
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_3_description (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_3_label (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_3_unit (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_3_standard_unit (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_3_display_unit (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_3_format (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_3_min_value (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_3_max_value (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_3_writable_attr_name (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"AttributeConfig_3_level = %u (%s)",u_octet4,val_to_str(u_octet4,Tango_DispLevel,"Unknown Enum Value"));
}
decode_Tango_AttributeAlarm_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
decode_Tango_EventProperties_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
u_octet4_loop_AttributeConfig_3_extensions = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of AttributeConfig_3_extensions = %u",u_octet4_loop_AttributeConfig_3_extensions);
}
for (i_AttributeConfig_3_extensions=0; i_AttributeConfig_3_extensions < u_octet4_loop_AttributeConfig_3_extensions; i_AttributeConfig_3_extensions++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_3_extensions (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
u_octet4_loop_AttributeConfig_3_sys_extensions = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of AttributeConfig_3_sys_extensions = %u",u_octet4_loop_AttributeConfig_3_sys_extensions);
}
for (i_AttributeConfig_3_sys_extensions=0; i_AttributeConfig_3_sys_extensions < u_octet4_loop_AttributeConfig_3_sys_extensions; i_AttributeConfig_3_sys_extensions++) {
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"AttributeConfig_3_sys_extensions (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
}
static void decode_Tango_DevInfo_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
gint32 s_octet4;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevInfo_dev_class (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevInfo_server_id (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevInfo_server_host (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"DevInfo_server_version = %i",s_octet4);
}
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevInfo_doc_url (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
static void decode_Tango_DevInfo_3_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint32 u_octet4;
gchar *seq = NULL;
gint32 s_octet4;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevInfo_3_dev_class (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevInfo_3_server_id (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevInfo_3_server_host (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
s_octet4 = get_CDR_long(tvb,offset,stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4,4,"DevInfo_3_server_version = %i",s_octet4);
}
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevInfo_3_doc_url (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"DevInfo_3_dev_type (%u) = %s",
u_octet4, (u_octet4 > 0) ? seq : "");
}
g_free(seq);
seq = NULL;
}
static void decode_Tango_DevCmdHistory_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint8 u_octet1;
guint32 u_octet4_loop_DevCmdHistory_errors;
guint32 i_DevCmdHistory_errors;
decode_Tango_TimeVal_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
u_octet1 = get_CDR_boolean(tvb,offset);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-1,1,"DevCmdHistory_cmd_failed = %u",u_octet1);
}
get_CDR_any(tvb,tree,offset,stream_is_big_endian, boundary, header);
u_octet4_loop_DevCmdHistory_errors = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevCmdHistory_errors = %u",u_octet4_loop_DevCmdHistory_errors);
}
for (i_DevCmdHistory_errors=0; i_DevCmdHistory_errors < u_octet4_loop_DevCmdHistory_errors; i_DevCmdHistory_errors++) {
decode_Tango_DevError_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
}
static void decode_Tango_DevAttrHistory_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint8 u_octet1;
guint32 u_octet4_loop_DevAttrHistory_errors;
guint32 i_DevAttrHistory_errors;
u_octet1 = get_CDR_boolean(tvb,offset);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-1,1,"DevAttrHistory_attr_failed = %u",u_octet1);
}
decode_Tango_AttributeValue_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
u_octet4_loop_DevAttrHistory_errors = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of DevAttrHistory_errors = %u",u_octet4_loop_DevAttrHistory_errors);
}
for (i_DevAttrHistory_errors=0; i_DevAttrHistory_errors < u_octet4_loop_DevAttrHistory_errors; i_DevAttrHistory_errors++) {
decode_Tango_DevError_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
}
static void decode_Tango_DevAttrHistory_3_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_, gboolean stream_is_big_endian _U_) {
guint8 u_octet1;
u_octet1 = get_CDR_boolean(tvb,offset);
if (tree) {
proto_tree_add_text(tree,tvb,*offset-1,1,"DevAttrHistory_3_attr_failed = %u",u_octet1);
}
decode_Tango_AttributeValue_3_st(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
}
static proto_tree *start_dissecting(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset) {
proto_item *ti = NULL;
proto_tree *tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TANGO");
if (ptree) {
ti = proto_tree_add_item(ptree, proto_tango, tvb, *offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_tango);
}
return tree;
}
static gboolean dissect_tango(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset, MessageHeader *header, gchar *operation, gchar *idlname) {
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
if (strcmp(operation, Tango_Device_command_inout_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_command_inout(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_get_attribute_config_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_get_attribute_config(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_set_attribute_config_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_set_attribute_config(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_read_attributes_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_read_attributes(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_write_attributes_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_write_attributes(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_ping_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_ping(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_black_box_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_black_box(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_info_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_info(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_command_list_query_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_command_list_query(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_command_query_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_command_query(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_2_command_inout_2_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_2") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_2_command_inout_2(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_2_read_attributes_2_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_2") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_2_read_attributes_2(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_2_get_attribute_config_2_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_2") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_2_get_attribute_config_2(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_2_command_list_query_2_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_2") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_2_command_list_query_2(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_2_command_query_2_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_2") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_2_command_query_2(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_2_command_inout_history_2_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_2") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_2_command_inout_history_2(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_2_read_attribute_history_2_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_2") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_2_read_attribute_history_2(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_3_read_attributes_3_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_3") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_3_read_attributes_3(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_3_write_attributes_3_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_3") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_3_write_attributes_3(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_3_read_attribute_history_3_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_3") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_3_read_attribute_history_3(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_3_info_3_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_3") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_3_info_3(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_3_get_attribute_config_3_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_3") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_3_get_attribute_config_3(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, Tango_Device_3_set_attribute_config_3_op) == 0
&& (!idlname || strcmp(idlname, "Tango/Device_3") == 0)) {
process_RequestOperation();
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_Tango_Device_3_set_attribute_config_3(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, get_Tango_Device_name_at) == 0 && (header->message_type == Reply) && (header->rep_status == NO_EXCEPTION) ) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_get_Tango_Device_name_at(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, get_Tango_Device_description_at) == 0 && (header->message_type == Reply) && (header->rep_status == NO_EXCEPTION) ) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_get_Tango_Device_description_at(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, get_Tango_Device_state_at) == 0 && (header->message_type == Reply) && (header->rep_status == NO_EXCEPTION) ) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_get_Tango_Device_state_at(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, get_Tango_Device_status_at) == 0 && (header->message_type == Reply) && (header->rep_status == NO_EXCEPTION) ) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_get_Tango_Device_status_at(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
return TRUE;
}
if (strcmp(operation, get_Tango_Device_adm_name_at) == 0 && (header->message_type == Reply) && (header->rep_status == NO_EXCEPTION) ) {
tree = start_dissecting(tvb, pinfo, ptree, offset);
decode_get_Tango_Device_adm_name_at(tvb, pinfo, tree, offset, header, operation, stream_is_big_endian);
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
void proto_register_giop_tango(void) {
static hf_register_info hf[] = {
{&hf_operationrequest, {"Request_Operation","TANGO.Request_Operation",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
};
static gint *ett[] = {
&ett_tango,
};
proto_tango = proto_register_protocol("Tango Dissector Using GIOP API" , "TANGO", "giop-tango" );
proto_register_field_array(proto_tango, hf, array_length(hf));
proto_register_subtree_array(ett,array_length(ett));
}
void proto_reg_handoff_giop_tango(void) {
register_giop_user_module(dissect_tango, "TANGO", "Tango/Device", proto_tango );
register_giop_user_module(dissect_tango, "TANGO", "Tango/Device_2", proto_tango );
register_giop_user_module(dissect_tango, "TANGO", "Tango/Device_3", proto_tango );
register_giop_user(dissect_tango, "TANGO" ,proto_tango);
}
