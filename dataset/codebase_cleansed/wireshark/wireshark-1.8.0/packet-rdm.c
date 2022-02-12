static guint16
rdm_checksum(tvbuff_t *tvb, unsigned length)
{
guint16 sum = RDM_SC_RDM;
unsigned i;
for (i = 0; i < length; i++)
sum += tvb_get_guint8(tvb, i);
return sum;
}
static guint
dissect_rdm_pd_queued_message(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_GET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_queued_message_status, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
return offset;
}
static guint
dissect_rdm_pd_dmx_start_address(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_dmx_start_address, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
}
return offset;
}
static guint
dissect_rdm_pd_device_info(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_proto_vers, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_rdm_pd_device_model_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_rdm_pd_product_cat, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_rdm_pd_software_vers_id, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_rdm_pd_dmx_footprint, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_rdm_pd_dmx_pers_current, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_rdm_pd_dmx_pers_total, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_rdm_pd_dmx_start_address, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_rdm_pd_sub_device_count, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_rdm_pd_sensor_count, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
return offset;
}
static guint
dissect_rdm_pd_device_model_description(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_device_model_description, tvb,
offset, len, ENC_BIG_ENDIAN);
offset+=len;
break;
}
return offset;
}
static guint
dissect_rdm_pd_device_label(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_device_label, tvb,
offset, len, ENC_BIG_ENDIAN);
offset+=len;
break;
}
return offset;
}
static guint
dissect_rdm_pd_device_hours(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_device_hours, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
}
return offset;
}
static guint
dissect_rdm_pd_lamp_hours(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_lamp_hours, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
}
return offset;
}
static guint
dissect_rdm_pd_lamp_strikes(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_lamp_strikes, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
}
return offset;
}
static guint
dissect_rdm_pd_sensor_definition(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_sensor_nr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_sensor_nr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_rdm_pd_sensor_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_rdm_pd_sensor_unit, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_rdm_pd_sensor_prefix, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_rdm_pd_sensor_range_min_value, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_rdm_pd_sensor_range_max_value, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_rdm_pd_sensor_normal_min_value, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_rdm_pd_sensor_normal_max_value, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_rdm_pd_sensor_recorded_value_support, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_rdm_pd_sensor_description, tvb,
offset, len - 13, ENC_BIG_ENDIAN);
offset += (len - 13);
break;
}
return offset;
}
static guint
dissect_rdm_pd_sensor_value(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND:
case RDM_CC_SET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_sensor_nr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case RDM_CC_GET_COMMAND_RESPONSE:
case RDM_CC_SET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_sensor_nr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_rdm_pd_sensor_value_pres, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if (len == 7 || len == 9) {
proto_tree_add_item(tree, hf_rdm_pd_sensor_value_low, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_rdm_pd_sensor_value_high, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
}
if (len == 5 || len == 9) {
proto_tree_add_item(tree, hf_rdm_pd_sensor_value_rec, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
}
break;
}
return offset;
}
static guint
dissect_rdm_pd_manufacturer_label(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_manu_label, tvb,
offset, len, ENC_BIG_ENDIAN);
offset+=len;
break;
}
return offset;
}
static guint
dissect_rdm_pd_disc_unique_branch(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_DISCOVERY_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_disc_unique_branch_lb_uid, tvb,
offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_rdm_pd_disc_unique_branch_ub_uid, tvb,
offset, 6, ENC_NA);
offset += 6;
break;
}
return offset;
}
static guint
dissect_rdm_pd_disc_mute(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_DISCOVERY_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_disc_mute_control_field, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (len > 2) {
proto_tree_add_item(tree, hf_rdm_pd_disc_mute_binding_uid, tvb,
offset, 6, ENC_NA);
offset += 6;
}
break;
}
return offset;
}
static guint
dissect_rdm_pd_disc_un_mute(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_DISCOVERY_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_disc_unmute_control_field, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (len > 2) {
proto_tree_add_item(tree, hf_rdm_pd_disc_unmute_binding_uid, tvb,
offset, 6, ENC_NA);
offset += 6;
}
break;
}
return offset;
}
static guint
dissect_rdm_pd_proxied_devices(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
while (len >= 6) {
proto_tree_add_item(tree, hf_rdm_pd_proxied_devices_uid, tvb,
offset, 6, ENC_NA);
offset += 6;
len -= 6;
}
break;
}
return offset;
}
static guint
dissect_rdm_pd_proxied_device_count(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_proxied_device_count, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_proxied_device_list_change, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_comms_status(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_comms_status_short_msg, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_comms_status_len_mismatch, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_comms_status_csum_fail, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
}
return offset;
}
static guint
dissect_rdm_pd_status_messages(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_status_messages_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case RDM_CC_GET_COMMAND_RESPONSE:
while (len >= 9) {
proto_tree_add_item(tree, hf_rdm_pd_status_messages_sub_device_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len -= 2;
proto_tree_add_item(tree, hf_rdm_pd_status_messages_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
proto_tree_add_item(tree, hf_rdm_pd_status_messages_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len -= 2;
proto_tree_add_item(tree, hf_rdm_pd_status_messages_data_value_1, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len -= 2;
proto_tree_add_item(tree, hf_rdm_pd_status_messages_data_value_2, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len -= 2;
}
break;
}
return offset;
}
static guint
dissect_rdm_pd_status_id_description(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_status_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_status_id_description, tvb,
offset, len, ENC_BIG_ENDIAN);
offset += len;
break;
}
return offset;
}
static guint
dissect_rdm_pd_clear_status_id(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_, guint8 cc _U_, guint8 len _U_)
{
return offset;
}
static guint
dissect_rdm_pd_sub_device_status_report_threshold(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_sub_device_status_report_threshold_status_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_supported_parameters(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
while (len >= 2) {
proto_tree_add_item(tree, hf_rdm_pd_parameter_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len -= 2;
}
break;
}
return offset;
}
static guint
dissect_rdm_pd_parameter_description(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_parameter_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_parameter_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_parameter_pdl_size, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_parameter_data_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_parameter_cmd_class, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_parameter_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_parameter_unit, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_parameter_prefix, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_parameter_min_value, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rdm_pd_parameter_max_value, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rdm_pd_parameter_default_value, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rdm_pd_parameter_description, tvb,
offset, len - 0x14, ENC_BIG_ENDIAN);
offset += (len - 0x14);
break;
}
return offset;
}
static guint
dissect_rdm_pd_product_detail_id_list(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
while (len >= 2) {
proto_tree_add_item(tree, hf_rdm_pd_product_detail_id_list, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len -= 2;
}
break;
}
return offset;
}
static guint
dissect_rdm_pd_factory_defaults(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_factory_defaults, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_language_capabilities(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
while (len >= 2) {
proto_tree_add_item(tree, hf_rdm_pd_language_code, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len -= 2;
}
break;
}
return offset;
}
static guint
dissect_rdm_pd_language(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_language_code, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
}
return offset;
}
static guint
dissect_rdm_pd_software_version_label(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_software_version_label, tvb,
offset, len, ENC_BIG_ENDIAN);
offset += len;
break;
}
return offset;
}
static guint
dissect_rdm_pd_boot_software_version_id(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_boot_software_version_id, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
}
return offset;
}
static guint
dissect_rdm_pd_boot_software_version_label(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_boot_software_version_label, tvb,
offset, len, ENC_BIG_ENDIAN);
offset += len;
break;
}
return offset;
}
static guint
dissect_rdm_pd_dmx_personality(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_dmx_pers_nr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_dmx_pers_current, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_dmx_pers_count, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_dmx_personality_description(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_dmx_pers_description, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_dmx_pers_description, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_dmx_pers_slots, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_dmx_pers_text, tvb,
offset, (len - 3), ENC_BIG_ENDIAN);
offset += (len - 3);
break;
}
return offset;
}
static guint
dissect_rdm_pd_slot_info(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
while (len >= 5) {
proto_tree_add_item(tree, hf_rdm_pd_slot_offset, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len -= 2;
proto_tree_add_item(tree, hf_rdm_pd_slot_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
proto_tree_add_item(tree, hf_rdm_pd_slot_label_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len -= 2;
}
break;
}
return offset;
}
static guint
dissect_rdm_pd_slot_description(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_slot_nr, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_slot_nr, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_slot_description, tvb,
offset, (len - 2), ENC_BIG_ENDIAN);
offset += (len - 2);
break;
}
return offset;
}
static guint
dissect_rdm_pd_slot_value(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND_RESPONSE:
while (len >= 3) {
proto_tree_add_item(tree, hf_rdm_pd_slot_offset, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len -= 2;
proto_tree_add_item(tree, hf_rdm_pd_slot_value, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
}
break;
}
return offset;
}
static guint
dissect_rdm_pd_record_sensors(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_sensor_nr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_sensor_nr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_sensor_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_sensor_unit, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_sensor_prefix, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_sensor_range_min_value, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_sensor_range_max_value, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_sensor_normal_min_value, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_sensor_normal_max_value, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_rec_value_support, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_sensor_description, tvb,
offset, (len - 13), ENC_BIG_ENDIAN);
offset += (len - 13);
break;
}
return offset;
}
static guint
dissect_rdm_pd_lamp_state(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_lamp_state, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_lamp_on_mode(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_lamp_on_mode, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_device_power_cycles(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_device_power_cycles, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset +=4;
break;
}
return offset;
}
static guint
dissect_rdm_pd_display_invert(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_display_invert, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_display_level(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_display_level, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_pan_invert(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_pan_invert, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_tilt_invert(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_tilt_invert, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_pan_tilt_swap(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_tilt_swap, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_real_time_clock(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_real_time_clock_year, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_real_time_clock_month, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_real_time_clock_day, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_real_time_clock_hour, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_real_time_clock_minute, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_real_time_clock_second, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_identify_device(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_identify_device, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_identify_device_state, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_reset_device(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_reset_device, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_power_state(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_power_state, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_perform_selftest(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_selftest_nr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_selftest_state, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_pd_self_test_description(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len)
{
switch(cc) {
case RDM_CC_GET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_selftest_nr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_selftest_nr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rdm_pd_selftest_description, tvb,
offset, (len - 1), ENC_BIG_ENDIAN);
offset += (len - 1);
break;
}
return offset;
}
static guint
dissect_rdm_pd_capture_preset(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
proto_tree_add_item(tree, hf_rdm_pd_capture_preset_scene_nr, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_capture_preset_up_fade_time, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_capture_preset_down_fade_time, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_capture_preset_wait_time, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
}
return offset;
}
static guint
dissect_rdm_pd_preset_playback(tvbuff_t *tvb, guint offset, proto_tree *tree, guint8 cc, guint8 len _U_)
{
switch(cc) {
case RDM_CC_SET_COMMAND:
case RDM_CC_GET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_pd_preset_playback_mode, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rdm_pd_preset_playback_level, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
return offset;
}
static guint
dissect_rdm_mdb(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint8 cc;
guint16 param_id;
guint8 parameter_data_length;
proto_tree *hi,*si, *mdb_tree;
cc = tvb_get_guint8(tvb, offset + 4);
switch (cc) {
case RDM_CC_DISCOVERY_COMMAND:
case RDM_CC_GET_COMMAND:
case RDM_CC_SET_COMMAND:
proto_tree_add_item(tree, hf_rdm_port_id, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case RDM_CC_DISCOVERY_COMMAND_RESPONSE:
case RDM_CC_GET_COMMAND_RESPONSE:
case RDM_CC_SET_COMMAND_RESPONSE:
proto_tree_add_item(tree, hf_rdm_response_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
proto_tree_add_item(tree, hf_rdm_message_count, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_rdm_sub_device, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
hi = proto_tree_add_item(tree, hf_rdm_mdb, tvb,
offset, -1, ENC_BIG_ENDIAN);
mdb_tree = proto_item_add_subtree(hi,ett_rdm);
proto_tree_add_item(mdb_tree, hf_rdm_command_class, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
param_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(mdb_tree, hf_rdm_parameter_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
parameter_data_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mdb_tree, hf_rdm_parameter_data_length, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_item_set_len( mdb_tree, parameter_data_length + 4);
if (parameter_data_length > 0) {
hi = proto_tree_add_item(mdb_tree, hf_rdm_parameter_data, tvb,
offset, parameter_data_length, ENC_BIG_ENDIAN);
si = proto_item_add_subtree(hi,ett_rdm);
switch(param_id) {
case RDM_PARAM_ID_SENSOR_VALUE:
offset = dissect_rdm_pd_sensor_value(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_QUEUED_MESSAGE:
offset = dissect_rdm_pd_queued_message(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DMX_START_ADDRESS:
offset = dissect_rdm_pd_dmx_start_address(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DEVICE_INFO:
offset = dissect_rdm_pd_device_info(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DEVICE_MODEL_DESCRIPTION:
offset = dissect_rdm_pd_device_model_description(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DEVICE_LABEL:
offset = dissect_rdm_pd_device_label(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DEVICE_HOURS:
offset = dissect_rdm_pd_device_hours(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_LAMP_HOURS:
offset = dissect_rdm_pd_lamp_hours(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_LAMP_STRIKES:
offset = dissect_rdm_pd_lamp_strikes(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_SENSOR_DEFINITION:
offset = dissect_rdm_pd_sensor_definition(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_MANUFACTURER_LABEL:
offset = dissect_rdm_pd_manufacturer_label(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DISC_UNIQUE_BRANCH:
offset = dissect_rdm_pd_disc_unique_branch(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DISC_MUTE:
offset = dissect_rdm_pd_disc_mute(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DISC_UN_MUTE:
offset = dissect_rdm_pd_disc_un_mute(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_PROXIED_DEVICES:
offset = dissect_rdm_pd_proxied_devices(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_PROXIED_DEVICE_COUNT:
offset = dissect_rdm_pd_proxied_device_count(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_COMMS_STATUS:
offset = dissect_rdm_pd_comms_status(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_STATUS_MESSAGES:
offset = dissect_rdm_pd_status_messages(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_STATUS_ID_DESCRIPTION:
offset = dissect_rdm_pd_status_id_description(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_CLEAR_STATUS_ID:
offset = dissect_rdm_pd_clear_status_id(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_SUB_DEVICE_STATUS_REPORT_THRESHOLD:
offset = dissect_rdm_pd_sub_device_status_report_threshold(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_SUPPORTED_PARAMETERS:
offset = dissect_rdm_pd_supported_parameters(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_PARAMETER_DESCRIPTION:
offset = dissect_rdm_pd_parameter_description(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_PRODUCT_DETAIL_ID_LIST:
offset = dissect_rdm_pd_product_detail_id_list(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_FACTORY_DEFAULTS:
offset = dissect_rdm_pd_factory_defaults(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_LANGUAGE_CAPABILITIES:
offset = dissect_rdm_pd_language_capabilities(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_LANGUAGE:
offset = dissect_rdm_pd_language(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_SOFTWARE_VERSION_LABEL:
offset = dissect_rdm_pd_software_version_label(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_BOOT_SOFTWARE_VERSION_ID:
offset = dissect_rdm_pd_boot_software_version_id(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_BOOT_SOFTWARE_VERSION_LABEL:
offset = dissect_rdm_pd_boot_software_version_label(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DMX_PERSONALITY:
offset = dissect_rdm_pd_dmx_personality(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DMX_PERSONALITY_DESCRIPTION:
offset = dissect_rdm_pd_dmx_personality_description(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_SLOT_INFO:
offset = dissect_rdm_pd_slot_info(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_SLOT_DESCRIPTION:
offset = dissect_rdm_pd_slot_description(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DEFAULT_SLOT_VALUE:
offset = dissect_rdm_pd_slot_value(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_RECORD_SENSORS:
offset = dissect_rdm_pd_record_sensors(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_LAMP_STATE:
offset = dissect_rdm_pd_lamp_state(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_LAMP_ON_MODE:
offset = dissect_rdm_pd_lamp_on_mode(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DEVICE_POWER_CYCLES:
offset = dissect_rdm_pd_device_power_cycles(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DISPLAY_INVERT:
offset = dissect_rdm_pd_display_invert(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_DISPLAY_LEVEL:
offset = dissect_rdm_pd_display_level(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_PAN_INVERT:
offset = dissect_rdm_pd_pan_invert(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_TILT_INVERT:
offset = dissect_rdm_pd_tilt_invert(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_PAN_TILT_SWAP:
offset = dissect_rdm_pd_pan_tilt_swap(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_REAL_TIME_CLOCK:
offset = dissect_rdm_pd_real_time_clock(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_IDENTIFY_DEVICE:
offset = dissect_rdm_pd_identify_device(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_RESET_DEVICE:
offset = dissect_rdm_pd_reset_device(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_POWER_STATE:
offset = dissect_rdm_pd_power_state(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_PERFORM_SELFTEST:
offset = dissect_rdm_pd_perform_selftest(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_SELF_TEST_DESCRIPTION:
offset = dissect_rdm_pd_self_test_description(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_CAPTURE_PRESET:
offset = dissect_rdm_pd_capture_preset(tvb, offset, si, cc, parameter_data_length);
break;
case RDM_PARAM_ID_PRESET_PLAYBACK:
offset = dissect_rdm_pd_preset_playback(tvb, offset, si, cc, parameter_data_length);
break;
default:
proto_tree_add_item(si, hf_rdm_parameter_data_raw, tvb,
offset, parameter_data_length, ENC_NA);
offset += parameter_data_length;
break;
}
}
return offset;
}
static void
dissect_rdm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RDM");
col_clear(pinfo->cinfo, COL_INFO);
if (tree != NULL) {
gint padding_size;
guint16 man_id;
guint32 dev_id;
unsigned message_length, checksum, checksum_shouldbe, offset = 0;
proto_item *item;
proto_tree *checksum_tree;
proto_tree *ti = proto_tree_add_item(tree, proto_rdm, tvb,
offset, -1, ENC_NA);
proto_tree *rdm_tree = proto_item_add_subtree(ti, ett_rdm);
proto_tree_add_item(rdm_tree, hf_rdm_sub_start_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
message_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(rdm_tree, hf_rdm_message_length, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
man_id = tvb_get_ntohs(tvb, offset);
dev_id = tvb_get_ntohl(tvb, offset + 2);
proto_item_append_text(ti, ", Dst UID: %04x:%08x", man_id, dev_id);
proto_tree_add_item(rdm_tree, hf_rdm_dest_uid, tvb,
offset, 6, ENC_NA);
offset += 6;
man_id = tvb_get_ntohs(tvb, offset);
dev_id = tvb_get_ntohl(tvb, offset + 2);
proto_item_append_text(ti, ", Src UID: %04x:%08x", man_id, dev_id);
proto_tree_add_item(rdm_tree, hf_rdm_src_uid, tvb,
offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(rdm_tree, hf_rdm_transaction_number, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
offset = dissect_rdm_mdb(tvb, offset, rdm_tree);
padding_size = offset - (message_length - 1);
if (padding_size > 0) {
proto_tree_add_item(rdm_tree, hf_rdm_intron, tvb,
offset, padding_size, ENC_NA);
offset += padding_size;
}
checksum_shouldbe = rdm_checksum(tvb, offset);
checksum = tvb_get_ntohs(tvb, offset);
item = proto_tree_add_item(rdm_tree, hf_rdm_checksum, tvb,
offset, 2, ENC_BIG_ENDIAN);
if (checksum == checksum_shouldbe) {
proto_item_append_text(item, " [correct]");
checksum_tree = proto_item_add_subtree(item, ett_rdm);
item = proto_tree_add_boolean(checksum_tree, hf_rdm_checksum_good, tvb,
offset, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_rdm_checksum_bad, tvb,
offset, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
} else {
proto_item_append_text(item, " [incorrect, should be 0x%04x]", checksum_shouldbe);
checksum_tree = proto_item_add_subtree(item, ett_rdm);
item = proto_tree_add_boolean(checksum_tree, hf_rdm_checksum_good, tvb,
offset, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_rdm_checksum_bad, tvb,
offset, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
}
offset += 2;
if (offset < tvb_length(tvb))
proto_tree_add_item(rdm_tree, hf_rdm_trailer, tvb,
offset, -1, ENC_NA);
}
}
void
proto_register_rdm(void)
{
static hf_register_info hf[] = {
{ &hf_rdm_sub_start_code,
{ "Sub-start code", "rdm.ssc",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_message_length,
{ "Message length", "rdm.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_dest_uid,
{ "Destination UID", "rdm.dst",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_src_uid,
{ "Source UID", "rdm.src",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_transaction_number,
{ "Transaction number", "rdm.tn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_port_id,
{ "Port ID", "rdm.port_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_response_type,
{ "Response type", "rdm.rt",
FT_UINT8, BASE_HEX, VALS(rdm_rt_vals), 0x0,
NULL, HFILL }},
{ &hf_rdm_message_count,
{ "Message count", "rdm.mc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_sub_device,
{ "Sub-device", "rdm.sd",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_mdb,
{ "Message Data Block", "rdm.mdb",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_command_class,
{ "Command class", "rdm.cc",
FT_UINT8, BASE_HEX, VALS(rdm_cc_vals), 0x0,
NULL, HFILL }},
{ &hf_rdm_parameter_id,
{ "Parameter ID", "rdm.pid",
FT_UINT16, BASE_HEX, VALS(rdm_param_id_vals), 0x0,
NULL, HFILL }},
{ &hf_rdm_parameter_data_length,
{ "Parameter data length", "rdm.pdl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_parameter_data,
{ "Parameter data", "rdm.pd",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_parameter_data_raw,
{ "Raw Data", "rdm.pd.raw",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_intron,
{ "Intron", "rdm.intron",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_checksum,
{ "Checksum", "rdm.checksum",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_checksum_good,
{ "Good Checksum", "rdm.checksum_good",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum matches packet content; False: doesn't match content", HFILL }},
{ &hf_rdm_checksum_bad,
{ "Bad Checksum", "rdm.checksum_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum doesn't match packet content; False: matches content", HFILL }},
{ &hf_rdm_trailer,
{ "Trailer", "rdm.trailer",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_queued_message_status,
{ "Status", "rdm.pd.queued_message.status",
FT_UINT8, BASE_HEX, VALS(rdm_status_vals), 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_nr,
{ "Sensor Nr.", "rdm.pd.sensor.nr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_value_pres,
{ "Sensor Present Value", "rdm.pd.sensor.value.present",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_value_low,
{ "Sensor Lowest Value", "rdm.pd.sensor.value.lowest",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_value_high,
{ "Sensor Highest Value", "rdm.pd.sensor.value.highest",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_value_rec,
{ "Sensor Recorded Value", "rdm.pd.sensor.value.recorded",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_range_min_value,
{ "Sensor Range Min. Value", "rdm.pd.sensor.range.min_value",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_range_max_value,
{ "Sensor Range Max. Value", "rdm.pd.sensor.range.max_value",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_normal_min_value,
{ "Sensor Normal Min. Value", "rdm.pd.sensor.normal.min_value",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_normal_max_value,
{ "Sensor Normal Max. Value", "rdm.pd.sensor.normal.max_value",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_recorded_value_support,
{ "Sensor Recorded Value Support", "rdm.pd.sensor.recorded_value_support",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_type,
{ "Sensor Type", "rdm.pd.sensor_type",
FT_UINT8, BASE_HEX, VALS(rdm_sensor_type_vals), 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_unit,
{ "Sensor Unit", "rdm.pd.sensor_unit",
FT_UINT8, BASE_HEX, VALS(rdm_unit_vals), 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_prefix,
{ "Sensor Prefix", "rdm.pd.sensor_prefix",
FT_UINT8, BASE_HEX, VALS(rdm_prefix_vals), 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_description,
{ "Sensor Description", "rdm.pd.sensor.description",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_manu_label,
{ "Manufacturur Label", "rdm.pd.manu_label",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_device_label,
{ "Device Label", "rdm.pd.device_label",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_dmx_start_address,
{ "DMX Start Address", "rdm.pd.dmx_start_address",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_device_hours,
{ "Device Hours", "rdm.pd.device_hours",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_lamp_hours,
{ "Lamp Hours", "rdm.pd.lamp_hours",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_lamp_strikes,
{ "Lamp Strikes", "rdm.pd.lamp_strikes",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_proto_vers,
{ "RDM Protocol Version", "rdm.pd.proto_vers",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_device_model_id,
{ "Device Model ID", "rdm.pd.device_model_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_product_cat,
{ "Product Category", "rdm.pd.product_cat",
FT_UINT16, BASE_HEX, VALS(rdm_product_cat_vals), 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_software_vers_id,
{ "Software Version ID", "rdm.pd.software_version_id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_dmx_footprint,
{ "DMX Footprint", "rdm.pd.dmx_footprint",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_dmx_pers_current,
{ "Current DMX Personallity", "rdm.pd.dmx_pers_current",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_dmx_pers_total,
{ "Total nr. DMX Personallities", "rdm.pd.dmx_pers_total",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sub_device_count,
{ "Sub-Device Count", "rdm.pd.sub_device_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sensor_count,
{ "Sensor Count", "rdm.pd.sensor_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_device_model_description,
{ "Device Model Description", "rdm.pd.device_model_description",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_disc_unique_branch_lb_uid,
{ "Lower Bound UID", "rdm.pd.disc_unique_branch.lb_uid",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_disc_unique_branch_ub_uid,
{ "Upper Bound UID", "rdm.pd.disc_unique_branch.ub_uid",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_disc_mute_control_field,
{ "Control Field", "rdm.pd.disc_mute.control_field",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_disc_mute_binding_uid,
{ "Binding UID", "rdm.pd.disc_mute.binding_uid",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_disc_unmute_control_field,
{ "Control Field", "rdm.pd.disc_unmute.control_field",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_disc_unmute_binding_uid,
{ "Binding UID", "rdm.pd.disc_unmute.binding_uid",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_proxied_devices_uid,
{ "UID", "rdm.pd.proxied_devices.uid",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_proxied_device_count,
{ "Device Count", "rdm.pd.device_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_proxied_device_list_change,
{ "List Change", "rdm.pd.list_change",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_real_time_clock_year,
{ "Year", "rdm.pd.real_time_clock.year",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_real_time_clock_month,
{ "Month", "rdm.pd.real_time_clock.month",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_real_time_clock_day,
{ "Day", "rdm.pd.real_time_clock.day",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_real_time_clock_hour,
{ "Hour", "rdm.pd.real_time_clock.hour",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_real_time_clock_minute,
{ "Minute", "rdm.pd.real_time_clock.minute",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_real_time_clock_second,
{ "Second", "rdm.pd.real_time_clock.second",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_lamp_state,
{ "Lamp State", "rdm.pd.lamp_state",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_lamp_on_mode,
{ "Lamp On Mode", "rdm.pd.lamp_on_mode",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_device_power_cycles,
{ "Device Power Cycles", "rdm.pd.device_power_cycles",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_display_invert,
{ "Display Invert", "rdm.pd.display_invert",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_display_level,
{ "Display Level", "rdm.pd.display_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_pan_invert,
{ "Pan Invert", "rdm.pd.pan_invert",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_tilt_invert,
{ "Tilt Invert", "rdm.pd.tilt_invert",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_tilt_swap,
{ "Tilt Swap", "rdm.pd.tilt_swap",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_selftest_nr,
{ "Selftest Nr.", "rdm.pd.selftest.nr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_selftest_state,
{ "Selftest State", "rdm.pd.selftest.state",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_selftest_description,
{ "Selftest Description", "rdm.pd.selftest.description",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_language_code,
{ "Language Code", "rdm.pd.language_code",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_identify_device,
{ "Identify Device", "rdm.pd.identify_device",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_identify_device_state,
{ "Identify Device State", "rdm.pd.identify_device.state",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_reset_device,
{ "Reset Device", "rdm.pd.reset_device",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_power_state,
{ "Power State", "rdm.pd.power_state",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_capture_preset_scene_nr,
{ "Scene Nr.", "rdm.pd.capture_preset.scene_nr",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_capture_preset_up_fade_time,
{ "Up Fade Time", "rdm.pd.capture_preset.up_fade_time",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_capture_preset_down_fade_time,
{ "Down Fade Time", "rdm.pd.capture_preset.down_fade_time",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_capture_preset_wait_time,
{ "Wait Time", "rdm.pd.capture_preset.wait_time",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_preset_playback_mode,
{ "Mode", "rdm.pd.preset_playback.mode",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_preset_playback_level,
{ "Level", "rdm.pd.preset_playback.level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_parameter_id,
{ "ID", "rdm.pd.parameter.id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_parameter_pdl_size,
{ "PDL Size", "rdm.pd.parameter.pdl_size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_parameter_data_type,
{ "Data Type", "rdm.pd.parameter.data_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_parameter_cmd_class,
{ "Command Class", "rdm.pd.parameter.cmd_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_parameter_type,
{ "Type", "rdm.pd.parameter.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_parameter_unit,
{ "Unit", "rdm.pd.parameter.unit",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_parameter_prefix,
{ "Prefix", "rdm.pd.parameter.prefix",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_parameter_min_value,
{ "Min. Value", "rdm.pd.parameter.min_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_parameter_max_value,
{ "Max. Value", "rdm.pd.parameter.max_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_parameter_default_value,
{ "Delauft Value", "rdm.pd.parameter.default_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_parameter_description,
{ "Description", "rdm.pd.parameter.description",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_software_version_label,
{ "Version Label", "rdm.pd.software_version.label",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_boot_software_version_id,
{ "Version ID", "rdm.pd.boot_software_version.id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_boot_software_version_label,
{ "Version Label", "rdm.pd.boot_software_version.label",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_comms_status_short_msg,
{ "Short Msg", "rdm.pd.comms_status.short_msg",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_comms_status_len_mismatch,
{ "Len Mismatch", "rdm.pd.comms_status.len_mismatch",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_comms_status_csum_fail,
{ "Checksum Fail", "rdm.pd.comms_status.csum_fail",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_status_messages_type,
{ "Type", "rdm.pd.status_messages.type",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_status_messages_sub_device_id,
{ "Sub. Device ID", "rdm.pd.status_messages.sub_devices_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_status_messages_id,
{ "ID", "rdm.pd.status_messages.id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_status_messages_data_value_1,
{ "Data Value 1", "rdm.pd.status_messages.data_value_1",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_status_messages_data_value_2,
{ "Data Value 2", "rdm.pd.status_messages.data_value_2",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_status_id,
{ "ID", "rdm.pd.status_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_status_id_description,
{ "Description", "rdm.pd.status_id.description",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_sub_device_status_report_threshold_status_type,
{ "Status Type", "rdm.pd.sub_device_status_report_threshold.status_type",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_product_detail_id_list,
{ "Sensor Count", "rdm.pd.product_detail_id_list",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_factory_defaults,
{ "Factory Defaults", "rdm.pd.factory_defaults",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_dmx_pers_nr,
{ "DMX Pers. Nr.", "rdm.pd.dmx_pers.nr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_dmx_pers_count,
{ "DMX Pers. Count", "rdm.pd.dmx_pers.count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_dmx_pers_description,
{ "DMX Pers. Description", "rdm.pd.dmx_pers.description",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_dmx_pers_slots,
{ "DMX Pers. Slots", "rdm.pd.dmx_pers.slots",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_dmx_pers_text,
{ "DMX Pers. Text", "rdm.pd.dmx_pers.text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_slot_offset,
{ "Slot Offset", "rdm.pd.slot_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_slot_type,
{ "Slot Type", "rdm.pd.slot_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_slot_label_id,
{ "Slot Label ID", "rdm.pd.slot_label_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_slot_nr,
{ "Slot Nr.", "rdm.pd.slot_nr",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_slot_description,
{ "Slot Description", "rdm.pd.slot_description",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_slot_value,
{ "Slot Value", "rdm.pd.slot_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rdm_pd_rec_value_support,
{ "Rec. Value Support", "rdm.pd.rec_value_support",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_rdm
};
proto_rdm = proto_register_protocol("Remote Device Management",
"RDM", "rdm");
proto_register_field_array(proto_rdm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("rdm", dissect_rdm, proto_rdm);
}
void
proto_reg_handoff_rdm(void)
{
}
