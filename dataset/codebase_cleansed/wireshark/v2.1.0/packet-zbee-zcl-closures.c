static int
dissect_zbee_zcl_shade_configuration(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
dissect_zcl_shade_configuration_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int * shade_config_status[] = {
&hf_zbee_zcl_shade_configuration_status_shade_operational,
&hf_zbee_zcl_shade_configuration_status_shade_adjusting,
&hf_zbee_zcl_shade_configuration_status_shade_direction,
&hf_zbee_zcl_shade_configuration_status_motor_forward_direction,
NULL
};
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_SHADE_CONFIGURATION_STATUS:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_shade_configuration_status, ett_zbee_zcl_shade_configuration_status, shade_config_status, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_SHADE_CONFIGURATION_MODE:
proto_tree_add_item(tree, hf_zbee_zcl_shade_configuration_mode, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_SHADE_CONFIGURATION_PHYSICAL_CLOSED_LIMIT:
case ZBEE_ZCL_ATTR_ID_SHADE_CONFIGURATION_MOTOR_STEP_SIZE:
case ZBEE_ZCL_ATTR_ID_SHADE_CONFIGURATION_CLOSED_LIMIT:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_shade_configuration(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_shade_configuration_attr_id,
{ "Attribute", "zbee_zcl_closures.shade_configuration.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_shade_configuration_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_shade_configuration_status,
{ "Shade Configuration Status", "zbee_zcl_closures.shade_configuration.attr.status", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_shade_configuration_status_shade_operational,
{ "Shade Operational", "zbee_zcl_closures.shade_configuration.attr.status.shade_operational", FT_BOOLEAN, 8, TFS(&tfs_no_yes),
ZBEE_ZCL_SHADE_CONFIGURATION_STATUS_SHADE_OPERATIONAL, NULL, HFILL } },
{ &hf_zbee_zcl_shade_configuration_status_shade_adjusting,
{ "Shade Adjusting", "zbee_zcl_closures.shade_configuration.attr.status.shade_adjusting", FT_BOOLEAN, 8, TFS(&tfs_no_yes),
ZBEE_ZCL_SHADE_CONFIGURATION_STATUS_SHADE_ADJUSTING, NULL, HFILL } },
{ &hf_zbee_zcl_shade_configuration_status_shade_direction,
{ "Shade Direction", "zbee_zcl_closures.shade_configuration.attr.status.shade_direction", FT_UINT8, BASE_DEC, VALS(zbee_zcl_shade_configuration_shade_motor_direction_names),
ZBEE_ZCL_SHADE_CONFIGURATION_STATUS_SHADE_DIRECTION, NULL, HFILL } },
{ &hf_zbee_zcl_shade_configuration_status_motor_forward_direction,
{ "Motor Forward Direction", "zbee_zcl_closures.shade_configuration.attr.status.motor_forward_direction", FT_UINT8, BASE_DEC, VALS(zbee_zcl_shade_configuration_shade_motor_direction_names),
ZBEE_ZCL_SHADE_CONFIGURATION_STATUS_MOTOR_FORWARD_DIRECTION, NULL, HFILL } },
{ &hf_zbee_zcl_shade_configuration_mode,
{ "Mode", "zbee_zcl_closures.shade_configuration.attr.mode", FT_UINT8, BASE_HEX, VALS(zbee_zcl_shade_configuration_mode_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_SHADE_CONFIGURATION_NUM_ETT];
ett[0] = &ett_zbee_zcl_shade_configuration;
ett[1] = &ett_zbee_zcl_shade_configuration_status;
proto_zbee_zcl_shade_configuration = proto_register_protocol("ZigBee ZCL Shade Configuration", "ZCL Shade Configuration", ZBEE_PROTOABBREV_ZCL_SHADE_CONFIG);
proto_register_field_array(proto_zbee_zcl_shade_configuration, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_SHADE_CONFIG, dissect_zbee_zcl_shade_configuration, proto_zbee_zcl_shade_configuration);
}
void
proto_reg_handoff_zbee_zcl_shade_configuration(void)
{
dissector_handle_t shade_config_handle;
shade_config_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_SHADE_CONFIG);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_SHADE_CONFIG, shade_config_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_shade_configuration,
ett_zbee_zcl_shade_configuration,
ZBEE_ZCL_CID_SHADE_CONFIG,
hf_zbee_zcl_shade_configuration_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_shade_configuration_attr_data
);
}
static int
dissect_zbee_zcl_door_lock(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
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
val_to_str_const(cmd_id, zbee_zcl_door_lock_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_door_lock_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_door_lock, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_DOOR_LOCK_LOCK_DOOR:
case ZBEE_ZCL_CMD_ID_DOOR_LOCK_UNLOCK_DOOR:
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_door_lock_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_door_lock_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_door_lock, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_DOOR_LOCK_LOCK_DOOR_RESPONSE:
case ZBEE_ZCL_CMD_ID_DOOR_LOCK_UNLOCK_DOOR_RESPONSE:
dissect_zcl_door_lock_lock_unlock_door_response(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_door_lock_lock_unlock_door_response(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_door_lock_status, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
void
dissect_zcl_door_lock_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_DOOR_LOCK_LOCK_STATE:
proto_tree_add_item(tree, hf_zbee_zcl_door_lock_lock_state, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_DOOR_LOCK_LOCK_TYPE:
proto_tree_add_item(tree, hf_zbee_zcl_door_lock_lock_type, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_DOOR_LOCK_ACTUATOR_ENABLED:
proto_tree_add_item(tree, hf_zbee_zcl_door_lock_actuator_enabled, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_DOOR_LOCK_DOOR_STATE:
proto_tree_add_item(tree, hf_zbee_zcl_door_lock_door_state, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_DOOR_LOCK_DOOR_OPEN_EVENTS:
case ZBEE_ZCL_ATTR_ID_DOOR_LOCK_DOOR_CLOSED_EVENTS:
case ZBEE_ZCL_ATTR_ID_DOOR_LOCK_OPEN_PERIOD:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_door_lock(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_door_lock_attr_id,
{ "Attribute", "zbee_zcl_closures.door_lock.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_door_lock_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_door_lock_lock_state,
{ "Lock State", "zbee_zcl_closures.door_lock.attr.lock_state", FT_UINT8, BASE_HEX, VALS(zbee_zcl_door_lock_lock_state_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_door_lock_lock_type,
{ "Lock Type", "zbee_zcl_closures.door_lock.attr.lock_type", FT_UINT8, BASE_HEX, VALS(zbee_zcl_door_lock_lock_type_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_door_lock_door_state,
{ "Door State", "zbee_zcl_closures.door_lock.attr.door_state", FT_UINT8, BASE_HEX, VALS(zbee_zcl_door_lock_door_state_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_door_lock_actuator_enabled,
{ "Actuator enabled", "zbee_zcl_closures.door_lock.attr.actuator_enabled", FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled),
0x01, NULL, HFILL } },
{ &hf_zbee_zcl_door_lock_status,
{ "Lock Status", "zbee_zcl_closures.door_lock.status", FT_UINT8, BASE_HEX, VALS(zbee_zcl_status_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_door_lock_srv_rx_cmd_id,
{ "Command", "zbee_zcl_closures.door_lock.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_door_lock_srv_rx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_door_lock_srv_tx_cmd_id,
{ "Command", "zbee_zcl_closures.door_lock.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_door_lock_srv_tx_cmd_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_DOOR_LOCK_NUM_ETT];
ett[0] = &ett_zbee_zcl_door_lock;
proto_zbee_zcl_door_lock = proto_register_protocol("ZigBee ZCL Door Lock", "ZCL Door Lock", ZBEE_PROTOABBREV_ZCL_DOOR_LOCK);
proto_register_field_array(proto_zbee_zcl_door_lock, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_DOOR_LOCK, dissect_zbee_zcl_door_lock, proto_zbee_zcl_door_lock);
}
void
proto_reg_handoff_zbee_zcl_door_lock(void)
{
dissector_handle_t door_lock_handle;
door_lock_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_DOOR_LOCK);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_DOOR_LOCK, door_lock_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_door_lock,
ett_zbee_zcl_door_lock,
ZBEE_ZCL_CID_DOOR_LOCK,
hf_zbee_zcl_door_lock_attr_id,
hf_zbee_zcl_door_lock_srv_rx_cmd_id,
hf_zbee_zcl_door_lock_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_door_lock_attr_data
);
}
