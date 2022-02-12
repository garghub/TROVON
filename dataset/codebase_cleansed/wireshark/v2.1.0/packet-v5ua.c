static void
dissect_int_interface_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint32 identifier;
guint16 number_of_ids, id_number;
gint offset;
number_of_ids= (tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH) / INT_INTERFACE_ID_LENGTH;
offset = INT_IF_ID_LINK_OFFSET;
proto_item_append_text(parameter_item, "(");
for (id_number = 0; id_number < number_of_ids; id_number++) {
proto_tree_add_item(parameter_tree, hf_link_id, parameter_tvb, offset, INT_IF_ID_LINK_LENGTH, ENC_BIG_ENDIAN);
identifier = tvb_get_ntohl(parameter_tvb,offset)>>5;
if (id_number < 1) {
proto_item_append_text(parameter_item, "L:%d",identifier);
} else {
proto_item_append_text(parameter_item, " | L:%d",identifier);
}
linkIdentifier = identifier;
proto_tree_add_item(parameter_tree, hf_chnl_id, parameter_tvb, offset+3, INT_IF_ID_CHNL_LENGTH, ENC_BIG_ENDIAN);
identifier = tvb_get_guint8(parameter_tvb,offset+3)&0x1f;
proto_item_append_text(parameter_item, " C:%d", identifier);
offset += INT_INTERFACE_ID_LENGTH;
}
proto_item_append_text(parameter_item, ")");
}
static void
dissect_text_interface_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 if_id_length;
if_id_length = tvb_get_ntohs(parameter_tvb, TEXT_IF_ID_LENGTH_OFFSET) - TEXT_IF_ID_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_text_if_id, parameter_tvb, TEXT_IF_ID_VALUE_OFFSET, if_id_length, ENC_ASCII|ENC_NA);
proto_item_append_text(parameter_item, " (0x%.*s)", if_id_length,
tvb_get_string_enc(wmem_packet_scope(), parameter_tvb, TEXT_IF_ID_VALUE_OFFSET, if_id_length, ENC_ASCII));
}
static void
dissect_dlci_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item, packet_info *pinfo)
{
guint16 efa = 0, offset = 0;
guint8 sapi = -1;
guint8 tei = -1;
if (iua_version == RFC) offset = DLCI_SAPI_OFFSET;
else if(iua_version == DRAFT) offset = DLCI_HEADER_LENGTH + tvb_get_ntohs(parameter_tvb, DLCI_LENGTH_OFFSET);
proto_tree_add_item(parameter_tree, hf_dlci_zero_bit, parameter_tvb, offset, DLCI_SAPI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_dlci_spare_bit, parameter_tvb, offset, DLCI_SAPI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_dlci_sapi, parameter_tvb, offset, DLCI_SAPI_LENGTH, ENC_BIG_ENDIAN);
offset += DLCI_SAPI_LENGTH;
proto_tree_add_item(parameter_tree, hf_dlci_one_bit, parameter_tvb, offset, DLCI_TEI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_dlci_tei, parameter_tvb, offset, DLCI_TEI_LENGTH, ENC_BIG_ENDIAN);
sapi = tvb_get_ntohs(parameter_tvb, offset-DLCI_TEI_LENGTH-DLCI_SAPI_LENGTH)>>2;
tei = tvb_get_ntohs(parameter_tvb, offset-DLCI_TEI_LENGTH)>>1;
offset += DLCI_TEI_LENGTH;
efa = tvb_get_ntohs(parameter_tvb, offset);
dlci_efa = tvb_get_ntohs(parameter_tvb, offset);
if (dlci_efa >= 0 && dlci_efa <= 8175) { col_append_fstr(pinfo->cinfo, COL_INFO, " | ISDN: %u", dlci_efa); }
else if (dlci_efa == 8176) { col_append_str(pinfo->cinfo, COL_INFO, " | PSTN"); }
else if (dlci_efa == 8177) { col_append_str(pinfo->cinfo, COL_INFO, " | Ctrl"); }
else if (dlci_efa == 8178) { col_append_str(pinfo->cinfo, COL_INFO, " | BCC"); }
else if (dlci_efa == 8179) { col_append_str(pinfo->cinfo, COL_INFO, " | ProtProt"); }
else if (dlci_efa == 8180) { col_append_str(pinfo->cinfo, COL_INFO, " | LinkCtrl"); }
if(efa <= 8175) {
proto_tree_add_uint_format_value(parameter_tree, hf_efa, parameter_tvb, offset, EFA_LENGTH, efa,
"ISDN (%u)", efa);
proto_item_append_text(parameter_item, " (SAPI:%u TEI:%u EFA:ISDN (%u))",sapi,tei,efa);
}
else if (efa > 8175 && efa <= 8180){
proto_tree_add_uint_format_value(parameter_tree, hf_efa, parameter_tvb, offset, EFA_LENGTH, efa,
"%s (%u)", val_to_str_const(efa, efa_values, "unknown EFA"),tvb_get_ntohs(parameter_tvb, offset));
proto_item_append_text(parameter_item, " (SAPI:%u TEI:%u EFA:%s (%u))",sapi,tei,val_to_str_const(efa, efa_values, "unknown EFA-value"),efa);
}
else {
proto_tree_add_uint_format_value(parameter_tree, hf_efa, parameter_tvb, offset, EFA_LENGTH, efa,
"RESERVED (%u)", efa);
proto_item_append_text(parameter_item, " (SAPI:%u TEI:%u EFA:RESERVED (%u))",sapi,tei,efa);
}
}
static void
dissect_draft_error_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree)
{
guint16 offset = MGMT_ERROR_MSG_HEADER_LENGTH + tvb_get_ntohs(parameter_tvb, MGMT_ERROR_MSG_LENGTH_OFFSET) + 4;
proto_tree_add_item(parameter_tree, hf_draft_error_code, parameter_tvb, offset, MGMT_ERROR_CODE_LENGTH, ENC_BIG_ENDIAN);
offset += MGMT_ERROR_CODE_LENGTH ;
if( tvb_reported_length_remaining(parameter_tvb,offset) > 0 )
proto_tree_add_item(parameter_tree, hf_info_string, parameter_tvb, offset, msg_length - offset,ENC_ASCII|ENC_NA);
}
static void
dissect_error_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_error_code, parameter_tvb, MGMT_ERROR_CODE_OFFSET, MGMT_ERROR_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, MGMT_ERROR_CODE_OFFSET), error_code_values, "Unknown error code"));
}
static void
dissect_diagnostic_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 diag_info_length;
diag_info_length = tvb_get_ntohs(parameter_tvb, MGMT_ERROR_MSG_LENGTH_OFFSET) - MGMT_ERROR_MSG_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_diagnostic_info, parameter_tvb, PARAMETER_VALUE_OFFSET, diag_info_length, ENC_NA);
proto_item_append_text(parameter_item, " (%u byte%s)", diag_info_length, plurality(diag_info_length, "", "s"));
}
static void
dissect_status_type_identification_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 status_type, status_id;
status_type = tvb_get_ntohs(parameter_tvb, NTFY_STATUS_TYPE_OFFSET);
status_id = tvb_get_ntohs(parameter_tvb, NTFY_STATUS_IDENT_OFFSET);
proto_tree_add_item(parameter_tree, hf_status_type, parameter_tvb, NTFY_STATUS_TYPE_OFFSET, NTFY_STATUS_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(parameter_tree, hf_status_id, parameter_tvb, NTFY_STATUS_IDENT_OFFSET, NTFY_STATUS_IDENT_LENGTH,
status_id, "%u (%s)", status_id,
val_to_str_const(status_type * 256 * 256 + status_id, status_type_id_values, "unknown"));
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(status_type * 256 * 256 + status_id, status_type_id_values, "Unknown status information"));
}
static void
dissect_tei_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_tei_status, parameter_tvb, TEI_STATUS_OFFSET, TEI_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, TEI_STATUS_OFFSET), tei_status_values, "Unknown TEI status"));
}
static void
dissect_draft_tei_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
gint offset;
offset = tvb_get_ntohs(parameter_tvb, TEI_STATUS_LENGTH_OFFSET) + 8;
if(tvb_reported_length_remaining(parameter_tvb, offset) > 0 ){
proto_tree_add_item(parameter_tree, hf_tei_draft_status, parameter_tvb, offset, TEI_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, offset), tei_draft_status_values, "Unknown TEI Status"));
}
}
static void
dissect_asp_msg_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 adaptation_layer_id_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
proto_tree_add_item(parameter_tree, hf_adaptation_layer_id, parameter_tvb, PARAMETER_VALUE_OFFSET, adaptation_layer_id_length, ENC_ASCII|ENC_NA);
proto_item_append_text(parameter_item, " (%.*s)", adaptation_layer_id_length,
tvb_get_string_enc(wmem_packet_scope(), parameter_tvb, PARAMETER_VALUE_OFFSET, adaptation_layer_id_length, ENC_ASCII));
}
static void
dissect_scn_protocol_id_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 id_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
proto_tree_add_item(parameter_tree, hf_scn_protocol_id, parameter_tvb, PARAMETER_VALUE_OFFSET, id_length, ENC_ASCII|ENC_NA);
proto_item_append_text(parameter_item, " (%.*s)", id_length,
tvb_get_string_enc(wmem_packet_scope(), parameter_tvb, PARAMETER_VALUE_OFFSET, id_length, ENC_ASCII));
}
static void
dissect_asp_reason_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_asp_reason, parameter_tvb, ASP_REASON_OFFSET, ASP_REASON_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, ASP_REASON_OFFSET), asp_reason_values, "Unknown ASP down reason"));
}
static void
dissect_heartbeat_data_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 heartbeat_data_length;
heartbeat_data_length = tvb_get_ntohs(parameter_tvb, HEARTBEAT_MSG_LENGTH_OFFSET) - HEARTBEAT_MSG_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_heartbeat_data, parameter_tvb, HEARTBEAT_DATA_OFFSET, heartbeat_data_length, ENC_NA);
proto_item_append_text(parameter_item, " (%u byte%s)", heartbeat_data_length, plurality(heartbeat_data_length, "", "s"));
}
static void
dissect_traffic_mode_type_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_traffic_mode_type, parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET, TRAFFIC_MODE_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET), traffic_mode_type_values, "Unknown traffic mode type"));
}
static void
dissect_integer_range_interface_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 number_of_ranges, range_number, offset;
number_of_ranges = (tvb_get_ntohs(parameter_tvb, INT_RANGE_LENGTH_OFFSET) - INT_RANGE_HEADER_LENGTH) / IF_ID_INTERVAL_LENGTH;
offset = INT_RANGE_START_OFFSET;
for(range_number = 0; range_number < number_of_ranges; range_number++) {
proto_tree_add_item(parameter_tree, hf_if_range_start, parameter_tvb, offset + IF_ID_START_OFFSET, IF_ID_START_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_if_range_end, parameter_tvb, offset + IF_ID_END_OFFSET, IF_ID_END_LENGTH, ENC_BIG_ENDIAN);
offset += IF_ID_INTERVAL_LENGTH;
};
proto_item_append_text(parameter_item, " (%u range%s)", number_of_ranges, plurality(number_of_ranges, "", "s"));
}
static void
dissect_layer3_message(tvbuff_t *layer3_data_tvb, proto_tree *v5ua_tree,proto_item *parameter_item, packet_info *pinfo)
{
guint16 discriminator_offset;
if(iua_version == DRAFT){
discriminator_offset = DISCRIMINATOR_OFFSET;
}
else{
discriminator_offset = DISCRIMINATOR_OFFSET + PARAMETER_HEADER_LENGTH;
}
if (tvb_get_guint8(layer3_data_tvb, discriminator_offset) == 0x48){
guint16 protocol_data_length;
tvbuff_t *protocol_data_tvb;
protocol_data_length = tvb_get_ntohs(layer3_data_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
protocol_data_tvb = tvb_new_subset_length(layer3_data_tvb, PARAMETER_VALUE_OFFSET, protocol_data_length);
call_dissector(v52_handle, protocol_data_tvb, pinfo, v5ua_tree);
proto_item_append_text(parameter_item, " (%u byte%s)", protocol_data_length, plurality(protocol_data_length, "", "s"));
}
else{
guint16 protocol_data_length;
tvbuff_t *protocol_data_tvb;
protocol_data_length = tvb_get_ntohs(layer3_data_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
protocol_data_tvb = tvb_new_subset_length(layer3_data_tvb, PARAMETER_VALUE_OFFSET, protocol_data_length);
call_dissector(q931_handle, protocol_data_tvb, pinfo, v5ua_tree);
proto_item_append_text(parameter_item, " (%u byte%s)", protocol_data_length, plurality(protocol_data_length, "", "s"));
}
}
static void
dissect_release_reason_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
gint offset = RELEASE_REASON_OFFSET;
if(iua_version == DRAFT) offset = tvb_get_ntohs(parameter_tvb, RELEASE_REASON_LENGTH_OFFSET)+8;
proto_tree_add_item(parameter_tree, hf_release_reason, parameter_tvb, offset, RELEASE_REASON_LENGTH, ENC_BIG_ENDIAN);
if(iua_version != DRAFT)
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, offset), release_reason_values, "Unknown release reason"));
}
static void
dissect_link_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_link_status, parameter_tvb, LINK_STATUS_OFFSET, LINK_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, LINK_STATUS_OFFSET),link_status_values, "Unknown Link status"));
link_status_operational = tvb_get_ntohl(parameter_tvb, LINK_STATUS_OFFSET);
}
static void
dissect_sa_bit_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sa_bit_id, parameter_tvb, SA_BIT_ID_OFFSET, SA_BIT_ID_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sa_bit_value, parameter_tvb, SA_BIT_VALUE_OFFSET, SA_BIT_VALUE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s %s)",
val_to_str_const(tvb_get_ntohs(parameter_tvb, SA_BIT_ID_OFFSET), sa_bit_values, "unknown"),
val_to_str_const(tvb_get_ntohs(parameter_tvb, SA_BIT_VALUE_OFFSET), sa_bit_values, "unknown Bit"));
sa_bit_id = tvb_get_ntohs(parameter_tvb, SA_BIT_VALUE_OFFSET);
}
static void
dissect_error_indication_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_error_reason, parameter_tvb, ERROR_REASON_OFFSET, ERROR_REASON_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, ERROR_REASON_OFFSET), error_reason_values, "unknown"));
}
static void
dissect_asp_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_asp_identifier, parameter_tvb, ASP_IDENTIFIER_OFFSET, ASP_IDENTIFIER_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%d) ",tvb_get_ntohl(parameter_tvb,ASP_IDENTIFIER_OFFSET));
}
static void
dissect_info_string_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 info_string_length;
info_string_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
if(iua_version == DRAFT) info_string_length += 4;
if(info_string_length > 4){
info_string_length -= PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_info_string, parameter_tvb, INFO_STRING_OFFSET, info_string_length, ENC_ASCII|ENC_NA);
proto_item_append_text(parameter_item, " (%.*s)", info_string_length,
tvb_get_string_enc(wmem_packet_scope(), parameter_tvb, INFO_STRING_OFFSET, info_string_length, ENC_ASCII));
}
}
static void
dissect_unknown_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 parameter_value_length;
parameter_value_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
if (parameter_value_length > 0)
proto_tree_add_item(parameter_tree, hf_parameter_value, parameter_tvb, PARAMETER_VALUE_OFFSET, parameter_value_length, ENC_NA);
proto_item_append_text(parameter_item, " with tag %u and %u byte%s value",
tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET), parameter_value_length, plurality(parameter_value_length, "", "s"));
}
static void
dissect_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *v5ua_tree)
{
guint16 tag, length, padding_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
if((iua_version==DRAFT)&&(tag<=0x4)){
if(tag==0x1) length += 8;
else if(tag<=0x4) length += PARAMETER_HEADER_LENGTH;
if((msg_class==0 || msg_class==1 || msg_class==9) && msg_type<=10)
length = msg_length;
}
padding_length = tvb_reported_length(parameter_tvb) - length;
paddingl = padding_length;
switch(iua_version){
case RFC:
parameter_tree = proto_tree_add_subtree(v5ua_tree, parameter_tvb, PARAMETER_HEADER_OFFSET, -1, ett_v5ua_parameter, &parameter_item,
val_to_str_const(tag, parameter_tag_values, "Unknown parameter"));
proto_tree_add_item(parameter_tree, hf_parameter_tag, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, ENC_BIG_ENDIAN);
break;
case DRAFT:
default:
parameter_tree = proto_tree_add_subtree(v5ua_tree, parameter_tvb, PARAMETER_HEADER_OFFSET, -1, ett_v5ua_parameter, &parameter_item,
val_to_str_const(tag, parameter_tag_draft_values, "Unknown parameter"));
proto_tree_add_item(parameter_tree, hf_parameter_tag_draft, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, ENC_BIG_ENDIAN);
break;
};
proto_tree_add_item(parameter_tree, hf_parameter_length, parameter_tvb, PARAMETER_LENGTH_OFFSET, PARAMETER_LENGTH_LENGTH, ENC_BIG_ENDIAN);
switch(tag) {
case INT_INTERFACE_IDENTIFIER_PARAMETER_TAG:
if(iua_version == RFC) dissect_int_interface_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
if(iua_version == DRAFT){
dissect_int_interface_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
dissect_dlci_parameter(parameter_tvb, parameter_tree, parameter_item, pinfo);
if(msg_class==0 && msg_type==0) dissect_draft_error_code_parameter(parameter_tvb, parameter_tree);
if(msg_class==1) dissect_draft_tei_status_parameter(parameter_tvb, parameter_tree, parameter_item);
if(msg_class==9){
if(msg_type==1||msg_type==2||msg_type==3||msg_type==4){
guint16 length_2, offset;
tvbuff_t *layer3_data_tvb;
offset = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) + 8;
length_2 = msg_length - offset;
if(length_2 > 0){
if(tvb_get_guint8(parameter_tvb, offset) == 0x48){
layer3_data_tvb = tvb_new_subset_length(parameter_tvb, offset, length_2);
dissect_layer3_message(layer3_data_tvb, v5ua_tree, parameter_item, pinfo);
}
}
}
else if(msg_type==8||msg_type==10) dissect_release_reason_parameter(parameter_tvb, parameter_tree, parameter_item);
}
}
break;
case ASP_MSG_PARAMETER_TAG:
dissect_asp_msg_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case TEXT_INTERFACE_IDENTIFIER_PARAMETER_TAG:
if(iua_version == RFC)
dissect_text_interface_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
if(iua_version == DRAFT)
dissect_scn_protocol_id_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case INFO_PARAMETER_TAG:
dissect_info_string_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DLCI_PARAMETER_TAG:
dissect_dlci_parameter(parameter_tvb, parameter_tree, parameter_item, pinfo);
break;
case DIAGNOSTIC_INFORMATION_PARAMETER_TAG:
dissect_diagnostic_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case INTEGER_RANGE_INTERFACE_IDENTIFIER_PARAMETER_TAG:
dissect_integer_range_interface_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case HEARTBEAT_DATA_PARAMETER_TAG:
dissect_heartbeat_data_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ASP_DOWN_REASON_PARAMETER_TAG:
dissect_asp_reason_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case TRAFFIC_MODE_TYPE_PARAMETER_TAG:
dissect_traffic_mode_type_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ERROR_CODE_PARAMETER_TAG:
dissect_error_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case STATUS_TYPE_INDENTIFICATION_PARAMETER_TAG:
dissect_status_type_identification_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PROTOCOL_DATA_PARAMETER_TAG:
dissect_layer3_message(parameter_tvb, v5ua_tree, parameter_item, pinfo);
break;
case RELEASE_REASON_PARAMETER_TAG:
dissect_release_reason_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case TEI_STATUS_PARAMETER_TAG:
dissect_tei_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ASP_IDENTIFIER_PARAMETER_TAG:
dissect_asp_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case LINK_STATUS_PARAMETER_TAG:
dissect_link_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case SA_BIT_STATUS_PARAMETER_TAG:
dissect_sa_bit_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ERROR_INDICATION_PARAMETER_TAG:
dissect_error_indication_parameter( parameter_tvb, parameter_tree, parameter_item);
break;
default:
dissect_unknown_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
};
if (padding_length > 0){
proto_tree_add_item(parameter_tree, hf_parameter_padding, parameter_tvb, PARAMETER_HEADER_OFFSET + length, padding_length, ENC_NA);
}
}
static void
dissect_parameters(tvbuff_t *parameters_tvb, packet_info *pinfo, proto_tree *tree _U_, proto_tree *v5ua_tree)
{
gint tag, offset, length, total_length, remaining_length;
tvbuff_t *parameter_tvb;
offset = 0;
while((remaining_length = tvb_reported_length_remaining(parameters_tvb, offset))) {
tag = tvb_get_ntohs(parameters_tvb, offset + PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameters_tvb, offset + PARAMETER_LENGTH_OFFSET);
if(iua_version==DRAFT){
if(tag==0x1) length += 8;
else if(tag<=0x4) length += PARAMETER_HEADER_LENGTH;
if((msg_class==0 || msg_class==1 || msg_class==9)&&msg_type<=10)
length = msg_length;
}
total_length = ADD_PADDING(length);
if (remaining_length >= length)
total_length = MIN(total_length, remaining_length);
parameter_tvb = tvb_new_subset_length(parameters_tvb, offset, total_length);
dissect_parameter(parameter_tvb, pinfo, v5ua_tree);
offset += total_length;
}
}
static void
dissect_common_header(tvbuff_t *common_header_tvb, packet_info *pinfo, proto_tree *v5ua_tree)
{
proto_item *common_header_item;
proto_tree *common_header_tree;
guint8 message_class, message_type;
message_class = tvb_get_guint8(common_header_tvb, COMMON_HEADER_MSG_CLASS_OFFSET);
message_type = tvb_get_guint8(common_header_tvb, COMMON_HEADER_MSG_TYPE_OFFSET);
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(message_class * 256 + message_type, msg_class_type_values_short, "UNKNOWN"));
if (v5ua_tree) {
common_header_tree = proto_tree_add_subtree(v5ua_tree, common_header_tvb, COMMON_HEADER_OFFSET, -1,
ett_v5ua_common_header, &common_header_item, "Common Msg-Header");
proto_tree_add_item(common_header_tree, hf_version, common_header_tvb, COMMON_HEADER_VERSION_OFFSET, COMMON_HEADER_VERSION_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(common_header_tree, hf_reserved, common_header_tvb, COMMON_HEADER_RESERVED_OFFSET, COMMON_HEADER_RESERVED_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(common_header_tree, hf_msg_class, common_header_tvb, COMMON_HEADER_MSG_CLASS_OFFSET, COMMON_HEADER_MSG_CLASS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(common_header_tree, hf_msg_type,
common_header_tvb, COMMON_HEADER_MSG_TYPE_OFFSET, COMMON_HEADER_MSG_TYPE_LENGTH,
message_type, "%s ( %u )",
val_to_str_const(message_class * 256 + message_type, msg_class_type_values, "reserved"), message_type);
proto_tree_add_item(common_header_tree, hf_msg_length, common_header_tvb, COMMON_HEADER_MSG_LENGTH_OFFSET, COMMON_HEADER_MSG_LENGTH_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(common_header_item, " (%s)",val_to_str_const(message_class * 256 + message_type, msg_class_type_values, "Unknown Msg-Type"));
messageclassCopy = message_class;
}
if (iua_version == DRAFT){
msg_class = message_class;
msg_type = message_type;
msg_length = tvb_get_ntohl (common_header_tvb, COMMON_HEADER_MSG_LENGTH_OFFSET);
}
}
static void
dissect_v5ua_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_tree *v5ua_tree)
{
tvbuff_t *common_header_tvb, *parameters_tvb;
common_header_tvb = tvb_new_subset_length(tvb, COMMON_HEADER_OFFSET, COMMON_HEADER_LENGTH);
dissect_common_header(common_header_tvb, pinfo, v5ua_tree);
parameters_tvb = tvb_new_subset_remaining(tvb, COMMON_HEADER_LENGTH);
dissect_parameters(parameters_tvb, pinfo, tree, v5ua_tree);
if (dlci_efa >= 0 && dlci_efa <= 8175) {
if ((messageclassCopy == 0) || (messageclassCopy == 3) || (messageclassCopy == 4)) {
messageclassCopy = -1;
}
else {
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_fstr(pinfo->cinfo, COL_INFO, "LinkId: %u", linkIdentifier);
}
}
if (sa_bit_id > -1) {
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_fstr(pinfo->cinfo, COL_INFO, "SA7bit: %u", sa_bit_id);
sa_bit_id = -1;
}
if (link_status_operational > -1) {
if (link_status_operational == 0) {
col_append_str(pinfo->cinfo, COL_INFO, " | operational");
}
else if (link_status_operational == 1) {
col_append_str(pinfo->cinfo, COL_INFO, " | non-operational");
}
link_status_operational = -1;
}
}
static int
dissect_v5ua(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint offset, remaining_length, length, tag, one_bit;
proto_tree *v5ua_tree;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "V5UA");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_v5ua, tvb, 0, -1, ENC_NA);
v5ua_tree = proto_item_add_subtree(ti, ett_v5ua);
iua_version = RFC;
offset = COMMON_HEADER_LENGTH;
remaining_length = tvb_reported_length_remaining(tvb, offset);
while(remaining_length) {
tag = tvb_get_ntohs(tvb, offset);
if(tag==0x1){
length = tvb_get_ntohs(tvb, offset+2);
tag = tvb_get_ntohs(tvb, offset+length);
if(tag==0x81){
remaining_length = FALSE;
}
else{
one_bit = tvb_get_guint8(tvb, offset+4+length+1);
if((one_bit & 0x01) == 0x01){
iua_version = DRAFT;
remaining_length = FALSE;
}
else{
proto_item_append_text(v5ua_tree, " !! DLCI INCORRECT !!");
iua_version = DRAFT;
remaining_length = FALSE;
}
}
}
else if(tag==0x02){
iua_version = DRAFT;
remaining_length = FALSE;
}
else if(tag==0x03){
iua_version = RFC;
remaining_length = FALSE;
}
else if(tag==0x11){
remaining_length = FALSE;
}
else if(tag==0x04 || tag == 0x0a || tag == 0x0b || tag == 0x0c || tag == 0x0d){
remaining_length = FALSE;
}
else{
offset+=2;
remaining_length = tvb_reported_length_remaining(tvb, offset);
}
if(iua_version == DRAFT){
col_set_str(pinfo->cinfo, COL_PROTOCOL, "V5UA (draft)");
}
}
dissect_v5ua_message(tvb, pinfo, tree, v5ua_tree);
return tvb_captured_length(tvb);
}
void
proto_register_v5ua(void)
{
static hf_register_info hf[] = {
{ &hf_version,
{ "Version", "v5ua.version",
FT_UINT8, BASE_DEC, VALS(v5ua_protocol_version_values), 0x0,
NULL, HFILL } },
{ &hf_reserved,
{ "Reserved", "v5ua.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_msg_class,
{ "Message class", "v5ua.msg_class",
FT_UINT8, BASE_DEC, VALS(msg_class_values), 0x0,
NULL, HFILL } },
{ &hf_msg_type,
{ "Message Type", "v5ua.msg_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
#if 0
{ &hf_msg_type_id,
{ "Message Type ID", "v5ua.msg_type_id",
FT_UINT8, BASE_DEC, VALS(msg_class_type_values), 0x0,
NULL, HFILL } },
#endif
{ &hf_msg_length,
{ "Message length", "v5ua.msg_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_link_id,
{ "Link Identifier", "v5ua.link_id",
FT_UINT32, BASE_DEC, NULL, 0xffffffe0,
NULL, HFILL } },
{ &hf_chnl_id,
{ "Channel Identifier", "v5ua.channel_id",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL } },
{ &hf_adaptation_layer_id,
{ "Adaptation Layer ID", "v5ua.adaptation_layer_id",
FT_STRING, BASE_NONE,NULL, 0x0,
NULL, HFILL } },
{ &hf_text_if_id,
{ "Text interface identifier","v5ua.text_interface_id",
FT_STRING, BASE_NONE,NULL, 0x0,
NULL, HFILL } },
{ &hf_scn_protocol_id,
{ "SCN Protocol Identifier","v5ua.scn_protocol_id",
FT_STRING, BASE_NONE,NULL, 0x0,
NULL, HFILL } },
{ &hf_info_string,
{ "Info String", "v5ua.info_string",
FT_STRING, BASE_NONE,NULL, 0x0,
NULL, HFILL } },
{ &hf_asp_identifier,
{ "ASP Identifier", "v5ua.asp_identifier",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_dlci_zero_bit,
{ "Zero bit", "v5ua.dlci_zero_bit",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL } },
{ &hf_dlci_spare_bit,
{ "Spare bit", "v5ua.dlci_spare_bit",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL } },
{ &hf_dlci_sapi,
{ "SAPI", "v5ua.dlci_sapi",
FT_UINT8, BASE_HEX, NULL, 0xfc,
NULL, HFILL } },
{ &hf_dlci_one_bit,
{ "One bit", "v5ua.dlci_one_bit",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL } },
{ &hf_dlci_tei,
{ "TEI", "v5ua.dlci_tei",
FT_UINT8, BASE_HEX, NULL, 0xfe,
NULL, HFILL } },
{ &hf_efa,
{ "Envelope Function Address","v5ua.efa",
FT_UINT16, BASE_DEC, VALS(efa_values), 0x0,
NULL, HFILL } },
#if 0
{ &hf_spare_efa,
{ "Envelope Function Address (spare)","v5ua.efa",
FT_UINT16, BASE_DEC, NULL, ~7,
NULL, HFILL } },
#endif
{ &hf_asp_reason,
{ "Reason", "v5ua.asp_reason",
FT_UINT32, BASE_HEX, VALS(asp_reason_values), 0x0,
NULL, HFILL } },
{ &hf_release_reason,
{ "Release Reason", "v5ua.release_reason",
FT_UINT32, BASE_HEX, VALS(release_reason_values), 0x0,
NULL, HFILL } },
{ &hf_tei_status,
{ "TEI status", "v5ua.tei_status",
FT_UINT32, BASE_HEX, VALS(tei_status_values), 0x0,
NULL, HFILL } },
{ &hf_tei_draft_status,
{ "TEI status", "v5ua.tei_draft_status",
FT_UINT32, BASE_HEX, VALS(tei_draft_status_values), 0x0,
NULL, HFILL } },
{ &hf_link_status,
{ "Link Status", "v5ua.link_status",
FT_UINT32, BASE_HEX, VALS(link_status_values), 0x0,
NULL, HFILL } },
{ &hf_sa_bit_id,
{ "BIT ID", "v5ua.sa_bit_id",
FT_UINT16, BASE_HEX, VALS(sa_bit_values), 0x0,
NULL, HFILL } },
{ &hf_sa_bit_value,
{ "Bit Value", "v5ua.sa_bit_value",
FT_UINT16, BASE_HEX, VALS(sa_bit_values), 0x0,
NULL, HFILL } },
{ &hf_parameter_tag,
{ "Parameter Tag", "v5ua.parameter_tag",
FT_UINT16, BASE_HEX, VALS(parameter_tag_values), 0x0,
NULL, HFILL } },
{ &hf_parameter_tag_draft,
{ "Parameter Tag", "v5ua.parameter_tag",
FT_UINT16, BASE_HEX, VALS(parameter_tag_draft_values), 0x0,
NULL, HFILL } },
{ &hf_parameter_length,
{ "Parameter length", "v5ua.parameter_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_parameter_value,
{ "Parameter value", "v5ua.parameter_value",
FT_BYTES, BASE_NONE,NULL, 0x0,
NULL, HFILL } },
{ &hf_parameter_padding,
{ "Parameter padding", "v5ua.parameter_padding",
FT_BYTES, BASE_NONE,NULL, 0x0,
NULL, HFILL } },
{ &hf_diagnostic_info,
{ "Diagnostic Information", "v5ua.diagnostic_info",
FT_BYTES, BASE_NONE,NULL, 0x0,
NULL, HFILL } },
{ &hf_if_range_start,
{ "Interface range Start", "v5ua.interface_range_start",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_if_range_end,
{ "Interface range End", "v5ua.interface_range_end",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_heartbeat_data,
{ "Heartbeat data", "v5ua.heartbeat_data",
FT_BYTES, BASE_NONE,NULL, 0x0,
NULL, HFILL } },
{ &hf_traffic_mode_type,
{ "Traffic mode type", "v5ua.traffic_mode_type",
FT_UINT32, BASE_HEX, VALS(traffic_mode_type_values), 0x0,
NULL, HFILL } },
{ &hf_error_code,
{ "Error code", "v5ua.error_code",
FT_UINT32, BASE_HEX, VALS(error_code_values), 0x0,
NULL, HFILL } },
{ &hf_draft_error_code,
{ "Error code (draft)", "v5ua.draft_error_code",
FT_UINT32, BASE_HEX, VALS(draft_error_code_values), 0x0,
NULL, HFILL } },
{ &hf_status_type,
{ "Status type", "v5ua.status_type",
FT_UINT16, BASE_DEC, VALS(status_type_values), 0x0,
NULL, HFILL } },
{ &hf_status_id,
{ "Status identification", "v5ua.status_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_error_reason,
{ "Error Reason", "v5ua.error_reason",
FT_UINT32, BASE_HEX, VALS(error_reason_values), 0x0,
NULL, HFILL } }
};
static gint *ett[] = {
&ett_v5ua,
&ett_v5ua_common_header,
&ett_v5ua_parameter,
&ett_v5ua_layer3
};
proto_v5ua = proto_register_protocol("V5.2-User Adaptation Layer", "V5UA", "v5ua");
proto_register_field_array(proto_v5ua, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_v5ua(void)
{
dissector_handle_t v5ua_handle;
v5ua_handle = create_dissector_handle(dissect_v5ua, proto_v5ua);
q931_handle = find_dissector_add_dependency("q931", proto_v5ua);
v52_handle = find_dissector_add_dependency("v52", proto_v5ua);
dissector_add_uint("sctp.port", SCTP_PORT_V5UA_DRAFT, v5ua_handle);
dissector_add_uint("sctp.port", SCTP_PORT_V5UA_RFC, v5ua_handle);
dissector_add_uint("sctp.ppi", V5UA_PAYLOAD_PROTOCOL_ID, v5ua_handle);
}
