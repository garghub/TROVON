static const gchar*
get_register_name_from_address(guint64 addr, gboolean* is_custom_register, u3v_conv_info_t * u3v_conv_info)
{
const gchar* address_string = NULL;
guint32 offset_address;
if (is_custom_register != NULL) {
*is_custom_register = FALSE;
}
if ( addr < 0x10000 ) {
offset_address = (guint32)addr;
address_string = try_val_to_str(offset_address, bootstrap_register_names_abrm);
}
if ( u3v_conv_info && u3v_conv_info->sbrm_addr != 0 && (addr >= u3v_conv_info->sbrm_addr)) {
offset_address = (guint32)( addr - u3v_conv_info->sbrm_addr);
address_string = try_val_to_str(offset_address, bootstrap_register_names_sbrm);
}
if ( u3v_conv_info && u3v_conv_info->sirm_addr != 0 && (addr >= u3v_conv_info->sirm_addr)) {
offset_address = (guint32)( addr - u3v_conv_info->sirm_addr);
address_string = try_val_to_str(offset_address, bootstrap_register_names_sirm);
}
if ( u3v_conv_info && u3v_conv_info->eirm_addr != 0 && (addr >= u3v_conv_info->eirm_addr)) {
offset_address = (guint32)( addr - u3v_conv_info->eirm_addr);
address_string = try_val_to_str(offset_address, bootstrap_register_names_eirm);
}
if (!address_string) {
address_string = wmem_strdup_printf(wmem_packet_scope(), "[Addr:0x%016" G_GINT64_MODIFIER "X]", addr);
if (is_custom_register != NULL) {
*is_custom_register = TRUE;
}
}
return address_string;
}
static int
is_known_bootstrap_register(guint64 addr, u3v_conv_info_t * u3v_conv_info)
{
const gchar* address_string = NULL;
guint32 offset_address;
if ( addr < 0x10000 ) {
offset_address = (guint32)addr;
address_string = try_val_to_str(offset_address, bootstrap_register_names_abrm);
}
if ( u3v_conv_info->sbrm_addr != 0 && (addr >= u3v_conv_info->sbrm_addr)) {
offset_address = (guint32)( addr - u3v_conv_info->sbrm_addr);
address_string = try_val_to_str(offset_address, bootstrap_register_names_sbrm);
}
if ( u3v_conv_info->sirm_addr != 0 && (addr >= u3v_conv_info->sirm_addr)) {
offset_address = (guint32)( addr - u3v_conv_info->sirm_addr);
address_string = try_val_to_str(offset_address, bootstrap_register_names_sirm);
}
if ( u3v_conv_info->eirm_addr != 0 && (addr >= u3v_conv_info->eirm_addr)) {
offset_address = (guint32)( addr - u3v_conv_info->eirm_addr);
address_string = try_val_to_str(offset_address, bootstrap_register_names_eirm);
}
return address_string != NULL;
}
static void
dissect_u3v_register_bases(guint64 addr, tvbuff_t *tvb, gint offset, u3v_conv_info_t * u3v_conv_info)
{
if ( addr < 0x10000 ) {
switch (addr) {
case U3V_ABRM_SBRM_ADDRESS:
u3v_conv_info->sbrm_addr = tvb_get_letoh64(tvb, offset);
break;
case U3V_ABRM_MANIFEST_TABLE_ADDRESS:
u3v_conv_info->manifest_addr = tvb_get_letoh64(tvb, offset);
break;
}
}
if ( u3v_conv_info->sbrm_addr != 0 && (addr >= u3v_conv_info->sbrm_addr)) {
addr -= u3v_conv_info->sbrm_addr;
switch(addr) {
case U3V_SBRM_SIRM_ADDRESS:
u3v_conv_info->sirm_addr = tvb_get_letoh64(tvb, offset);
break;
case U3V_SBRM_EIRM_ADDRESS:
u3v_conv_info->eirm_addr = tvb_get_letoh64(tvb, offset);
break;
case U3V_SBRM_IIDC2_ADDRESS:
u3v_conv_info->iidc2_addr = tvb_get_letoh64(tvb, offset);
break;
}
}
}
static int
dissect_u3v_register(guint64 addr, proto_tree *branch, tvbuff_t *tvb, gint offset, gint length, u3v_conv_info_t * u3v_conv_info)
{
gint isABRM = FALSE, isSBRM = FALSE, isSIRM = FALSE,isEIRM = FALSE;
if ( addr < 0x10000 ) {
isABRM = TRUE;
switch (addr) {
case U3V_ABRM_GENCP_VERSION:
proto_tree_add_item(branch, hf_u3v_bootstrap_GenCP_Version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_MANUFACTURER_NAME:
if ( length <= 64 ) {
proto_tree_add_item(branch, hf_u3v_bootstrap_Manufacturer_Name, tvb, offset, length, ENC_ASCII|ENC_NA);
}
break;
case U3V_ABRM_MODEL_NAME:
if ( length <= 64 ) {
proto_tree_add_item(branch, hf_u3v_bootstrap_Model_Name, tvb, offset, length, ENC_ASCII|ENC_NA);
}
break;
case U3V_ABRM_FAMILY_NAME:
if ( length <= 64 ) {
proto_tree_add_item(branch, hf_u3v_bootstrap_Family_Name, tvb, offset, length, ENC_ASCII|ENC_NA);
}
break;
case U3V_ABRM_DEVICE_VERSION:
if ( length <= 64 ) {
proto_tree_add_item(branch, hf_u3v_bootstrap_Device_Version, tvb, offset, length, ENC_ASCII|ENC_NA);
}
break;
case U3V_ABRM_MANUFACTURER_INFO:
if ( length <= 64 ) {
proto_tree_add_item(branch, hf_u3v_bootstrap_Manufacturer_Info, tvb, offset, length, ENC_ASCII|ENC_NA);
}
break;
case U3V_ABRM_SERIAL_NUMBER:
if ( length <= 64 ) {
proto_tree_add_item(branch, hf_u3v_bootstrap_Serial_Number, tvb, offset, length, ENC_ASCII|ENC_NA);
}
break;
case U3V_ABRM_USER_DEFINED_NAME:
if ( length <= 64 ) {
proto_tree_add_item(branch, hf_u3v_bootstrap_User_Defined_Name, tvb, offset, length, ENC_ASCII|ENC_NA);
}
break;
case U3V_ABRM_DEVICE_CAPABILITY:
proto_tree_add_item(branch, hf_u3v_bootstrap_Device_Capability, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_MAXIMUM_DEVICE_RESPONSE_TIME:
proto_tree_add_item(branch, hf_u3v_bootstrap_Maximum_Device_Response_Time, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_MANIFEST_TABLE_ADDRESS:
proto_tree_add_item(branch, hf_u3v_bootstrap_Manifest_Table_Address, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_SBRM_ADDRESS:
proto_tree_add_item(branch, hf_u3v_bootstrap_SBRM_Address, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_DEVICE_CONFIGURATION:
proto_tree_add_item(branch, hf_u3v_bootstrap_Device_Configuration, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_HEARTBEAT_TIMEOUT:
proto_tree_add_item(branch, hf_u3v_bootstrap_Heartbeat_Timeout, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_MESSAGE_CHANNEL_CHANNEL_ID:
proto_tree_add_item(branch, hf_u3v_bootstrap_Message_Channel_channel_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_TIMESTAMP:
proto_tree_add_item(branch, hf_u3v_bootstrap_Timestamp, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_TIMESTAMP_LATCH:
proto_tree_add_item(branch, hf_u3v_bootstrap_Timestamp_Latch, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_TIMESTAMP_INCREMENT:
proto_tree_add_item(branch, hf_u3v_bootstrap_Timestamp_Increment, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_ACCESS_PRIVILEGE:
proto_tree_add_item(branch, hf_u3v_bootstrap_Access_Privilege, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_PROTOCOL_ENDIANNESS:
proto_tree_add_item(branch, hf_u3v_bootstrap_Protocol_Endianness, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_ABRM_IMPLEMENTATION_ENDIANNESS:
proto_tree_add_item(branch, hf_u3v_bootstrap_Implementation_Endianness, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
default:
isABRM = FALSE;
break;
}
}
if ( u3v_conv_info->sbrm_addr != 0 && (addr >= u3v_conv_info->sbrm_addr)) {
guint64 map_offset = addr - u3v_conv_info->sbrm_addr;
isSBRM = TRUE;
switch(map_offset) {
case U3V_SBRM_U3V_VERSION:
proto_tree_add_item(branch, hf_u3v_bootstrap_U3V_Version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SBRM_U3VCP_CAPABILITY_REGISTER:
proto_tree_add_item(branch, hf_u3v_bootstrap_U3VCP_Capability_Register, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
case U3V_SBRM_U3VCP_CONFIGURATION_REGISTER:
proto_tree_add_item(branch, hf_u3v_bootstrap_U3VCP_Configuration_Register, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
case U3V_SBRM_MAXIMUM_COMMAND_TRANSFER_LENGTH:
proto_tree_add_item(branch, hf_u3v_bootstrap_Maximum_Command_Transfer_Length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SBRM_MAXIMUM_ACKNOWLEDGE_TRANSFER_LENGTH:
proto_tree_add_item(branch, hf_u3v_bootstrap_Maximum_Acknowledge_Transfer_Length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SBRM_NUMBER_OF_STREAM_CHANNELS:
proto_tree_add_item(branch, hf_u3v_bootstrap_Number_of_Stream_Channels, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SBRM_SIRM_ADDRESS:
proto_tree_add_item(branch, hf_u3v_bootstrap_SIRM_Address, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
case U3V_SBRM_SIRM_LENGTH:
proto_tree_add_item(branch, hf_u3v_bootstrap_SIRM_Length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SBRM_EIRM_ADDRESS:
proto_tree_add_item(branch, hf_u3v_bootstrap_EIRM_Address, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
case U3V_SBRM_EIRM_LENGTH:
proto_tree_add_item(branch, hf_u3v_bootstrap_EIRM_Length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SBRM_IIDC2_ADDRESS:
proto_tree_add_item(branch, hf_u3v_bootstrap_IIDC2_Address, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
case U3V_SBRM_CURRENT_SPEED:
proto_tree_add_item(branch, hf_u3v_bootstrap_Current_Speed, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
default:
isSBRM = FALSE;
break;
}
}
if ( u3v_conv_info->sirm_addr != 0 && (addr >= u3v_conv_info->sirm_addr)) {
guint64 map_offset = addr - u3v_conv_info->sirm_addr;
isSIRM = TRUE;
switch(map_offset) {
case U3V_SIRM_SI_INFO:
proto_tree_add_item(branch, hf_u3v_bootstrap_SI_Info, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SIRM_SI_CONTROL:
proto_tree_add_item(branch, hf_u3v_bootstrap_SI_Control, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SIRM_SI_REQUIRED_PAYLOAD_SIZE:
proto_tree_add_item(branch, hf_u3v_bootstrap_SI_Required_Payload_Size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
case U3V_SIRM_SI_REQUIRED_LEADER_SIZE:
proto_tree_add_item(branch, hf_u3v_bootstrap_SI_Required_Leader_Size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SIRM_SI_REQUIRED_TRAILER_SIZE:
proto_tree_add_item(branch, hf_u3v_bootstrap_SI_Required_Trailer_Size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SIRM_SI_MAXIMUM_LEADER_SIZE:
proto_tree_add_item(branch, hf_u3v_bootstrap_SI_Maximum_Leader_Size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SIRM_SI_PAYLOAD_TRANSFER_SIZE:
proto_tree_add_item(branch, hf_u3v_bootstrap_SI_Payload_Transfer_Size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SIRM_SI_PAYLOAD_TRANSFER_COUNT:
proto_tree_add_item(branch, hf_u3v_bootstrap_SI_Payload_Transfer_Count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SIRM_SI_PAYLOAD_FINAL_TRANSFER1_SIZE:
proto_tree_add_item(branch, hf_u3v_bootstrap_SI_Payload_Final_Transfer1_Size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SIRM_SI_PAYLOAD_FINAL_TRANSFER2_SIZE:
proto_tree_add_item(branch, hf_u3v_bootstrap_SI_Payload_Final_Transfer2_Size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_SIRM_SI_MAXIMUM_TRAILER_SIZE:
proto_tree_add_item(branch, hf_u3v_bootstrap_SI_Maximum_Trailer_Size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
default:
isSIRM = FALSE;
break;
}
}
if ( u3v_conv_info->eirm_addr != 0 && (addr >= u3v_conv_info->eirm_addr)) {
guint64 map_offset = addr -u3v_conv_info->eirm_addr;
isEIRM=TRUE;
switch(map_offset) {
case U3V_EIRM_EI_CONTROL:
proto_tree_add_item(branch, hf_u3v_bootstrap_EI_Control, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_EIRM_MAXIMUM_EVENT_TRANSFER_LENGTH:
proto_tree_add_item(branch, hf_u3v_bootstrap_Maximum_Event_Transfer_Length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case U3V_EIRM_EVENT_TEST_CONTROL:
proto_tree_add_item(branch, hf_u3v_bootstrap_Event_Test_Control, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
default:
isEIRM = FALSE;
break;
}
}
if(isABRM || isSBRM || isSIRM || isEIRM ) {
return 1;
}
return 0;
}
static void
dissect_u3v_read_mem_cmd(proto_tree *u3v_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length, u3v_conv_info_t *u3v_conv_info, gencp_transaction_t * gencp_trans)
{
guint64 addr = 0;
const gchar* address_string = NULL;
gboolean is_custom_register = FALSE;
guint16 count = 0;
gint offset = startoffset;
proto_item *item = NULL;
addr = tvb_get_letoh64(tvb, offset);
gencp_trans->address = addr;
address_string = get_register_name_from_address(addr, &is_custom_register, u3v_conv_info);
count = tvb_get_letohs(tvb, offset + 10);
gencp_trans->count = count;
if ( 0xffffffff00000000 & addr ) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (0x%016" G_GINT64_MODIFIER "X (%d) bytes) %s", addr, count, address_string);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " (0x%08X (%d) bytes)", (guint32)addr, count);
}
item = proto_tree_add_item(u3v_telegram_tree, hf_u3v_scd_readmem_cmd, tvb, offset, length, ENC_NA);
u3v_telegram_tree = proto_item_add_subtree(item, ett_u3v_payload_cmd);
if (is_known_bootstrap_register(addr, u3v_conv_info)) {
item = proto_tree_add_uint64(u3v_telegram_tree, hf_u3v_address, tvb, offset, 8, addr);
proto_item_append_text(item, " %s", address_string);
} else {
proto_tree_add_item(u3v_telegram_tree, hf_u3v_custom_memory_addr, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_u3v_write_mem_cmd(proto_tree *u3v_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length, u3v_conv_info_t *u3v_conv_info, gencp_transaction_t *gencp_trans)
{
const gchar* address_string = NULL;
gboolean is_custom_register = FALSE;
guint64 addr = 0;
guint byte_count = 0;
proto_item *item = NULL;
guint offset = startoffset + 8;
addr = tvb_get_letoh64(tvb, startoffset);
byte_count = length - 8;
address_string = get_register_name_from_address(addr, &is_custom_register, u3v_conv_info);
gencp_trans->address = addr;
gencp_trans->count = byte_count;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s: %d bytes", address_string, byte_count);
item = proto_tree_add_item(u3v_telegram_tree, hf_u3v_scd_writemem_cmd, tvb, startoffset, length, ENC_NA);
u3v_telegram_tree = proto_item_add_subtree(item, ett_u3v_payload_cmd);
if (is_known_bootstrap_register(addr, u3v_conv_info)) {
item = proto_tree_add_uint64(u3v_telegram_tree, hf_u3v_address, tvb, startoffset, 8, addr);
proto_item_append_text(item, " %s", address_string);
dissect_u3v_register(addr, u3v_telegram_tree, tvb, offset, byte_count, u3v_conv_info);
} else {
proto_tree_add_item(u3v_telegram_tree, hf_u3v_custom_memory_addr, tvb, startoffset, 8, ENC_LITTLE_ENDIAN);
proto_tree_add_item(u3v_telegram_tree, hf_u3v_custom_memory_data, tvb, startoffset + 8, byte_count, ENC_NA);
}
}
static void
dissect_u3v_event_cmd(proto_tree *u3v_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length)
{
gint32 eventid;
gint offset = startoffset;
proto_item *item = NULL;
eventid = tvb_get_letohs(tvb, offset + 2);
col_append_fstr(pinfo->cinfo, COL_INFO, "[ID: 0x%04X]", eventid);
item = proto_tree_add_item(u3v_telegram_tree, hf_u3v_scd_event_cmd, tvb, offset, length, ENC_NA);
u3v_telegram_tree = proto_item_add_subtree(item, ett_u3v_payload_cmd);
offset += 2;
if ((eventid >= 0x0000) && (eventid <= 0x8000)) {
proto_tree_add_item(u3v_telegram_tree, hf_u3v_eventcmd_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else if ((eventid >= 0x8001) && (eventid <= 0x8FFF)) {
proto_tree_add_item(u3v_telegram_tree, hf_u3v_eventcmd_error_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else if ((eventid >= 0x9000) && (eventid <= 0xFFFF)) {
proto_tree_add_item(u3v_telegram_tree, hf_u3v_eventcmd_device_specific_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_eventcmd_timestamp, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
if (length > offset ) {
proto_tree_add_item(u3v_telegram_tree, hf_u3v_eventcmd_data, tvb, offset, length - 12, ENC_NA);
}
}
static void
dissect_u3v_read_mem_ack(proto_tree *u3v_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length, u3v_conv_info_t *u3v_conv_info, gencp_transaction_t * gencp_trans)
{
guint64 addr = 0;
const gchar *address_string = NULL;
gboolean is_custom_register = FALSE;
gboolean have_address = (0 != gencp_trans->cmd_frame);
proto_item *item = NULL;
guint offset = startoffset;
guint byte_count = (length);
addr = gencp_trans->address;
dissect_u3v_register_bases(addr, tvb, startoffset, u3v_conv_info);
if (have_address) {
address_string = get_register_name_from_address(addr, &is_custom_register, u3v_conv_info);
col_append_str(pinfo->cinfo, COL_INFO, address_string);
}
item = proto_tree_add_item(u3v_telegram_tree, hf_u3v_scd_ack_readmem_ack, tvb, startoffset, length, ENC_NA);
u3v_telegram_tree = proto_item_add_subtree(item, ett_u3v_payload_cmd);
if (have_address) {
item = proto_tree_add_uint64(u3v_telegram_tree, hf_u3v_address, tvb, 0,0 , addr);
PROTO_ITEM_SET_GENERATED(item);
if (is_known_bootstrap_register(addr, u3v_conv_info)) {
dissect_u3v_register(addr, u3v_telegram_tree, tvb, offset, byte_count, u3v_conv_info);
} else {
proto_tree_add_item(u3v_telegram_tree, hf_u3v_custom_memory_data, tvb, startoffset, length, ENC_NA);
}
}
}
static void
dissect_u3v_write_mem_ack(proto_tree *u3v_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length, u3v_conv_info_t *u3v_conv_info , gencp_transaction_t * gencp_trans)
{
guint64 addr = 0;
gint offset = startoffset;
const gchar *address_string = NULL;
gboolean is_custom_register = FALSE;
gboolean have_address = (0 != gencp_trans->cmd_frame);
proto_item *item = NULL;
addr = gencp_trans->address;
if (have_address) {
address_string = get_register_name_from_address(addr, &is_custom_register, u3v_conv_info);
col_append_str(pinfo->cinfo, COL_INFO, address_string);
}
item = proto_tree_add_item(u3v_telegram_tree, hf_u3v_scd_writemem_ack, tvb, startoffset, length, ENC_NA);
u3v_telegram_tree = proto_item_add_subtree(item, ett_u3v_payload_cmd);
if (have_address) {
item = proto_tree_add_uint64(u3v_telegram_tree, hf_u3v_address, tvb, 0,0 , addr);
PROTO_ITEM_SET_GENERATED(item);
}
if ( length == 4 ) {
proto_tree_add_item(u3v_telegram_tree, hf_u3v_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_u3v_pending_ack(proto_tree *u3v_telegram_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint startoffset, gint length, u3v_conv_info_t *u3v_conv_info _U_, gencp_transaction_t *gencp_trans _U_)
{
proto_item *item = NULL;
guint offset = startoffset;
col_append_fstr(pinfo->cinfo, COL_INFO, " %d ms", tvb_get_letohs(tvb, startoffset+2));
item = proto_tree_add_item(u3v_telegram_tree, hf_u3v_ccd_pending_ack, tvb, startoffset, length, ENC_NA);
u3v_telegram_tree = proto_item_add_subtree(item, ett_u3v_payload_cmd);
proto_tree_add_item(u3v_telegram_tree, hf_u3v_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_time_to_completion, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_u3v_stream_leader(proto_tree *u3v_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, usb_conv_info_t *usb_conv_info _U_)
{
guint32 offset = 0;
guint32 payload_type = 0;
guint64 block_id = 0;
proto_item *item = NULL;
item = proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_leader, tvb, 0, -1, ENC_NA);
u3v_telegram_tree = proto_item_add_subtree(item, ett_u3v_stream_leader);
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_prefix, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_leader_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
block_id = tvb_get_letoh64(tvb, offset);
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_block_id, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
payload_type = tvb_get_letohs(tvb, offset);
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_payload_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, "Stream Leader [ Block ID: %" G_GINT64_MODIFIER "u , Type %s]",
block_id,
val_to_str(payload_type, payload_type_names, "Unknown Payload Type"));
if (payload_type == U3V_STREAM_PAYLOAD_IMAGE ||
payload_type == U3V_STREAM_PAYLOAD_IMAGE_EXT_CHUNK ||
payload_type == U3V_STREAM_PAYLOAD_CHUNK) {
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_timestamp, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
}
if (payload_type == U3V_STREAM_PAYLOAD_IMAGE ||
payload_type == U3V_STREAM_PAYLOAD_IMAGE_EXT_CHUNK ) {
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_pixel_format, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_size_x, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_size_y, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_offset_x, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_offset_y, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_padding_x, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_reserved, tvb, offset, 2, ENC_NA);
}
}
static void
dissect_u3v_stream_trailer(proto_tree *u3v_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, usb_conv_info_t *usb_conv_info _U_)
{
gint offset = 0;
guint64 block_id;
proto_item *item = NULL;
item = proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_trailer, tvb, 0, -1, ENC_NA);
u3v_telegram_tree = proto_item_add_subtree(item, ett_u3v_stream_trailer);
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_prefix, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_trailer_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
block_id = tvb_get_letoh64(tvb, offset);
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_block_id, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_status, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_valid_payload_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
col_append_fstr(pinfo->cinfo, COL_INFO, "Stream Trailer [ Block ID: %" G_GINT64_MODIFIER "u]", block_id);
if (tvb_captured_length_remaining(tvb,offset) >=4 ) {
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_size_y, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
if (tvb_captured_length_remaining(tvb,offset) >=4 ) {
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_chunk_layout_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_u3v_stream_payload(proto_tree *u3v_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
item = proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_payload, tvb, 0, -1, ENC_NA);
u3v_telegram_tree = proto_item_add_subtree(item, ett_u3v_stream_payload);
proto_tree_add_item(u3v_telegram_tree, hf_u3v_stream_data, tvb, 0, -1, ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO, "Stream Payload");
}
static int
dissect_u3v(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
gint offset = 0;
proto_tree *u3v_tree = NULL, *ccd_tree_flag, *u3v_telegram_tree = NULL, *ccd_tree = NULL;
gint data_length = 0;
gint req_id = 0;
gint command_id = -1;
gint status = 0;
guint prefix = 0;
proto_item *ti = NULL;
proto_item *item = NULL;
const char *command_string;
usb_conv_info_t *usb_conv_info;
gint stream_detected = FALSE;
gint control_detected = FALSE;
u3v_conv_info_t *u3v_conv_info = NULL;
gencp_transaction_t *gencp_trans = NULL;
usb_conv_info = (usb_conv_info_t *)data;
u3v_conv_info = (u3v_conv_info_t *)usb_conv_info->class_data;
if (!u3v_conv_info) {
u3v_conv_info = wmem_new0(wmem_file_scope(), u3v_conv_info_t);
usb_conv_info->class_data = u3v_conv_info;
usb_conv_info->class_data_type = USB_CONV_U3V;
} else if (usb_conv_info->class_data_type != USB_CONV_U3V) {
return 0;
}
prefix = tvb_get_letohl(tvb, 0);
if ((tvb_reported_length(tvb) >= 4) && ( ( U3V_CONTROL_PREFIX == prefix ) || ( U3V_EVENT_PREFIX == prefix ) ) ) {
control_detected = TRUE;
}
if (((tvb_reported_length(tvb) >= 4) && (( U3V_STREAM_LEADER_PREFIX == prefix ) || ( U3V_STREAM_TRAILER_PREFIX == prefix )))
|| (usb_conv_info->endpoint == u3v_conv_info->ep_stream)) {
stream_detected = TRUE;
}
if ( control_detected || stream_detected){
if ( usb_conv_info->interfaceClass == IF_CLASS_UNKNOWN &&
usb_conv_info->interfaceSubclass == IF_SUBCLASS_UNKNOWN){
usb_conv_info->interfaceClass = IF_CLASS_MISCELLANEOUS;
usb_conv_info->interfaceSubclass = IF_SUBCLASS_MISC_U3V;
}
}
if ( control_detected ) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "U3V");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_u3v, tvb, offset, -1, ENC_NA);
u3v_tree = proto_item_add_subtree(ti, ett_u3v);
prefix = tvb_get_letohl(tvb, offset);
command_id = tvb_get_letohs(tvb, offset+6);
if ((prefix == U3V_CONTROL_PREFIX || prefix == U3V_EVENT_PREFIX) && ((command_id % 2) == 0)) {
command_string = val_to_str(command_id,command_names,"Unknown Command (0x%x)");
item = proto_tree_add_item(u3v_tree, hf_u3v_ccd_cmd, tvb, offset, 8, ENC_NA);
proto_item_append_text(item, ": %s", command_string);
ccd_tree = proto_item_add_subtree(item, ett_u3v_cmd);
proto_tree_add_item(ccd_tree, hf_u3v_gencp_prefix, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
item = proto_tree_add_item(ccd_tree, hf_u3v_flag, tvb, offset, 2, ENC_LITTLE_ENDIAN);
ccd_tree_flag = proto_item_add_subtree(item, ett_u3v_flags);
proto_tree_add_item(ccd_tree_flag, hf_u3v_acknowledge_required_flag, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, "> %s ", command_string);
} else if (prefix == U3V_CONTROL_PREFIX && ((command_id % 2) == 1)) {
command_string = val_to_str(command_id,command_names,"Unknown Acknowledge (0x%x)");
item = proto_tree_add_item(u3v_tree, hf_u3v_ccd_ack, tvb, offset, 8, ENC_NA);
proto_item_append_text(item, ": %s", command_string);
ccd_tree = proto_item_add_subtree(item, ett_u3v_ack);
proto_tree_add_item(ccd_tree, hf_u3v_gencp_prefix, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ccd_tree, hf_u3v_status, tvb, offset, 2,ENC_LITTLE_ENDIAN);
status = tvb_get_letohs(tvb, offset);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, "< %s %s",
command_string,
val_to_str(status, status_names_short, "Unknown status (0x%04X)"));
} else {
return 0;
}
proto_tree_add_item(ccd_tree, hf_u3v_command_id, tvb, offset, 2,ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(ccd_tree, hf_u3v_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
data_length = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(ccd_tree, hf_u3v_request_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
req_id = tvb_get_letohs(tvb, offset);
offset += 2;
u3v_telegram_tree = proto_item_add_subtree(u3v_tree, ett_u3v);
if (!PINFO_FD_VISITED(pinfo)) {
if ((command_id % 2) == 0) {
gencp_trans = wmem_new0(wmem_file_scope(), gencp_transaction_t);
gencp_trans->cmd_frame = pinfo->fd->num;
gencp_trans->ack_frame = 0;
gencp_trans->cmd_time = pinfo->fd->abs_ts;
p_add_proto_data(wmem_file_scope(), pinfo, proto_u3v, req_id, gencp_trans);
u3v_conv_info->trans_info = gencp_trans;
} else {
gencp_trans = u3v_conv_info->trans_info;
if (gencp_trans) {
gencp_trans->ack_frame = pinfo->fd->num;
p_add_proto_data(wmem_file_scope(), pinfo, proto_u3v, req_id, gencp_trans);
}
}
} else {
gencp_trans = (gencp_transaction_t*)p_get_proto_data(wmem_file_scope(),pinfo, proto_u3v, req_id);
}
if (!gencp_trans) {
gencp_trans = wmem_new0(wmem_packet_scope(), gencp_transaction_t);
gencp_trans->cmd_frame = 0;
gencp_trans->ack_frame = 0;
gencp_trans->cmd_time = pinfo->fd->abs_ts;
}
switch (command_id) {
case U3V_READMEM_CMD:
dissect_u3v_read_mem_cmd(u3v_telegram_tree, tvb, pinfo, offset, data_length,u3v_conv_info,gencp_trans);
break;
case U3V_WRITEMEM_CMD:
dissect_u3v_write_mem_cmd(u3v_telegram_tree, tvb, pinfo, offset, data_length,u3v_conv_info,gencp_trans);
break;
case U3V_EVENT_CMD:
dissect_u3v_event_cmd(u3v_telegram_tree, tvb, pinfo, offset, data_length);
break;
case U3V_READMEM_ACK:
if ( U3V_STATUS_GENCP_SUCCESS == status ) {
dissect_u3v_read_mem_ack(u3v_telegram_tree, tvb, pinfo, offset, data_length,u3v_conv_info,gencp_trans);
}
break;
case U3V_WRITEMEM_ACK:
dissect_u3v_write_mem_ack(u3v_telegram_tree, tvb, pinfo, offset, data_length, u3v_conv_info,gencp_trans);
break;
case U3V_PENDING_ACK:
dissect_u3v_pending_ack(u3v_telegram_tree, tvb, pinfo, offset, data_length, u3v_conv_info,gencp_trans);
break;
default:
proto_tree_add_item(u3v_telegram_tree, hf_u3v_payloaddata, tvb, offset, data_length, ENC_NA);
break;
}
return data_length + 12;
} else if ( stream_detected ) {
u3v_conv_info = (u3v_conv_info_t *)usb_conv_info->class_data;
u3v_conv_info->ep_stream = usb_conv_info->endpoint;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "U3V");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_u3v, tvb, offset, -1, ENC_NA);
u3v_tree = proto_item_add_subtree(ti, ett_u3v);
if(tvb_captured_length(tvb) >=4) {
prefix = tvb_get_letohl(tvb, offset);
switch (prefix) {
case U3V_STREAM_LEADER_PREFIX:
dissect_u3v_stream_leader(u3v_tree, tvb, pinfo, usb_conv_info);
break;
case U3V_STREAM_TRAILER_PREFIX:
dissect_u3v_stream_trailer(u3v_tree, tvb, pinfo, usb_conv_info);
break;
default:
dissect_u3v_stream_payload(u3v_tree, tvb, pinfo, usb_conv_info);
break;
}
}
return tvb_captured_length(tvb);
}
return 0;
}
static gboolean
dissect_u3v_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
guint32 prefix;
usb_conv_info_t *usb_conv_info;
if (tvb_reported_length(tvb) < 4)
return FALSE;
prefix = tvb_get_letohl(tvb, 0);
usb_conv_info = (usb_conv_info_t *)data;
if (!usb_conv_info)
return FALSE;
if ((U3V_STREAM_LEADER_PREFIX == prefix) || (U3V_STREAM_TRAILER_PREFIX == prefix) ||
(U3V_CONTROL_PREFIX == prefix) || (U3V_EVENT_PREFIX == prefix) ||
((usb_conv_info->interfaceClass == IF_CLASS_MISCELLANEOUS &&
usb_conv_info->interfaceSubclass == IF_SUBCLASS_MISC_U3V))) {
dissect_u3v(tvb, pinfo, tree, data);
return TRUE;
}
return FALSE;
}
static gint
dissect_u3v_descriptors(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
guint8 type;
gint offset = 0;
proto_item * ti;
proto_tree * sub_tree;
guint32 version;
if (tvb_reported_length(tvb) < 2) {
return 0;
}
type = tvb_get_guint8(tvb, 1);
if (type != DESCRIPTOR_TYPE_U3V_INTERFACE) {
return 0;
}
ti = proto_tree_add_item(tree, hf_u3v_device_info_descriptor, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_u3v_device_info_descriptor);
proto_tree_add_item(tree, hf_u3v_device_info_descriptor_bLength, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
ti = proto_tree_add_item(tree, hf_u3v_device_info_descriptor_bDescriptorType, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (U3V INTERFACE)");
offset++;
proto_tree_add_item(tree, hf_u3v_device_info_descriptor_bDescriptorSubtype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (!tvb_bytes_exist(tvb, offset, 4)) {
return offset;
}
version = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(tree, hf_u3v_device_info_descriptor_bGenCPVersion, tvb, offset, 4, ENC_NA);
proto_item_append_text(ti, ": %u.%u", version >> 16, version & 0xFFFF);
sub_tree = proto_item_add_subtree(ti, ett_u3v_device_info_descriptor_gencp_version);
proto_tree_add_item(sub_tree, hf_u3v_device_info_descriptor_bGenCPVersion_minor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sub_tree, hf_u3v_device_info_descriptor_bGenCPVersion_major, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (!tvb_bytes_exist(tvb, offset, 4)) {
return offset;
}
version = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(tree, hf_u3v_device_info_descriptor_bU3VVersion, tvb, offset, 4, ENC_NA);
proto_item_append_text(ti, ": %u.%u", version >> 16, version & 0xFFFF);
sub_tree = proto_item_add_subtree(ti, ett_u3v_device_info_descriptor_u3v_version);
proto_tree_add_item(sub_tree, hf_u3v_device_info_descriptor_bU3VVersion_minor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sub_tree, hf_u3v_device_info_descriptor_bU3VVersion_major, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_u3v_device_info_descriptor_iDeviceGUID, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_u3v_device_info_descriptor_iVendorName, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_u3v_device_info_descriptor_iModelName, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_u3v_device_info_descriptor_iFamilyName, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_u3v_device_info_descriptor_iDeviceVersion, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_u3v_device_info_descriptor_iManufacturerInfo, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_u3v_device_info_descriptor_iSerialNumber, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_u3v_device_info_descriptor_iUserDefinedName, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_bitmask(tree, tvb, offset, hf_u3v_device_info_descriptor_bmSpeedSupport,
ett_u3v_device_info_descriptor_speed_support, speed_support_fields, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
void
proto_register_u3v(void)
{
static gint *ett[] = {
&ett_u3v,
&ett_u3v_cmd,
&ett_u3v_flags,
&ett_u3v_ack,
&ett_u3v_payload_cmd,
&ett_u3v_payload_ack,
&ett_u3v_payload_ack_subtree,
&ett_u3v_payload_cmd_subtree,
&ett_u3v_bootstrap_fields,
&ett_u3v_stream_leader,
&ett_u3v_stream_trailer,
&ett_u3v_stream_payload,
&ett_u3v_device_info_descriptor,
&ett_u3v_device_info_descriptor_speed_support,
&ett_u3v_device_info_descriptor_gencp_version,
&ett_u3v_device_info_descriptor_u3v_version,
};
proto_u3v = proto_register_protocol("USB 3 Vision", "U3V", "u3v");
proto_register_field_array(proto_u3v, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
u3v_handle = register_dissector("u3v", dissect_u3v, proto_u3v);
}
void
proto_reg_handoff_u3v(void)
{
dissector_handle_t u3v_descr_handle = NULL;
dissector_add_uint("usb.bulk", IF_CLASS_MISCELLANEOUS, u3v_handle);
heur_dissector_add("usb.bulk", dissect_u3v_heur, "USB3Vision Protocol", "u3v", proto_u3v,HEURISTIC_ENABLE);
u3v_descr_handle = create_dissector_handle(dissect_u3v_descriptors, proto_u3v);
dissector_add_uint("usb.descriptor", IF_CLASS_MISCELLANEOUS, u3v_descr_handle);
}
