static int
dissect_zbee_zcl_pump_config_control(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_pump_config_control_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int * pump_status[] = {
&hf_zbee_zcl_pump_config_control_status_device_fault,
&hf_zbee_zcl_pump_config_control_status_supply_fault,
&hf_zbee_zcl_pump_config_control_status_speed_low,
&hf_zbee_zcl_pump_config_control_status_speed_high,
&hf_zbee_zcl_pump_config_control_status_local_override,
&hf_zbee_zcl_pump_config_control_status_running,
&hf_zbee_zcl_pump_config_control_status_rem_pressure,
&hf_zbee_zcl_pump_config_control_status_rem_flow,
&hf_zbee_zcl_pump_config_control_status_rem_temp,
NULL
};
static const int * alarm_mask[] = {
&hf_zbee_zcl_pump_config_control_alarm_volt_too_low,
&hf_zbee_zcl_pump_config_control_alarm_volt_too_high,
&hf_zbee_zcl_pump_config_control_alarm_pwr_missing_phase,
&hf_zbee_zcl_pump_config_control_alarm_press_too_low,
&hf_zbee_zcl_pump_config_control_alarm_press_too_high,
&hf_zbee_zcl_pump_config_control_alarm_dry_running,
&hf_zbee_zcl_pump_config_control_alarm_mtr_temp_too_high,
&hf_zbee_zcl_pump_config_control_alarm_pump_mtr_fatal_fail,
&hf_zbee_zcl_pump_config_control_alarm_elec_temp_too_high,
&hf_zbee_zcl_pump_config_control_alarm_pump_block,
&hf_zbee_zcl_pump_config_control_alarm_sensor_fail,
&hf_zbee_zcl_pump_config_control_alarm_elec_non_fatal_fail,
&hf_zbee_zcl_pump_config_control_alarm_fatal_fail,
&hf_zbee_zcl_pump_config_control_alarm_gen_fault,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_EFFECTIVE_OPR_MODE:
proto_tree_add_item(tree, hf_zbee_zcl_pump_config_control_attr_eff_opr_mode, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_OPR_MODE:
proto_tree_add_item(tree, hf_zbee_zcl_pump_config_control_attr_opr_mode, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_EFFECTIVE_CTRL_MODE:
proto_tree_add_item(tree, hf_zbee_zcl_pump_config_control_attr_eff_ctrl_mode, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_CTRL_MODE:
proto_tree_add_item(tree, hf_zbee_zcl_pump_config_control_attr_ctrl_mode, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_PUMP_STATUS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_pump_config_control_status, ett_zbee_zcl_pump_config_control_status, pump_status, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_ALARM_MASK:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_pump_config_control_alarm, ett_zbee_zcl_pump_config_control_alarm, alarm_mask, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_MAX_PRESSURE:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_MAX_SPEED:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_MAX_FLOW:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_MIN_CONST_PRESSURE:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_MAX_CONST_PRESSURE:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_MIN_COMP_PRESSURE:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_POWER_MAX_COMP_PRESSURE:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_MIN_CONST_SPEED:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_MAX_CONST_SPEED:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_MIN_CONST_FLOW:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_MAX_CONST_FLOW:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_MIN_CONST_TEMP:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_MAX_CONST_TEMP:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_CAPACITY:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_SPEED:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_LIFETIME_RUNNING_HOURS:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_POWER:
case ZBEE_ZCL_ATTR_ID_PUMP_CONFIG_CONTROL_LIFETIME_ENERGY_CONS:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_pump_config_control(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_pump_config_control_attr_id,
{ "Attribute", "zbee_zcl_hvac.pump_config_control.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_pump_config_control_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_attr_eff_opr_mode,
{ "Effective Operation Mode", "zbee_zcl_hvac.pump_config_control.attr.effective_opr_mode", FT_UINT8, BASE_DEC, VALS(zbee_zcl_pump_config_control_operation_mode_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_attr_opr_mode,
{ "Operation Mode", "zbee_zcl_hvac.pump_config_control.attr.opr_mode", FT_UINT8, BASE_DEC, VALS(zbee_zcl_pump_config_control_operation_mode_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_attr_eff_ctrl_mode,
{ "Effective Control Mode", "zbee_zcl_hvac.pump_config_control.attr.ctrl_mode", FT_UINT8, BASE_DEC, VALS(zbee_zcl_pump_config_control_control_mode_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_attr_ctrl_mode,
{ "Control Mode", "zbee_zcl_hvac.pump_config_control.attr.ctrl_mode", FT_UINT8, BASE_DEC, VALS(zbee_zcl_pump_config_control_control_mode_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_status,
{ "Pump Status", "zbee_zcl_hvac.pump_config_control.attr.status", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_status_device_fault,
{ "Device Fault", "zbee_zcl_hvac.pump_config_control.attr.status.device_fault", FT_BOOLEAN, 8, TFS(&tfs_no_yes),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_STATUS_DEVICE_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_status_supply_fault,
{ "Supply Fault", "zbee_zcl_hvac.pump_config_control.attr.status.supply_fault", FT_BOOLEAN, 8, TFS(&tfs_no_yes),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_STATUS_SUPPLY_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_status_speed_low,
{ "Speed Low", "zbee_zcl_hvac.pump_config_control.attr.status.speed_low", FT_BOOLEAN, 8, TFS(&tfs_no_yes),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_STATUS_SPEED_LOW, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_status_speed_high,
{ "Speed High", "zbee_zcl_hvac.pump_config_control.attr.status.speed_high", FT_BOOLEAN, 8, TFS(&tfs_no_yes),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_STATUS_SPEED_HIGH, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_status_local_override,
{ "Local Override", "zbee_zcl_hvac.pump_config_control.attr.status.local_override", FT_BOOLEAN, 8, TFS(&tfs_no_yes),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_STATUS_LOCAL_OVERRIDE, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_status_running,
{ "Running", "zbee_zcl_hvac.pump_config_control.attr.status.running", FT_BOOLEAN, 8, TFS(&tfs_no_yes),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_STATUS_RUNNING, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_status_rem_pressure,
{ "Remote Pressure", "zbee_zcl_hvac.pump_config_control.attr.status.rem_pressure", FT_BOOLEAN, 8, TFS(&tfs_no_yes),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_STATUS_REMOTE_PRESSURE, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_status_rem_flow,
{ "Remote Flow", "zbee_zcl_hvac.pump_config_control.attr.status.rem_flow", FT_BOOLEAN, 8, TFS(&tfs_no_yes),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_STATUS_REMOTE_FLOW, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_status_rem_temp,
{ "Remote Temperature", "zbee_zcl_hvac.pump_config_control.attr.status.rem_temp", FT_BOOLEAN, 8, TFS(&tfs_no_yes),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_STATUS_REMOTE_TEMP, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm,
{ "Alarm Mask", "zbee_zcl_hvac.pump_config_control.attr.alarm", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_volt_too_low,
{ "Supply voltage too low", "zbee_zcl_hvac.pump_config_control.attr.alarm.volt_too_low", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_VOLTAGE_TOO_LOW, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_volt_too_high,
{ "Supply voltage too high", "zbee_zcl_hvac.pump_config_control.attr.alarm.volt_too_high", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_VOLTAGE_TOO_HIGH, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_pwr_missing_phase,
{ "Power missing phase", "zbee_zcl_hvac.pump_config_control.attr.alarm.pwr_missing_phase", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_PWR_MISSING_PHASE, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_press_too_low,
{ "System pressure too low", "zbee_zcl_hvac.pump_config_control.attr.alarm.press_too_low", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_PRESSURE_TOO_LOW, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_press_too_high,
{ "System pressure too high", "zbee_zcl_hvac.pump_config_control.attr.alarm.press_too_high", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_PRESSURE_TOO_HIGH, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_dry_running,
{ "Dry running", "zbee_zcl_hvac.pump_config_control.attr.alarm.dry_running", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_DRY_RUNNING, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_mtr_temp_too_high,
{ "Motor temperature too high", "zbee_zcl_hvac.pump_config_control.attr.alarm.mtr_temp_too_high", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_MTR_TEMP_TOO_HIGH, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_pump_mtr_fatal_fail,
{ "Pump motor has fatal failure", "zbee_zcl_hvac.pump_config_control.attr.alarm.mtr_fatal_fail", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_PUMP_MTR_FATAL_FAILURE, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_elec_temp_too_high,
{ "Electronic temperature too high", "zbee_zcl_hvac.pump_config_control.attr.alarm.elec_temp_too_high", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_ELEC_TEMP_TOO_HIGH, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_pump_block,
{ "Pump blocked", "zbee_zcl_hvac.pump_config_control.attr.alarm.pump_block", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_PUMP_BLOCK, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_sensor_fail,
{ "Sensor failure", "zbee_zcl_hvac.pump_config_control.attr.alarm.sensor_fail", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_SENSOR_FAILURE, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_elec_non_fatal_fail,
{ "Electronic non-fatal failure", "zbee_zcl_hvac.pump_config_control.attr.alarm.elec_non_fatal_fail", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_ELEC_NON_FATAL_FAILURE, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_fatal_fail,
{ "Electronic fatal failure", "zbee_zcl_hvac.pump_config_control.attr.alarm.elec_fatal_fail", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_ELEC_FATAL_FAILURE, NULL, HFILL } },
{ &hf_zbee_zcl_pump_config_control_alarm_gen_fault,
{ "Genral fault", "zbee_zcl_hvac.pump_config_control.attr.alarm.gen_fault", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
ZBEE_ZCL_PUMP_CONFIG_CONTROL_ALARM_GENERAL_FAULT, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_PUMP_CONFIG_CONTROL_NUM_ETT];
ett[0] = &ett_zbee_zcl_pump_config_control;
ett[1] = &ett_zbee_zcl_pump_config_control_status;
ett[2] = &ett_zbee_zcl_pump_config_control_alarm;
proto_zbee_zcl_pump_config_control = proto_register_protocol("ZigBee ZCL Pump Configuration and Control", "ZCL Pump Configuration and Control", ZBEE_PROTOABBREV_ZCL_PUMP_CONFIG_CTRL);
proto_register_field_array(proto_zbee_zcl_pump_config_control, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_PUMP_CONFIG_CTRL, dissect_zbee_zcl_pump_config_control, proto_zbee_zcl_pump_config_control);
}
void
proto_reg_handoff_zbee_zcl_pump_config_control(void)
{
dissector_handle_t pump_config_ctrl_handle;
pump_config_ctrl_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_PUMP_CONFIG_CTRL);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_PUMP_CONFIG_CONTROL, pump_config_ctrl_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_pump_config_control,
ett_zbee_zcl_pump_config_control,
ZBEE_ZCL_CID_PUMP_CONFIG_CONTROL,
hf_zbee_zcl_pump_config_control_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_pump_config_control_attr_data
);
}
static int
dissect_zbee_zcl_fan_control(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_fan_control_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_FAN_CONTROL_FAN_MODE:
proto_tree_add_item(tree, hf_zbee_zcl_fan_control_attr_fan_mode, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_FAN_CONTROL_FAN_MODE_SEQUENCE:
proto_tree_add_item(tree, hf_zbee_zcl_fan_control_attr_fan_mode_seq, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_fan_control(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_fan_control_attr_id,
{ "Attribute", "zbee_zcl_hvac.fan_control.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_fan_control_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_fan_control_attr_fan_mode,
{ "Fan Mode", "zbee_zcl_hvac.fan_control.attr.fan_mode", FT_UINT8, BASE_HEX, VALS(zbee_zcl_fan_control_fan_mode_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_fan_control_attr_fan_mode_seq,
{ "Fan Mode Sequence", "zbee_zcl_hvac.fan_control.attr.fan_mode_seq", FT_UINT8, BASE_HEX, VALS(zbee_zcl_fan_control_fan_mode_seq_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_FAN_CONTROL_NUM_ETT];
ett[0] = &ett_zbee_zcl_fan_control;
proto_zbee_zcl_fan_control = proto_register_protocol("ZigBee ZCL Fan Control", "ZCL Fan Control", ZBEE_PROTOABBREV_ZCL_FAN_CONTROL);
proto_register_field_array(proto_zbee_zcl_fan_control, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_FAN_CONTROL, dissect_zbee_zcl_fan_control, proto_zbee_zcl_fan_control);
}
void
proto_reg_handoff_zbee_zcl_fan_control(void)
{
dissector_handle_t fan_control_handle;
fan_control_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_FAN_CONTROL);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_FAN_CONTROL, fan_control_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_fan_control,
ett_zbee_zcl_fan_control,
ZBEE_ZCL_CID_FAN_CONTROL,
hf_zbee_zcl_fan_control_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_fan_control_attr_data
);
}
static int
dissect_zbee_zcl_dehumidification_control(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);;
}
void
dissect_zcl_dehumidification_control_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_DEHUMIDIFICATION_CONTROL_RELATIVE_HUMIDITY_MODE:
proto_tree_add_item(tree, hf_zbee_zcl_dehumidification_control_attr_rel_hum_mode, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_DEHUMIDIFICATION_CONTROL_DEHUM_LOCKOUT:
proto_tree_add_item(tree, hf_zbee_zcl_dehumidification_control_attr_dehum_lockout, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_DEHUMIDIFICATION_CONTROL_RELATIVE_HUMIDITY_DISPLAY:
proto_tree_add_item(tree, hf_zbee_zcl_dehumidification_control_attr_rel_hum_display, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_DEHUMIDIFICATION_CONTROL_RELATIVE_HUMIDITY:
case ZBEE_ZCL_ATTR_ID_DEHUMIDIFICATION_CONTROL_DEHUM_COOLING:
case ZBEE_ZCL_ATTR_ID_DEHUMIDIFICATION_CONTROL_RH_DEHUM_SETPOINT:
case ZBEE_ZCL_ATTR_ID_DEHUMIDIFICATION_CONTROL_DEHUM_HYSTERESIS:
case ZBEE_ZCL_ATTR_ID_DEHUMIDIFICATION_CONTROL_DEHUM_MAX_COOL:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_dehumidification_control(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_dehumidification_control_attr_id,
{ "Attribute", "zbee_zcl_hvac.dehumidification_control.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_dehumidification_control_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_dehumidification_control_attr_rel_hum_mode,
{ "Relative Humidity Mode", "zbee_zcl_hvac.dehumidification_control.attr.rel_humidity_mode", FT_UINT8, BASE_HEX, VALS(zbee_zcl_dehumidification_control_rel_hum_mode_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_dehumidification_control_attr_dehum_lockout,
{ "Dehumidification Lockout", "zbee_zcl_hvac.dehumidification_control.attr.dehumidification_lockout", FT_UINT8, BASE_HEX, VALS(zbee_zcl_dehumidification_control_dehum_lockout_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_dehumidification_control_attr_rel_hum_display,
{ "Relative Humidity Display", "zbee_zcl_hvac.dehumidification_control.attr.rel_humidity_display", FT_UINT8, BASE_HEX, VALS(zbee_zcl_dehumidification_control_rel_hum_display_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_DEHUMIDIFICATION_CONTROL_NUM_ETT];
ett[0] = &ett_zbee_zcl_dehumidification_control;
proto_zbee_zcl_dehumidification_control = proto_register_protocol("ZigBee ZCL Dehumidification Control", "ZCL Dehumidification Control", ZBEE_PROTOABBREV_ZCL_DEHUMIDIFICATION_CONTROL);
proto_register_field_array(proto_zbee_zcl_dehumidification_control, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_DEHUMIDIFICATION_CONTROL, dissect_zbee_zcl_dehumidification_control, proto_zbee_zcl_dehumidification_control);
}
void
proto_reg_handoff_zbee_zcl_dehumidification_control(void)
{
dissector_handle_t dehumidification_control_handle;
dehumidification_control_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_DEHUMIDIFICATION_CONTROL);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_DEHUMIDIFICATION_CONTROL, dehumidification_control_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_dehumidification_control,
ett_zbee_zcl_dehumidification_control,
ZBEE_ZCL_CID_DEHUMIDIFICATION_CONTROL,
hf_zbee_zcl_dehumidification_control_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_dehumidification_control_attr_data
);
}
static int
dissect_zbee_zcl_thermostat_ui_config(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_thermostat_ui_config_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_THERMOSTAT_UI_CONFIG_TEMP_DISP_MODE:
proto_tree_add_item(tree, hf_zbee_zcl_thermostat_ui_config_attr_temp_disp_mode, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_THERMOSTAT_UI_CONFIG_KEYPAD_LOCKOUT:
proto_tree_add_item(tree, hf_zbee_zcl_thermostat_ui_config_attr_keypad_lockout, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_thermostat_ui_config(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_thermostat_ui_config_attr_id,
{ "Attribute", "zbee_zcl_hvac.thermostat_ui_config.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_thermostat_ui_config_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_thermostat_ui_config_attr_temp_disp_mode,
{ "Temperature Display Mode", "zbee_zcl_hvac.thermostat_ui_config.attr.temp_disp_mode", FT_UINT8, BASE_HEX, VALS(zbee_zcl_thermostat_ui_config_temp_disp_mode_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_thermostat_ui_config_attr_keypad_lockout,
{ "Keypad Lockout", "zbee_zcl_hvac.thermostat_ui_config.attr.keypad_lockout", FT_UINT8, BASE_HEX, VALS(zbee_zcl_thermostat_ui_config_keypad_lockout_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_THERMOSTAT_UI_CONFIG_NUM_ETT];
ett[0] = &ett_zbee_zcl_thermostat_ui_config;
proto_zbee_zcl_thermostat_ui_config = proto_register_protocol("ZigBee ZCL Thermostat User Interface Configuration", "ZCL Thermostat User Interface Configuration", ZBEE_PROTOABBREV_ZCL_THERMOSTAT_UI_CONFIG);
proto_register_field_array(proto_zbee_zcl_thermostat_ui_config, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_THERMOSTAT_UI_CONFIG, dissect_zbee_zcl_thermostat_ui_config, proto_zbee_zcl_thermostat_ui_config);
}
void
proto_reg_handoff_zbee_zcl_thermostat_ui_config(void)
{
dissector_handle_t thermostat_ui_config_handle;
thermostat_ui_config_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_THERMOSTAT_UI_CONFIG);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_THERMOSTAT_UI_CONFIG, thermostat_ui_config_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_thermostat_ui_config,
ett_zbee_zcl_thermostat_ui_config,
ZBEE_ZCL_CID_THERMOSTAT_UI_CONFIG,
hf_zbee_zcl_thermostat_ui_config_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_thermostat_ui_config_attr_data
);
}
