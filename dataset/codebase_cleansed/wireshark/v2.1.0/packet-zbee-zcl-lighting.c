static int
dissect_zbee_zcl_color_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
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
val_to_str_const(cmd_id, zbee_zcl_color_control_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_color_control_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_color_control, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_COLOR_CONTROL_MOVE_TO_HUE:
dissect_zcl_color_control_move_to_hue(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_COLOR_CONTROL_MOVE_HUE:
dissect_zcl_color_control_move_hue_saturation(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_COLOR_CONTROL_STEP_HUE:
dissect_zcl_color_control_step_hue_saturation(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_COLOR_CONTROL_MOVE_TO_SATURATION:
dissect_zcl_color_control_move_to_saturation(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_COLOR_CONTROL_MOVE_SATURATION:
dissect_zcl_color_control_move_hue_saturation(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_COLOR_CONTROL_STEP_SATURATION:
dissect_zcl_color_control_step_hue_saturation(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_COLOR_CONTROL_MOVE_TO_HUE_AND_SATURATION:
dissect_zcl_color_control_move_to_hue_and_saturation(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_COLOR_CONTROL_MOVE_TO_COLOR:
dissect_zcl_color_control_move_to_color(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_COLOR_CONTROL_MOVE_COLOR:
dissect_zcl_color_control_move_color(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_COLOR_CONTROL_STEP_COLOR:
dissect_zcl_color_control_step_color(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_COLOR_CONTROL_MOVE_TO_COLOR_TEMP:
dissect_zcl_color_control_move_to_color_temp(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_color_control_move_to_hue(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_color_control_hue, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_direction, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_transit_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_color_control_move_hue_saturation(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_color_control_move_mode, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_rate, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void
dissect_zcl_color_control_step_hue_saturation(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_color_control_step_mode, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_step_size, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_transit_time_8bit, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void
dissect_zcl_color_control_move_to_saturation(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_color_control_saturation, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_transit_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_color_control_move_to_hue_and_saturation(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_color_control_hue, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_saturation, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_transit_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_color_control_move_to_color(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_color_control_color_X, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_color_Y, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_transit_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_color_control_move_color(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_color_control_rate_X, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_rate_Y, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_color_control_step_color(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_color_control_step_X, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_step_Y, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_transit_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_color_control_move_to_color_temp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_color_control_color_temp, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_color_control_transit_time, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
void
dissect_zcl_color_control_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_DRIFT_COMPENSATION:
proto_tree_add_item(tree, hf_zbee_zcl_color_control_attr_drift_compensation, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_COLOR_MODE:
proto_tree_add_item(tree, hf_zbee_zcl_color_control_attr_color_mode, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_REMAINING_TIME:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_CURRENT_HUE:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_CURRENT_SATURATION:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_CURRENT_X:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_CURRENT_Y:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_COMPENSATION_TEXT:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_COLOR_TEMP:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_NO_OF_PRIMARIES:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_1X:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_1Y:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_1INTENSITY:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_2X:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_2Y:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_2INTENSITY:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_3X:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_3Y:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_3INTENSITY:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_4X:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_4Y:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_4INTENSITY:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_5X:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_5Y:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_5INTENSITY:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_6X:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_6Y:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_PRIMARY_6INTENSITY:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_WHITE_POINT_X:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_WHITE_POINT_Y:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_COLOR_POINT_RX:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_COLOR_POINT_RY:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_COLOR_POINT_R_INTENSITY:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_COLOR_POINT_GX:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_COLOR_POINT_GY:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_COLOR_POINT_G_INTENSITY:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_COLOR_POINT_BX:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_COLOR_POINT_BY:
case ZBEE_ZCL_ATTR_ID_COLOR_CONTROL_COLOR_POINT_B_INTENSITY:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_color_control(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_color_control_attr_id,
{ "Attribute", "zbee_zcl_lighting.color_control.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_color_control_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_color_control_attr_drift_compensation,
{ "Drift Compensation", "zbee_zcl_lighting.color_control.attr.drift_compensation", FT_UINT8, BASE_HEX, VALS(zbee_zcl_color_control_drift_compensation_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_color_control_attr_color_mode,
{ "Color Mode", "zbee_zcl_lighting.color_control.color_mode", FT_UINT8, BASE_HEX, VALS(zbee_zcl_color_control_color_mode_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_color_control_hue,
{ "Hue", "zbee_zcl_lighting.color_control.hue", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_color_control_direction,
{ "Direction", "zbee_zcl_lighting.color_control.direction", FT_UINT8, BASE_HEX, VALS(zbee_zcl_color_control_direction_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_color_control_transit_time,
{ "Transition Time", "zbee_zcl_lighting.color_control.transit_time", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_color_control_move_mode,
{ "Move Mode", "zbee_zcl_lighting.color_control.move_mode", FT_UINT8, BASE_HEX, VALS(zbee_zcl_color_control_move_mode),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_color_control_rate,
{ "Rate", "zbee_zcl_lighting.color_control.rate", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_color_control_step_mode,
{ "Step Mode", "zbee_zcl_lighting.color_control.step_mode", FT_UINT8, BASE_HEX, VALS(zbee_zcl_color_control_step_mode),
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_color_control_step_size,
{ "Step Size", "zbee_zcl_lighting.color_control.step_size", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_color_control_transit_time_8bit,
{ "Transition Time", "zbee_zcl_lighting.color_control.transition_time_8bit", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_color_control_saturation,
{ "Saturation", "zbee_zcl_lighting.color_control.saturation", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_color_control_color_X,
{ "Color X", "zbee_zcl_lighting.color_control.color_x", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_color_control_color_Y,
{ "Color Y", "zbee_zcl_lighting.color_control.color_y", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_color_control_rate_X,
{ "Rate X", "zbee_zcl_lighting.color_control.rate_x", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_color_control_rate_Y,
{ "Rate Y", "zbee_zcl_lighting.color_control.rate_y", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_color_control_step_X,
{ "Step X", "zbee_zcl_lighting.color_control.step_x", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_color_control_step_Y,
{ "Step Y", "zbee_zcl_lighting.color_control.step_y", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_color_control_color_temp,
{ "Color temperature", "zbee_zcl_lighting.color_control.color_temp", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL }},
{ &hf_zbee_zcl_color_control_srv_rx_cmd_id,
{ "Command", "zbee_zcl_lighting.color_control.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_color_control_srv_rx_cmd_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_COLOR_CONTROL_NUM_ETT];
ett[0] = &ett_zbee_zcl_color_control;
proto_zbee_zcl_color_control = proto_register_protocol("ZigBee ZCL Color Control", "ZCL Color Control", ZBEE_PROTOABBREV_ZCL_COLOR_CONTROL);
proto_register_field_array(proto_zbee_zcl_color_control, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_COLOR_CONTROL, dissect_zbee_zcl_color_control, proto_zbee_zcl_color_control);
}
void
proto_reg_handoff_zbee_zcl_color_control(void)
{
dissector_handle_t color_control_handle;
color_control_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_COLOR_CONTROL);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_COLOR_CONTROL, color_control_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_color_control,
ett_zbee_zcl_color_control,
ZBEE_ZCL_CID_COLOR_CONTROL,
hf_zbee_zcl_color_control_attr_id,
hf_zbee_zcl_color_control_srv_rx_cmd_id,
-1,
(zbee_zcl_fn_attr_data)dissect_zcl_color_control_attr_data
);
}
static int
dissect_zbee_zcl_ballast_configuration(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_ballast_configuration_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int * ballast_status[] = {
&hf_zbee_zcl_ballast_configuration_status_non_operational,
&hf_zbee_zcl_ballast_configuration_status_lamp_not_in_socket,
NULL
};
static const int * lamp_alarm_mode[] = {
&hf_zbee_zcl_ballast_configuration_lamp_alarm_mode_lamp_burn_hours,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_BALLAST_STATUS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_ballast_configuration_status, ett_zbee_zcl_ballast_configuration_status, ballast_status, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_LAMP_ALARM_MODE:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_ballast_configuration_lamp_alarm_mode, ett_zbee_zcl_ballast_configuration_lamp_alarm_mode, lamp_alarm_mode, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_PHYSICAL_MIN_LEVEL:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_PHYSICAL_MAX_LEVEL:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_MIN_LEVEL:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_MAX_LEVEL:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_POWER_ON_LEVEL:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_POWER_ON_FADE_TIME:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_INTRINSIC_BALLAST_FACTOR:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_BALLAST_FACT_ADJ:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_LAMP_QUANTITY:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_LAMP_TYPE:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_LAMP_MANUFACTURER:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_LAMP_RATED_HOURS:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_LAMP_BURN_HOURS:
case ZBEE_ZCL_ATTR_ID_BALLAST_CONFIGURATION_LAMP_BURN_HOURS_TRIP_POINT:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_ballast_configuration(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_ballast_configuration_attr_id,
{ "Attribute", "zbee_zcl_lighting.ballast_configuration.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_ballast_configuration_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ballast_configuration_status,
{ "Status", "zbee_zcl_lighting.ballast_configuration.attr.status", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ballast_configuration_status_non_operational,
{ "Non-operational", "zbee_zcl_lighting.ballast_configuration.attr.status.non_operational", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ballast_configuration_status_non_operational_names),
ZBEE_ZCL_BALLAST_CONFIGURATION_STATUS_NON_OPERATIONAL, NULL, HFILL } },
{ &hf_zbee_zcl_ballast_configuration_status_lamp_not_in_socket,
{ "Not in Socket", "zbee_zcl_lighting.ballast_configuration.attr.status.not_in_socket", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ballast_configuration_status_lamp_not_in_socket_names),
ZBEE_ZCL_BALLAST_CONFIGURATION_STATUS_LAMP_NOT_IN_SOCKET, NULL, HFILL } },
{ &hf_zbee_zcl_ballast_configuration_lamp_alarm_mode,
{ "Lamp Alarm Mode", "zbee_zcl_lighting.ballast_configuration.attr.lamp_alarm_mode", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ballast_configuration_lamp_alarm_mode_lamp_burn_hours,
{ "Lamp Burn Hours", "zbee_zcl_lighting.ballast_configuration.attr.lamp_alarm_mode.lamp_burn_hours", FT_BOOLEAN, 8, NULL,
ZBEE_ZCL_BALLAST_CONFIGURATION_LAMP_ALARM_MODE_LAMP_BURN_HOURS, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_BALLAST_CONFIGURATION_NUM_ETT];
ett[0] = &ett_zbee_zcl_ballast_configuration;
ett[1] = &ett_zbee_zcl_ballast_configuration_status;
ett[2] = &ett_zbee_zcl_ballast_configuration_lamp_alarm_mode;
proto_zbee_zcl_ballast_configuration = proto_register_protocol("ZigBee ZCL Ballast Configuration", "ZCL Ballast Configuration", ZBEE_PROTOABBREV_ZCL_BALLAST_CONFIG);
proto_register_field_array(proto_zbee_zcl_ballast_configuration, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_BALLAST_CONFIG, dissect_zbee_zcl_ballast_configuration, proto_zbee_zcl_ballast_configuration);
}
void
proto_reg_handoff_zbee_zcl_ballast_configuration(void)
{
dissector_handle_t ballast_config_handle;
ballast_config_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_BALLAST_CONFIG);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_BALLAST_CONFIG, ballast_config_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_ballast_configuration,
ett_zbee_zcl_ballast_configuration,
ZBEE_ZCL_CID_BALLAST_CONFIG,
hf_zbee_zcl_ballast_configuration_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_ballast_configuration_attr_data
);
}
