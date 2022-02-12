static int
dissect_zbee_zcl_basic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_basic_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
if (tree) {
proto_tree_add_item(tree, hf_zbee_zcl_basic_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
}
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_BASIC_RESET_FACTORY_DEFAULTS:
break;
default:
break;
}
}
return tvb_captured_length(tvb);
}
void
dissect_zcl_basic_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int * alarm_mask[] = {
&hf_zbee_zcl_basic_alarm_mask_gen_hw_fault,
&hf_zbee_zcl_basic_alarm_mask_gen_sw_fault,
&hf_zbee_zcl_basic_alarm_mask_reserved,
NULL
};
static const int * local_cfg[] = {
&hf_zbee_zcl_basic_disable_local_cfg_reset,
&hf_zbee_zcl_basic_disable_local_cfg_device_cfg,
&hf_zbee_zcl_basic_disable_local_cfg_reserved,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_BASIC_POWER_SOURCE:
proto_tree_add_item(tree, hf_zbee_zcl_basic_pwr_src, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BASIC_DEVICE_ENABLED:
proto_tree_add_item(tree, hf_zbee_zcl_basic_dev_en, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BASIC_ALARM_MASK:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_basic_alarm_mask , ett_zbee_zcl_basic_alarm_mask, alarm_mask, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BASIC_DISABLE_LOCAL_CFG:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_basic_disable_local_cfg , ett_zbee_zcl_basic_dis_local_cfg, local_cfg, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BASIC_ZCL_VERSION:
case ZBEE_ZCL_ATTR_ID_BASIC_APPL_VERSION:
case ZBEE_ZCL_ATTR_ID_BASIC_STACK_VERSION:
case ZBEE_ZCL_ATTR_ID_BASIC_HW_VERSION:
case ZBEE_ZCL_ATTR_ID_BASIC_MANUFACTURER_NAME:
case ZBEE_ZCL_ATTR_ID_BASIC_MODEL_ID:
case ZBEE_ZCL_ATTR_ID_BASIC_DATE_CODE:
case ZBEE_ZCL_ATTR_ID_BASIC_PHY_ENVIRONMENT:
case ZBEE_ZCL_ATTR_ID_BASIC_LOCATION_DESCR:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_basic(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_basic_attr_id,
{ "Attribute", "zbee_zcl_general.basic.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_basic_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_basic_pwr_src,
{ "Power Source", "zbee_zcl_general.basic.attr.pwr_src", FT_UINT8, BASE_HEX, VALS(zbee_zcl_basic_pwr_src_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_basic_dev_en,
{ "Device Enabled", "zbee_zcl_general.basic.attr.dev_en", FT_UINT8, BASE_HEX, VALS(zbee_zcl_basic_dev_en_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_basic_alarm_mask,
{ "Alarm Mask", "zbee_zcl_general.basic.attr.alarm_mask", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_basic_alarm_mask_gen_hw_fault,
{ "General hardware fault", "zbee_zcl_general.basic.attr.alarm_mask.gen_hw_fault", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_BASIC_ALARM_GEN_HW_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_basic_alarm_mask_gen_sw_fault,
{ "General software fault", "zbee_zcl_general.basic.attr.alarm_mask.gen_sw_fault", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_BASIC_ALARM_GEN_SW_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_basic_alarm_mask_reserved,
{ "Reserved", "zbee_zcl_general.basic.attr.alarm_mask.reserved", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_BASIC_ALARM_RESERVED, NULL, HFILL } },
{ &hf_zbee_zcl_basic_disable_local_cfg,
{ "Disable Local Config", "zbee_zcl_general.basic.attr.dis_loc_cfg", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_basic_disable_local_cfg_reset,
{ "Reset (to factory defaults)", "zbee_zcl_general.basic.attr.dis_loc_cfg.reset", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_BASIC_DIS_LOC_CFG_RESET , NULL, HFILL } },
{ &hf_zbee_zcl_basic_disable_local_cfg_device_cfg,
{ "Device configuration", "zbee_zcl_general.basic.attr.dis_loc_cfg.dev_cfg", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_BASIC_DIS_LOC_CFG_DEV_CFG , NULL, HFILL } },
{ &hf_zbee_zcl_basic_disable_local_cfg_reserved,
{ "Reserved", "zbee_zcl_general.basic.attr.dis_loc_cfg.reserved", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_BASIC_DIS_LOC_CFG_RESERVED , NULL, HFILL } },
{ &hf_zbee_zcl_basic_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.basic.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_basic_srv_rx_cmd_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_BASIC_NUM_ETT];
ett[0] = &ett_zbee_zcl_basic;
ett[1] = &ett_zbee_zcl_basic_alarm_mask;
ett[2] = &ett_zbee_zcl_basic_dis_local_cfg;
proto_zbee_zcl_basic = proto_register_protocol("ZigBee ZCL Basic", "ZCL Basic", ZBEE_PROTOABBREV_ZCL_BASIC);
proto_register_field_array(proto_zbee_zcl_basic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_BASIC, dissect_zbee_zcl_basic, proto_zbee_zcl_basic);
}
void
proto_reg_handoff_zbee_zcl_basic(void)
{
dissector_handle_t basic_handle;
basic_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_BASIC);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_BASIC, basic_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_basic,
ett_zbee_zcl_basic,
ZBEE_ZCL_CID_BASIC,
hf_zbee_zcl_basic_attr_id,
hf_zbee_zcl_basic_srv_rx_cmd_id,
-1,
(zbee_zcl_fn_attr_data)dissect_zcl_basic_attr_data
);
}
static int
dissect_zbee_zcl_power_config(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
static void
decode_power_conf_voltage(gchar *s, guint32 value)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%d [V]", value/10, value%10);
return;
}
static void
decode_power_conf_frequency(gchar *s, guint32 value)
{
if(value == 0x00)
g_snprintf(s, ITEM_LABEL_LENGTH, "Frequency too low to be measured (or DC supply)");
else if(value == 0xfe)
g_snprintf(s, ITEM_LABEL_LENGTH, "Frequency too high to be measured");
else if (value == 0xff)
g_snprintf(s, ITEM_LABEL_LENGTH, "Frequency could not be measured");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d [Hz]", value*2);
return;
}
static void
decode_power_conf_batt_AHr(gchar *s, guint32 value)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d [mAHr]", value*10);
return;
}
void
dissect_zcl_power_config_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
proto_item *it;
static const int * mains_alarm_mask[] = {
&hf_zbee_zcl_power_config_mains_alarm_mask_low,
&hf_zbee_zcl_power_config_mains_alarm_mask_high,
&hf_zbee_zcl_power_config_mains_alarm_mask_reserved,
NULL
};
static const int * batt_alarm_mask[] = {
&hf_zbee_zcl_power_config_batt_alarm_mask_low,
&hf_zbee_zcl_power_config_batt_alarm_mask_reserved,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_POWER_CONF_MAINS_VOLTAGE:
proto_tree_add_item(tree, hf_zbee_zcl_power_config_mains_voltage, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_POWER_CONF_MAINS_FREQUENCY:
proto_tree_add_item(tree, hf_zbee_zcl_power_config_mains_frequency, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_POWER_CONF_MAINS_ALARM_MASK:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_power_config_mains_alarm_mask, ett_zbee_zcl_power_config_mains_alarm_mask, mains_alarm_mask, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_POWER_CONF_MAINS_VOLTAGE_MIN_THR:
proto_tree_add_item(tree, hf_zbee_zcl_power_config_mains_voltage_min_thr, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_POWER_CONF_MAINS_VOLTAGE_MAX_THR:
proto_tree_add_item(tree, hf_zbee_zcl_power_config_mains_voltage_max_thr, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_POWER_CONF_MAINS_VOLTAGE_DWELL_TP:
it = proto_tree_add_item(tree, hf_zbee_zcl_power_config_mains_voltage_dwell_tp, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(it, " [s]");
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_POWER_CONF_BATTERY_SIZE:
proto_tree_add_item(tree, hf_zbee_zcl_power_config_batt_type, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_POWER_CONF_BATTERY_VOLTAGE:
proto_tree_add_item(tree, hf_zbee_zcl_power_config_batt_voltage, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_POWER_CONF_BATTERY_AH_RATING:
proto_tree_add_item(tree, hf_zbee_zcl_power_config_batt_ah_rating, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_POWER_CONF_BATTERY_RATED_VOLTAGE:
proto_tree_add_item(tree, hf_zbee_zcl_power_config_batt_rated_voltage, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_POWER_CONF_BATTERY_ALARM_MASK:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_power_config_batt_alarm_mask, ett_zbee_zcl_power_config_batt_alarm_mask, batt_alarm_mask, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_POWER_CONF_BATTERY_VOLTAGE_MIN_THR:
proto_tree_add_item(tree, hf_zbee_zcl_power_config_batt_voltage_min_thr, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_POWER_CONF_BATTERY_MANUFACTURER:
case ZBEE_ZCL_ATTR_ID_POWER_CONF_BATTERY_QUANTITY:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_power_config(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_power_config_attr_id,
{ "Attribute", "zbee_zcl_general.power_config.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_power_config_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_batt_type,
{ "Battery Type", "zbee_zcl_general.power_config.attr.batt_type", FT_UINT8, BASE_HEX, VALS(zbee_zcl_power_config_batt_type_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_mains_alarm_mask,
{ "Mains Alarm Mask", "zbee_zcl_general.power_config.attr.mains_alarm_mask", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_mains_alarm_mask_low,
{ "Mains Voltage too low", "zbee_zcl_general.power_config.attr.mains_alarm_mask.mains_too_low", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_POWER_CONF_MAINS_ALARM_LOW, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_mains_alarm_mask_high,
{ "Mains Voltage too high", "zbee_zcl_general.power_config.attr.mains_alarm_mask.mains_too_high", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_POWER_CONF_MAINS_ALARM_HIGH, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_mains_alarm_mask_reserved,
{ "Reserved", "zbee_zcl_general.power_config.attr.mains_alarm_mask.reserved", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_POWER_CONF_MAINS_ALARM_RESERVED, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_batt_alarm_mask,
{ "Battery Alarm Mask", "zbee_zcl_general.power_config.attr.batt_alarm_mask", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_batt_alarm_mask_low,
{ "Battery Voltage too low", "zbee_zcl_general.power_config.batt_attr.alarm_mask.batt_too_low", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_POWER_CONF_BATTERY_ALARM_LOW, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_batt_alarm_mask_reserved,
{ "Reserved", "zbee_zcl_general.power_config.attr.batt_alarm_mask.reserved", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_POWER_CONF_BATTERY_ALARM_RESERVED, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_mains_voltage,
{ "Measured Mains Voltage", "zbee_zcl_general.power_config.attr.mains_voltage", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_power_conf_voltage),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_mains_frequency,
{ "Measured Mains Frequency", "zbee_zcl_general.power_config.attr.mains_frequency", FT_UINT8, BASE_CUSTOM, CF_FUNC(decode_power_conf_frequency),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_mains_voltage_min_thr,
{ "Mains Voltage Minimum Threshold", "zbee_zcl_general.power_config.attr.mains_volt_min", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_power_conf_voltage),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_mains_voltage_max_thr,
{ "Mains Voltage Maximum Threshold", "zbee_zcl_general.power_config.attr.mains_volt_max", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_power_conf_voltage),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_batt_voltage,
{ "Measured Battery Voltage", "zbee_zcl_general.power_config.attr.batt_voltage", FT_UINT8, BASE_CUSTOM, CF_FUNC(decode_power_conf_voltage),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_batt_ah_rating,
{ "Battery Capacity", "zbee_zcl_general.power_config.attr.batt_AHr", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_power_conf_batt_AHr),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_batt_rated_voltage,
{ "Battery Rated Voltage", "zbee_zcl_general.power_config.attr.batt_rated_voltage", FT_UINT8, BASE_CUSTOM, CF_FUNC(decode_power_conf_voltage),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_batt_voltage_min_thr,
{ "Battery Voltage Minimum Threshold", "zbee_zcl_general.power_config.attr.batt_voltage_min_thr", FT_UINT8, BASE_CUSTOM, CF_FUNC(decode_power_conf_voltage),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_power_config_mains_voltage_dwell_tp,
{ "Mains Voltage Dwell Trip Point", "zbee_zcl_general.power_config.attr.mains_dwell_tp", FT_UINT16, BASE_DEC, NULL,
0x00, NULL, HFILL } },
};
static gint *ett[] = {
&ett_zbee_zcl_power_config,
&ett_zbee_zcl_power_config_mains_alarm_mask,
&ett_zbee_zcl_power_config_batt_alarm_mask
};
proto_zbee_zcl_power_config = proto_register_protocol("ZigBee ZCL Power Configuration", "ZCL Power Configuration", ZBEE_PROTOABBREV_ZCL_POWER_CONFIG);
proto_register_field_array(proto_zbee_zcl_power_config, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_POWER_CONFIG, dissect_zbee_zcl_power_config, proto_zbee_zcl_power_config);
}
void
proto_reg_handoff_zbee_zcl_power_config(void)
{
dissector_handle_t handle;
handle = find_dissector(ZBEE_PROTOABBREV_ZCL_POWER_CONFIG);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_POWER_CONFIG, handle);
zbee_zcl_init_cluster( proto_zbee_zcl_power_config,
ett_zbee_zcl_power_config,
ZBEE_ZCL_CID_POWER_CONFIG,
hf_zbee_zcl_power_config_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_power_config_attr_data
);
}
static int
dissect_zbee_zcl_device_temperature_configuration(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);;
}
void
dissect_zcl_device_temperature_configuration_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int * device_temp_alarm_mask[] = {
&hf_zbee_zcl_device_temperature_configuration_device_temp_alarm_mask_too_low,
&hf_zbee_zcl_device_temperature_configuration_device_temp_alarm_mask_too_high,
&hf_zbee_zcl_device_temperature_configuration_device_temp_alarm_mask_reserved,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_DEVICE_TEMPERATURE_CONFIGURATION_DEVICE_TEMP_ALARM_MASK:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_device_temperature_configuration_device_temp_alarm_mask, ett_zbee_zcl_device_temperature_configuration_device_temp_alarm_mask, device_temp_alarm_mask, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_DEVICE_TEMPERATURE_CONFIGURATION_CURRENT_TEMP:
case ZBEE_ZCL_ATTR_ID_DEVICE_TEMPERATURE_CONFIGURATION_MIN_TEMP_EXP:
case ZBEE_ZCL_ATTR_ID_DEVICE_TEMPERATURE_CONFIGURATION_MAX_TEMP_EXP:
case ZBEE_ZCL_ATTR_ID_DEVICE_TEMPERATURE_CONFIGURATION_OVER_TEMP_TOTAL_DWELL:
case ZBEE_ZCL_ATTR_ID_DEVICE_TEMPERATURE_CONFIGURATION_LOW_TEMP_THRESHOLD:
case ZBEE_ZCL_ATTR_ID_DEVICE_TEMPERATURE_CONFIGURATION_HIGH_TEMP_THRESHOLD:
case ZBEE_ZCL_ATTR_ID_DEVICE_TEMPERATURE_CONFIGURATION_LOW_TEMP_DWELL_TRIP_POINT:
case ZBEE_ZCL_ATTR_ID_DEVICE_TEMPERATURE_CONFIGURATION_HIGH_TEMP_DWELL_TRIP_POINT:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_device_temperature_configuration(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_device_temperature_configuration_attr_id,
{ "Attribute", "zbee_zcl_general.device_temperature_configuration.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_device_temperature_configuration_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_device_temperature_configuration_device_temp_alarm_mask,
{ "Device Temperature Alarm Mask", "zbee_zcl_general.device_temperature_configuration.attr.device_temp_alarm_mask", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_device_temperature_configuration_device_temp_alarm_mask_too_low,
{ "Device Temperature too low", "zbee_zcl_general.device_temperature_configuration.attr.device_temp_alarm_mask.too_low", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_DEVICE_TEMPERATURE_CONFIGURATION_DEVICE_TEMP_ALARM_MASK_TOO_LOW, NULL, HFILL } },
{ &hf_zbee_zcl_device_temperature_configuration_device_temp_alarm_mask_too_high,
{ "Device Temperature too high", "zbee_zcl_general.device_temperature_configuration.attr.device_temp_alarm_mask.too_high", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_DEVICE_TEMPERATURE_CONFIGURATION_DEVICE_TEMP_ALARM_MASK_TOO_HIGH, NULL, HFILL } },
{ &hf_zbee_zcl_device_temperature_configuration_device_temp_alarm_mask_reserved,
{ "Reserved", "zbee_zcl_general.device_temperature_configuration.attr.device_temp_alarm_mask.reserved", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_DEVICE_TEMPERATURE_CONFIGURATION_DEVICE_TEMP_ALARM_MASK_RESERVED, NULL, HFILL } }
};
static gint *ett[]={
&ett_zbee_zcl_device_temperature_configuration,
&ett_zbee_zcl_device_temperature_configuration_device_temp_alarm_mask
};
proto_zbee_zcl_device_temperature_configuration = proto_register_protocol("ZigBee ZCL Device Temperature Configuration", "ZCL Device Temperature Configuration", ZBEE_PROTOABBREV_ZCL_DEVICE_TEMP_CONFIG);
proto_register_field_array(proto_zbee_zcl_device_temperature_configuration, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_DEVICE_TEMP_CONFIG, dissect_zbee_zcl_device_temperature_configuration, proto_zbee_zcl_device_temperature_configuration);
}
void
proto_reg_handoff_zbee_zcl_device_temperature_configuration(void)
{
dissector_handle_t device_temperature_config_handle;
device_temperature_config_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_DEVICE_TEMP_CONFIG);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_DEVICE_TEMP_CONFIG, device_temperature_config_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_device_temperature_configuration,
ett_zbee_zcl_device_temperature_configuration,
ZBEE_ZCL_CID_DEVICE_TEMP_CONFIG,
hf_zbee_zcl_device_temperature_configuration_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_device_temperature_configuration_attr_data
);
}
static int
dissect_zbee_zcl_identify(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_identify_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_identify_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_identify, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_IDENTIFY_IDENTITY:
dissect_zcl_identify_identify(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_IDENTIFY_IDENTITY_QUERY:
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_identify_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_identify_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_identify, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_IDENTIFY_IDENTITY_QUERY_RSP:
dissect_zcl_identify_identifyqueryrsp(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_identify_identify(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_identify_identify_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_identify_identifyqueryrsp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_identify_identify_timeout, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
void
dissect_zcl_identify_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_IDENTIFY_IDENTIFY_TIME:
proto_tree_add_item(tree, hf_zbee_zcl_identify_identify_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_identify(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_identify_attr_id,
{ "Attribute", "zbee_zcl_general.identify.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_identify_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_identify_identify_time,
{ "Identify Time", "zbee_zcl_general.identify.attr.identify_time", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_zcl_time_in_seconds),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_identify_identify_timeout,
{ "Identify Timeout", "zbee_zcl_general.identify.identify_timeout", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_zcl_time_in_seconds),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_identify_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.identify.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_identify_srv_rx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_identify_srv_tx_cmd_id,
{ "Command", "zbee_zcl_general.identify.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_identify_srv_tx_cmd_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_IDENTIFY_NUM_ETT];
ett[0] = &ett_zbee_zcl_identify;
proto_zbee_zcl_identify = proto_register_protocol("ZigBee ZCL Identify", "ZCL Identify", ZBEE_PROTOABBREV_ZCL_IDENTIFY);
proto_register_field_array(proto_zbee_zcl_identify, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_IDENTIFY, dissect_zbee_zcl_identify, proto_zbee_zcl_identify);
}
void
proto_reg_handoff_zbee_zcl_identify(void)
{
dissector_handle_t identify_handle;
identify_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_IDENTIFY);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_IDENTIFY, identify_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_identify,
ett_zbee_zcl_identify,
ZBEE_ZCL_CID_IDENTIFY,
hf_zbee_zcl_identify_attr_id,
hf_zbee_zcl_identify_srv_rx_cmd_id,
hf_zbee_zcl_identify_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_identify_attr_data
);
}
static int
dissect_zbee_zcl_groups(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_groups_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_groups_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_groups, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_GROUPS_ADD_GROUP:
dissect_zcl_groups_add_group_or_if_identifying(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_GROUPS_VIEW_GROUP:
dissect_zcl_groups_view_group(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_GROUPS_ADD_GET_GROUP_MEMBERSHIP:
dissect_zcl_groups_get_group_membership(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_GROUPS_REMOVE_GROUP:
dissect_zcl_groups_remove_group(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_GROUPS_REMOVE_ALL_GROUPS:
break;
case ZBEE_ZCL_CMD_ID_GROUPS_ADD_GROUP_IF_IDENTIFYING:
dissect_zcl_groups_add_group_or_if_identifying(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_groups_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_groups_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_groups, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_GROUPS_ADD_GROUP_RESPONSE:
dissect_zcl_groups_add_remove_group_response(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_GROUPS_VIEW_GROUP_RESPONSE:
dissect_zcl_groups_view_group_response(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_GROUPS_GET_GROUP_MEMBERSHIP_RESPONSE:
dissect_zcl_groups_get_group_membership_response(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_GROUPS_REMOVE_GROUP_RESPONSE:
dissect_zcl_groups_add_remove_group_response(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_groups_add_group_or_if_identifying(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint attr_uint;
guint8 *attr_string;
proto_tree_add_item(tree, hf_zbee_zcl_groups_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
attr_uint = tvb_get_guint8(tvb, *offset);
if (attr_uint == 0xff) attr_uint = 0;
proto_tree_add_uint(tree, hf_zbee_zcl_groups_attr_str_len, tvb, *offset, 1, attr_uint);
*offset += 1;
attr_string = tvb_get_string_enc(wmem_packet_scope(), tvb, *offset, attr_uint, ENC_ASCII);
proto_item_append_text(tree, ", String: %s", attr_string);
proto_tree_add_string(tree, hf_zbee_zcl_groups_attr_str, tvb, *offset, attr_uint, attr_string);
*offset += attr_uint;
}
static void
dissect_zcl_groups_view_group(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_groups_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_groups_get_group_membership(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_item *grp_list;
proto_tree *grp_list_tree;
guint8 count, i;
count = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_groups_group_count, tvb, *offset, 1, count);
*offset += 1;
if(count > 0)
{
grp_list = proto_tree_add_item(tree, hf_zbee_zcl_groups_group_list, tvb, *offset, 2*count, ENC_NA);
grp_list_tree = proto_item_add_subtree(grp_list, ett_zbee_zcl_groups_grp_ctrl);
for( i = 0; i < count; i++)
{
proto_tree_add_item(grp_list_tree, hf_zbee_zcl_groups_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
}
}
static void
dissect_zcl_groups_remove_group(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_groups_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_groups_add_remove_group_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_groups_status, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_groups_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_groups_view_group_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint attr_uint;
guint8 *attr_string;
proto_tree_add_item(tree, hf_zbee_zcl_groups_status, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_groups_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
attr_uint = tvb_get_guint8(tvb, *offset);
if (attr_uint == 0xff) attr_uint = 0;
proto_tree_add_uint(tree, hf_zbee_zcl_groups_attr_str_len, tvb, *offset, 1, attr_uint);
*offset += 1;
attr_string = tvb_get_string_enc(wmem_packet_scope(), tvb, *offset, attr_uint, ENC_ASCII);
proto_item_append_text(tree, ", String: %s", attr_string);
proto_tree_add_string(tree, hf_zbee_zcl_groups_attr_str, tvb, *offset, attr_uint, attr_string);
*offset += attr_uint;
}
static void
dissect_zcl_groups_get_group_membership_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_item *grp_list;
proto_tree *grp_list_tree;
guint8 count, i;
proto_tree_add_item(tree, hf_zbee_zcl_groups_group_capacity, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
count = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_groups_group_count, tvb, *offset, 1, count);
*offset += 1;
if(count > 0)
{
grp_list = proto_tree_add_item(tree, hf_zbee_zcl_groups_group_list, tvb, *offset, 2*count, ENC_NA);
grp_list_tree = proto_item_add_subtree(grp_list, ett_zbee_zcl_groups_grp_ctrl);
for( i = 0; i < count; i++)
{
proto_tree_add_item(grp_list_tree, hf_zbee_zcl_groups_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
}
}
void
dissect_zcl_groups_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_GROUPS_NAME_SUPPORT:
proto_tree_add_item(tree, hf_zbee_zcl_groups_group_name_support, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_groups(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_groups_attr_id,
{ "Attribute", "zbee_zcl_general.groups.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_groups_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_groups_group_name_support,
{ "Group Name Support", "zbee_zcl_general.groups.attr.group_name_support", FT_BOOLEAN, 8, TFS(&tfs_true_false),
ZBEE_ZCL_CMD_ID_GROUPS_NAME_SUPPORT_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_groups_group_id,
{ "Group ID", "zbee_zcl_general.groups.group_id", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_groups_group_list,
{"Group List", "zbee_zcl_general.groups.group_list",FT_NONE,BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_groups_group_count,
{ "Group Count", "zbee_zcl_general.groups.group_count", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_groups_group_capacity,
{ "Group Capacity", "zbee_zcl_general.groups.group_capacity", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_groups_status,
{ "Group Status", "zbee_zcl_general.groups.group_status", FT_UINT8, BASE_HEX, VALS(zbee_zcl_status_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_groups_attr_str_len,
{ "Length", "zbee_zcl_general.groups.attr_str_len", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_groups_attr_str,
{ "String", "zbee_zcl_general.groups_attr_str", FT_STRING, BASE_NONE, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_groups_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.groups.cmd_srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_groups_srv_rx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_groups_srv_tx_cmd_id,
{ "Command", "zbee_zcl_general.groups.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_groups_srv_tx_cmd_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_GROUPS_NUM_ETT];
ett[0] = &ett_zbee_zcl_groups;
ett[1] = &ett_zbee_zcl_groups_grp_ctrl;
proto_zbee_zcl_groups = proto_register_protocol("ZigBee ZCL Groups", "ZCL Groups", ZBEE_PROTOABBREV_ZCL_GROUPS);
proto_register_field_array(proto_zbee_zcl_groups, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_GROUPS, dissect_zbee_zcl_groups, proto_zbee_zcl_groups);
}
void
proto_reg_handoff_zbee_zcl_groups(void)
{
dissector_handle_t groups_handle;
groups_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_GROUPS);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_GROUPS, groups_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_groups,
ett_zbee_zcl_groups,
ZBEE_ZCL_CID_GROUPS,
hf_zbee_zcl_groups_attr_id,
hf_zbee_zcl_groups_srv_rx_cmd_id,
hf_zbee_zcl_groups_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_groups_attr_data
);
}
static int
dissect_zbee_zcl_scenes(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_scenes_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_scenes_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_scenes, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_SCENES_ADD_SCENE:
dissect_zcl_scenes_add_scene(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_SCENES_VIEW_SCENE:
case ZBEE_ZCL_CMD_ID_SCENES_REMOVE_SCENE:
case ZBEE_ZCL_CMD_ID_SCENES_STORE_SCENE:
case ZBEE_ZCL_CMD_ID_SCENES_RECALL_SCENE:
dissect_zcl_scenes_view_remove_store_recall_scene(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_SCENES_REMOVE_ALL_SCENES:
case ZBEE_ZCL_CMD_ID_SCENES_GET_SCENE_MEMBERSHIP:
dissect_zcl_scenes_remove_all_get_scene_membership(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_scenes_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_scenes_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_scenes, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_SCENES_ADD_SCENE_RESPONSE:
case ZBEE_ZCL_CMD_ID_SCENES_REMOVE_SCENE_RESPONSE:
case ZBEE_ZCL_CMD_ID_SCENES_STORE_SCENE_RESPONSE:
dissect_zcl_scenes_add_remove_store_scene_response(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_SCENES_VIEW_SCENE_RESPONSE:
dissect_zcl_scenes_view_scene_response(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_SCENES_REMOVE_ALL_SCENES_RESPONSE:
dissect_zcl_scenes_remove_all_scenes_response(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_SCENES_GET_SCENE_MEMBERSHIP_RESPONSE:
dissect_zcl_scenes_get_scene_membership_response(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_scenes_add_scene(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint attr_uint;
guint8 *attr_string;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_scene_id, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_transit_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
attr_uint = tvb_get_guint8(tvb, *offset);
if (attr_uint == 0xff) attr_uint = 0;
proto_tree_add_uint(tree, hf_zbee_zcl_scenes_attr_str_len, tvb, *offset, 1, attr_uint);
*offset += 1;
attr_string = tvb_get_string_enc(wmem_packet_scope(), tvb, *offset, attr_uint, ENC_ASCII);
proto_item_append_text(tree, ", String: %s", attr_string);
proto_tree_add_string(tree, hf_zbee_zcl_scenes_attr_str, tvb, *offset, attr_uint, attr_string);
*offset += attr_uint;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_extension_set_field, tvb, *offset, -1, ENC_NA);
}
static void
dissect_zcl_scenes_view_remove_store_recall_scene(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_scenes_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_scene_id, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void
dissect_zcl_scenes_remove_all_get_scene_membership(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_scenes_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_scenes_add_remove_store_scene_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_scenes_status, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_scene_id, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void
dissect_zcl_scenes_view_scene_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 status, *attr_string;
guint attr_uint;
status = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_scenes_status, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_scene_id, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
if(status == ZBEE_ZCL_STAT_SUCCESS)
{
proto_tree_add_item(tree, hf_zbee_zcl_scenes_transit_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
attr_uint = tvb_get_guint8(tvb, *offset);
if (attr_uint == 0xff) attr_uint = 0;
proto_tree_add_uint(tree, hf_zbee_zcl_scenes_attr_str_len, tvb, *offset, 1, attr_uint);
*offset += 1;
attr_string = tvb_get_string_enc(wmem_packet_scope(), tvb, *offset, attr_uint, ENC_ASCII);
proto_item_append_text(tree, ", String: %s", attr_string);
proto_tree_add_string(tree, hf_zbee_zcl_scenes_attr_str, tvb, *offset, attr_uint, attr_string);
*offset += attr_uint;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_extension_set_field, tvb, *offset, -1, ENC_NA);
}
}
static void
dissect_zcl_scenes_remove_all_scenes_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_scenes_status, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_scenes_get_scene_membership_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_item *scene_list;
proto_tree *scene_list_tree;
guint8 status, count, i;
status = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_scenes_status, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_capacity, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_scenes_group_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
if(status == ZBEE_ZCL_STAT_SUCCESS)
{
count = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_scenes_scene_count, tvb, *offset, 1, count);
*offset += 1;
if(count>0)
{
scene_list=proto_tree_add_item(tree, hf_zbee_zcl_scenes_scene_list, tvb, *offset, count, ENC_NA);
scene_list_tree = proto_item_add_subtree(scene_list, ett_zbee_zcl_scenes_scene_ctrl);
for( i = 0; i < count; i++)
{
proto_tree_add_item(scene_list_tree, hf_zbee_zcl_scenes_scene_id, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
}
}
}
void
dissect_zcl_scenes_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_SCENES_SCENE_VALID:
proto_tree_add_item(tree, hf_zbee_zcl_scenes_attr_id_scene_valid, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_SCENES_NAME_SUPPORT:
proto_tree_add_item(tree, hf_zbee_zcl_scenes_attr_id_name_support, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_SCENES_SCENE_COUNT:
case ZBEE_ZCL_ATTR_ID_SCENES_CURRENT_SCENE:
case ZBEE_ZCL_ATTR_ID_SCENES_CURRENT_GROUP:
case ZBEE_ZCL_ATTR_ID_SCENES_LAST_CONFIGURED_BY:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_scenes(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_scenes_attr_id,
{ "Attribute", "zbee_zcl_general.scenes.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_scenes_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_scenes_scene_list,
{"Scene List", "zbee_zcl_general.groups.scene_list",FT_NONE,BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_scenes_group_id,
{ "Group ID", "zbee_zcl_general.scenes.group_id", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_scenes_scene_id,
{ "Scene ID", "zbee_zcl_general.scenes.scene_id", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_scenes_transit_time,
{ "Transition Time", "zbee_zcl_general.scenes.transit_time", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_scenes_status,
{ "Scenes Status", "zbee_zcl_general.scenes.scenes_status", FT_UINT8, BASE_HEX, VALS(zbee_zcl_status_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_scenes_capacity,
{ "Scene Capacity", "zbee_zcl_general.scenes.scene_capacity", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_scenes_scene_count,
{ "Scene Count", "zbee_zcl_general.scenes.scene_count", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_scenes_attr_id_name_support,
{ "Scene Name Support", "zbee_zcl_general.scenes.attr.name_support", FT_UINT8, BASE_HEX, VALS(zbee_zcl_scenes_group_names_support_values),
ZBEE_ZCL_CMD_ID_SCENES_NAME_SUPPORT_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_scenes_attr_id_scene_valid,
{ "Scene Validity", "zbee_zcl_general.scenes.scene_valid", FT_BOOLEAN, 8, TFS(&tfs_true_false),
ZBEE_ZCL_CMD_ID_SCENES_SUPPORTED_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_scenes_attr_str_len,
{ "Length", "zbee_zcl_general.scenes.attr_str_len", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_scenes_attr_str,
{ "String", "zbee_zcl_general.scenes.attr_str", FT_STRING, BASE_NONE, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_scenes_extension_set_field,
{ "Extension Set", "zbee_zcl_general.scenes.extension_set", FT_BYTES, BASE_NONE, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_scenes_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.scenes.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_scenes_srv_rx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_scenes_srv_tx_cmd_id,
{ "Command", "zbee_zcl_general.scenes.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_scenes_srv_tx_cmd_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_SCENES_NUM_ETT];
ett[0] = &ett_zbee_zcl_scenes;
ett[1] = &ett_zbee_zcl_scenes_scene_ctrl;
proto_zbee_zcl_scenes = proto_register_protocol("ZigBee ZCL Scenes", "ZCL Scenes", ZBEE_PROTOABBREV_ZCL_SCENES);
proto_register_field_array(proto_zbee_zcl_scenes, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_SCENES, dissect_zbee_zcl_scenes, proto_zbee_zcl_scenes);
}
void
proto_reg_handoff_zbee_zcl_scenes(void)
{
dissector_handle_t scenes_handle;
scenes_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_SCENES);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_SCENES, scenes_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_scenes,
ett_zbee_zcl_scenes,
ZBEE_ZCL_CID_SCENES,
hf_zbee_zcl_scenes_attr_id,
hf_zbee_zcl_scenes_srv_rx_cmd_id,
hf_zbee_zcl_scenes_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_scenes_attr_data
);
}
static int
dissect_zbee_zcl_on_off(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_on_off_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_on_off_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
}
return tvb_captured_length(tvb);
}
void
dissect_zcl_on_off_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
case ZBEE_ZCL_ON_OFF_ATTR_ID_ONOFF:
proto_tree_add_item(tree, hf_zbee_zcl_on_off_attr_onoff, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_on_off(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_on_off_attr_id,
{ "Attribute", "zbee_zcl_general.onoff.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_on_off_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_on_off_attr_onoff,
{ "Data Value", "zbee_zcl_general.onoff.attr.onoff", FT_UINT8, BASE_HEX, VALS(zbee_zcl_on_off_onoff_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_on_off_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.onoff.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_on_off_srv_rx_cmd_names),
0x00, NULL, HFILL } }
};
proto_zbee_zcl_on_off = proto_register_protocol("ZigBee ZCL OnOff", "ZCL OnOff", ZBEE_PROTOABBREV_ZCL_ONOFF);
proto_register_field_array(proto_zbee_zcl_on_off, hf, array_length(hf));
register_dissector(ZBEE_PROTOABBREV_ZCL_ONOFF, dissect_zbee_zcl_on_off, proto_zbee_zcl_on_off);
}
void
proto_reg_handoff_zbee_zcl_on_off(void)
{
dissector_handle_t on_off_handle;
on_off_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_ONOFF);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_ON_OFF, on_off_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_on_off,
ett_zbee_zcl_on_off,
ZBEE_ZCL_CID_ON_OFF,
hf_zbee_zcl_on_off_attr_id,
hf_zbee_zcl_on_off_srv_rx_cmd_id,
-1,
(zbee_zcl_fn_attr_data)dissect_zcl_on_off_attr_data
);
}
static int
dissect_zbee_zcl_on_off_switch_configuration(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_on_off_switch_configuration_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
case ZBEE_ZCL_ON_OFF_SWITCH_CONFIGURATION_ATTR_ID_SWITCH_TYPE:
proto_tree_add_item(tree, hf_zbee_zcl_on_off_switch_configuration_attr_switch_type, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ON_OFF_SWITCH_CONFIGURATION_ATTR_ID_SWITCH_ACTIONS:
proto_tree_add_item(tree, hf_zbee_zcl_on_off_switch_configuration_attr_switch_actions, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_on_off_switch_configuration(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_on_off_switch_configuration_attr_id,
{ "Attribute", "zbee_zcl_general.onoff_switch_configuration.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_on_off_switch_configuration_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_on_off_switch_configuration_attr_switch_type,
{ "Switch Type", "zbee_zcl_general.onoff.attr.switch_type", FT_UINT8, BASE_HEX, VALS(zbee_zcl_on_off_switch_configuration_switch_type_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_on_off_switch_configuration_attr_switch_actions,
{ "Switch Action", "zbee_zcl_general.onoff.attr.switch_actions", FT_UINT8, BASE_HEX, VALS(zbee_zcl_on_off_switch_configuration_switch_actions_names),
0x00, NULL, HFILL } }
};
static gint *ett[]={
&ett_zbee_zcl_on_off_switch_configuration
};
proto_zbee_zcl_on_off_switch_configuration = proto_register_protocol("ZigBee ZCL OnOff Switch Configuration", "ZCL OnOff Switch Configuration", ZBEE_PROTOABBREV_ZCL_ONOFF_SWITCH_CONFIG);
proto_register_field_array(proto_zbee_zcl_on_off_switch_configuration, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_ONOFF_SWITCH_CONFIG, dissect_zbee_zcl_on_off_switch_configuration, proto_zbee_zcl_on_off_switch_configuration);
}
void
proto_reg_handoff_zbee_zcl_on_off_switch_configuration(void)
{
dissector_handle_t on_off_switch_configuration_handle;
on_off_switch_configuration_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_ONOFF_SWITCH_CONFIG);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_ON_OFF_SWITCH_CONFIG, on_off_switch_configuration_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_on_off_switch_configuration,
ett_zbee_zcl_on_off_switch_configuration,
ZBEE_ZCL_CID_ON_OFF_SWITCH_CONFIG,
hf_zbee_zcl_on_off_switch_configuration_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_on_off_switch_configuration_attr_data
);
}
static void
dissect_zcl_alarms_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_ALARMS_ALARM_COUNT:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static void
dissect_zcl_alarms_alarm_and_reset_alarm(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_alarms_alarm_code, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_alarms_cluster_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_alarms_get_alarm_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 status;
status = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_alarms_status, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
if(status == ZBEE_ZCL_STAT_SUCCESS)
{
proto_tree_add_item(tree, hf_zbee_zcl_alarms_alarm_code, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_alarms_cluster_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_alarms_timestamp, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
}
static int
dissect_zbee_zcl_alarms(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_alarms_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_alarms_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_alarms, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_ALARMS_RESET_ALARM:
dissect_zcl_alarms_alarm_and_reset_alarm(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_ALARMS_RESET_ALL_ALARMS:
case ZBEE_ZCL_CMD_ID_ALARMS_GET_ALARM:
case ZBEE_ZCL_CMD_ID_ALARMS_RESET_ALARM_LOG:
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_alarms_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_alarms_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_alarms, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_ALARMS_ALARM:
dissect_zcl_alarms_alarm_and_reset_alarm(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_ALARMS_GET_ALARM_RESPONSE:
dissect_zcl_alarms_get_alarm_response(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
void
proto_register_zbee_zcl_alarms(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_alarms_attr_id,
{ "Attribute", "zbee_zcl_general.alarms.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_alarms_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_alarms_alarm_code,
{ "Alarm Code", "zbee_zcl_general.alarms.alarm_code", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_alarms_cluster_id,
{ "Cluster ID", "zbee_zcl_general.alarms.cluster_id", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_alarms_status,
{ "Status", "zbee_zcl_general.alarms.status", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_alarms_timestamp,
{ "Timestamp", "zbee_zcl_general.alarms.timestamp", FT_UINT32, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_alarms_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.alarms.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_alarms_srv_rx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_alarms_srv_tx_cmd_id,
{ "Command", "zbee_zcl_general.alarms.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_alarms_srv_tx_cmd_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_ALARMS_NUM_ETT];
ett[0] = &ett_zbee_zcl_alarms;
proto_zbee_zcl_alarms = proto_register_protocol("ZigBee ZCL Alarms", "ZCL Alarms", ZBEE_PROTOABBREV_ZCL_ALARMS);
proto_register_field_array(proto_zbee_zcl_alarms, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_ALARMS, dissect_zbee_zcl_alarms, proto_zbee_zcl_alarms);
}
void
proto_reg_handoff_zbee_zcl_alarms(void)
{
dissector_handle_t alarms_handle;
alarms_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_ALARMS);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_ALARMS, alarms_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_alarms,
ett_zbee_zcl_alarms,
ZBEE_ZCL_CID_ALARMS,
hf_zbee_zcl_alarms_attr_id,
hf_zbee_zcl_alarms_srv_rx_cmd_id,
hf_zbee_zcl_alarms_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_alarms_attr_data
);
}
static void
dissect_zcl_time_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int * time_status_mask[] = {
&hf_zbee_zcl_time_status_master,
&hf_zbee_zcl_time_status_synchronized,
&hf_zbee_zcl_time_status_master_zone_dst,
&hf_zbee_zcl_time_status_superseding,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_TIME_TIME_STATUS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_time_status, ett_zbee_zcl_time_status_mask, time_status_mask, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_TIME_TIME:
case ZBEE_ZCL_ATTR_ID_TIME_TIME_ZONE:
case ZBEE_ZCL_ATTR_ID_TIME_DST_START:
case ZBEE_ZCL_ATTR_ID_TIME_DST_END:
case ZBEE_ZCL_ATTR_ID_TIME_DST_SHIFT:
case ZBEE_ZCL_ATTR_ID_TIME_STD_TIME:
case ZBEE_ZCL_ATTR_ID_TIME_LOCAL_TIME:
case ZBEE_ZCL_ATTR_ID_TIME_LAST_SET_TIME:
case ZBEE_ZCL_ATTR_ID_TIME_VALID_UNTIL_TIME:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static int
dissect_zbee_zcl_time(tvbuff_t _U_ *tvb, packet_info _U_ * pinfo, proto_tree _U_* tree, void _U_* data)
{
return 0;
}
void
proto_register_zbee_zcl_time(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_time_attr_id,
{ "Attribute", "zbee_zcl_general.time.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_time_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_time_status,
{ "Time Status", "zbee_zcl_general.time.attr.time_status", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_time_status_master,
{ "Master", "zbee_zcl_general.time.attr.time_status.master", FT_BOOLEAN, 8, TFS(&tfs_true_false),
ZBEE_ZCL_TIME_MASTER, NULL, HFILL } },
{ &hf_zbee_zcl_time_status_synchronized,
{ "Synchronized", "zbee_zcl_general.time.attr.time_status.synchronized", FT_BOOLEAN, 8, TFS(&tfs_true_false),
ZBEE_ZCL_TIME_SYNCHRONIZED, NULL, HFILL } },
{ &hf_zbee_zcl_time_status_master_zone_dst,
{ "Master for Time Zone and DST", "zbee_zcl_general.time.attr.time_status.master_zone_dst", FT_BOOLEAN, 8, TFS(&tfs_true_false),
ZBEE_ZCL_TIME_MASTER_ZONE_DST, NULL, HFILL } },
{ &hf_zbee_zcl_time_status_superseding,
{ "Superseded", "zbee_zcl_general.time.attr.time_status.superseding", FT_BOOLEAN, 8, TFS(&tfs_true_false),
ZBEE_ZCL_TIME_SUPERSEDING, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_TIME_NUM_ETT];
ett[0] = &ett_zbee_zcl_time;
ett[1] = &ett_zbee_zcl_time_status_mask;
proto_zbee_zcl_time = proto_register_protocol("ZigBee ZCL Time", "ZCL Time", ZBEE_PROTOABBREV_ZCL_TIME);
proto_register_field_array(proto_zbee_zcl_time, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_TIME, dissect_zbee_zcl_time, proto_zbee_zcl_time);
}
void
proto_reg_handoff_zbee_zcl_time(void)
{
dissector_handle_t time_handle;
time_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_TIME);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_TIME, time_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_time,
ett_zbee_zcl_time,
ZBEE_ZCL_CID_TIME,
hf_zbee_zcl_time_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_time_attr_data
);
}
static void
dissect_zcl_level_control_move_to_level(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_level_control_level, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_level_control_transit_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_level_control_move(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_level_control_move_mode, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_level_control_rate, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void
dissect_zcl_level_control_step(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_level_control_step_mode, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_level_control_step_size, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_level_control_transit_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static int
dissect_zbee_zcl_level_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_level_control_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_level_control_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_level_control, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_LEVEL_CONTROL_MOVE_TO_LEVEL:
case ZBEE_ZCL_CMD_ID_LEVEL_CONTROL_MOVE_TO_LEVEL_WITH_ONOFF:
dissect_zcl_level_control_move_to_level(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_LEVEL_CONTROL_MOVE:
case ZBEE_ZCL_CMD_ID_LEVEL_CONTROL_MOVE_WITH_ONOFF:
dissect_zcl_level_control_move(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_LEVEL_CONTROL_STEP:
case ZBEE_ZCL_CMD_ID_LEVEL_CONTROL_STEP_WITH_ONOFF:
dissect_zcl_level_control_step(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_LEVEL_CONTROL_STOP:
case ZBEE_ZCL_CMD_ID_LEVEL_CONTROL_STOP_WITH_ONOFF:
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_level_control_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_LEVEL_CONTROL_CURRENT_LEVEL:
case ZBEE_ZCL_ATTR_ID_LEVEL_CONTROL_REMAINING_TIME:
case ZBEE_ZCL_ATTR_ID_LEVEL_CONTROL_ONOFF_TRANSIT_TIME:
case ZBEE_ZCL_ATTR_ID_LEVEL_CONTROL_ON_LEVEL:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_level_control(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_level_control_attr_id,
{ "Attribute", "zbee_zcl_general.level_control.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_level_control_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_level_control_level,
{ "Level", "zbee_zcl_general.level_control.level", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_level_control_move_mode,
{ "Move Mode", "zbee_zcl_general.level_control.move_mode", FT_UINT8, BASE_HEX, VALS(zbee_zcl_level_control_move_step_mode_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_level_control_rate,
{ "Rate", "zbee_zcl_general.level_control.rate", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_level_control_step_mode,
{ "Step Mode", "zbee_zcl_general.level_control.step_mode", FT_UINT8, BASE_HEX, VALS(zbee_zcl_level_control_move_step_mode_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_level_control_step_size,
{ "Step Size", "zbee_zcl_general.level_control.step_size", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_level_control_transit_time,
{ "Transition Time", "zbee_zcl_general.level_control.transit_time", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_level_control_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.level_control.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_level_control_srv_rx_cmd_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_LEVEL_CONTROL_NUM_ETT];
ett[0] = &ett_zbee_zcl_level_control;
proto_zbee_zcl_level_control = proto_register_protocol("ZigBee ZCL Level Control", "ZCL Level Control", ZBEE_PROTOABBREV_ZCL_LEVEL_CONTROL);
proto_register_field_array(proto_zbee_zcl_level_control, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_LEVEL_CONTROL, dissect_zbee_zcl_level_control, proto_zbee_zcl_level_control);
}
void
proto_reg_handoff_zbee_zcl_level_control(void)
{
dissector_handle_t level_control_handle;
level_control_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_LEVEL_CONTROL);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_LEVEL_CONTROL, level_control_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_level_control,
ett_zbee_zcl_level_control,
ZBEE_ZCL_CID_LEVEL_CONTROL,
hf_zbee_zcl_level_control_attr_id,
hf_zbee_zcl_level_control_srv_rx_cmd_id,
-1,
(zbee_zcl_fn_attr_data)dissect_zcl_level_control_attr_data
);
}
static int
dissect_zbee_zcl_rssi_location(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_rssi_location_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_rssi_location, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_SET_ABSOLUTE_LOCATION:
dissect_zcl_rssi_location_set_absolute_location(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_SET_DEVICE_CONFIG:
dissect_zcl_rssi_location_set_device_config(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_GET_DEVICE_CONFIG:
dissect_zcl_rssi_location_get_device_config(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_GET_LOCATION_DATA:
dissect_zcl_rssi_location_get_location_data(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_RSSI_RESPONSE:
dissect_zcl_rssi_location_rssi_response(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_SEND_PINGS:
dissect_zcl_rssi_location_send_pings(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_ANCHOR_NODE_ANNOUNCE:
dissect_zcl_rssi_location_anchor_node_announce(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_rssi_location_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_rssi_location, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_DEVICE_CONFIG_RESPONSE:
dissect_zcl_rssi_location_device_config_response(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_LOCATION_DATA_RESPONSE:
dissect_zcl_rssi_location_location_data_response(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_LOCATION_DATA_NOTIF:
dissect_zcl_rssi_location_location_data_notif(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_COMPACT_LOCATION_DATA_NOTIF:
dissect_zcl_rssi_location_compact_location_data_notif(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_RSSI_PING:
dissect_zcl_rssi_location_rssi_ping(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_RSSI_REQUEST:
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_REPORT_RSSI_MEAS:
dissect_zcl_rssi_location_report_rssi_meas(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_RSSI_LOCATION_REQUEST_OWN_LOCATION:
dissect_zcl_rssi_location_request_own_location(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_rssi_location_set_absolute_location(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate1, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate2, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate3, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_power, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_path_loss_expo, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_rssi_location_set_device_config(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_power, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_path_loss_expo, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_calc_period, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_number_rssi_meas, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_reporting_period, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_rssi_location_get_device_config(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_target_add, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
}
static void
dissect_zcl_rssi_location_get_location_data(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 header;
static const int * location_header_fields[] = {
&hf_zbee_zcl_rssi_location_header_abs_only,
&hf_zbee_zcl_rssi_location_header_recalc,
&hf_zbee_zcl_rssi_location_header_bcast_ind,
&hf_zbee_zcl_rssi_location_header_bcast_res,
&hf_zbee_zcl_rssi_location_header_compact_res,
&hf_zbee_zcl_rssi_location_header_res,
NULL
};
header = tvb_get_guint8(tvb, *offset);
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_rssi_location_header, ett_zbee_zcl_rssi_location_header, location_header_fields, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_number_responses, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
if(header & 0x04)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_target_add, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
}
}
static void
dissect_zcl_rssi_location_rssi_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_replaying_device, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate1, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate2, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate3, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_rssi, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_number_rssi_meas, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void
dissect_zcl_rssi_location_send_pings(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_target_add, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_number_rssi_meas, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_calc_period, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_rssi_location_anchor_node_announce(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_anchor_node_add, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate1, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate2, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate3, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_rssi_location_device_config_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 status;
status = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_status, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
if(status == ZBEE_ZCL_STAT_SUCCESS)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_power, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_path_loss_expo, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_calc_period, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_number_rssi_meas, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_reporting_period, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
}
static void
dissect_zcl_rssi_location_location_data_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 status;
status = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_status, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
if(status == ZBEE_ZCL_STAT_SUCCESS)
{
dissect_zcl_rssi_location_attr_data(tree, tvb, offset, ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE, ZBEE_ZCL_8_BIT_DATA);
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate1, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate2, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate3, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_power, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_path_loss_expo, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_attr_id_location_method, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_quality_measure, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_location_age, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
}
static void
dissect_zcl_rssi_location_location_data_notif(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 temp;
temp = tvb_get_guint8(tvb, *offset);
dissect_zcl_rssi_location_attr_data(tree, tvb, offset, ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE, ZBEE_ZCL_8_BIT_DATA);
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate1, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate2, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
if((temp & ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE_2D) != 0x02)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate3, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_power, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_path_loss_expo, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
if((temp & ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE_COORDINATE) != 0x0C)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_attr_id_location_method, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_quality_measure, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_location_age, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
}
static void
dissect_zcl_rssi_location_compact_location_data_notif(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 temp;
temp = tvb_get_guint8(tvb, *offset);
dissect_zcl_rssi_location_attr_data(tree, tvb, offset, ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE, ZBEE_ZCL_8_BIT_DATA);
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate1, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate2, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
if((temp & ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE_2D) != 0x02)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate3, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
if((temp & ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE_COORDINATE) != 0x0C)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_quality_measure, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_location_age, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
}
static void
dissect_zcl_rssi_location_rssi_ping(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
dissect_zcl_rssi_location_attr_data(tree, tvb, offset, ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE, ZBEE_ZCL_8_BIT_DATA);
}
static void
dissect_zcl_rssi_location_report_rssi_meas(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 count, i;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_reporting_add, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
count = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_no_of_neigh, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
for( i = 0; i < count; i++)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_neighbour_add, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate1, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate2, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_coordinate3, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_rssi, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_number_rssi_meas, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
}
static void
dissect_zcl_rssi_location_request_own_location(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_request_add, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
}
void
dissect_zcl_rssi_location_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int *location_type[] = {
&hf_zbee_zcl_rssi_location_location_type_absolute,
&hf_zbee_zcl_rssi_location_location_type_2D,
&hf_zbee_zcl_rssi_location_location_type_coordinate_system,
&hf_zbee_zcl_rssi_location_location_type_reserved,
NULL
};
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_rssi_location_location_type, ett_zbee_zcl_rssi_location_location_type, location_type, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_METHOD:
proto_tree_add_item(tree, hf_zbee_zcl_rssi_location_attr_id_location_method, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_AGE:
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_QUALITY_MEASURE:
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_NUMBER_OF_DEVICES:
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_COORDINATE_1:
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_COORDINATE_2:
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_COORDINATE_3:
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_POWER:
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_PATH_LOSS_EXPONENT:
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_REPORTING_PERIOD:
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_CALCULATION_PERIOD:
case ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_NUMBER_RSSI_MEAS:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_rssi_location(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_rssi_location_attr_id,
{ "Attribute", "zbee_zcl_general.rssi_location.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_rssi_location_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_location_type,
{ "Location Type", "zbee_zcl_general.rssi_location.attr_id.location_type", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_location_type_absolute,
{ "Location Type Absolute/Measured", "zbee_zcl_general.rssi_location.attr_id.location_type.abs", FT_UINT8, BASE_HEX, VALS(zbee_zcl_rssi_location_location_type_abs_values),
ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE_ABSOLUTE, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_location_type_2D,
{ "Location Type 2D/3D", "zbee_zcl_general.rssi_location.attr_id.location_type.2D", FT_UINT8, BASE_HEX, VALS(zbee_zcl_rssi_location_location_type_2D_values),
ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE_2D, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_location_type_coordinate_system,
{ "Location Type Coordinate System", "zbee_zcl_general.rssi_location.attr_id.location_type.coordinate", FT_UINT8, BASE_HEX, VALS(zbee_zcl_rssi_location_location_type_coordinate_values),
ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE_COORDINATE, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_location_type_reserved,
{ "Reserved", "zbee_zcl_general.rssi_location.attr_id.location_type.reserved", FT_BOOLEAN, 8, NULL,
ZBEE_ZCL_ATTR_ID_RSSI_LOCATION_LOCATION_TYPE_RESERVED, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_attr_id_location_method,
{ "Location Method", "zbee_zcl_general.rssi_location.attr_id.location_method", FT_UINT8, BASE_HEX, VALS(zbee_zcl_rssi_location_location_method_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_coordinate1,
{ "Coordinate 1", "zbee_zcl_general.rssi_location.coordinate1", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_coordinate2,
{ "Coordinate 2", "zbee_zcl_general.rssi_location.coordinate2", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_coordinate3,
{ "Coordinate 3", "zbee_zcl_general.rssi_location.coordinate3", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_power,
{ "Power", "zbee_zcl_general.rssi_location.power", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_path_loss_expo,
{ "Path Loss Exponent", "zbee_zcl_general.rssi_location.path_loss_exponent", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_calc_period,
{ "Calculation Period", "zbee_zcl_general.rssi_location.calc_period", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_number_rssi_meas,
{ "Number RSSI Measurements", "zbee_zcl_general.rssi_location.number_rssi_meas", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_reporting_period,
{ "Reporting Period", "zbee_zcl_general.rssi_location.reporting_period", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_target_add,
{ "Target Address", "zbee_zcl_general.rssi_location.target_add", FT_UINT64, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_header,
{ "Header Data", "zbee_zcl_general.rssi_location.location_header", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_header_abs_only,
{ "Absolute Only", "zbee_zcl_general.rssi_location.header.abs_only", FT_BOOLEAN, 8, NULL,
0x01, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_header_recalc,
{ "Recalculate", "zbee_zcl_general.rssi_location.header.recalc", FT_BOOLEAN, 8, NULL,
0x02, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_header_bcast_ind,
{ "Broadcast Indicator", "zbee_zcl_general.rssi_location.header.bcast_ind", FT_BOOLEAN, 8, NULL,
0x04, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_header_bcast_res,
{ "Broadcast Response", "zbee_zcl_general.rssi_location.header.bcast_response", FT_BOOLEAN, 8, NULL,
0x08, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_header_compact_res,
{ "Compact Response", "zbee_zcl_general.rssi_location.compact_res", FT_BOOLEAN, 8, NULL,
0x10, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_header_res,
{ "Reserved", "zbee_zcl_general.rssi_location.reserved", FT_BOOLEAN, 8, NULL,
0xD0, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_number_responses,
{ "Number Responses", "zbee_zcl_general.rssi_location.number_responses", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_replaying_device,
{ "Replying Device", "zbee_zcl_general.rssi_location.replying_device", FT_UINT64, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_rssi,
{ "RSSI", "zbee_zcl_general.rssi_location.rssi", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_anchor_node_add,
{ "Anchor Node Address", "zbee_zcl_general.rssi_location.anchor_node_add", FT_UINT64, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_status,
{ "Status", "zbee_zcl_general.rssi_location.status", FT_UINT8, BASE_HEX, VALS(zbee_zcl_status_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_quality_measure,
{ "Quality Measure", "zbee_zcl_general.rssi_location.quality_measure", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_location_age,
{ "Location Age", "zbee_zcl_general.rssi_location.location_age", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_reporting_add,
{ "Reporting Address", "zbee_zcl_general.rssi_location.reporting_add", FT_UINT64, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_no_of_neigh,
{ "Number of Neighbours", "zbee_zcl_general.rssi_location.no_of_neigh", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_neighbour_add,
{ "Neighbour Address", "zbee_zcl_general.rssi_location.neighbour_add", FT_UINT64, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_request_add,
{ "Requesting Address", "zbee_zcl_general.rssi_location.request_add", FT_UINT64, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.rssi_location.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_rssi_location_srv_rx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_rssi_location_srv_tx_cmd_id,
{ "Command", "zbee_zcl_general.rssi_location.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_rssi_location_srv_tx_cmd_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_RSSI_LOCATION_NUM_ETT];
ett[0] = &ett_zbee_zcl_rssi_location;
ett[1] = &ett_zbee_zcl_rssi_location_location_type;
ett[2] = &ett_zbee_zcl_rssi_location_header;
proto_zbee_zcl_rssi_location = proto_register_protocol("ZigBee ZCL RSSI Location", "ZCL RSSI Location", ZBEE_PROTOABBREV_ZCL_RSSI_LOCATION);
proto_register_field_array(proto_zbee_zcl_rssi_location, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_RSSI_LOCATION, dissect_zbee_zcl_rssi_location, proto_zbee_zcl_rssi_location);
}
void
proto_reg_handoff_zbee_zcl_rssi_location(void)
{
dissector_handle_t rssi_location_handle;
rssi_location_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_RSSI_LOCATION);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_RSSI_LOCATION, rssi_location_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_rssi_location,
ett_zbee_zcl_rssi_location,
ZBEE_ZCL_CID_RSSI_LOCATION,
hf_zbee_zcl_rssi_location_attr_id,
hf_zbee_zcl_rssi_location_srv_rx_cmd_id,
hf_zbee_zcl_rssi_location_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_rssi_location_attr_data
);
}
static int
dissect_zbee_zcl_analog_input_basic(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_analog_input_basic_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int * status_flags[] = {
&hf_zbee_zcl_analog_input_basic_status_in_alarm,
&hf_zbee_zcl_analog_input_basic_status_fault,
&hf_zbee_zcl_analog_input_basic_status_overridden,
&hf_zbee_zcl_analog_input_basic_status_out_of_service,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_ANALOG_INPUT_BASIC_RELIABILITY:
proto_tree_add_item(tree, hf_zbee_zcl_analog_input_basic_reliability, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_ANALOG_INPUT_BASIC_STATUS_FLAGS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_analog_input_basic_status_flags, ett_zbee_zcl_analog_input_basic_status_flags, status_flags, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_ANALOG_INPUT_BASIC_DESCRIPTION:
case ZBEE_ZCL_ATTR_ID_ANALOG_INPUT_BASIC_MAX_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_ANALOG_INPUT_BASIC_MIN_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_ANALOG_INPUT_BASIC_OUT_OF_SERVICE:
case ZBEE_ZCL_ATTR_ID_ANALOG_INPUT_BASIC_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_ANALOG_INPUT_BASIC_RESOLUTION:
case ZBEE_ZCL_ATTR_ID_ANALOG_INPUT_BASIC_ENGINEERING_UNITS:
case ZBEE_ZCL_ATTR_ID_ANALOG_INPUT_BASIC_APPLICATION_TYPE:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_analog_input_basic(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_analog_input_basic_attr_id,
{ "Attribute", "zbee_zcl_general.analog_input_basic.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_analog_input_basic_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_input_basic_reliability,
{ "Reliability", "zbee_zcl_general.analog_input_basic.attr.reliability", FT_UINT8, BASE_HEX, VALS(zbee_zcl_reliability_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_input_basic_status_flags,
{ "Status Flags", "zbee_zcl_general.analog_input_basic.attr.status", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_input_basic_status_in_alarm,
{ "In Alarm Status", "zbee_zcl_general.analog_input_basic.attr.status.in_alarm", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_IN_ALARM, NULL, HFILL } },
{ &hf_zbee_zcl_analog_input_basic_status_fault,
{ "Fault Status", "zbee_zcl_general.analog_input_basic.attr.status.fault", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_analog_input_basic_status_overridden,
{ "Overridden Status", "zbee_zcl_general.analog_input_basic.attr.status.overridden", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OVERRIDDEN, NULL, HFILL } },
{ &hf_zbee_zcl_analog_input_basic_status_out_of_service,
{ "Out of Service Status", "zbee_zcl_general.analog_input_basic.attr.status.out_of_service", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OUT_OF_SERVICE, NULL, HFILL } }
};
static gint *ett[]={
&ett_zbee_zcl_analog_input_basic,
&ett_zbee_zcl_analog_input_basic_status_flags
};
proto_zbee_zcl_analog_input_basic = proto_register_protocol("ZigBee ZCL Analog Input Basic", "ZCL Analog Input Basic", ZBEE_PROTOABBREV_ZCL_ANALOG_INPUT_BASIC);
proto_register_field_array(proto_zbee_zcl_analog_input_basic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_ANALOG_INPUT_BASIC, dissect_zbee_zcl_analog_input_basic, proto_zbee_zcl_analog_input_basic);
}
void
proto_reg_handoff_zbee_zcl_analog_input_basic(void)
{
dissector_handle_t analog_input_basic_handle;
analog_input_basic_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_ANALOG_INPUT_BASIC);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_ANALOG_INPUT_BASIC, analog_input_basic_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_analog_input_basic,
ett_zbee_zcl_analog_input_basic,
ZBEE_ZCL_CID_ANALOG_INPUT_BASIC,
hf_zbee_zcl_analog_input_basic_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_analog_input_basic_attr_data
);
}
static int
dissect_zbee_zcl_analog_output_basic(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_analog_output_basic_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
proto_item *ti = NULL, *tj = NULL;
proto_tree *sub_tree = NULL, *sub = NULL;
int i;
static const int * status_flags[] = {
&hf_zbee_zcl_analog_output_basic_status_in_alarm,
&hf_zbee_zcl_analog_output_basic_status_fault,
&hf_zbee_zcl_analog_output_basic_status_overridden,
&hf_zbee_zcl_analog_output_basic_status_out_of_service,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_ANALOG_OUTPUT_BASIC_PRIORITY_ARRAY:
ti = proto_tree_add_item(tree,hf_zbee_zcl_analog_output_basic_priority_array, tvb, *offset, 80, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_analog_output_basic_priority_array);
for(i = 1; i <= 16; i++)
{
tj = proto_tree_add_item(sub_tree, hf_zbee_zcl_analog_output_basic_structure, tvb, *offset, 5, ENC_NA);
proto_item_append_text(tj," %d",i);
sub = proto_item_add_subtree(tj, ett_zbee_zcl_analog_output_basic_priority_array_structure);
proto_tree_add_item(sub, hf_zbee_zcl_analog_output_basic_priority_array_bool, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(sub, hf_zbee_zcl_analog_output_basic_priority_array_sing_prec, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
break;
case ZBEE_ZCL_ATTR_ID_ANALOG_OUTPUT_BASIC_RELIABILITY:
proto_tree_add_item(tree, hf_zbee_zcl_analog_output_basic_reliability, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_ANALOG_OUTPUT_BASIC_STATUS_FLAGS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_analog_output_basic_status_flags, ett_zbee_zcl_analog_output_basic_status_flags, status_flags, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_ANALOG_OUTPUT_BASIC_DESCRIPTION:
case ZBEE_ZCL_ATTR_ID_ANALOG_OUTPUT_BASIC_MAX_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_ANALOG_OUTPUT_BASIC_MIN_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_ANALOG_OUTPUT_BASIC_OUT_OF_SERVICE:
case ZBEE_ZCL_ATTR_ID_ANALOG_OUTPUT_BASIC_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_ANALOG_OUTPUT_BASIC_RELINQUISH_DEFAULT:
case ZBEE_ZCL_ATTR_ID_ANALOG_OUTPUT_BASIC_RESOLUTION:
case ZBEE_ZCL_ATTR_ID_ANALOG_OUTPUT_BASIC_ENGINEERING_UNITS:
case ZBEE_ZCL_ATTR_ID_ANALOG_OUTPUT_BASIC_APPLICATION_TYPE:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_analog_output_basic(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_analog_output_basic_attr_id,
{ "Attribute", "zbee_zcl_general.analog_output_basic.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_analog_output_basic_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_output_basic_reliability,
{ "Reliability", "zbee_zcl_general.analog_output_basic.attr.reliability", FT_UINT8, BASE_HEX, VALS(zbee_zcl_reliability_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_output_basic_status_flags,
{ "Status Flags", "zbee_zcl_general.analog_output_basic.attr.status", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_output_basic_status_in_alarm,
{ "In Alarm Status", "zbee_zcl_general.analog_output_basic.attr.status.in_alarm", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_IN_ALARM, NULL, HFILL } },
{ &hf_zbee_zcl_analog_output_basic_status_fault,
{ "Fault Status", "zbee_zcl_general.analog_output_basic.attr.status.falut", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_analog_output_basic_status_overridden,
{ "Overridden Status", "zbee_zcl_general.analog_output_basic.attr.status.overridden", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OVERRIDDEN, NULL, HFILL } },
{ &hf_zbee_zcl_analog_output_basic_status_out_of_service,
{ "Out of Service Status", "zbee_zcl_general.analog_output_basic.attr.status.out_of_service", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OUT_OF_SERVICE, NULL, HFILL } },
{ &hf_zbee_zcl_analog_output_basic_priority_array_bool,
{ "Valid/Invalid", "zbee_zcl_general.analog_output_basic.attr.priority_array.bool", FT_BOOLEAN, 8, TFS(&tfs_invalid_valid),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_output_basic_priority_array_sing_prec,
{ "Priority Value", "zbee_zcl_general.analog_output_basic.attr.priority_array.sing_prec", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_output_basic_priority_array,
{ "Priority Array", "zbee_zcl_general.analog_output_basic.priority_array.", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_output_basic_structure,
{ "Structure", "zbee_zcl_general.analog_output_basic.structure.", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } }
};
static gint *ett[]={
&ett_zbee_zcl_analog_output_basic,
&ett_zbee_zcl_analog_output_basic_status_flags,
&ett_zbee_zcl_analog_output_basic_priority_array,
&ett_zbee_zcl_analog_output_basic_priority_array_structure
};
proto_zbee_zcl_analog_output_basic = proto_register_protocol("ZigBee ZCL Analog Output Basic", "ZCL Analog Output Basic", ZBEE_PROTOABBREV_ZCL_ANALOG_OUTPUT_BASIC);
proto_register_field_array(proto_zbee_zcl_analog_output_basic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_ANALOG_OUTPUT_BASIC, dissect_zbee_zcl_analog_output_basic, proto_zbee_zcl_analog_output_basic);
}
void
proto_reg_handoff_zbee_zcl_analog_output_basic(void)
{
dissector_handle_t analog_output_basic_handle;
analog_output_basic_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_ANALOG_OUTPUT_BASIC);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_ANALOG_OUTPUT_BASIC, analog_output_basic_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_analog_output_basic,
ett_zbee_zcl_analog_output_basic,
ZBEE_ZCL_CID_ANALOG_OUTPUT_BASIC,
hf_zbee_zcl_analog_output_basic_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_analog_output_basic_attr_data
);
}
static int
dissect_zbee_zcl_analog_value_basic(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_analog_value_basic_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
proto_item *ti = NULL, *tj = NULL;
proto_tree *sub_tree = NULL, *sub = NULL;
int i;
static const int * status_flags[] = {
&hf_zbee_zcl_analog_value_basic_status_in_alarm,
&hf_zbee_zcl_analog_value_basic_status_fault,
&hf_zbee_zcl_analog_value_basic_status_overridden,
&hf_zbee_zcl_analog_value_basic_status_out_of_service,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_ANALOG_VALUE_BASIC_PRIORITY_ARRAY:
ti = proto_tree_add_item(tree,hf_zbee_zcl_analog_value_basic_priority_array, tvb, *offset, 80, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_analog_value_basic_priority_array);
for( i = 1; i <= 16; i++)
{
tj = proto_tree_add_item(sub_tree, hf_zbee_zcl_analog_value_basic_structure, tvb, *offset, 5, ENC_NA);
proto_item_append_text(tj," %d",i);
sub = proto_item_add_subtree(tj, ett_zbee_zcl_analog_value_basic_priority_array_structure);
proto_tree_add_item(sub, hf_zbee_zcl_analog_value_basic_priority_array_bool, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(sub, hf_zbee_zcl_analog_value_basic_priority_array_sing_prec, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
break;
case ZBEE_ZCL_ATTR_ID_ANALOG_VALUE_BASIC_RELIABILITY:
proto_tree_add_item(tree, hf_zbee_zcl_analog_value_basic_reliability, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_ANALOG_VALUE_BASIC_STATUS_FLAGS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_analog_value_basic_status_flags, ett_zbee_zcl_analog_value_basic_status_flags, status_flags, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_ANALOG_VALUE_BASIC_DESCRIPTION:
case ZBEE_ZCL_ATTR_ID_ANALOG_VALUE_BASIC_OUT_OF_SERVICE:
case ZBEE_ZCL_ATTR_ID_ANALOG_VALUE_BASIC_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_ANALOG_VALUE_BASIC_RELINQUISH_DEFAULT:
case ZBEE_ZCL_ATTR_ID_ANALOG_VALUE_BASIC_ENGINEERING_UNITS:
case ZBEE_ZCL_ATTR_ID_ANALOG_VALUE_BASIC_APPLICATION_TYPE:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_analog_value_basic(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_analog_value_basic_attr_id,
{ "Attribute", "zbee_zcl_general.analog_value_basic.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_analog_value_basic_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_value_basic_reliability,
{ "Reliability", "zbee_zcl_general.analog_value_basic.attr.reliability", FT_UINT8, BASE_HEX, VALS(zbee_zcl_reliability_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_value_basic_status_flags,
{ "Status Flags", "zbee_zcl_general.analog_value_basic.attr.status", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_value_basic_status_in_alarm,
{ "In Alarm Status", "zbee_zcl_general.analog_value_basic.attr.status.in_alarm", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_IN_ALARM, NULL, HFILL } },
{ &hf_zbee_zcl_analog_value_basic_status_fault,
{ "Fault Status", "zbee_zcl_general.analog_value_basic.attr.status.fault", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_analog_value_basic_status_overridden,
{ "Overridden Status", "zbee_zcl_general.analog_value_basic.attr.status.overridden", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OVERRIDDEN, NULL, HFILL } },
{ &hf_zbee_zcl_analog_value_basic_status_out_of_service,
{ "Out of Service Status", "zbee_zcl_general.analog_value_basic.attr.status.out_of_service", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OUT_OF_SERVICE, NULL, HFILL } },
{ &hf_zbee_zcl_analog_value_basic_priority_array_bool,
{ "Valid/Invalid", "zbee_zcl_general.analog_value_basic.attr.priority_array.bool", FT_BOOLEAN, 8, TFS(&tfs_invalid_valid),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_value_basic_priority_array_sing_prec,
{ "Priority Value", "zbee_zcl_general.analog_value_basic.attr.priority_array.sing_prec", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_value_basic_priority_array,
{ "Priority Array", "zbee_zcl_general.analog_value_basic.priority_array.", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_analog_value_basic_structure,
{ "Structure", "zbee_zcl_general.analog_value_basic.structure.", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } }
};
static gint *ett[]={
&ett_zbee_zcl_analog_value_basic,
&ett_zbee_zcl_analog_value_basic_status_flags,
&ett_zbee_zcl_analog_value_basic_priority_array,
&ett_zbee_zcl_analog_value_basic_priority_array_structure
};
proto_zbee_zcl_analog_value_basic = proto_register_protocol("ZigBee ZCL Analog Value Basic", "ZCL Analog Value Basic", ZBEE_PROTOABBREV_ZCL_ANALOG_VALUE_BASIC);
proto_register_field_array(proto_zbee_zcl_analog_value_basic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_ANALOG_VALUE_BASIC, dissect_zbee_zcl_analog_value_basic, proto_zbee_zcl_analog_value_basic);
}
void
proto_reg_handoff_zbee_zcl_analog_value_basic(void)
{
dissector_handle_t analog_value_basic_handle;
analog_value_basic_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_ANALOG_VALUE_BASIC);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_ANALOG_VALUE_BASIC, analog_value_basic_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_analog_value_basic,
ett_zbee_zcl_analog_value_basic,
ZBEE_ZCL_CID_ANALOG_VALUE_BASIC,
hf_zbee_zcl_analog_value_basic_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_analog_value_basic_attr_data
);
}
static int
dissect_zbee_zcl_binary_input_basic(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_binary_input_basic_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int * status_flags[] = {
&hf_zbee_zcl_binary_input_basic_status_in_alarm,
&hf_zbee_zcl_binary_input_basic_status_fault,
&hf_zbee_zcl_binary_input_basic_status_overridden,
&hf_zbee_zcl_binary_input_basic_status_out_of_service,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_BINARY_INPUT_BASIC_POLARITY:
proto_tree_add_item(tree, hf_zbee_zcl_binary_input_basic_polarity, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BINARY_INPUT_BASIC_RELIABILITY:
proto_tree_add_item(tree, hf_zbee_zcl_binary_input_basic_reliability, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BINARY_INPUT_BASIC_STATUS_FLAGS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_binary_input_basic_status_flags, ett_zbee_zcl_binary_input_basic_status_flags, status_flags, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BINARY_INPUT_BASIC_ACTIVE_TEXT:
case ZBEE_ZCL_ATTR_ID_BINARY_INPUT_BASIC_INACTIVE_TEXT:
case ZBEE_ZCL_ATTR_ID_BINARY_INPUT_BASIC_DESCRIPTION:
case ZBEE_ZCL_ATTR_ID_BINARY_INPUT_BASIC_OUT_OF_SERVICE:
case ZBEE_ZCL_ATTR_ID_BINARY_INPUT_BASIC_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_BINARY_INPUT_BASIC_APPLICATION_TYPE:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_binary_input_basic(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_binary_input_basic_attr_id,
{ "Attribute", "zbee_zcl_general.binary_input_basic.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_binary_input_basic_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_input_basic_reliability,
{ "Reliability", "zbee_zcl_general.binary_input_basic.attr.reliability", FT_UINT8, BASE_HEX, VALS(zbee_zcl_reliability_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_input_basic_status_flags,
{ "Status Flags", "zbee_zcl_general.binary_input_basic.attr.status", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_input_basic_status_in_alarm,
{ "In Alarm Status", "zbee_zcl_general.binary_input_basic.attr.status.in_alarm", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_IN_ALARM, NULL, HFILL } },
{ &hf_zbee_zcl_binary_input_basic_status_fault,
{ "Fault Status", "zbee_zcl_general.binary_input_basic.attr.status.fault", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_binary_input_basic_status_overridden,
{ "Overridden Status", "zbee_zcl_general.binary_input_basic.attr.status.overridden", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OVERRIDDEN, NULL, HFILL } },
{ &hf_zbee_zcl_binary_input_basic_status_out_of_service,
{ "Out of Service Status", "zbee_zcl_general.binary_input_basic.attr.status.out_of_service", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OUT_OF_SERVICE, NULL, HFILL } },
{ &hf_zbee_zcl_binary_input_basic_polarity,
{ "Polarity", "zbee_zcl_general.binary_input_basic.attr.polarity", FT_UINT8, BASE_HEX, VALS(zbee_zcl_binary_input_polarity_values),
0x00, NULL, HFILL } }
};
static gint *ett[]={
&ett_zbee_zcl_binary_input_basic,
&ett_zbee_zcl_binary_input_basic_status_flags
};
proto_zbee_zcl_binary_input_basic = proto_register_protocol("ZigBee ZCL Binary Input Basic", "ZCL Binary Input Basic", ZBEE_PROTOABBREV_ZCL_BINARY_INPUT_BASIC);
proto_register_field_array(proto_zbee_zcl_binary_input_basic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_BINARY_INPUT_BASIC, dissect_zbee_zcl_binary_input_basic, proto_zbee_zcl_binary_input_basic);
}
void
proto_reg_handoff_zbee_zcl_binary_input_basic(void)
{
dissector_handle_t binary_input_basic_handle;
binary_input_basic_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_BINARY_INPUT_BASIC);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_BINARY_INPUT_BASIC, binary_input_basic_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_binary_input_basic,
ett_zbee_zcl_binary_input_basic,
ZBEE_ZCL_CID_BINARY_INPUT_BASIC,
hf_zbee_zcl_binary_input_basic_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_binary_input_basic_attr_data
);
}
static int
dissect_zbee_zcl_binary_output_basic(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_binary_output_basic_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
proto_item *ti = NULL, *tj = NULL;
proto_tree *sub_tree = NULL, *sub = NULL;
int i;
static const int * status_flags[] = {
&hf_zbee_zcl_binary_output_basic_status_in_alarm,
&hf_zbee_zcl_binary_output_basic_status_fault,
&hf_zbee_zcl_binary_output_basic_status_overridden,
&hf_zbee_zcl_binary_output_basic_status_out_of_service,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_PRIORITY_ARRAY:
ti = proto_tree_add_item(tree,hf_zbee_zcl_binary_output_basic_priority_array, tvb, *offset, 80, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_binary_output_basic_priority_array);
for(i = 1; i <= 16; i++)
{
tj = proto_tree_add_item(sub_tree, hf_zbee_zcl_binary_output_basic_structure, tvb, *offset, 5, ENC_NA);
proto_item_append_text(tj," %d",i);
sub = proto_item_add_subtree(tj, ett_zbee_zcl_binary_output_basic_priority_array_structure);
proto_tree_add_item(sub, hf_zbee_zcl_binary_output_basic_priority_array_bool, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(sub, hf_zbee_zcl_binary_output_basic_priority_array_sing_prec, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
break;
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_POLARITY:
proto_tree_add_item(tree, hf_zbee_zcl_binary_output_basic_polarity, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_RELIABILITY:
proto_tree_add_item(tree, hf_zbee_zcl_binary_output_basic_reliability, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_STATUS_FLAGS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_binary_output_basic_status_flags, ett_zbee_zcl_binary_output_basic_status_flags, status_flags, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_ACTIVE_TEXT:
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_DESCRIPTION:
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_INACTIVE_TEXT:
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_MIN_OFF_TIME:
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_MIN_ON_TIME:
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_OUT_OF_SERVICE:
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_RELINQUISH_DEFAULT:
case ZBEE_ZCL_ATTR_ID_BINARY_OUTPUT_BASIC_APPLICATION_TYPE:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_binary_output_basic(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_binary_output_basic_attr_id,
{ "Attribute", "zbee_zcl_general.binary_output_basic.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_binary_output_basic_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_output_basic_reliability,
{ "Reliability", "zbee_zcl_general.binary_output_basic.attr.reliability", FT_UINT8, BASE_HEX, VALS(zbee_zcl_reliability_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_output_basic_status_flags,
{ "Status Flags", "zbee_zcl_general.binary_output_basic.attr.status", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_output_basic_status_in_alarm,
{ "In Alarm Status", "zbee_zcl_general.binary_output_basic.attr.status.in_alarm", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_IN_ALARM, NULL, HFILL } },
{ &hf_zbee_zcl_binary_output_basic_status_fault,
{ "Fault Status", "zbee_zcl_general.binary_output_basic.attr.status.fault", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_binary_output_basic_status_overridden,
{ "Overridden Status", "zbee_zcl_general.binary_output_basic.attr.status.overridden", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OVERRIDDEN, NULL, HFILL } },
{ &hf_zbee_zcl_binary_output_basic_status_out_of_service,
{ "Out of Service Status", "zbee_zcl_general.binary_output_basic.attr.status.out_of_service", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OUT_OF_SERVICE, NULL, HFILL } },
{ &hf_zbee_zcl_binary_output_basic_polarity,
{ "Polarity", "zbee_zcl_general.binary_output_basic.attr.polarity", FT_UINT8, BASE_HEX, VALS(zbee_zcl_binary_output_polarity_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_output_basic_priority_array_bool,
{ "Valid/Invalid", "zbee_zcl_general.binary_output_basic.attr.priority_array.bool", FT_BOOLEAN, 8, TFS(&tfs_invalid_valid),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_output_basic_priority_array_sing_prec,
{ "Priority Value", "zbee_zcl_general.binary_output_basic.attr.priority_array.sing_prec", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_output_basic_priority_array,
{ "Priority Array", "zbee_zcl_general.binary_output_basic.priority_array.", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_output_basic_structure,
{ "Structure", "zbee_zcl_general.binary_output_basic.structure.", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } }
};
static gint *ett[]={
&ett_zbee_zcl_binary_output_basic,
&ett_zbee_zcl_binary_output_basic_status_flags,
&ett_zbee_zcl_binary_output_basic_priority_array,
&ett_zbee_zcl_binary_output_basic_priority_array_structure
};
proto_zbee_zcl_binary_output_basic = proto_register_protocol("ZigBee ZCL Binary Output Basic", "ZCL Binary Output Basic", ZBEE_PROTOABBREV_ZCL_BINARY_OUTPUT_BASIC);
proto_register_field_array(proto_zbee_zcl_binary_output_basic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_BINARY_OUTPUT_BASIC, dissect_zbee_zcl_binary_output_basic, proto_zbee_zcl_binary_output_basic);
}
void
proto_reg_handoff_zbee_zcl_binary_output_basic(void)
{
dissector_handle_t binary_output_basic_handle;
binary_output_basic_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_BINARY_OUTPUT_BASIC);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_BINARY_OUTPUT_BASIC, binary_output_basic_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_binary_output_basic,
ett_zbee_zcl_binary_output_basic,
ZBEE_ZCL_CID_BINARY_OUTPUT_BASIC,
hf_zbee_zcl_binary_output_basic_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_binary_output_basic_attr_data
);
}
static int
dissect_zbee_zcl_binary_value_basic(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_binary_value_basic_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
proto_item *ti = NULL, *tj = NULL;
proto_tree *sub_tree = NULL, *sub = NULL;
int i;
static const int * status_flags[] = {
&hf_zbee_zcl_binary_value_basic_status_in_alarm,
&hf_zbee_zcl_binary_value_basic_status_fault,
&hf_zbee_zcl_binary_value_basic_status_overridden,
&hf_zbee_zcl_binary_value_basic_status_out_of_service,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_BINARY_VALUE_BASIC_PRIORITY_ARRAY:
ti = proto_tree_add_item(tree,hf_zbee_zcl_binary_value_basic_priority_array, tvb, *offset, 80, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_binary_value_basic_priority_array);
for( i = 1; i <= 16; i++)
{
tj = proto_tree_add_item(sub_tree, hf_zbee_zcl_binary_value_basic_structure, tvb, *offset, 5, ENC_NA);
proto_item_append_text(tj," %d",i);
sub = proto_item_add_subtree(tj, ett_zbee_zcl_binary_value_basic_priority_array_structure);
proto_tree_add_item(sub, hf_zbee_zcl_binary_value_basic_priority_array_bool, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(sub, hf_zbee_zcl_binary_value_basic_priority_array_sing_prec, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
break;
case ZBEE_ZCL_ATTR_ID_BINARY_VALUE_BASIC_RELIABILITY:
proto_tree_add_item(tree, hf_zbee_zcl_binary_value_basic_reliability, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BINARY_VALUE_BASIC_STATUS_FLAGS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_binary_value_basic_status_flags, ett_zbee_zcl_binary_value_basic_status_flags, status_flags, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BINARY_VALUE_BASIC_ACTIVE_TEXT:
case ZBEE_ZCL_ATTR_ID_BINARY_VALUE_BASIC_DESCRIPTION:
case ZBEE_ZCL_ATTR_ID_BINARY_VALUE_BASIC_INACTIVE_TEXT:
case ZBEE_ZCL_ATTR_ID_BINARY_VALUE_BASIC_MIN_OFF_TIME:
case ZBEE_ZCL_ATTR_ID_BINARY_VALUE_BASIC_MIN_ON_TIME:
case ZBEE_ZCL_ATTR_ID_BINARY_VALUE_BASIC_OUT_OF_SERVICE:
case ZBEE_ZCL_ATTR_ID_BINARY_VALUE_BASIC_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_BINARY_VALUE_BASIC_RELINQUISH_DEFAULT:
case ZBEE_ZCL_ATTR_ID_BINARY_VALUE_BASIC_APPLICATION_TYPE:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_binary_value_basic(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_binary_value_basic_attr_id,
{ "Attribute", "zbee_zcl_general.binary_value_basic.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_binary_value_basic_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_value_basic_reliability,
{ "Reliability", "zbee_zcl_general.binary_value_basic.attr.reliability", FT_UINT8, BASE_HEX, VALS(zbee_zcl_reliability_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_value_basic_status_flags,
{ "Status Flags", "zbee_zcl_general.binary_value_basic.attr.status", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_value_basic_status_in_alarm,
{ "In Alarm Status", "zbee_zcl_general.binary_value_basic.attr.status.in_alarm", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_IN_ALARM, NULL, HFILL } },
{ &hf_zbee_zcl_binary_value_basic_status_fault,
{ "Fault Status", "zbee_zcl_general.binary_value_basic.attr.status.fault", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_binary_value_basic_status_overridden,
{ "Overridden Status", "zbee_zcl_general.binary_value_basic.attr.status.overridden", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OVERRIDDEN, NULL, HFILL } },
{ &hf_zbee_zcl_binary_value_basic_status_out_of_service,
{ "Out of Service Status", "zbee_zcl_general.binary_value_basic.attr.status.out_of_service", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OUT_OF_SERVICE, NULL, HFILL } },
{ &hf_zbee_zcl_binary_value_basic_priority_array_bool,
{ "Valid/Invalid", "zbee_zcl_general.binary_value_basic.attr.priority_array.bool", FT_BOOLEAN, 8,TFS(&tfs_invalid_valid),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_value_basic_priority_array_sing_prec,
{ "Priority Value", "zbee_zcl_general.binary_value_basic.attr.priority_array.sing_prec", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_value_basic_priority_array,
{ "Priority Array", "zbee_zcl_general.binary_value_basic.priority_array.", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_binary_value_basic_structure,
{ "Structure", "zbee_zcl_general.binary_value_basic.structure.", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } }
};
static gint *ett[]={
&ett_zbee_zcl_binary_value_basic,
&ett_zbee_zcl_binary_value_basic_status_flags,
&ett_zbee_zcl_binary_value_basic_priority_array,
&ett_zbee_zcl_binary_value_basic_priority_array_structure
};
proto_zbee_zcl_binary_value_basic = proto_register_protocol("ZigBee ZCL Binary Value Basic", "ZCL Binary Value Basic", ZBEE_PROTOABBREV_ZCL_BINARY_VALUE_BASIC);
proto_register_field_array(proto_zbee_zcl_binary_value_basic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_BINARY_VALUE_BASIC, dissect_zbee_zcl_binary_value_basic, proto_zbee_zcl_binary_value_basic);
}
void
proto_reg_handoff_zbee_zcl_binary_value_basic(void)
{
dissector_handle_t binary_value_basic_handle;
binary_value_basic_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_BINARY_VALUE_BASIC);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_BINARY_VALUE_BASIC, binary_value_basic_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_binary_value_basic,
ett_zbee_zcl_binary_value_basic,
ZBEE_ZCL_CID_BINARY_VALUE_BASIC,
hf_zbee_zcl_binary_value_basic_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_binary_value_basic_attr_data
);
}
static int
dissect_zbee_zcl_multistate_input_basic(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_multistate_input_basic_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int * status_flags[] = {
&hf_zbee_zcl_multistate_input_basic_status_in_alarm,
&hf_zbee_zcl_multistate_input_basic_status_fault,
&hf_zbee_zcl_multistate_input_basic_status_overridden,
&hf_zbee_zcl_multistate_input_basic_status_out_of_service,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_MULTISTATE_INPUT_BASIC_RELIABILITY:
proto_tree_add_item(tree, hf_zbee_zcl_multistate_input_basic_reliability, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_MULTISTATE_INPUT_BASIC_STATUS_FLAGS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_multistate_input_basic_status_flags, ett_zbee_zcl_multistate_input_basic_status_flags, status_flags, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_MULTISTATE_INPUT_BASIC_DESCRIPTION:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_INPUT_BASIC_NUMBER_OF_STATES:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_INPUT_BASIC_OUT_OF_SERVICE:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_INPUT_BASIC_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_INPUT_BASIC_APPLICATION_TYPE:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_multistate_input_basic(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_multistate_input_basic_attr_id,
{ "Attribute", "zbee_zcl_general.multistate_input_basic.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_multistate_input_basic_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_input_basic_reliability,
{ "Reliability", "zbee_zcl_general.multistate_input_basic.attr.reliability", FT_UINT8, BASE_HEX, VALS(zbee_zcl_reliability_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_input_basic_status_flags,
{ "Status Flags", "zbee_zcl_general.multistate_input_basic.attr.status", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_input_basic_status_in_alarm,
{ "In Alarm Status", "zbee_zcl_general.multistate_input_basic.attr.status.in_alarm", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_IN_ALARM, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_input_basic_status_fault,
{ "Fault Status", "zbee_zcl_general.multistate_input_basic.attr.status.fault", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_input_basic_status_overridden,
{ "Overridden Status", "zbee_zcl_general.multistate_input_basic.attr.status.overridden", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OVERRIDDEN, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_input_basic_status_out_of_service,
{ "Out of Service Status", "zbee_zcl_general.multistate_input_basic.attr.status.out_of_service", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OUT_OF_SERVICE, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_MULTISTATE_INPUT_BASIC_NUM_ETT];
ett[0] = &ett_zbee_zcl_multistate_input_basic;
ett[1] = &ett_zbee_zcl_multistate_input_basic_status_flags;
proto_zbee_zcl_multistate_input_basic = proto_register_protocol("ZigBee ZCL Multistate Input Basic", "ZCL Multistate Input Basic", ZBEE_PROTOABBREV_ZCL_MULTISTATE_INPUT_BASIC);
proto_register_field_array(proto_zbee_zcl_multistate_input_basic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_MULTISTATE_INPUT_BASIC, dissect_zbee_zcl_multistate_input_basic, proto_zbee_zcl_multistate_input_basic);
}
void
proto_reg_handoff_zbee_zcl_multistate_input_basic(void)
{
dissector_handle_t multistate_input_basic_handle;
multistate_input_basic_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_MULTISTATE_INPUT_BASIC);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_MULTISTATE_INPUT_BASIC, multistate_input_basic_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_multistate_input_basic,
ett_zbee_zcl_multistate_input_basic,
ZBEE_ZCL_CID_MULTISTATE_INPUT_BASIC,
hf_zbee_zcl_multistate_input_basic_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_multistate_input_basic_attr_data
);
}
static int
dissect_zbee_zcl_multistate_output_basic(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_multistate_output_basic_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
proto_item *ti = NULL, *tj = NULL;
proto_tree *sub_tree = NULL, *sub = NULL;
int i;
static const int * status_flags[] = {
&hf_zbee_zcl_multistate_output_basic_status_in_alarm,
&hf_zbee_zcl_multistate_output_basic_status_fault,
&hf_zbee_zcl_multistate_output_basic_status_overridden,
&hf_zbee_zcl_multistate_output_basic_status_out_of_service,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_MULTISTATE_OUTPUT_BASIC_PRIORITY_ARRAY:
ti = proto_tree_add_item(tree,hf_zbee_zcl_multistate_output_basic_priority_array, tvb, *offset, 80, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_multistate_output_basic_priority_array);
for( i = 1; i <= 16; i++)
{
tj = proto_tree_add_item(sub_tree, hf_zbee_zcl_multistate_output_basic_structure, tvb, *offset, 5, ENC_NA);
proto_item_append_text(tj," %d",i);
sub = proto_item_add_subtree(tj, ett_zbee_zcl_multistate_output_basic_priority_array_structure);
proto_tree_add_item(sub, hf_zbee_zcl_multistate_output_basic_priority_array_bool, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(sub, hf_zbee_zcl_multistate_output_basic_priority_array_sing_prec, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
break;
case ZBEE_ZCL_ATTR_ID_MULTISTATE_OUTPUT_BASIC_RELIABILITY:
proto_tree_add_item(tree, hf_zbee_zcl_multistate_output_basic_reliability, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_MULTISTATE_OUTPUT_BASIC_STATUS_FLAGS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_multistate_output_basic_status_flags, ett_zbee_zcl_multistate_output_basic_status_flags, status_flags, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_MULTISTATE_OUTPUT_BASIC_DESCRIPTION:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_OUTPUT_BASIC_NUMBER_OF_STATES:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_OUTPUT_BASIC_OUT_OF_SERVICE:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_OUTPUT_BASIC_RELINQUISH_DEFAULT:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_OUTPUT_BASIC_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_OUTPUT_BASIC_APPLICATION_TYPE:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_multistate_output_basic(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_multistate_output_basic_attr_id,
{ "Attribute", "zbee_zcl_general.multistate_output_basic.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_multistate_output_basic_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_output_basic_reliability,
{ "Reliability", "zbee_zcl_general.multistate_output_basic.attr.reliability", FT_UINT8, BASE_HEX, VALS(zbee_zcl_reliability_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_output_basic_status_flags,
{ "Status Flags", "zbee_zcl_general.multistate_output_basic.attr.status", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_output_basic_status_in_alarm,
{ "In Alarm Status", "zbee_zcl_general.multistate_output_basic.attr.status.in_alarm", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_IN_ALARM, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_output_basic_status_fault,
{ "Fault Status", "zbee_zcl_general.multistate_output_basic.attr.status.fault", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_output_basic_status_overridden,
{ "Overridden Status", "zbee_zcl_general.multistate_output_basic.attr.status.overridden", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OVERRIDDEN, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_output_basic_status_out_of_service,
{ "Out of Service Status", "zbee_zcl_general.multistate_output_basic.attr.status.out_of_service", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OUT_OF_SERVICE, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_output_basic_priority_array_bool,
{ "Valid/Invalid", "zbee_zcl_general.multistate_output_basic.attr.priority_array.bool", FT_UINT8, BASE_HEX, VALS(zbee_zcl_multistate_output_basic_priority_array_bool_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_output_basic_priority_array_sing_prec,
{ "Priority Value", "zbee_zcl_general.multistate_output_basic.attr.priority_array.sing_prec", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } } ,
{ &hf_zbee_zcl_multistate_output_basic_priority_array,
{ "Priority Array", "zbee_zcl_general.multistate_output_basic.priority_array.", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_output_basic_structure,
{ "Structure", "zbee_zcl_general.multistate_output_basic.structure.", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_MULTISTATE_OUTPUT_BASIC_NUM_ETT];
ett[0] = &ett_zbee_zcl_multistate_output_basic;
ett[1] = &ett_zbee_zcl_multistate_output_basic_status_flags;
ett[2] = &ett_zbee_zcl_multistate_output_basic_priority_array;
ett[3] = &ett_zbee_zcl_multistate_output_basic_priority_array_structure;
proto_zbee_zcl_multistate_output_basic = proto_register_protocol("ZigBee ZCL Multistate Output Basic", "ZCL Multistate Output Basic", ZBEE_PROTOABBREV_ZCL_MULTISTATE_OUTPUT_BASIC);
proto_register_field_array(proto_zbee_zcl_multistate_output_basic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_MULTISTATE_OUTPUT_BASIC, dissect_zbee_zcl_multistate_output_basic, proto_zbee_zcl_multistate_output_basic);
}
void
proto_reg_handoff_zbee_zcl_multistate_output_basic(void)
{
dissector_handle_t multistate_output_basic_handle;
multistate_output_basic_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_MULTISTATE_OUTPUT_BASIC);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_MULTISTATE_OUTPUT_BASIC, multistate_output_basic_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_multistate_output_basic,
ett_zbee_zcl_multistate_output_basic,
ZBEE_ZCL_CID_MULTISTATE_OUTPUT_BASIC,
hf_zbee_zcl_multistate_output_basic_attr_id,
-1,-1,
(zbee_zcl_fn_attr_data)dissect_zcl_multistate_output_basic_attr_data
);
}
static int
dissect_zbee_zcl_multistate_value_basic(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_multistate_value_basic_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
proto_item *ti = NULL, *tj = NULL;
proto_tree *sub_tree = NULL, *sub = NULL;
int i;
static const int * status_flags[] = {
&hf_zbee_zcl_multistate_value_basic_status_in_alarm,
&hf_zbee_zcl_multistate_value_basic_status_fault,
&hf_zbee_zcl_multistate_value_basic_status_overridden,
&hf_zbee_zcl_multistate_value_basic_status_out_of_service,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_MULTISTATE_VALUE_BASIC_PRIORITY_ARRAY:
ti = proto_tree_add_item(tree,hf_zbee_zcl_multistate_value_basic_priority_array, tvb, *offset, 80, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_multistate_value_basic_priority_array);
for( i = 1; i <= 16; i++)
{
tj = proto_tree_add_item(sub_tree,hf_zbee_zcl_multistate_value_basic_structure, tvb, *offset, 5,ENC_NA);
proto_item_append_text(tj," %d",i);
sub = proto_item_add_subtree(tj, ett_zbee_zcl_multistate_value_basic_priority_array_structure);
proto_tree_add_item(sub, hf_zbee_zcl_multistate_value_basic_priority_array_bool, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(sub, hf_zbee_zcl_multistate_value_basic_priority_array_sing_prec, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
break;
case ZBEE_ZCL_ATTR_ID_MULTISTATE_VALUE_BASIC_RELIABILITY:
proto_tree_add_item(tree, hf_zbee_zcl_multistate_value_basic_reliability, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_MULTISTATE_VALUE_BASIC_STATUS_FLAGS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_multistate_value_basic_status_flags, ett_zbee_zcl_multistate_value_basic_status_flags, status_flags, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_MULTISTATE_VALUE_BASIC_DESCRIPTION:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_VALUE_BASIC_NUMBER_OF_STATES:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_VALUE_BASIC_OUT_OF_SERVICE:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_VALUE_BASIC_RELINQUISH_DEFAULT:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_VALUE_BASIC_PRESENT_VALUE:
case ZBEE_ZCL_ATTR_ID_MULTISTATE_VALUE_BASIC_APPLICATION_TYPE:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_multistate_value_basic(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_multistate_value_basic_attr_id,
{ "Attribute", "zbee_zcl_general.multistate_value_basic.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_multistate_value_basic_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_value_basic_reliability,
{ "Reliability", "zbee_zcl_general.multistate_value_basic.attr.reliability", FT_UINT8, BASE_HEX, VALS(zbee_zcl_reliability_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_value_basic_status_flags,
{ "Status Flags", "zbee_zcl_general.multistate_value_basic.attr.status", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_value_basic_status_in_alarm,
{ "In Alarm Status", "zbee_zcl_general.multistate_value_basic.attr.status.in_alarm", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_IN_ALARM, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_value_basic_status_fault,
{ "Fault Status", "zbee_zcl_general.multistate_value_basic.attr.status.fault", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_value_basic_status_overridden,
{ "Overridden Status", "zbee_zcl_general.multistate_value_basic.attr.status.overridden", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OVERRIDDEN, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_value_basic_status_out_of_service,
{ "Out of Service Status", "zbee_zcl_general.multistate_value_basic.attr.status.out_of_service", FT_UINT8, BASE_DEC, VALS(zbee_zcl_status_values),
ZBEE_ZCL_STATUS_OUT_OF_SERVICE, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_value_basic_priority_array_bool,
{ "Valid/Invalid", "zbee_zcl_general.multistate_value_basic.attr.priority_array.bool", FT_UINT8, BASE_HEX, VALS(zbee_zcl_multistate_value_basic_priority_array_bool_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_value_basic_priority_array_sing_prec,
{ "Priority Value", "zbee_zcl_general.multistate_value_basic.attr.priority_array.sing_prec", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_value_basic_priority_array,
{ "Priority Array", "zbee_zcl_general.multistate_value_basic.priority_array.", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_multistate_value_basic_structure,
{ "Structure", "zbee_zcl_general.multistate_value_basic.structure.", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_MULTISTATE_VALUE_BASIC_NUM_ETT];
ett[0] = &ett_zbee_zcl_multistate_value_basic;
ett[1] = &ett_zbee_zcl_multistate_value_basic_status_flags;
ett[2] = &ett_zbee_zcl_multistate_value_basic_priority_array;
ett[3] = &ett_zbee_zcl_multistate_value_basic_priority_array_structure;
proto_zbee_zcl_multistate_value_basic = proto_register_protocol("ZigBee ZCL Multistate Value Basic", "ZCL Multistate Value Basic", ZBEE_PROTOABBREV_ZCL_MULTISTATE_VALUE_BASIC);
proto_register_field_array(proto_zbee_zcl_multistate_value_basic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_MULTISTATE_VALUE_BASIC, dissect_zbee_zcl_multistate_value_basic, proto_zbee_zcl_multistate_value_basic);
}
void
proto_reg_handoff_zbee_zcl_multistate_value_basic(void)
{
dissector_handle_t multistate_value_basic_handle;
multistate_value_basic_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_MULTISTATE_VALUE_BASIC);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_MULTISTATE_VALUE_BASIC, multistate_value_basic_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_multistate_value_basic,
ett_zbee_zcl_multistate_value_basic,
ZBEE_ZCL_CID_MULTISTATE_VALUE_BASIC,
hf_zbee_zcl_multistate_value_basic_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_multistate_value_basic_attr_data
);
}
static int
dissect_zbee_zcl_commissioning(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_commissioning_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_commissioning_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_commissioning, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_COMMISSIONING_RESTART_DEVICE:
dissect_zcl_commissioning_restart_device(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_COMMISSIONING_RESET_STARTUP_PARAMETERS:
dissect_zcl_commissioning_reset_startup_parameters(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_COMMISSIONING_SAVE_STARTUP_PARAMETERS:
case ZBEE_ZCL_CMD_ID_COMMISSIONING_RESTORE_STARTUP_PARAMETERS:
dissect_zcl_commissioning_save_restore_startup_parameters(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_commissioning_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_commissioning_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_commissioning, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_COMMISSIONING_RESTART_DEVICE_RESPONSE:
case ZBEE_ZCL_CMD_ID_COMMISSIONING_SAVE_STARTUP_PARAMETERS_RESPONSE:
case ZBEE_ZCL_CMD_ID_COMMISSIONING_RESTORE_STARTUP_PARAMETERS_RESPONSE:
case ZBEE_ZCL_CMD_ID_COMMISSIONING_RESET_STARTUP_PARAMETERS_RESPONSE:
dissect_zcl_commissioning_response(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_commissioning_restart_device(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
static const int * restart_device_mask[] = {
&hf_zbee_zcl_commissioning_restart_device_options_startup_mode,
&hf_zbee_zcl_commissioning_restart_device_options_immediate,
&hf_zbee_zcl_commissioning_restart_device_options_reserved,
NULL
};
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_commissioning_restart_device_options, ett_zbee_zcl_commissioning_restart_device_options, restart_device_mask, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_commissioning_delay, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_commissioning_jitter, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void
dissect_zcl_commissioning_save_restore_startup_parameters(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_commissioning_options, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_commissioning_index, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void
dissect_zcl_commissioning_reset_startup_parameters(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
static const int * reset_startup_mask[] = {
&hf_zbee_zcl_commissioning_reset_startup_options_reset_current,
&hf_zbee_zcl_commissioning_reset_startup_options_reset_all,
&hf_zbee_zcl_commissioning_reset_startup_options_erase_index,
&hf_zbee_zcl_commissioning_reset_startup_options_reserved,
NULL
};
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_commissioning_reset_startup_options, ett_zbee_zcl_commissioning_reset_startup_options, reset_startup_mask, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_commissioning_index, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void
dissect_zcl_commissioning_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_commissioning_status, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
void
dissect_zcl_commissioning_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_STACK_PROFILE:
proto_tree_add_item(tree, hf_zbee_zcl_commissioning_attr_stack_profile, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_STARTUP_CONTROL:
proto_tree_add_item(tree, hf_zbee_zcl_commissioning_attr_startup_control, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_SHORT_ADDRESS:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_EXTENDED_PAN_ID:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_PAN_ID:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_CHANNEL_MASK:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_PROTOCOL_VERSION:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_TRUST_CENTER_ADDRESS:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_TRUST_CENTER_MASTER_KEY:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_NETWORK_KEY:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_USE_INSECURE_JOIN:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_PRECONFIGURED_LINK_KEY:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_NETWORK_KEY_SEQ_NUM:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_NETWORK_KEY_TYPE:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_NETWORK_MANAGER_ADDRESS:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_SCAN_ATTEMPTS:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_TIME_BETWEEN_SCANS:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_REJOIN_INTERVAL:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_MAX_REJOIN_INTERVAL:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_INDIRECT_POLL_RATE:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_PARENT_RETRY_THRESHOLD:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_CONCENTRATOR_FLAG:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_CONCENTRATOR_RADIUS:
case ZBEE_ZCL_ATTR_ID_COMMISSIONING_CONCENTRATOR_DISCOVERY_TIME:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_commissioning(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_commissioning_attr_id,
{ "Attribute", "zbee_zcl_general.commissioning.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_commissioning_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_attr_stack_profile,
{ "Stack Profile", "zbee_zcl_general.commissioning.attr.stack_profile", FT_UINT8, BASE_HEX, VALS(zbee_zcl_commissioning_stack_profile_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_attr_startup_control,
{ "Startup Control", "zbee_zcl_general.commissioning.attr.startup_control", FT_UINT8, BASE_HEX, VALS(zbee_zcl_commissioning_startup_control_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_restart_device_options,
{ "Restart Device Options", "zbee_zcl_general.commissioning.restart_device_options", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_restart_device_options_startup_mode,
{ "Startup Mode", "zbee_zcl_general.commissioning.restart_device_options.startup_mode", FT_UINT8, BASE_HEX, VALS(zbee_zcl_commissioning_startup_mode_values),
ZBEE_ZCL_COMMISSIONING_RESTART_DEVICE_OPTIONS_STARTUP_MODE, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_restart_device_options_immediate,
{ "Immediate", "zbee_zcl_general.commissioning.restart_device_options.immediate", FT_BOOLEAN, 8, NULL,
ZBEE_ZCL_COMMISSIONING_RESTART_DEVICE_OPTIONS_IMMEDIATE, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_restart_device_options_reserved,
{ "Reserved", "zbee_zcl_general.commissioning.restart_device_options.reserved", FT_BOOLEAN, 8, NULL,
ZBEE_ZCL_COMMISSIONING_RESTART_DEVICE_OPTIONS_RESERVED, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_delay,
{ "Delay", "zbee_zcl_general.commissioning.delay", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_jitter,
{ "Jitter", "zbee_zcl_general.commissioning.jitter", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_options,
{ "Options (Reserved)", "zbee_zcl_general.commissioning.options", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_index,
{ "Index", "zbee_zcl_general.commissioning.index", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_reset_startup_options,
{ "Reset Startup Options", "zbee_zcl_general.commissioning.reset_startup_options", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_reset_startup_options_reset_current,
{ "Reset Current", "zbee_zcl_general.commissioning.reset_startup_options.current", FT_BOOLEAN, 8, NULL,
ZBEE_ZCL_COMMISSIONING_RESET_STARTUP_OPTIONS_RESET_CURRENT, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_reset_startup_options_reset_all,
{ "Reset All", "zbee_zcl_general.commissioning.reset_startup_options.reset_all", FT_BOOLEAN, 8, NULL,
ZBEE_ZCL_COMMISSIONING_RESET_STARTUP_OPTIONS_RESET_ALL, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_reset_startup_options_erase_index,
{ "Erase Index", "zbee_zcl_general.commissioning.reset_startup_options.erase_index", FT_BOOLEAN, 8, NULL,
ZBEE_ZCL_COMMISSIONING_RESET_STARTUP_OPTIONS_ERASE_INDEX, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_reset_startup_options_reserved,
{ "Reserved", "zbee_zcl_general.commissioning.reset_startup_options.reserved", FT_BOOLEAN, 8, NULL,
ZBEE_ZCL_COMMISSIONING_RESET_STARTUP_OPTIONS_RESERVED, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_status,
{ "Status", "zbee_zcl_general.commissioning.status", FT_UINT8, BASE_HEX, VALS(zbee_zcl_status_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.commissioning.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_commissioning_srv_rx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_commissioning_srv_tx_cmd_id,
{ "Command", "zbee_zcl_general.commissioning.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_commissioning_srv_tx_cmd_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_COMMISSIONING_NUM_ETT];
ett[0] = &ett_zbee_zcl_commissioning;
ett[1] = &ett_zbee_zcl_commissioning_restart_device_options;
ett[2] = &ett_zbee_zcl_commissioning_reset_startup_options;
proto_zbee_zcl_commissioning = proto_register_protocol("ZigBee ZCL Commissioning", "ZCL Commissioning", ZBEE_PROTOABBREV_ZCL_COMMISSIONING);
proto_register_field_array(proto_zbee_zcl_commissioning, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_COMMISSIONING, dissect_zbee_zcl_commissioning, proto_zbee_zcl_commissioning);
}
void
proto_reg_handoff_zbee_zcl_commissioning(void)
{
dissector_handle_t commissioning_handle;
commissioning_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_COMMISSIONING);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_COMMISSIONING, commissioning_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_commissioning,
ett_zbee_zcl_commissioning,
ZBEE_ZCL_CID_COMMISSIONING,
hf_zbee_zcl_commissioning_attr_id,
hf_zbee_zcl_commissioning_srv_rx_cmd_id,
hf_zbee_zcl_commissioning_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_commissioning_attr_data
);
}
static int
dissect_zbee_zcl_part(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_part_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_part_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_part, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_PART_TRANSF_PART_FRAME:
dissect_zcl_part_trasfpartframe(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_PART_RD_HANDSHAKE_PARAM:
dissect_zcl_part_rdhandshakeparam(tvb, pinfo, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_PART_WR_HANDSHAKE_PARAM:
dissect_zcl_part_wrhandshakeparam(tvb, pinfo, payload_tree, &offset);
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_part_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_part_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_part, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_PART_MULTI_ACK:
dissect_zcl_part_multiack(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_PART_RD_HANDSHAKE_PARAM_RSP:
dissect_zcl_part_rdhandshakeparamrsp(tvb, pinfo, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void dissect_zcl_part_trasfpartframe(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 options;
guint16 u16len;
guint8 frame_len;
static const int * part_opt[] = {
&hf_zbee_zcl_part_opt_first_block,
&hf_zbee_zcl_part_opt_indic_len,
&hf_zbee_zcl_part_opt_res,
NULL
};
options = tvb_get_guint8(tvb, *offset);
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_part_opt, ett_zbee_zcl_part_fragm_options, part_opt, ENC_NA);
*offset += 1;
if ((options & ZBEE_ZCL_PART_OPT_INDIC_LEN) == 0)
{
u16len = (guint16)tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_part_part_indicator, tvb, *offset, 1, (u16len & 0xFF));
*offset += 1;
}
else {
u16len = tvb_get_letohs(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_part_part_indicator, tvb, *offset, 2, u16len);
*offset += 2;
}
frame_len = tvb_get_guint8(tvb, *offset);
if (frame_len == ZBEE_ZCL_INVALID_STR_LENGTH)
frame_len = 0;
proto_tree_add_item(tree, hf_zbee_zcl_part_part_frame_len, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_part_part_frame, tvb, *offset, frame_len, ENC_NA);
*offset += frame_len;
}
static void
dissect_zcl_part_rdhandshakeparam(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_part_partitioned_cluster_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_read_attr(tvb, pinfo, tree, offset, ZBEE_ZCL_CID_PARTITION);
}
static void
dissect_zcl_part_wrhandshakeparam(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_part_partitioned_cluster_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_write_attr(tvb, pinfo, tree, offset, ZBEE_ZCL_CID_PARTITION);
}
static void
dissect_zcl_part_multiack(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint tvb_len = tvb_reported_length(tvb);
guint i = 0;
guint8 options;
guint16 first_frame_id;
guint16 nack_id;
static const int * ack_opts[] = {
&hf_zbee_zcl_part_ack_opt_nack_id_len,
&hf_zbee_zcl_part_ack_opt_res,
NULL
};
options = tvb_get_guint8(tvb, *offset);
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_part_ack_opt, ett_zbee_zcl_part_ack_opts, ack_opts, ENC_NA);
*offset += 1;
if ((options & ZBEE_ZCL_PART_ACK_OPT_NACK_LEN) == 0)
{
first_frame_id = (guint16)tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_part_first_frame_id, tvb, *offset, 1, (first_frame_id & 0xFF));
*offset += 1;
}
else {
first_frame_id = tvb_get_letohs(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_part_first_frame_id, tvb, *offset, 2, first_frame_id);
*offset += 2;
}
while ( *offset < tvb_len && i < ZBEE_ZCL_PART_NUM_NACK_ID_ETT )
{
if ((options & ZBEE_ZCL_PART_ACK_OPT_NACK_LEN) == 0)
{
nack_id = (guint16)tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_part_nack_id, tvb, *offset, 1, (nack_id & 0xFF));
*offset += 1;
}
else {
nack_id = tvb_get_letohs(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_part_nack_id, tvb, *offset, 2, nack_id);
*offset += 2;
}
i++;
}
}
static void
dissect_zcl_part_rdhandshakeparamrsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_part_partitioned_cluster_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_read_attr_resp(tvb, pinfo, tree, offset, ZBEE_ZCL_CID_PARTITION);
}
void proto_register_zbee_zcl_part(void)
{
guint8 i, j;
static hf_register_info hf[] = {
{ &hf_zbee_zcl_part_attr_id,
{ "Attribute", "zbee_zcl_general.part.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_part_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_part_srv_tx_cmd_id,
{ "Command", "zbee_zcl_general.part.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_part_srv_tx_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_part_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.part.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_part_srv_rx_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_part_opt,
{ "Fragmentation Options", "zbee_zcl_general.part.opt", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_part_opt_first_block,
{ "First Block", "zbee_zcl_general.part.opt.first_block", FT_UINT8, BASE_HEX, NULL,
ZBEE_ZCL_PART_OPT_1_BLOCK, NULL, HFILL } },
{ &hf_zbee_zcl_part_opt_indic_len,
{ "Indicator length", "zbee_zcl_general.part.opt.indic_len", FT_UINT8, BASE_DEC, VALS(zbee_zcl_part_id_length_names),
ZBEE_ZCL_PART_OPT_INDIC_LEN, NULL, HFILL } },
{ &hf_zbee_zcl_part_opt_res,
{ "Reserved", "zbee_zcl_general.part.opt.res", FT_UINT8, BASE_HEX, NULL,
ZBEE_ZCL_PART_OPT_RESERVED, NULL, HFILL } },
{ &hf_zbee_zcl_part_first_frame_id,
{ "First Frame ID", "zbee_zcl_general.part.first_frame_id", FT_UINT16, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_part_part_indicator,
{ "Partition Indicator", "zbee_zcl_general.part.part_indicator", FT_UINT16, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_part_part_frame_len,
{ "Partition Frame Length", "zbee_zcl_general.part.part_frame_length", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_part_part_frame,
{ "Partition Frame", "zbee_zcl_general.part.part_frame", FT_BYTES, SEP_COLON, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_part_partitioned_cluster_id,
{ "Partitioned Cluster ID", "zbee_zcl_general.part.part_cluster_id", FT_UINT16, BASE_HEX, VALS(zbee_aps_cid_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_part_ack_opt,
{ "Ack Options", "zbee_zcl_general.ack_opt.part", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_part_ack_opt_nack_id_len,
{ "Nack Id Length", "zbee_zcl_general.ack_opt.part.nack_id.len", FT_UINT8, BASE_HEX, VALS(zbee_zcl_part_id_length_names),
ZBEE_ZCL_PART_ACK_OPT_NACK_LEN, NULL, HFILL } },
{ &hf_zbee_zcl_part_ack_opt_res,
{ "Reserved", "zbee_zcl_general.part.ack_opt.reserved", FT_UINT8, BASE_HEX, NULL,
ZBEE_ZCL_PART_ACK_OPT_RESERVED, NULL, HFILL } },
{ &hf_zbee_zcl_part_nack_id,
{ "Nack Id", "zbee_zcl_general.part.nack_id", FT_UINT16, BASE_DEC, NULL,
0x00, NULL, HFILL } }
};
gint *ett[ZBEE_ZCL_PART_NUM_ETT];
ett[0] = &ett_zbee_zcl_part;
ett[1] = &ett_zbee_zcl_part_fragm_options;
ett[2] = &ett_zbee_zcl_part_ack_opts;
for ( i = 0, j = ZBEE_ZCL_PART_NUM_GENERIC_ETT; i < ZBEE_ZCL_PART_NUM_NACK_ID_ETT; i++, j++) {
ett_zbee_zcl_part_nack_id_list[i] = -1;
ett[j] = &ett_zbee_zcl_part_nack_id_list[i];
}
for ( i = 0; i < ZBEE_ZCL_PART_NUM_ATTRS_ID_ETT; i++, j++) {
ett_zbee_zcl_part_attrs_id_list[i] = -1;
ett[j] = &ett_zbee_zcl_part_attrs_id_list[i];
}
proto_zbee_zcl_part = proto_register_protocol("ZigBee ZCL Partition", "ZCL Partition", ZBEE_PROTOABBREV_ZCL_PART);
proto_register_field_array(proto_zbee_zcl_part, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_PART, dissect_zbee_zcl_part, proto_zbee_zcl_part);
}
void proto_reg_handoff_zbee_zcl_part(void)
{
dissector_handle_t part_handle;
part_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_PART);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_PARTITION, part_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_part,
ett_zbee_zcl_part,
ZBEE_ZCL_CID_PARTITION,
hf_zbee_zcl_part_attr_id,
hf_zbee_zcl_part_srv_rx_cmd_id,
hf_zbee_zcl_part_srv_tx_cmd_id,
NULL
);
}
static void
decode_zcl_ota_curr_time(gchar *s, guint32 value)
{
if (value == ZBEE_ZCL_OTA_TIME_NOW) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Now");
}
else {
gchar *tmp;
value += ZBEE_ZCL_NSTIME_UTC_OFFSET;
tmp = abs_time_secs_to_str(NULL, value, ABSOLUTE_TIME_LOCAL, 1);
g_snprintf(s, ITEM_LABEL_LENGTH, "%s", tmp);
wmem_free(NULL, tmp);
}
return;
}
static void
decode_zcl_ota_req_time(gchar *s, guint32 value)
{
if (value == ZBEE_ZCL_OTA_TIME_WAIT) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Wrong Value");
}
else {
gchar *tmp = signed_time_secs_to_str(NULL, value);
g_snprintf(s, ITEM_LABEL_LENGTH, "%s from now", tmp);
wmem_free(NULL, tmp);
}
return;
}
static void
decode_zcl_ota_upgr_time(gchar *s, guint32 value)
{
if (value == ZBEE_ZCL_OTA_TIME_WAIT) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Wait for upgrade command");
}
else {
gchar *tmp = signed_time_secs_to_str(NULL, value);
g_snprintf(s, ITEM_LABEL_LENGTH, "%s from now", tmp);
wmem_free(NULL, tmp);
}
return;
}
static void
decode_zcl_ota_size_in_bytes(gchar *s, guint32 value)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d [Bytes]", value);
}
static void
dissect_zcl_ota_file_version_field(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
static const int * file_version[] = {
&hf_zbee_zcl_ota_file_version_appl_release,
&hf_zbee_zcl_ota_file_version_appl_build,
&hf_zbee_zcl_ota_file_version_stack_release,
&hf_zbee_zcl_ota_file_version_stack_build,
NULL
};
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_ota_file_version, ett_zbee_zcl_ota_file_version, file_version, ENC_BIG_ENDIAN);
*offset += 4;
}
static guint8
dissect_zcl_ota_field_ctrl_field(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 field;
static const int * field_ctrl[] = {
&hf_zbee_zcl_ota_field_ctrl_hw_ver_present,
&hf_zbee_zcl_ota_field_ctrl_reserved,
NULL
};
field = tvb_get_guint8(tvb, *offset);
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_ota_field_ctrl, ett_zbee_zcl_ota_field_ctrl, field_ctrl, ENC_BIG_ENDIAN);
*offset += 1;
return field;
}
static void
dissect_zcl_ota_imagenotify(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 payload_type;
payload_type = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_payload_type, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ota_query_jitter, tvb, *offset, 1, ENC_NA);
*offset += 1;
if (payload_type >= ZBEE_ZCL_OTA_PAYLOAD_TYPE_QJ_MC) {
proto_tree_add_item(tree, hf_zbee_zcl_ota_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
if (payload_type >= ZBEE_ZCL_OTA_PAYLOAD_TYPE_QJ_MC_IT) {
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
if (payload_type >= ZBEE_ZCL_OTA_PAYLOAD_TYPE_QJ_MC_IT_FV) {
dissect_zcl_ota_file_version_field(tvb, tree, offset);
}
}
static void
dissect_zcl_ota_querynextimagereq(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 field_ctrl;
field_ctrl = dissect_zcl_ota_field_ctrl_field(tvb, tree, offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_ota_file_version_field(tvb, tree, offset);
if (field_ctrl & ZBEE_ZCL_OTA_FIELD_CTRL_HW_VER_PRESENT) {
proto_tree_add_item(tree, hf_zbee_zcl_ota_hw_version, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
}
static void
dissect_zcl_ota_querynextimagersp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 status;
status = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
if (status == ZBEE_ZCL_STAT_SUCCESS) {
proto_tree_add_item(tree, hf_zbee_zcl_ota_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_ota_file_version_field(tvb, tree, offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_size, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
}
static void
dissect_zcl_ota_imageblockreq(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 field_ctrl;
field_ctrl = dissect_zcl_ota_field_ctrl_field(tvb, tree, offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_ota_file_version_field(tvb, tree, offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_file_offset, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
proto_tree_add_item(tree, hf_zbee_zcl_ota_max_data_size, tvb, *offset, 1, ENC_NA);
*offset += 1;
if (field_ctrl & ZBEE_ZCL_OTA_FIELD_CTRL_IEEE_ADDR_PRESENT) {
proto_tree_add_item(tree, hf_zbee_zcl_ota_req_node_addr, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
}
}
static void
dissect_zcl_ota_imagepagereq(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 field_ctrl;
field_ctrl = dissect_zcl_ota_field_ctrl_field(tvb, tree, offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_ota_file_version_field(tvb, tree, offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_file_offset, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
proto_tree_add_item(tree, hf_zbee_zcl_ota_max_data_size, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ota_page_size, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ota_rsp_spacing, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
if (field_ctrl & ZBEE_ZCL_OTA_FIELD_CTRL_IEEE_ADDR_PRESENT) {
proto_tree_add_item(tree, hf_zbee_zcl_ota_req_node_addr, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
}
}
static void
dissect_zcl_ota_imageblockrsp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 status;
guint8 data_size;
status = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
if (status == ZBEE_ZCL_STAT_SUCCESS) {
proto_tree_add_item(tree, hf_zbee_zcl_ota_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_ota_file_version_field(tvb, tree, offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_file_offset, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
data_size = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_data_size, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_data, tvb, *offset, data_size, ENC_NA);
*offset += data_size;
}
else if (status == ZBEE_ZCL_STAT_OTA_WAIT_FOR_DATA) {
proto_tree_add_item(tree, hf_zbee_zcl_ota_current_time, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
proto_tree_add_item(tree, hf_zbee_zcl_ota_request_time, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
else {
}
}
static void
dissect_zcl_ota_upgradeendreq(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ota_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ota_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_ota_file_version_field(tvb, tree, offset);
}
static void
dissect_zcl_ota_upgradeendrsp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ota_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_ota_file_version_field(tvb, tree, offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_current_time, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
proto_tree_add_item(tree, hf_zbee_zcl_ota_upgrade_time, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
static void
dissect_zcl_ota_queryspecfilereq(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ota_req_node_addr, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
proto_tree_add_item(tree, hf_zbee_zcl_ota_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_ota_file_version_field(tvb, tree, offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_zb_stack_ver, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_ota_queryspecfilersp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 status;
status = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
if (status == ZBEE_ZCL_STAT_SUCCESS) {
proto_tree_add_item(tree, hf_zbee_zcl_ota_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_ota_file_version_field(tvb, tree, offset);
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_size, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
}
static void
dissect_zcl_ota_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id )
{
case ZBEE_ZCL_ATTR_ID_OTA_CURRENT_FILE_VERSION:
case ZBEE_ZCL_ATTR_ID_OTA_DOWNLOADED_FILE_VERSION:
dissect_zcl_ota_file_version_field(tvb, tree, offset);
break;
case ZBEE_ZCL_ATTR_ID_OTA_CURRENT_ZB_STACK_VERSION:
case ZBEE_ZCL_ATTR_ID_OTA_DOWNLOADED_ZB_STACK_VERSION:
proto_tree_add_item(tree, hf_zbee_zcl_ota_zb_stack_ver, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_OTA_IMAGE_UPGRADE_STATUS:
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_upgrade_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_OTA_MANUFACTURER_ID:
proto_tree_add_item(tree, hf_zbee_zcl_ota_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_OTA_IMAGE_TYPE_ID:
proto_tree_add_item(tree, hf_zbee_zcl_ota_image_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_OTA_MIN_BLOCK_REQ_DELAY:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static int
dissect_zbee_zcl_ota(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_ota_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_ota_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_ota, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_OTA_QUERY_NEXT_IMAGE_REQ:
dissect_zcl_ota_querynextimagereq(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_OTA_IMAGE_BLOCK_REQ:
dissect_zcl_ota_imageblockreq(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_OTA_IMAGE_PAGE_REQ:
dissect_zcl_ota_imagepagereq(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_OTA_UPGRADE_END_REQ:
dissect_zcl_ota_upgradeendreq(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_OTA_QUERY_SPEC_FILE_REQ:
dissect_zcl_ota_queryspecfilereq(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_ota_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_ota_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_ota, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_OTA_IMAGE_NOTIFY:
dissect_zcl_ota_imagenotify(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_OTA_QUERY_NEXT_IMAGE_RSP:
dissect_zcl_ota_querynextimagersp(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_OTA_IMAGE_BLOCK_RSP:
dissect_zcl_ota_imageblockrsp(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_OTA_UPGRADE_END_RSP:
dissect_zcl_ota_upgradeendrsp(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_OTA_QUERY_SPEC_FILE_RSP:
dissect_zcl_ota_queryspecfilersp(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
void proto_register_zbee_zcl_ota(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_ota_attr_id,
{ "Attribute", "zbee_zcl_general.ota.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_ota_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_srv_tx_cmd_id,
{ "Command", "zbee_zcl_general.ota.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ota_srv_tx_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.ota.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ota_srv_rx_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_image_upgrade_status,
{ "Image Upgrade Status", "zbee_zcl_general.ota.status_attr", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ota_image_upgrade_attr_status_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_zb_stack_ver,
{ "ZigBee Stack Version", "zbee_zcl_general.ota.zb_stack.ver", FT_UINT16, BASE_HEX | BASE_RANGE_STRING,
RVALS(zbee_zcl_ota_zb_stack_ver_names), 0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_payload_type,
{ "Payload Type", "zbee_zcl_general.ota.payload.type", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ota_paylaod_type_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_query_jitter,
{ "Query Jitter", "zbee_zcl_general.ota.query_jitter", FT_UINT8, BASE_CUSTOM, CF_FUNC(decode_zcl_time_in_seconds),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_manufacturer_code,
{ "Manufacturer Code", "zbee_zcl_general.ota.manufacturer_code", FT_UINT16, BASE_HEX, VALS(zbee_mfr_code_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_image_type,
{ "Image Type", "zbee_zcl_general.ota.image.type", FT_UINT16, BASE_HEX | BASE_RANGE_STRING,
RVALS(zbee_zcl_ota_image_type_names), 0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_file_version,
{ "File Version", "zbee_zcl_general.ota.file.version", FT_UINT32, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_file_version_appl_release,
{ "Application Release", "zbee_zcl_general.ota.file.version.appl.release", FT_UINT32, BASE_DEC, NULL,
ZBEE_ZCL_OTA_FILE_VERS_APPL_RELEASE, NULL, HFILL } },
{ &hf_zbee_zcl_ota_file_version_appl_build,
{ "Application Build", "zbee_zcl_general.ota.file.version.appl.build", FT_UINT32, BASE_DEC, NULL,
ZBEE_ZCL_OTA_FILE_VERS_APPL_BUILD, NULL, HFILL } },
{ &hf_zbee_zcl_ota_file_version_stack_release,
{ "Stack Release", "zbee_zcl_general.ota.file.version.stack.release", FT_UINT32, BASE_DEC, NULL,
ZBEE_ZCL_OTA_FILE_VERS_STACK_RELEASE, NULL, HFILL } },
{ &hf_zbee_zcl_ota_file_version_stack_build,
{ "Stack Build", "zbee_zcl_general.ota.file.version.stack.build", FT_UINT32, BASE_DEC, NULL,
ZBEE_ZCL_OTA_FILE_VERS_STACK_BUILD, NULL, HFILL } },
{ &hf_zbee_zcl_ota_field_ctrl,
{ "Field Control", "zbee_zcl_general.ota.field_ctrl",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_field_ctrl_hw_ver_present,
{ "Hardware Version", "zbee_zcl_general.ota.field_ctrl_hw_ver_present",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), ZBEE_ZCL_OTA_FIELD_CTRL_HW_VER_PRESENT, NULL, HFILL } },
{ &hf_zbee_zcl_ota_field_ctrl_reserved,
{ "Reserved", "zbee_zcl_general.ota.field_ctrl_reserved", FT_UINT8, BASE_HEX, NULL,
ZBEE_ZCL_OTA_FIELD_CTRL_RESERVED, NULL, HFILL } },
{ &hf_zbee_zcl_ota_hw_version,
{ "Hardware Version", "zbee_zcl_general.ota.hw_ver", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_status,
{ "Status", "zbee_zcl_general.ota.status", FT_UINT8, BASE_HEX, VALS(zbee_zcl_status_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_image_size,
{ "Image Size", "zbee_zcl_general.ota.image.size", FT_UINT32, BASE_CUSTOM, CF_FUNC(decode_zcl_ota_size_in_bytes),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_file_offset,
{ "File Offset", "zbee_zcl_general.ota.file.offset", FT_UINT32, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_max_data_size,
{ "Max Data Size", "zbee_zcl_general.ota.max_data_size", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_req_node_addr,
{ "Ieee Address", "zbee_zcl_general.ota.ieee_addr", FT_UINT64, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_page_size,
{ "Page Size", "zbee_zcl_general.ota.page.size", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_zcl_ota_size_in_bytes),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_rsp_spacing,
{ "Response Spacing", "zbee_zcl_general.ota.rsp_spacing", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_current_time,
{ "Current Time", "zbee_zcl_general.ota.current_time", FT_UINT32, BASE_CUSTOM, CF_FUNC(decode_zcl_ota_curr_time),
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ota_request_time,
{ "Request Time", "zbee_zcl_general.ota.request_time", FT_UINT32, BASE_CUSTOM, CF_FUNC(decode_zcl_ota_req_time),
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ota_upgrade_time,
{ "Upgrade Time", "zbee_zcl_general.ota.upgrade_time", FT_UINT32, BASE_CUSTOM, CF_FUNC(decode_zcl_ota_upgr_time),
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ota_data_size,
{ "Data Size", "zbee_zcl_general.ota.data_size", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ota_image_data,
{ "Image Data", "zbee_zcl_general.ota.image.data", FT_BYTES, SEP_COLON, NULL,
0x00, NULL, HFILL } }
};
gint *ett[ZBEE_ZCL_OTA_NUM_ETT];
ett[0] = &ett_zbee_zcl_ota;
ett[1] = &ett_zbee_zcl_ota_field_ctrl;
ett[2] = &ett_zbee_zcl_ota_file_version;
proto_zbee_zcl_ota = proto_register_protocol("ZigBee ZCL OTA", "ZCL OTA", ZBEE_PROTOABBREV_ZCL_OTA);
proto_register_field_array(proto_zbee_zcl_ota, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_OTA, dissect_zbee_zcl_ota, proto_zbee_zcl_ota);
}
void proto_reg_handoff_zbee_zcl_ota(void)
{
dissector_handle_t ota_handle;
ota_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_OTA);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_OTA_UPGRADE, ota_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_ota,
ett_zbee_zcl_ota,
ZBEE_ZCL_CID_OTA_UPGRADE,
hf_zbee_zcl_ota_attr_id,
hf_zbee_zcl_ota_srv_rx_cmd_id,
hf_zbee_zcl_ota_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_ota_attr_data
);
}
static int
dissect_zbee_zcl_pwr_prof (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_pwr_prof_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_pwr_prof, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_PWR_PROF_PWR_PROF_REQ:
case ZBEE_ZCL_CMD_ID_PWR_PROF_PWR_PROF_SCHED_CONSTRS_REQ:
case ZBEE_ZCL_CMD_ID_PWR_PROF_ENERGY_PHASES_SCHED_STATE_REQ:
dissect_zcl_pwr_prof_pwrprofreq(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_PWR_PROF_PWR_PROF_STATE_REQ:
break;
case ZBEE_ZCL_CMD_ID_PWR_PROF_GET_PWR_PROF_PRICE_RSP:
case ZBEE_ZCL_CMD_ID_PWR_PROF_GET_PWR_PROF_PRICE_EXT_RSP:
dissect_zcl_pwr_prof_getpwrprofpricersp(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_PWR_PROF_GET_OVERALL_SCHED_PRICE_RSP:
dissect_zcl_pwr_prof_getoverallschedpricersp(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_PWR_PROF_ENERGY_PHASES_SCHED_NOTIF:
case ZBEE_ZCL_CMD_ID_PWR_PROF_ENERGY_PHASES_SCHED_RSP:
dissect_zcl_pwr_prof_enphsschednotif(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_pwr_prof_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_pwr_prof, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_PWR_PROF_PWR_PROF_NOTIF:
case ZBEE_ZCL_CMD_ID_PWR_PROF_PWR_PROF_RSP:
dissect_zcl_pwr_prof_pwrprofnotif(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_PWR_PROF_PWR_PROF_STATE_RSP:
case ZBEE_ZCL_CMD_ID_PWR_PROF_PWR_PROF_STATE_NOTIF:
dissect_zcl_pwr_prof_pwrprofstatersp(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_PWR_PROF_GET_OVERALL_SCHED_PRICE:
break;
case ZBEE_ZCL_CMD_ID_PWR_PROF_ENERGY_PHASES_SCHED_STATE_RSP:
case ZBEE_ZCL_CMD_ID_PWR_PROF_ENERGY_PHASES_SCHED_STATE_NOITIF:
dissect_zcl_pwr_prof_enphsschednotif(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_PWR_PROF_GET_PWR_PROF_PRICE:
case ZBEE_ZCL_CMD_ID_PWR_PROF_ENERGY_PHASES_SCHED_REQ:
dissect_zcl_pwr_prof_pwrprofreq(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_PWR_PROF_PWR_PROF_SCHED_CONSTRS_NOTIF:
case ZBEE_ZCL_CMD_ID_PWR_PROF_PWR_PROF_SCHED_CONSTRS_RSP:
dissect_zcl_pwr_prof_pwrprofschedcontrsnotif(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_PWR_PROF_GET_PWR_PROF_PRICE_EXT:
dissect_zcl_pwr_prof_pwrprofpriceext(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_pwr_prof_pwrprofreq(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
}
static void
dissect_zcl_pwr_prof_getpwrprofpricersp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_currency, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_price, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_price_trailing_digit, tvb, *offset, 1, ENC_NA);
*offset += 1;
}
static void
dissect_zcl_pwr_prof_getoverallschedpricersp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_currency, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_price, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_price_trailing_digit, tvb, *offset, 1, ENC_NA);
*offset += 1;
}
static void
dissect_zcl_sched_energy_phase(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_energy_phase_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_scheduled_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_pwr_prof_enphsschednotif(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree *sub_tree = NULL;
guint i;
guint8 num_of_sched_phases;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
num_of_sched_phases = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_num_of_sched_phases, tvb, *offset, 1, ENC_NA);
*offset += 1;
for (i=0 ; (i<num_of_sched_phases && i < ZBEE_ZCL_PWR_PROF_NUM_EN_PHS_ETT); i++) {
sub_tree = proto_tree_add_subtree_format(tree, tvb, *offset, 1,
ett_zbee_zcl_pwr_prof_enphases[i], NULL, "Energy Phase #%u", i);
dissect_zcl_sched_energy_phase(tvb, sub_tree, offset);
}
}
static void
dissect_zcl_energy_phase(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_energy_phase_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_macro_phase_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_expect_duration, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_peak_power, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_energy, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_max_active_delay, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_pwr_prof_pwrprofnotif(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree *sub_tree = NULL;
guint i;
guint8 total_profile_number;
guint8 num_of_transferred_phases;
total_profile_number = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_tot_prof_num, tvb, *offset, 1, ENC_NA);
*offset += 1;
if ( total_profile_number != 0 ) {
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
num_of_transferred_phases = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_num_of_trans_phases, tvb, *offset, 1, ENC_NA);
*offset += 1;
for ( i=0 ; (i<num_of_transferred_phases && i < ZBEE_ZCL_PWR_PROF_NUM_EN_PHS_ETT); i++) {
sub_tree = proto_tree_add_subtree_format(tree, tvb, *offset, 1,
ett_zbee_zcl_pwr_prof_enphases[i], NULL, "Energy Phase #%u", i);
dissect_zcl_energy_phase(tvb, sub_tree, offset);
}
}
}
static void
dissect_zcl_power_profile(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_energy_phase_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_rem_ctrl, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_state, tvb, *offset, 1, ENC_NA);
*offset += 1;
}
static void
dissect_zcl_pwr_prof_pwrprofstatersp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree *sub_tree = NULL;
guint i;
guint8 power_profile_count;
power_profile_count = MIN(tvb_get_guint8(tvb, *offset), ZBEE_ZCL_PWR_PROF_NUM_PWR_PROF_ETT);
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_count, tvb, *offset, 1, ENC_NA);
*offset += 1;
for (i=0 ; i<power_profile_count ; i++) {
sub_tree = proto_tree_add_subtree_format(tree, tvb, *offset, 1,
ett_zbee_zcl_pwr_prof_pwrprofiles[i], NULL, "Power Profile #%u", i);
dissect_zcl_power_profile(tvb, sub_tree, offset);
}
}
static void
dissect_zcl_pwr_prof_pwrprofschedcontrsnotif(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_start_after, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_stop_before, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_pwr_prof_pwrprofpriceext(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
static const int * options[] = {
&hf_zbee_zcl_pwr_prof_options_01,
&hf_zbee_zcl_pwr_prof_options_res,
NULL
};
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_pwr_prof_options, ett_zbee_zcl_pwr_prof_options, options, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_stime, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_pwr_prof_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int * format_fields[] = {
&hf_zbee_zcl_pwr_prof_energy_format_rdigit,
&hf_zbee_zcl_pwr_prof_energy_format_ldigit,
&hf_zbee_zcl_pwr_prof_energy_format_noleadingzero,
NULL
};
static const int * modes[] = {
&hf_zbee_zcl_pwr_prof_sched_mode_cheapest,
&hf_zbee_zcl_pwr_prof_sched_mode_greenest,
&hf_zbee_zcl_pwr_prof_sched_mode_reserved,
NULL
};
switch ( attr_id )
{
case ZBEE_ZCL_ATTR_ID_PWR_PROF_TOT_PROF_NUM:
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_tot_prof_num, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_PWR_PROF_MULTIPLE_SCHED:
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_multiple_sched, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_PWR_PROF_ENERGY_FORMAT:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_pwr_prof_energy_format, ett_zbee_zcl_pwr_prof_en_format, format_fields, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_PWR_PROF_ENERGY_REMOTE:
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_energy_remote, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_PWR_PROF_SCHED_MODE:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_pwr_prof_sched_mode, ett_zbee_zcl_pwr_prof_sched_mode, modes, ENC_NA);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static void
decode_power_profile_id(gchar *s, guint8 id)
{
if (id == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%d (All)", id);
}
else {
g_snprintf(s, ITEM_LABEL_LENGTH, "%d", id);
}
}
static void
decode_price_in_cents(gchar *s, guint32 value)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d cents", value);
}
static void
decode_power_in_watt(gchar *s, guint16 value)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d Watt", value);
}
static void
decode_energy(gchar *s, guint16 value)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d Watt per hours", value);
}
static void
func_decode_delayinminute(gchar *s, guint16 value)
{
if (value == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%d minutes (Not permitted)", value);
}
else {
g_snprintf(s, ITEM_LABEL_LENGTH, "%d minutes", value);
}
}
void
proto_register_zbee_zcl_pwr_prof(void)
{
guint i, j;
static hf_register_info hf[] = {
{ &hf_zbee_zcl_pwr_prof_tot_prof_num,
{ "Total Profile Number", "zbee_zcl_general.pwrprof.attr.totprofnum", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_multiple_sched,
{ "Multiple Scheduling", "zbee_zcl_general.pwrprof.attr.multiplesched", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_supported_not_supported), 0x0, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_energy_format,
{ "Data", "zbee_zcl_general.pwrprof.attr.energyformat",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_energy_format_rdigit,
{ "Number of Digits to the right of the Decimal Point", "zbee_zcl_general.pwrprof.attr.energyformat.rdigit",
FT_UINT8, BASE_DEC, NULL, ZBEE_ZCL_OPT_PWRPROF_NUM_R_DIGIT, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_energy_format_ldigit,
{ "Number of Digits to the left of the Decimal Point", "zbee_zcl_general.pwrprof.attr.energyformat.ldigit",
FT_UINT8, BASE_DEC, NULL, ZBEE_ZCL_OPT_PWRPROF_NUM_L_DIGIT, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_energy_format_noleadingzero,
{ "Suppress leading zeros.", "zbee_zcl_general.pwrprof.attr.energyformat.noleadingzero",
FT_BOOLEAN, 8, TFS(&tfs_true_false), ZBEE_ZCL_OPT_PWRPROF_NO_LEADING_ZERO, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_energy_remote,
{ "Energy Remote", "zbee_zcl_general.pwrprof.attr.energyremote", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_enabled_disabled), 0x0, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_sched_mode,
{ "Schedule Mode", "zbee_zcl_general.pwrprof.attr.schedmode",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_sched_mode_cheapest,
{ "Schedule Mode Cheapest", "zbee_zcl_general.pwrprof.attr.schedmode.cheapest",
FT_BOOLEAN, 8, TFS(&tfs_active_inactive), ZBEE_ZCL_OPT_PWRPROF_SCHED_CHEAPEST, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_sched_mode_greenest,
{ "Schedule Mode Greenest", "zbee_zcl_general.pwrprof.attr.schedmode.greenest",
FT_BOOLEAN, 8, TFS(&tfs_active_inactive), ZBEE_ZCL_OPT_PWRPROF_SCHED_GREENEST, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_sched_mode_reserved,
{ "Schedule Mode Reserved", "zbee_zcl_general.pwrprof.attr.schedmode.reserved",
FT_UINT8, BASE_HEX, NULL, ZBEE_ZCL_OPT_PWRPROF_SCHED_RESERVED, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_attr_id,
{ "Attribute", "zbee_zcl_general.pwrprof.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_pwr_prof_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_srv_tx_cmd_id,
{ "Command", "zbee_zcl_general.pwrprof.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_pwr_prof_srv_tx_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.pwrprof.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_pwr_prof_srv_rx_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_pwr_prof_id,
{ "Power Profile ID", "zbee_zcl_general.pwrprof.pwrprofid", FT_UINT8, BASE_CUSTOM, CF_FUNC(decode_power_profile_id), 0x00,
"Identifier of the specific profile", HFILL } },
{ &hf_zbee_zcl_pwr_prof_currency,
{ "Currency", "zbee_zcl_general.pwrprof.currency", FT_UINT16, BASE_HEX, VALS(zbee_zcl_currecy_names), 0x0,
"Local unit of currency (ISO 4217) used in the price field.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_price,
{ "Price", "zbee_zcl_general.pwrprof.price", FT_UINT32, BASE_CUSTOM, CF_FUNC(decode_price_in_cents), 0x0,
"Price of the energy of a specific Power Profile.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_price_trailing_digit,
{ "Price Trailing Digit", "zbee_zcl_general.pwrprof.pricetrailingdigit", FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of digits to the right of the decimal point.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_num_of_sched_phases,
{ "Number of Scheduled Phases", "zbee_zcl_general.pwrprof.numofschedphases", FT_UINT8, BASE_DEC, NULL, 0x0,
"Total number of the energy phases of the Power Profile that need to be scheduled.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_energy_phase_id,
{ "Energy Phase ID", "zbee_zcl_general.pwrprof.energyphaseid", FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifier of the specific phase.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_scheduled_time,
{ "Scheduled Time", "zbee_zcl_general.pwrprof.scheduledtime", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_zcl_time_in_minutes), 0x0,
NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_macro_phase_id,
{ "Macro Phase ID", "zbee_zcl_general.pwrprof.macrophaseid", FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifier of the specific energy phase.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_expect_duration,
{ "Expected Duration", "zbee_zcl_general.pwrprof.expecduration", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_zcl_time_in_minutes), 0x0,
"The estimated duration of the specific phase.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_num_of_trans_phases,
{ "Number of Transferred Phases", "zbee_zcl_general.pwrprof.numoftransphases", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_peak_power,
{ "Peak Power", "zbee_zcl_general.pwrprof.peakpower", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_power_in_watt), 0x0,
"The estimated power for the specific phase.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_energy,
{ "Energy", "zbee_zcl_general.pwrprof.energy", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_energy), 0x0,
"The estimated energy consumption for the accounted phase.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_max_active_delay,
{ "Max Activation Delay", "zbee_zcl_general.pwrprof.maxactivdelay", FT_UINT16, BASE_CUSTOM, CF_FUNC(func_decode_delayinminute), 0x0,
"The maximum interruption time between the end of the previous phase and the beginning of the specific phase.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_pwr_prof_count,
{ "Power Profile Count", "zbee_zcl_general.pwrprof.pwrprofcount", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_pwr_prof_rem_ctrl,
{ "Power Profile Remote Control", "zbee_zcl_general.pwrprof.pwrprofremctrl", FT_BOOLEAN, BASE_NONE, TFS(&tfs_enabled_disabled), 0x00,
"It indicates if the PowerProfile is currently remotely controllable or not.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_pwr_prof_state,
{ "Power Profile State", "zbee_zcl_general.pwrprof.pwrprofstate", FT_UINT8, BASE_HEX, VALS(zbee_zcl_pwr_prof_state_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_start_after,
{ "Start After", "zbee_zcl_general.pwrprof.startafter", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_zcl_time_in_minutes), 0x0,
NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_stop_before,
{ "Stop Before", "zbee_zcl_general.pwrprof.stopbefore", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_zcl_time_in_minutes), 0x0,
NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_options,
{ "Options", "zbee_zcl_general.pwrprof.options", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_options_01,
{ "PowerProfileStartTime Field Present", "zbee_zcl_general.pwrprof.options.01", FT_BOOLEAN, 8, TFS(&tfs_true_false),
ZBEE_ZCL_OPT_PWRPROF_STIME_PRESENT, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_options_res,
{ "Reserved", "zbee_zcl_general.pwrprof.options.reserved", FT_UINT8, BASE_HEX, NULL,
ZBEE_ZCL_OPT_PWRPROF_RESERVED, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_pwr_prof_stime,
{ "Power Profile Start Time", "zbee_zcl_general.pwrprof.pwrprofstime", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_zcl_time_in_minutes), 0x0,
NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_PWR_PROF_NUM_ETT];
ett[0] = &ett_zbee_zcl_pwr_prof;
ett[1] = &ett_zbee_zcl_pwr_prof_options;
ett[2] = &ett_zbee_zcl_pwr_prof_en_format;
ett[3] = &ett_zbee_zcl_pwr_prof_sched_mode;
for ( i = 0, j = ZBEE_ZCL_PWR_PROF_NUM_GENERIC_ETT; i < ZBEE_ZCL_PWR_PROF_NUM_PWR_PROF_ETT; i++, j++ ) {
ett_zbee_zcl_pwr_prof_pwrprofiles[i] = -1;
ett[j] = &ett_zbee_zcl_pwr_prof_pwrprofiles[i];
}
for ( i = 0; i < ZBEE_ZCL_PWR_PROF_NUM_EN_PHS_ETT; i++, j++ ) {
ett_zbee_zcl_pwr_prof_enphases[i] = -1;
ett[j] = &ett_zbee_zcl_pwr_prof_enphases[i];
}
proto_zbee_zcl_pwr_prof = proto_register_protocol("ZigBee ZCL Power Profile", "ZCL Power Profile", ZBEE_PROTOABBREV_ZCL_PWRPROF);
proto_register_field_array(proto_zbee_zcl_pwr_prof, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_PWRPROF, dissect_zbee_zcl_pwr_prof, proto_zbee_zcl_pwr_prof);
}
void
proto_reg_handoff_zbee_zcl_pwr_prof(void)
{
dissector_handle_t pwr_prof_handle;
pwr_prof_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_PWRPROF);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_POWER_PROFILE, pwr_prof_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_pwr_prof,
ett_zbee_zcl_pwr_prof,
ZBEE_ZCL_CID_POWER_PROFILE,
hf_zbee_zcl_pwr_prof_attr_id,
hf_zbee_zcl_pwr_prof_srv_rx_cmd_id,
hf_zbee_zcl_pwr_prof_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_pwr_prof_attr_data
);
}
static int
dissect_zbee_zcl_appl_ctrl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_appl_ctrl_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_appl_ctrl, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_APPL_CTRL_EXECUTION_CMD:
dissect_zcl_appl_ctrl_exec_cmd(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_APPL_CTRL_SIGNAL_STATE:
case ZBEE_ZCL_CMD_ID_APPL_CTRL_OVERLOAD_PAUSE_RESUME:
case ZBEE_ZCL_CMD_ID_APPL_CTRL_OVERLOAD_PAUSE:
break;
case ZBEE_ZCL_CMD_ID_APPL_CTRL_WRITE_FUNCS:
dissect_zcl_appl_ctrl_wr_funcs(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_APPL_CTRL_OVERLOAD_WARNING:
dissect_zcl_appl_ctrl_ovrl_warning(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_appl_ctrl_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_appl_ctrl, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_APPL_CTRL_SIGNAL_STATE_RSP:
case ZBEE_ZCL_CMD_ID_APPL_CTRL_SIGNAL_STATE_NOTIF:
dissect_zcl_appl_ctrl_signal_state_rsp(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_appl_ctrl_exec_cmd(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_exec_cmd_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
}
static void
dissect_zcl_appl_ctrl_attr_func(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 func_data_type;
guint16 func_id;
func_id = tvb_get_letohs(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_attr_func_id, tvb, *offset, 2,ENC_LITTLE_ENDIAN);
*offset += 2;
proto_item_append_text(tree, ", %s",
val_to_str_ext_const(func_id, &zbee_zcl_appl_ctrl_attr_names_ext, "Reserved"));
func_data_type = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_attr_func_data_type, tvb, *offset, 1, ENC_NA);
*offset += 1;
dissect_zcl_appl_ctrl_attr_data(tree, tvb, offset, func_id, func_data_type);
}
static void
dissect_zcl_appl_ctrl_wr_funcs(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree *sub_tree = NULL;
guint tvb_len;
guint i = 0;
tvb_len = tvb_reported_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_APPL_CTRL_NUM_FUNC_ETT ) {
sub_tree = proto_tree_add_subtree_format(tree, tvb, *offset, 0,
ett_zbee_zcl_appl_ctrl_func[i], NULL, "Function #%d", i);
i++;
dissect_zcl_appl_ctrl_attr_func(tvb, sub_tree, offset);
}
}
static void
dissect_zcl_appl_ctrl_ovrl_warning(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_warning_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
}
static void
dissect_zcl_appl_ctrl_signal_state_rsp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
static const int * flags[] = {
&hf_zbee_zcl_appl_ctrl_rem_en_flags,
&hf_zbee_zcl_appl_ctrl_status2,
NULL
};
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_appl_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_appl_ctrl_rem_en_flags_raw, ett_zbee_zcl_appl_ctrl_flags, flags, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_status2_array, tvb, *offset, 3, ENC_BIG_ENDIAN);
}
static void
dissect_zcl_appl_ctrl_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int * flags[] = {
&hf_zbee_zcl_appl_ctrl_time_mm,
&hf_zbee_zcl_appl_ctrl_time_encoding_type,
&hf_zbee_zcl_appl_ctrl_time_hh,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_APPL_CTRL_START_TIME:
case ZBEE_ZCL_ATTR_ID_APPL_CTRL_FINISH_TIME:
case ZBEE_ZCL_ATTR_ID_APPL_CTRL_REMAINING_TIME:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_appl_ctrl_time, ett_zbee_zcl_appl_ctrl_time, flags, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_appl_ctrl(void)
{
guint i, j;
static hf_register_info hf[] = {
{ &hf_zbee_zcl_appl_ctrl_attr_id,
{ "Attribute", "zbee_zcl_general.applctrl.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_appl_ctrl_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_time,
{ "Data", "zbee_zcl_general.applctrl.time", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_time_mm,
{ "Minutes", "zbee_zcl_general.applctrl.time.mm", FT_UINT16, BASE_DEC, NULL, ZBEE_ZCL_APPL_CTRL_TIME_MM,
NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_time_encoding_type,
{ "Encoding Type", "zbee_zcl_general.applctrl.time.encoding_type", FT_UINT16, BASE_HEX, VALS(zbee_zcl_appl_ctrl_time_encoding_type_names),
ZBEE_ZCL_APPL_CTRL_TIME_ENCOD_TYPE, NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_time_hh,
{ "Hours", "zbee_zcl_general.applctrl.time.hh", FT_UINT16, BASE_DEC, NULL, ZBEE_ZCL_APPL_CTRL_TIME_HH,
NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_srv_tx_cmd_id,
{ "Command", "zbee_zcl_general.applctrl.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_ctrl_srv_tx_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.applctrl.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_ctrl_srv_rx_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_appl_status,
{ "Appliance Status", "zbee_zcl_general.applctrl.status", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_ctrl_appl_status_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_rem_en_flags_raw,
{ "Remote Enable Flags", "zbee_zcl_general.applctrl.remote_enable_flags", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_rem_en_flags,
{ "Remote Enable Flags", "zbee_zcl_general.applctrl.remenflags", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_ctrl_rem_flags_names),
ZBEE_ZCL_APPL_CTRL_REM_EN_FLAGS_FLAGS, NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_status2,
{ "Appliance Status 2", "zbee_zcl_general.applctrl.status2", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_ctrl_status2_names),
ZBEE_ZCL_APPL_CTRL_REM_EN_FLAGS_STATUS2, NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_status2_array,
{ "Appliance Status 2", "zbee_zcl_general.applctrl.status2.array", FT_UINT24, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_exec_cmd_id,
{ "Command", "zbee_zcl_general.applctrl.execcmd.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_ctrl_exec_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_attr_func_id,
{ "ID", "zbee_zcl_general.applctrl.attr_func.id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_appl_ctrl_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_attr_func_data_type,
{ "Data Type", "zbee_zcl_general.applctrl.attr_func.datatype", FT_UINT8, BASE_HEX, VALS(zbee_zcl_short_data_type_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_ctrl_warning_id,
{ "Warning", "zbee_zcl_general.applctrl.ovrlwarning.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_ctrl_ovrl_warning_names),
0x0, NULL, HFILL } }
};
gint *ett[ZBEE_ZCL_APPL_CTRL_NUM_ETT];
ett[0] = &ett_zbee_zcl_appl_ctrl;
ett[1] = &ett_zbee_zcl_appl_ctrl_flags;
ett[2] = &ett_zbee_zcl_appl_ctrl_time;
for ( i = 0, j = ZBEE_ZCL_APPL_CTRL_NUM_GENERIC_ETT; i < ZBEE_ZCL_APPL_CTRL_NUM_FUNC_ETT; i++, j++) {
ett_zbee_zcl_appl_ctrl_func[i] = -1;
ett[j] = &ett_zbee_zcl_appl_ctrl_func[i];
}
proto_zbee_zcl_appl_ctrl = proto_register_protocol("ZigBee ZCL Appliance Control", "ZCL Appliance Control", ZBEE_PROTOABBREV_ZCL_APPLCTRL);
proto_register_field_array(proto_zbee_zcl_appl_ctrl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_APPLCTRL, dissect_zbee_zcl_appl_ctrl, proto_zbee_zcl_appl_ctrl);
}
void
proto_reg_handoff_zbee_zcl_appl_ctrl(void)
{
dissector_handle_t appl_ctrl_handle;
appl_ctrl_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_APPLCTRL);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_APPLIANCE_CONTROL, appl_ctrl_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_appl_ctrl,
ett_zbee_zcl_appl_ctrl,
ZBEE_ZCL_CID_APPLIANCE_CONTROL,
hf_zbee_zcl_appl_ctrl_attr_id,
hf_zbee_zcl_appl_ctrl_srv_rx_cmd_id,
hf_zbee_zcl_appl_ctrl_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_appl_ctrl_attr_data
);
}
static int
dissect_zbee_zcl_poll_ctrl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_poll_ctrl_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_poll_ctrl_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
offset++;
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_POLL_CTRL_CHECK_IN_RESPONSE:
proto_tree_add_item(tree, hf_zbee_zcl_poll_ctrl_start_fast_polling, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_zbee_zcl_poll_ctrl_fast_poll_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case ZBEE_ZCL_CMD_ID_POLL_CTRL_FAST_POLL_STOP:
break;
case ZBEE_ZCL_CMD_ID_POLL_CTRL_SET_LONG_POLL:
proto_tree_add_item(tree, hf_zbee_zcl_poll_ctrl_new_long_poll_interval, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case ZBEE_ZCL_CMD_ID_POLL_CTRL_SET_SHORT_POLL:
proto_tree_add_item(tree, hf_zbee_zcl_poll_ctrl_new_short_poll_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
default:
break;
}
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_poll_ctrl_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_poll_ctrl_srv_tx_cmd_id, tvb, offset, 1, ENC_NA);
offset++;
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_POLL_CTRL_CHECK_IN:
default:
break;
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_poll_ctrl_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id _U_, guint data_type)
{
dissect_zcl_attr_data(tvb, tree, offset, data_type);
}
void
proto_register_zbee_zcl_poll_ctrl(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_poll_ctrl_attr_id,
{ "Attribute", "zbee_zcl_general.poll.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_poll_ctrl_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_poll_ctrl_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.poll.cmd.srv_rx.id", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_poll_ctrl_srv_rx_cmd_names), 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_poll_ctrl_srv_tx_cmd_id,
{ "Command", "zbee_zcl_general.poll.cmd.srv_tx.id", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_poll_ctrl_srv_tx_cmd_names), 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_poll_ctrl_start_fast_polling,
{ "Start Fast Polling", "zbee_zcl_general.poll.start", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_poll_ctrl_fast_poll_timeout,
{ "Fast Poll Timeout (quarterseconds)", "zbee_zcl_general.poll.fast_timeout", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_poll_ctrl_new_long_poll_interval,
{ "New Long Poll Interval", "zbee_zcl_general.poll.new_long_interval", FT_UINT32, BASE_DEC, NULL, 0x0, NULL,
HFILL }},
{ &hf_zbee_zcl_poll_ctrl_new_short_poll_interval,
{ "New Short Poll Interval", "zbee_zcl_general.poll.new_short_interval", FT_UINT16, BASE_DEC, NULL, 0x0, NULL,
HFILL }}
};
static gint *ett[ZBEE_ZCL_POLL_CTRL_NUM_ETT];
ett[0] = &ett_zbee_zcl_poll_ctrl;
proto_zbee_zcl_poll_ctrl = proto_register_protocol("ZigBee ZCL Poll Control", "ZCL Poll Control", ZBEE_PROTOABBREV_ZCL_POLL);
proto_register_field_array(proto_zbee_zcl_poll_ctrl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_POLL, dissect_zbee_zcl_poll_ctrl, proto_zbee_zcl_poll_ctrl);
}
void
proto_reg_handoff_zbee_zcl_poll_ctrl(void)
{
dissector_handle_t poll_handle;
poll_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_POLL);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_POLL_CONTROL, poll_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_poll_ctrl,
ett_zbee_zcl_poll_ctrl,
ZBEE_ZCL_CID_POLL_CONTROL,
hf_zbee_zcl_poll_ctrl_attr_id,
hf_zbee_zcl_poll_ctrl_srv_rx_cmd_id,
hf_zbee_zcl_poll_ctrl_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_poll_ctrl_attr_data
);
}
static int
dissect_zbee_zcl_gp_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint payload_size;
proto_tree_add_item(tree, hf_zbee_gp_gpd_command_id, tvb, offset, 1, ENC_NA);
offset += 1;
payload_size = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_zbee_gp_gpd_payload_size, tvb, offset, 1, ENC_NA);
offset += 1;
if (payload_size != 0 && payload_size != 0xff) {
tvbuff_t *gtvb = tvb_new_composite();
gboolean writable = col_get_writable(pinfo->cinfo, COL_INFO);
tvb_composite_append(gtvb, tvb_new_subset_length(tvb, offset-2, 1));
tvb_composite_append(gtvb, tvb_new_subset_length(tvb, offset, payload_size));
tvb_composite_finalize(gtvb);
col_set_writable(pinfo->cinfo, COL_INFO, FALSE);
call_dissector_only(zgp_handle, gtvb, pinfo, tree, NULL);
col_set_writable(pinfo->cinfo, COL_INFO, writable);
offset += payload_size;
}
return offset;
}
static int
dissect_zbee_zcl_gp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
static const int * gpp_gpd_link[] = {
&hf_zbee_gpp_gpd_link_rssi,
&hf_zbee_gpp_gpd_link_lqi,
NULL
};
zbee_zcl_packet *zcl;
volatile guint offset = 0;
guint8 cmd_id;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_gp_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_gp_srv_rx_cmd_id, tvb, offset, 1, ENC_NA);
offset++;
switch (cmd_id) {
case ZBEE_CMD_ID_GP_NOTIFICATION:
{
static const int * n_options[] = {
&hf_zbee_gp_cmd_notif_opt_app_id,
&hf_zbee_gp_cmd_notif_opt_also_unicast,
&hf_zbee_gp_cmd_notif_opt_also_derived_group,
&hf_zbee_gp_cmd_notif_opt_also_comm_group,
&hf_zbee_gp_cmd_notif_opt_secur_level,
&hf_zbee_gp_cmd_notif_opt_secur_key_type,
&hf_zbee_gp_cmd_notif_opt_rx_after_tx,
&hf_zbee_gp_cmd_notif_opt_tx_q_full,
&hf_zbee_gp_cmd_notif_opt_bidir_cap,
&hf_zbee_gp_cmd_notif_opt_proxy_info_present,
NULL
};
guint16 options = tvb_get_guint16(tvb, offset, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_cmd_notification_options,
ett_zbee_gp_cmd_notification_options, n_options, ENC_LITTLE_ENDIAN);
offset += 2;
if ((options & ZBEE_ZCL_GP_NOTIFICATION_OPTION_APP_ID) == 0) {
proto_tree_add_item(tree, hf_zbee_gp_src_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
else {
proto_tree_add_item(tree, hf_zbee_gp_ieee, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_gp_endpoint, tvb, offset, 1, ENC_NA);
offset += 1;
}
proto_tree_add_item(tree, hf_zbee_gp_secur_frame_counter, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_zbee_zcl_gp_payload(tvb, pinfo, tree, offset);
if (options & ZBEE_ZCL_GP_NOTIFICATION_OPTION_PROXY_INFO_PRESENT) {
proto_tree_add_item(tree, hf_zbee_gp_short_addr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_gpp_gpd_link,
ett_zbee_gp_gpp_gpd_link,
gpp_gpd_link, ENC_LITTLE_ENDIAN);
offset += 1;
}
break;
}
case ZBEE_CMD_ID_GP_PAIRING_SEARCH:
case ZBEE_CMD_ID_GP_TUNNELING_STOP:
break;
case ZBEE_CMD_ID_GP_COMMISSIONING_NOTIFICATION:
{
static const int * commn_options[] = {
&hf_zbee_gp_cmd_comm_notif_opt_app_id,
&hf_zbee_gp_cmd_comm_notif_opt_rx_after_tx,
&hf_zbee_gp_cmd_comm_notif_opt_secur_level,
&hf_zbee_gp_cmd_comm_notif_opt_secur_key_type,
&hf_zbee_gp_cmd_comm_notif_opt_secur_fail,
&hf_zbee_gp_cmd_comm_notif_opt_bidir_cap,
&hf_zbee_gp_cmd_comm_notif_opt_proxy_info_present,
NULL
};
guint16 options = tvb_get_guint16(tvb, offset, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_cmd_commissioning_notification_options,
ett_zbee_gp_cmd_commissioning_notification_options, commn_options, ENC_LITTLE_ENDIAN);
offset += 2;
if ((options & ZBEE_ZCL_GP_COMMISSIONING_NOTIFICATION_OPTION_APP_ID) == 0) {
proto_tree_add_item(tree, hf_zbee_gp_src_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
else {
proto_tree_add_item(tree, hf_zbee_gp_ieee, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_gp_endpoint, tvb, offset, 1, ENC_NA);
offset += 1;
}
proto_tree_add_item(tree, hf_zbee_gp_secur_frame_counter, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_zbee_zcl_gp_payload(tvb, pinfo, tree, offset);
if (options & ZBEE_ZCL_GP_COMMISSIONING_NOTIFICATION_OPTION_PROXY_INFO_PRESENT) {
proto_tree_add_item(tree, hf_zbee_gp_short_addr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_gpp_gpd_link,
ett_zbee_gp_gpp_gpd_link,
gpp_gpd_link, ENC_LITTLE_ENDIAN);
offset += 1;
}
if (options & ZBEE_ZCL_GP_COMMISSIONING_NOTIFICATION_OPTION_SECUR_FAILED) {
proto_tree_add_item(tree, hf_zbee_gp_mic, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
break;
}
case ZBEE_CMD_ID_GP_PAIRING_CONFIGURATION:
{
static const int * pc_actions[] = {
&hf_zbee_gp_cmd_pc_actions_action,
&hf_zbee_gp_cmd_pc_actions_send_gp_pairing,
NULL
};
static const int * pc_options[] = {
&hf_zbee_gp_cmd_pc_opt_app_id,
&hf_zbee_gp_cmd_pc_opt_communication_mode,
&hf_zbee_gp_cmd_pc_opt_seq_number_cap,
&hf_zbee_gp_cmd_px_opt_rx_on_cap,
&hf_zbee_gp_cmd_pc_opt_fixed_location,
&hf_zbee_gp_cmd_pc_opt_assigned_alias,
&hf_zbee_gp_cmd_pc_opt_security_use,
&hf_zbee_gp_cmd_pc_opt_app_info_present,
NULL
};
guint16 options;
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_cmd_pc_actions,
ett_zbee_gp_cmd_pc_actions, pc_actions, ENC_NA);
offset += 1;
options = tvb_get_guint16(tvb, offset, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_cmd_pc_options,
ett_zbee_gp_cmd_pc_options, pc_options, ENC_LITTLE_ENDIAN);
offset += 2;
if ((options & ZBEE_ZCL_GP_CMD_PC_OPT_APP_ID) == 0) {
proto_tree_add_item(tree, hf_zbee_gp_src_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
else {
proto_tree_add_item(tree, hf_zbee_gp_ieee, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_gp_endpoint, tvb, offset, 1, ENC_NA);
offset += 1;
}
proto_tree_add_item(tree, hf_zbee_gp_device_id, tvb, offset, 1, ENC_NA);
offset += 1;
if (((options & ZBEE_ZCL_GP_CMD_PC_OPT_COMMUNICATION_MODE) >> ZBEE_ZCL_GP_PAIRING_CONFIGURATION_OPTION_COMMUNICATION_MODE_SHIFT)
== ZBEE_ZCL_GP_COMMUNICATION_MODE_GROUPCAST_PRECOMMISSIONED) {
guint8 len = tvb_get_guint8(tvb, offset);
proto_tree *gl_tree = proto_tree_add_subtree_format(tree, tvb, offset, len*4+1, ett_zbee_zcl_gp_group_list, NULL, "GroupList #%d", len);
proto_tree_add_item(gl_tree, hf_zbee_gp_group_list_len, tvb, offset, 1, ENC_NA);
offset += 1;
while (len)
{
proto_tree_add_item(gl_tree, hf_zbee_gp_group_list_group_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(gl_tree, hf_zbee_gp_group_list_alias, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
len--;
}
}
if (options & ZBEE_ZCL_GP_CMD_PC_OPT_ASSIGNED_ALIAS) {
proto_tree_add_item(tree, hf_zbee_gp_assigned_alias, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
proto_tree_add_item(tree, hf_zbee_gp_forwarding_radius, tvb, offset, 1, ENC_NA);
offset += 1;
if (options & ZBEE_ZCL_GP_CMD_PC_OPT_SECURITY_USE) {
static const int * secur_options[] = {
&hf_zbee_gp_cmd_pc_secur_level,
&hf_zbee_gp_cmd_pc_secur_key_type,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_cmd_pc_secur_options,
ett_zbee_gp_cmd_pc_secur_options, secur_options, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_zbee_gp_secur_frame_counter, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_zbee_gp_gpd_key, tvb, offset, 16, ENC_NA);
offset += 16;
}
{
guint8 n_paired_endpoints = tvb_get_guint8(tvb, offset);
proto_tree *ep_tree = proto_tree_add_subtree_format(tree, tvb, offset, n_paired_endpoints+1, ett_zbee_zcl_gp_ep, NULL, "Paired Endpoints #%d", n_paired_endpoints);
proto_tree_add_item(ep_tree, hf_zbee_gp_n_paired_endpoints, tvb, offset, 1, ENC_NA);
offset += 1;
if (n_paired_endpoints != 0 && n_paired_endpoints != 0xfd
&& n_paired_endpoints != 0xfe && n_paired_endpoints != 0xff)
{
while (n_paired_endpoints)
{
proto_tree_add_item(ep_tree, hf_zbee_gp_paired_endpoint, tvb, offset, 1, ENC_NA);
offset += 1;
n_paired_endpoints--;
}
}
}
if (options & ZBEE_ZCL_GP_CMD_PC_OPT_APP_INFO_PRESENT) {
static const int * app_info[] = {
&hf_zbee_gp_cmd_pc_app_info_manuf_id_present,
&hf_zbee_gp_cmd_pc_app_info_model_id_present,
&hf_zbee_gp_cmd_pc_app_info_gpd_commands_present,
&hf_zbee_gp_cmd_pc_app_info_cluster_list_present,
NULL
};
guint8 appi = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_cmd_pc_app_info,
ett_zbee_gp_cmd_pc_app_info, app_info, ENC_NA);
offset += 1;
if (appi & ZBEE_ZCL_GP_CMD_PC_APP_INFO_MANUF_ID_PRESENT) {
proto_tree_add_item(tree, hf_zbee_zcl_gp_manufacturer_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if (appi & ZBEE_ZCL_GP_CMD_PC_APP_INFO_MODEL_ID_PRESENT) {
proto_tree_add_item(tree, hf_zbee_zcl_gp_model_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if (appi & ZBEE_ZCL_GP_CMD_PC_APP_INFO_GPD_COMMANDS_PRESENT) {
guint8 n_commands = tvb_get_guint8(tvb, offset);
proto_tree *c_tree = proto_tree_add_subtree_format(tree, tvb, offset, n_commands+1, ett_zbee_zcl_gp_cmds, NULL, "GPD CommandID list #%d", n_commands);
proto_tree_add_item(c_tree, hf_zbee_gp_n_gpd_commands, tvb, offset, 1, ENC_NA);
offset += 1;
while (n_commands)
{
proto_tree_add_item(c_tree, hf_zbee_gp_gpd_command, tvb, offset, 1, ENC_NA);
offset += 1;
n_commands--;
}
}
if (appi & ZBEE_ZCL_GP_CMD_PC_APP_INFO_CLUSTER_LIST_PRESENT) {
guint8 n = tvb_get_guint8(tvb, offset);
guint8 n_srv_clusters = n & ZBEE_ZCL_GP_CLUSTER_LIST_LEN_SRV;
guint8 n_cli_clusters = (n & ZBEE_ZCL_GP_CLUSTER_LIST_LEN_CLI) >> ZBEE_ZCL_GP_CLUSTER_LIST_LEN_CLI_SHIFT;
proto_tree *cl_tree = proto_tree_add_subtree_format(tree, tvb, offset, n*2+1, ett_zbee_zcl_gp_clusters, NULL, "Cluster List #%d/%d", n_srv_clusters, n_cli_clusters);
proto_tree_add_item(cl_tree, hf_zbee_gp_n_srv_clusters, tvb, offset, 1, ENC_NA);
proto_tree_add_item(cl_tree, hf_zbee_gp_n_cli_clusters, tvb, offset, 1, ENC_NA);
offset += 1;
if (n_srv_clusters)
{
proto_tree *s_tree = proto_tree_add_subtree_format(cl_tree, tvb, offset, n_srv_clusters*2, ett_zbee_zcl_gp_srv_clusters, NULL, "Server clusters #%d", n_srv_clusters);
while (n_srv_clusters)
{
proto_tree_add_item(s_tree, hf_zbee_gp_gpd_cluster_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
n_srv_clusters--;
}
}
if (n_cli_clusters)
{
proto_tree *c_tree = proto_tree_add_subtree_format(cl_tree, tvb, offset, n_cli_clusters*2, ett_zbee_zcl_gp_cli_clusters, NULL, "Client clusters #%d", n_cli_clusters);
while (n_cli_clusters)
{
proto_tree_add_item(c_tree, hf_zbee_gp_gpd_cluster_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
n_cli_clusters--;
}
}
}
}
break;
}
case ZBEE_CMD_ID_GP_SINK_COMMISSIONING_MODE:
case ZBEE_CMD_ID_GP_TRANSLATION_TABLE_UPDATE_COMMAND:
case ZBEE_CMD_ID_GP_TRANSLATION_TABLE_REQUEST:
case ZBEE_CMD_ID_GP_SINK_TABLE_REQUEST:
case ZBEE_CMD_ID_GP_PROXY_TABLE_RESPONSE:
break;
default:
break;
}
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_gp_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_gp_srv_tx_cmd_id, tvb, offset, 1, ENC_NA);
offset++;
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_GP_NOTIFICATION_RESPONSE:
break;
case ZBEE_ZCL_CMD_ID_GP_PAIRING:
{
static const int * p_options[] = {
&hf_zbee_gp_cmd_pairing_opt_app_id,
&hf_zbee_gp_cmd_pairing_opt_add_sink,
&hf_zbee_gp_cmd_pairing_opt_remove_gpd,
&hf_zbee_gp_cmd_pairing_opt_communication_mode,
&hf_zbee_gp_cmd_pairing_opt_gpd_fixed,
&hf_zbee_gp_cmd_pairing_opt_gpd_mac_seq_num_cap,
&hf_zbee_gp_cmd_pairing_opt_secur_level,
&hf_zbee_gp_cmd_pairing_opt_secur_key_type,
&hf_zbee_gp_cmd_pairing_opt_gpd_frame_cnt_present,
&hf_zbee_gp_cmd_pairing_opt_gpd_secur_key_present,
&hf_zbee_gp_cmd_pairing_opt_assigned_alias_present,
&hf_zbee_gp_cmd_pairing_opt_fwd_radius_present,
NULL
};
guint32 options = tvb_get_guint24(tvb, offset, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_cmd_pairing_options,
ett_zbee_gp_cmd_pairing_options, p_options, ENC_LITTLE_ENDIAN);
offset += 3;
if ((options & ZBEE_ZCL_GP_PAIRING_OPTION_APP_ID) == 0) {
proto_tree_add_item(tree, hf_zbee_gp_src_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
else {
proto_tree_add_item(tree, hf_zbee_gp_ieee, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_gp_endpoint, tvb, offset, 1, ENC_NA);
offset += 1;
}
if ((options & ZBEE_ZCL_GP_PAIRING_OPTION_REMOVE_GPD) == 0 &&
(options & ZBEE_ZCL_GP_PAIRING_OPTION_COMMUNICATION_MODE) == ZBEE_ZCL_GP_PAIRING_OPTION_COMMUNICATION_MODE) {
proto_tree_add_item(tree, hf_zbee_gp_sink_ieee, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_gp_sink_nwk, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if ((options & ZBEE_ZCL_GP_PAIRING_OPTION_REMOVE_GPD) == 0 &&
(options & ZBEE_ZCL_GP_PAIRING_OPTION_COMMUNICATION_MODE) != ZBEE_ZCL_GP_PAIRING_OPTION_COMMUNICATION_MODE &&
(options & ZBEE_ZCL_GP_PAIRING_OPTION_COMMUNICATION_MODE) != 0) {
proto_tree_add_item(tree, hf_zbee_gp_sink_group_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if (options & ZBEE_ZCL_GP_PAIRING_OPTION_ADD_SINK) {
proto_tree_add_item(tree, hf_zbee_gp_device_id, tvb, offset, 1, ENC_NA);
offset += 1;
}
if (options & ZBEE_ZCL_GP_PAIRING_OPTION_GPD_FRAME_CNT_PRESENT) {
proto_tree_add_item(tree, hf_zbee_gp_secur_frame_counter, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
if (options & ZBEE_ZCL_GP_PAIRING_OPTION_GPD_SECUR_KEY_PRESENT) {
proto_tree_add_item(tree, hf_zbee_gp_gpd_key, tvb, offset, 16, ENC_NA);
offset += 16;
}
if (options & ZBEE_ZCL_GP_PAIRING_OPTION_ASSIGNED_ALIAS_PRESENT) {
proto_tree_add_item(tree, hf_zbee_gp_assigned_alias, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if (options & ZBEE_ZCL_GP_PAIRING_OPTION_FWD_RADIUS_PRESENT) {
proto_tree_add_item(tree, hf_zbee_gp_forwarding_radius, tvb, offset, 1, ENC_NA);
offset += 1;
}
break;
}
case ZBEE_ZCL_CMD_ID_GP_PROXY_COMMISSIONING_MODE:
{
static const int * pcm_options[] = {
&hf_zbee_gp_cmd_pcm_opt_action,
&hf_zbee_gp_cmd_pcm_opt_exit_mode,
&hf_zbee_gp_cmd_pcm_opt_channel_present,
&hf_zbee_gp_cmd_pcm_opt_unicast_comm,
NULL
};
guint8 options = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_cmd_proxy_commissioning_mode_options,
ett_zbee_gp_cmd_proxy_commissioning_mode_options, pcm_options, ENC_NA);
if (options & ZBEE_ZCL_GP_PROXY_COMMISSIONING_MODE_OPTION_ACTION) {
static const int * exit_mode[] = {
&hf_zbee_gp_cmd_pcm_exit_mode_on_comm_window_expire,
&hf_zbee_gp_cmd_pcm_exit_mode_on_pairing_success,
&hf_zbee_gp_cmd_pcm_exit_mode_on_gp_proxy_comm_mode,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_cmd_proxy_commissioning_mode_exit_mode,
ett_zbee_gp_cmd_proxy_commissioning_mode_exit_mode, exit_mode, ENC_NA);
}
offset += 1;
if (options & ZBEE_ZCL_GP_PROXY_COMMISSIONING_MODE_OPTION_ON_COMMISSIONING_WINDOW_EXPIRATION) {
proto_tree_add_item(tree, hf_zbee_zcl_gp_commissioning_window, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if (options & ZBEE_ZCL_GP_PROXY_COMMISSIONING_MODE_OPTION_CHANNEL_PRESENT) {
proto_tree_add_item(tree, hf_zbee_zcl_gp_channel, tvb, offset, 1, ENC_NA);
offset += 1;
}
break;
}
case ZBEE_ZCL_CMD_ID_GP_RESPONSE:
{
static const int * rsp_options[] = {
&hf_zbee_gp_cmd_resp_opt_app_id,
&hf_zbee_gp_cmd_resp_opt_tx_on_ep_match,
NULL
};
static const int * tx_ch[] = {
&hf_zbee_gp_cmd_resp_tx_channel,
NULL
};
guint8 options = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_cmd_response_options,
ett_zbee_gp_cmd_response_options, rsp_options, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_zbee_gp_tmp_master_short_addr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_gp_cmd_response_tx_channel,
ett_zbee_gp_cmd_response_tx_channel, tx_ch, ENC_LITTLE_ENDIAN);
offset += 1;
if ((options & ZBEE_ZCL_GP_RESPONSE_OPTION_APP_ID) == 0) {
proto_tree_add_item(tree, hf_zbee_gp_src_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
else {
proto_tree_add_item(tree, hf_zbee_gp_ieee, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_gp_endpoint, tvb, offset, 1, ENC_NA);
offset += 1;
}
offset = dissect_zbee_zcl_gp_payload(tvb, pinfo, tree, offset);
break;
}
case ZBEE_ZCL_CMD_ID_GP_TRANS_TBL_RESPONSE:
case ZBEE_ZCL_CMD_ID_GP_SINK_TABLE_RESPONSE:
case ZBEE_ZCL_CMD_ID_GP_PROXY_TABLE_REQUEST:
break;
default:
break;
}
}
if (tvb_captured_length(tvb) > offset) {
call_data_dissector(tvb_new_subset_remaining(tvb, offset), pinfo, tree);
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_gp_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id _U_, guint data_type)
{
dissect_zcl_attr_data(tvb, tree, offset, data_type);
}
void
proto_register_zbee_zcl_gp(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_gp_attr_id,
{ "Attribute", "zbee_zcl_general.gp.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_gp_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_gp_srv_rx_cmd_id,
{ "Command", "zbee_zcl_general.gp.cmd.srv_rx.id", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_gp_srv_rx_cmd_names), 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_gp_srv_tx_cmd_id,
{ "Command", "zbee_zcl_general.gp.cmd.srv_tx.id", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_gp_srv_tx_cmd_names), 0x0, NULL, HFILL }},
{ &hf_zbee_gp_cmd_proxy_commissioning_mode_options,
{ "Options", "zbee_zcl_general.gp.proxy_comm_mode.options", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_gp_commissioning_window,
{ "Commissioning window", "zbee_zcl_general.gp.proxy_comm_mode.comm_window", FT_UINT16, BASE_DEC,
NULL, 0x0, "Commissioning window in seconds", HFILL }},
{ &hf_zbee_zcl_gp_channel,
{ "Channel", "zbee_zcl_general.gp.proxy_comm_mode.cnannel", FT_UINT8, BASE_DEC,
NULL, 0x0, "Identifier of the channel the devices SHOULD switch to on reception", HFILL }},
{ &hf_zbee_gp_cmd_pcm_opt_action,
{ "Action", "zbee_zcl_general.gp.proxy_comm_mode.opt.action", FT_UINT8, BASE_DEC,
VALS(zbee_zcl_gp_comm_mode_actions), ZBEE_ZCL_GP_PROXY_COMMISSIONING_MODE_OPTION_ACTION, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pcm_opt_exit_mode,
{ "Exit mode", "zbee_zcl_general.gp.proxy_comm_mode.opt.exit_mode", FT_UINT8, BASE_HEX,
NULL, ZBEE_ZCL_GP_PROXY_COMMISSIONING_MODE_OPTION_EXIT_MODE, "Commissioning mode exit requirements", HFILL }},
{ &hf_zbee_gp_cmd_pcm_opt_channel_present,
{ "Channel present", "zbee_zcl_general.gp.proxy_comm_mode.opt.ch_present", FT_BOOLEAN, 8,
NULL, ZBEE_ZCL_GP_PROXY_COMMISSIONING_MODE_OPTION_CHANNEL_PRESENT, "If set to 0b1, it indicates that the Channel field is present", HFILL }},
{ &hf_zbee_gp_cmd_pcm_opt_unicast_comm,
{ "Unicast", "zbee_zcl_general.gp.proxy_comm_mode.opt.unicast", FT_BOOLEAN, 8,
NULL, ZBEE_ZCL_GP_PROXY_COMMISSIONING_MODE_OPTION_UNICAST, "Send the GP Commissioning Notification commands in broadcast (0) vs unicast (1)", HFILL }},
{ &hf_zbee_gp_cmd_proxy_commissioning_mode_exit_mode,
{ "Exit mode", "zbee_zcl_general.gp.proxy_comm_mode.opt.exit_mode", FT_UINT8, BASE_HEX,
NULL, ZBEE_ZCL_GP_PROXY_COMMISSIONING_MODE_OPTION_EXIT_MODE, "Commissioning mode exit requirements", HFILL }},
{ &hf_zbee_gp_cmd_pcm_exit_mode_on_comm_window_expire,
{ "On Window expire", "zbee_zcl_general.gp.proxy_comm_mode.opt.exit_mode.win_expire", FT_BOOLEAN, 8,
NULL, ZBEE_ZCL_GP_PROXY_COMMISSIONING_MODE_OPTION_ON_COMMISSIONING_WINDOW_EXPIRATION, "On CommissioningWindow expiration", HFILL }},
{ &hf_zbee_gp_cmd_pcm_exit_mode_on_pairing_success,
{ "On first Pairing success", "zbee_zcl_general.gp.proxy_comm_mode.opt.exit_mode.pair_succs", FT_BOOLEAN, 8,
NULL, ZBEE_ZCL_GP_PROXY_COMMISSIONING_MODE_OPTION_ON_PAIRING_SUCCESS, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pcm_exit_mode_on_gp_proxy_comm_mode,
{ "On GP Proxy Commissioning Mode", "zbee_zcl_general.gp.proxy_comm_mode.opt.exit_mode.proxy_comm_mode", FT_BOOLEAN, 8,
NULL, ZBEE_ZCL_GP_PROXY_COMMISSIONING_MODE_OPTION_ON_GP_PROXY_COMM_MODE, "On GP Proxy Commissioning Mode (exit)", HFILL }},
{ &hf_zbee_gp_cmd_commissioning_notification_options,
{ "Options", "zbee_zcl_general.gp.comm_notif.options", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_gp_cmd_comm_notif_opt_app_id,
{ "ApplicationID", "zbee_zcl_general.gp.comm_notif.opt.app_id", FT_UINT16, BASE_HEX,
VALS(zbee_zcl_gp_app_ids), ZBEE_ZCL_GP_COMMISSIONING_NOTIFICATION_OPTION_APP_ID, NULL, HFILL }},
{ &hf_zbee_gp_cmd_comm_notif_opt_rx_after_tx,
{ "RxAfterTx", "zbee_zcl_general.gp.comm_notif.opt.rx_after_tx", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_COMMISSIONING_NOTIFICATION_OPTION_RX_AFTER_TX, NULL, HFILL }},
{ &hf_zbee_gp_cmd_comm_notif_opt_secur_level,
{ "SecurityLevel", "zbee_zcl_general.gp.comm_notif.opt.secur_lev", FT_UINT16, BASE_HEX,
VALS(zbee_zcl_gp_secur_levels), ZBEE_ZCL_GP_COMMISSIONING_NOTIFICATION_OPTION_SECUR_LEVEL, NULL, HFILL }},
{ &hf_zbee_gp_cmd_comm_notif_opt_secur_key_type,
{ "SecurityKeyType", "zbee_zcl_general.gp.comm_notif.opt.secur_key_type", FT_UINT16, BASE_HEX,
VALS(zbee_zcl_gp_secur_key_types), ZBEE_ZCL_GP_COMMISSIONING_NOTIFICATION_OPTION_SECUR_KEY_TYPE, NULL, HFILL }},
{ &hf_zbee_gp_cmd_comm_notif_opt_secur_fail,
{ "Security processing failed", "zbee_zcl_general.gp.comm_notif.opt.secur_failed", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_COMMISSIONING_NOTIFICATION_OPTION_SECUR_FAILED, NULL, HFILL }},
{ &hf_zbee_gp_cmd_comm_notif_opt_bidir_cap,
{ "Bidirectional Capability", "zbee_zcl_general.gp.comm_notif.opt.bidir_cap", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_COMMISSIONING_NOTIFICATION_OPTION_BIDIR_CAP, NULL, HFILL }},
{ &hf_zbee_gp_cmd_comm_notif_opt_proxy_info_present,
{ "Proxy info present", "zbee_zcl_general.gp.comm_notif.opt.proxy_info", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_COMMISSIONING_NOTIFICATION_OPTION_PROXY_INFO_PRESENT, NULL, HFILL }},
{ &hf_zbee_gp_src_id,
{ "SrcID", "zbee_zcl_general.gp.src_id", FT_UINT32, BASE_HEX,
NULL, 0, "GPD Source identifier", HFILL }},
{ &hf_zbee_gp_ieee,
{ "GPD IEEE", "zbee_zcl_general.gp.gpd_ieee", FT_EUI64, BASE_NONE,
NULL, 0, "GPD IEEE address", HFILL }},
{ &hf_zbee_gp_endpoint,
{ "Endpoint", "zbee_zcl_general.gp.endpoint", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_secur_frame_counter,
{ "Frame counter", "zbee_zcl_general.gp.frame_cnt", FT_UINT32, BASE_DEC,
NULL, 0, "GPD security frame counter", HFILL }},
{ &hf_zbee_gp_gpd_command_id,
{ "ZGPD CommandID", "zbee_zcl_general.gp.command_id", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&zbee_nwk_gp_cmd_names_ext, 0x0, NULL, HFILL }},
{ &hf_zbee_gp_short_addr,
{ "GPP short address", "zbee_zcl_general.gp.gpp_short", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_gpp_gpd_link,
{ "GPP-GPD link", "zbee_zcl_general.gp.gpd_gpp_link", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_mic,
{ "MIC", "zbee_zcl_general.gp.mic", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gpp_gpd_link_rssi,
{ "RSSI", "zbee_zcl_general.gp.gpp_gpd_link.rssi", FT_UINT8, BASE_HEX,
NULL, ZBEE_ZCL_GP_GPP_GPD_LINK_RSSI, NULL, HFILL }},
{ &hf_zbee_gpp_gpd_link_lqi,
{ "LQI", "zbee_zcl_general.gp.gpp_gpd_link.lqi", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_gp_lqi_vals), ZBEE_ZCL_GP_GPP_GPD_LINK_LQI, NULL, HFILL }},
{ &hf_zbee_gp_gpd_payload_size,
{ "Payload size", "zbee_zcl_general.gp.payload_size", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_cmd_notification_options,
{ "Options", "zbee_zcl_general.gp.notif.opt", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_cmd_notif_opt_app_id,
{ "ApplicationID", "zbee_zcl_general.gp.notif.opt.app_id", FT_UINT16, BASE_HEX,
VALS(zbee_zcl_gp_app_ids), ZBEE_ZCL_GP_NOTIFICATION_OPTION_APP_ID, NULL, HFILL }},
{ &hf_zbee_gp_cmd_notif_opt_also_unicast,
{ "Also Unicast", "zbee_zcl_general.gp.notif.opt.also_unicast", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_NOTIFICATION_OPTION_ALSO_UNICAST, NULL, HFILL }},
{ &hf_zbee_gp_cmd_notif_opt_also_derived_group,
{ "Also Derived Group", "zbee_zcl_general.gp.notif.opt.also_derived_grp", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_NOTIFICATION_OPTION_ALSO_DERIVED_GROUP, NULL, HFILL }},
{ &hf_zbee_gp_cmd_notif_opt_also_comm_group,
{ "Also Commissioned Group", "zbee_zcl_general.gp.notif.opt.also_comm_grp", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_NOTIFICATION_OPTION_ALSO_COMMISSIONED_GROUP, NULL, HFILL }},
{ &hf_zbee_gp_cmd_notif_opt_secur_level,
{ "SecurityLevel", "zbee_zcl_general.gp.notif.opt.secur_lev", FT_UINT16, BASE_HEX,
VALS(zbee_zcl_gp_secur_levels), ZBEE_ZCL_GP_NOTIFICATION_OPTION_SECUR_LEVEL, NULL, HFILL }},
{ &hf_zbee_gp_cmd_notif_opt_secur_key_type,
{ "SecurityKeyType", "zbee_zcl_general.gp.notif.opt.secur_key_type", FT_UINT16, BASE_HEX,
VALS(zbee_zcl_gp_secur_key_types), ZBEE_ZCL_GP_NOTIFICATION_OPTION_SECUR_KEY_TYPE, NULL, HFILL }},
{ &hf_zbee_gp_cmd_notif_opt_rx_after_tx,
{ "RxAfterTx", "zbee_zcl_general.gp.comm_notif.opt.rx_after_tx", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_NOTIFICATION_OPTION_RX_AFTER_TX, NULL, HFILL }},
{ &hf_zbee_gp_cmd_notif_opt_tx_q_full,
{ "gpTxQueueFull", "zbee_zcl_general.gp.comm_notif.opt.tx_q_full", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_NOTIFICATION_OPTION_TX_Q_FULL, NULL, HFILL }},
{ &hf_zbee_gp_cmd_notif_opt_bidir_cap,
{ "Bidirectional Capability", "zbee_zcl_general.gp.notif.opt.bidir_cap", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_NOTIFICATION_OPTION_BIDIR_CAP, NULL, HFILL }},
{ &hf_zbee_gp_cmd_notif_opt_proxy_info_present,
{ "Proxy info present", "zbee_zcl_general.gp.notif.opt.proxy_info", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_NOTIFICATION_OPTION_PROXY_INFO_PRESENT, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pairing_opt_app_id,
{ "ApplicationID", "zbee_zcl_general.gp.pairing.opt.app_id", FT_UINT24, BASE_HEX,
VALS(zbee_zcl_gp_app_ids), ZBEE_ZCL_GP_PAIRING_OPTION_APP_ID, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pairing_opt_add_sink,
{ "Add Sink", "zbee_zcl_general.gp.pairing.opt.add_sink", FT_BOOLEAN, 24,
NULL, ZBEE_ZCL_GP_PAIRING_OPTION_ADD_SINK, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pairing_opt_remove_gpd,
{ "Remove GPD", "zbee_zcl_general.gp.pairing.opt.remove_gpd", FT_BOOLEAN, 24,
NULL, ZBEE_ZCL_GP_PAIRING_OPTION_REMOVE_GPD, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pairing_opt_communication_mode,
{ "Communication mode", "zbee_zcl_general.gp.pairing.opt.comm_mode", FT_UINT24, BASE_HEX,
VALS(zbee_zcl_gp_communication_modes), ZBEE_ZCL_GP_PAIRING_OPTION_COMMUNICATION_MODE, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pairing_opt_gpd_fixed,
{ "GPD Fixed", "zbee_zcl_general.gp.pairing.opt.gpd_fixed", FT_BOOLEAN, 24,
NULL, ZBEE_ZCL_GP_PAIRING_OPTION_GPD_FIXED, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pairing_opt_gpd_mac_seq_num_cap,
{ "MAC Seq number cap", "zbee_zcl_general.gp.pairing.opt.seq_num_cap", FT_BOOLEAN, 24,
NULL, ZBEE_ZCL_GP_PAIRING_OPTION_GPD_MAC_SEQ_NUM_CAP, "GPD MAC sequence number capabilities", HFILL }},
{ &hf_zbee_gp_cmd_pairing_opt_secur_level,
{ "SecurityLevel", "zbee_zcl_general.gp.pairing.opt.secur_lev", FT_UINT24, BASE_HEX,
VALS(zbee_zcl_gp_secur_levels), ZBEE_ZCL_GP_PAIRING_OPTION_SECUR_LEVEL, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pairing_opt_secur_key_type,
{ "SecurityKeyType", "zbee_zcl_general.gp.pairing.opt.secur_key_type", FT_UINT24, BASE_HEX,
VALS(zbee_zcl_gp_secur_key_types), ZBEE_ZCL_GP_PAIRING_OPTION_SECUR_KEY_TYPE, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pairing_opt_gpd_frame_cnt_present,
{ "Frame Counter present", "zbee_zcl_general.gp.pairing.opt.seq_num_cap", FT_BOOLEAN, 24,
NULL, ZBEE_ZCL_GP_PAIRING_OPTION_GPD_FRAME_CNT_PRESENT, "GPD security Frame Counter present", HFILL }},
{ &hf_zbee_gp_cmd_pairing_opt_gpd_secur_key_present,
{ "Key present", "zbee_zcl_general.gp.pairing.opt.key_present", FT_BOOLEAN, 24,
NULL, ZBEE_ZCL_GP_PAIRING_OPTION_GPD_SECUR_KEY_PRESENT, "GPD security key present", HFILL }},
{ &hf_zbee_gp_cmd_pairing_opt_assigned_alias_present,
{ "Assigned Alias present", "zbee_zcl_general.gp.pairing.opt.asn_alias_present", FT_BOOLEAN, 24,
NULL, ZBEE_ZCL_GP_PAIRING_OPTION_ASSIGNED_ALIAS_PRESENT, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pairing_opt_fwd_radius_present,
{ "Forwarding Radius present", "zbee_zcl_general.gp.pairing.opt.fwd_radius_present", FT_BOOLEAN, 24,
NULL, ZBEE_ZCL_GP_PAIRING_OPTION_FWD_RADIUS_PRESENT, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pairing_options,
{ "Options", "zbee_zcl_general.gp.pairing.opt", FT_UINT24, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_sink_ieee,
{ "Sink IEEE", "zbee_zcl_general.gp.sink_ieee", FT_EUI64, BASE_NONE,
NULL, 0, "Sink IEEE address", HFILL }},
{ &hf_zbee_gp_sink_nwk,
{ "Sink NWK", "zbee_zcl_general.gp.sink_nwk", FT_UINT16, BASE_HEX,
NULL, 0, "Sink NWK address", HFILL }},
{ &hf_zbee_gp_sink_group_id,
{ "Sink GroupID", "zbee_zcl_general.gp.sink_grp", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_device_id,
{ "DeviceID", "zbee_zcl_general.gp.dev_id", FT_UINT8, BASE_HEX,
VALS(zbee_nwk_gp_device_ids_names), 0, NULL, HFILL }},
{ &hf_zbee_gp_assigned_alias,
{ "Assigned alias", "zbee_zcl_general.gp.asn_alias", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_forwarding_radius,
{ "Forwarding Radius", "zbee_zcl_general.gp.fw_radius", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_gpd_key,
{ "GPD key", "zbee_zcl_general.gp.gpd_key", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_cmd_response_options,
{ "Options", "zbee_zcl_general.gp.response.opt", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_cmd_resp_opt_app_id,
{ "ApplicationID", "zbee_zcl_general.gp.response.opt.app_id", FT_UINT8, BASE_HEX,
NULL, ZBEE_ZCL_GP_RESPONSE_OPTION_APP_ID, NULL, HFILL }},
{ &hf_zbee_gp_cmd_resp_opt_tx_on_ep_match,
{ "Transmit on endpoint match", "zbee_zcl_general.gp.response.opt.tx_on_ep_match", FT_UINT8, BASE_HEX,
NULL, ZBEE_ZCL_GP_RESPONSE_OPTION_TX_ON_ENDPOINT_MATCH, NULL, HFILL }},
{ &hf_zbee_gp_cmd_response_tx_channel,
{ "TempMaster Tx channel", "zbee_zcl_general.gp.response.tmpmaster_tx_chan", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_cmd_resp_tx_channel,
{ "Transmit channel", "zbee_zcl_general.gp.response.opt.tx_chan", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_gp_channels), ZBEE_ZCL_GP_RESPONSE_TX_CHANNEL, NULL, HFILL }},
{ &hf_zbee_gp_tmp_master_short_addr,
{ "TempMaster short address", "zbee_zcl_general.gp.response.tmpmaster_addr", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_actions_action,
{ "Action", "zbee_zcl_general.gp.pc.action.action", FT_UINT8, BASE_HEX,
VALS(zbee_gp_pc_actions), ZBEE_ZCL_GP_CMD_PC_ACTIONS_ACTION, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_actions_send_gp_pairing,
{ "Send GP Pairing", "zbee_zcl_general.gp.pc.action.send_gp_pairing", FT_BOOLEAN, 8,
NULL, ZBEE_ZCL_GP_CMD_PC_ACTIONS_SEND_GP_PAIRING, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_opt_app_id,
{ "ApplicationID", "zbee_zcl_general.gp.pp.opt.app_id", FT_UINT16, BASE_HEX,
NULL, ZBEE_ZCL_GP_CMD_PC_OPT_APP_ID, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_opt_communication_mode,
{ "Communication mode", "zbee_zcl_general.gp.pc.opt.comm_mode", FT_UINT16, BASE_HEX,
VALS(zbee_zcl_gp_communication_modes), ZBEE_ZCL_GP_CMD_PC_OPT_COMMUNICATION_MODE, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_opt_seq_number_cap,
{ "Sequence number capabilities", "zbee_zcl_general.gp.pc.opt.seq_num_cap", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_CMD_PC_OPT_SEQ_NUMBER_CAP, NULL, HFILL }},
{ &hf_zbee_gp_cmd_px_opt_rx_on_cap,
{ "RxOnCapability", "zbee_zcl_general.gp.pc.opt.rx_on_cap", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_CMD_PC_OPT_RX_ON_CAP, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_opt_fixed_location,
{ "FixedLocation", "zbee_zcl_general.gp.pc.opt.fixed_loc", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_CMD_PC_OPT_FIXED_LOCATION, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_opt_assigned_alias,
{ "AssignedAlias", "zbee_zcl_general.gp.pc.opt.asn_alias", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_CMD_PC_OPT_ASSIGNED_ALIAS, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_opt_security_use,
{ "Security use", "zbee_zcl_general.gp.pc.opt.secur_use", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_CMD_PC_OPT_SECURITY_USE, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_opt_app_info_present,
{ "Application in-formation present", "zbee_zcl_general.gp.pc.opt.app_info_present", FT_BOOLEAN, 16,
NULL, ZBEE_ZCL_GP_CMD_PC_OPT_APP_INFO_PRESENT, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_secur_level,
{ "SecurityLevel", "zbee_zcl_general.gp.pc.secur.secur_lev", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_gp_secur_levels), ZBEE_ZCL_GP_CMD_PC_SECUR_LEVEL, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_secur_key_type,
{ "SecurityKeyType", "zbee_zcl_general.gp.pc.secur.secur_key_type", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_gp_secur_key_types), ZBEE_ZCL_GP_CMD_PC_SECUR_KEY_TYPE, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_app_info_manuf_id_present,
{ "ManufacturerID present", "zbee_zcl_general.gp.pc.app.manuf_id_present", FT_BOOLEAN, 8,
NULL, ZBEE_ZCL_GP_CMD_PC_APP_INFO_MANUF_ID_PRESENT, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_app_info_model_id_present,
{ "ModelID present", "zbee_zcl_general.gp.pc.app.model_id_present", FT_BOOLEAN, 8,
NULL, ZBEE_ZCL_GP_CMD_PC_APP_INFO_MODEL_ID_PRESENT, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_app_info_gpd_commands_present,
{ "GPD commands present", "zbee_zcl_general.gp.pc.app.gpd_cmds_present", FT_BOOLEAN, 8,
NULL, ZBEE_ZCL_GP_CMD_PC_APP_INFO_GPD_COMMANDS_PRESENT, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_app_info_cluster_list_present,
{ "Cluster list present", "zbee_zcl_general.gp.pc.app.cluster_list_present", FT_BOOLEAN, 8,
NULL, ZBEE_ZCL_GP_CMD_PC_APP_INFO_CLUSTER_LIST_PRESENT, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_actions,
{ "Actions", "zbee_zcl_general.gp.pc.actions", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_options,
{ "Options", "zbee_zcl_general.gp.pc.options", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_group_list_len,
{ "Group list length", "zbee_zcl_general.gp.pc.group_list.len", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_group_list_group_id,
{ "Group id", "zbee_zcl_general.gp.pc.group_list.group", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_group_list_alias,
{ "Alias", "zbee_zcl_general.gp.pc.group_list.alias", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_secur_options,
{ "Security Options", "zbee_zcl_general.gp.pc.secur_options", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_n_paired_endpoints,
{ "Number of paired endpoints", "zbee_zcl_general.gp.pc.n_ep", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_paired_endpoint,
{ "Paired endpoint", "zbee_zcl_general.gp.pc.endpoint", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_cmd_pc_app_info,
{ "Application information", "zbee_zcl_general.gp.pc.app_info", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_zcl_gp_manufacturer_id,
{ "Manufacturer ID", "zbee_zcl_general.gp.pc.manufacturer_id", FT_UINT16, BASE_HEX,
VALS(zbee_mfr_code_names), 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_gp_model_id,
{ "Model ID", "zbee_zcl_general.gp.pc.model_id", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_n_gpd_commands,
{ "Number of GPD commands", "zbee_zcl_general.gp.pc.n_gpd_commands", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_zbee_gp_gpd_command,
{ "ZGPD Command ID", "zbee_zcl_general.gp.pc.gpd_command", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&zbee_nwk_gp_cmd_names_ext, 0x0, NULL, HFILL }},
{ &hf_zbee_gp_n_srv_clusters,
{ "Number of Server clusters", "zbee_zcl_general.gp.pc.n_srv_clusters", FT_UINT8, BASE_DEC,
NULL, ZBEE_ZCL_GP_CLUSTER_LIST_LEN_SRV, NULL, HFILL }},
{ &hf_zbee_gp_n_cli_clusters,
{ "Number of Client clusters", "zbee_zcl_general.gp.pc.n_srv_clusters", FT_UINT8, BASE_DEC,
NULL, ZBEE_ZCL_GP_CLUSTER_LIST_LEN_CLI, NULL, HFILL }},
{ &hf_zbee_gp_gpd_cluster_id,
{ "Cluster ID", "zbee_zcl_general.gp.pc.cluster", FT_UINT8, BASE_HEX, VALS(zbee_aps_cid_names),
0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_zbee_zcl_gp,
&ett_zbee_gp_cmd_proxy_commissioning_mode_options,
&ett_zbee_gp_cmd_proxy_commissioning_mode_exit_mode,
&ett_zbee_gp_cmd_commissioning_notification_options,
&ett_zbee_gp_gpp_gpd_link,
&ett_zbee_gp_cmd_notification_options,
&ett_zbee_gp_cmd_pairing_options,
&ett_zbee_gp_cmd_response_options,
&ett_zbee_gp_cmd_response_tx_channel,
&ett_zbee_gp_cmd_pc_actions,
&ett_zbee_gp_cmd_pc_options,
&ett_zbee_zcl_gp_group_list,
&ett_zbee_gp_cmd_pc_secur_options,
&ett_zbee_gp_cmd_pc_app_info,
&ett_zbee_zcl_gp_ep,
&ett_zbee_zcl_gp_cmds,
&ett_zbee_zcl_gp_clusters,
&ett_zbee_zcl_gp_srv_clusters,
&ett_zbee_zcl_gp_cli_clusters
};
proto_zbee_zcl_gp = proto_register_protocol("ZigBee ZCL Green Power", "ZCL Green Power", ZBEE_PROTOABBREV_ZCL_GP);
proto_register_field_array(proto_zbee_zcl_gp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_GP, dissect_zbee_zcl_gp, proto_zbee_zcl_gp);
}
void
proto_reg_handoff_zbee_zcl_gp(void)
{
dissector_handle_t handle;
handle = find_dissector(ZBEE_PROTOABBREV_ZCL_GP);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_GP, handle);
zgp_handle = find_dissector(ZBEE_PROTOABBREV_NWK_GP_CMD);
zbee_zcl_init_cluster( proto_zbee_zcl_gp,
ett_zbee_zcl_gp,
ZBEE_ZCL_CID_GP,
hf_zbee_zcl_gp_attr_id,
hf_zbee_zcl_gp_srv_rx_cmd_id,
hf_zbee_zcl_gp_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_gp_attr_data
);
}
