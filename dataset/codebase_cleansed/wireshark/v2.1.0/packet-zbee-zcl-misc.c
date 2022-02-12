static void
dissect_zcl_thermostat_schedule_days(proto_tree *tree, tvbuff_t *tvb, guint offset)
{
static const int *thermostat_schedule_days[] = {
&hf_zbee_zcl_thermostat_schedule_day_sunday,
&hf_zbee_zcl_thermostat_schedule_day_monday,
&hf_zbee_zcl_thermostat_schedule_day_tuesday,
&hf_zbee_zcl_thermostat_schedule_day_wednesday,
&hf_zbee_zcl_thermostat_schedule_day_thursday,
&hf_zbee_zcl_thermostat_schedule_day_friday,
&hf_zbee_zcl_thermostat_schedule_day_saturday,
&hf_zbee_zcl_thermostat_schedule_day_vacation,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_zcl_thermostat_schedule_day_sequence,
ett_zbee_zcl_thermostat_schedule_days, thermostat_schedule_days, ENC_NA);
}
static void
dissect_zcl_thermostat_schedule_mode(proto_tree *tree, tvbuff_t *tvb, guint offset)
{
static const int *thermostat_schedule_modes[] = {
&hf_zbee_zcl_thermostat_schedule_mode_heat,
&hf_zbee_zcl_thermostat_schedule_mode_cool,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_zcl_thermostat_schedule_mode_sequence,
ett_zbee_zcl_thermostat_schedule_mode, thermostat_schedule_modes, ENC_NA);
}
static int
dissect_zcl_thermostat_schedule(proto_tree *tree, tvbuff_t *tvb, guint offset)
{
guint start = offset;
guint8 num_transitions;
guint8 mode_sequence;
int i;
num_transitions = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_zcl_thermostat_schedule_num_trans, tvb, offset, 1,
num_transitions);
offset++;
dissect_zcl_thermostat_schedule_days(tree, tvb, offset);
offset++;
mode_sequence = tvb_get_guint8(tvb, offset);
dissect_zcl_thermostat_schedule_mode(tree, tvb, offset);
offset++;
for (i = 0; i < num_transitions; i++) {
nstime_t tv;
tv.secs = tvb_get_letohs(tvb, offset) * 60;
tv.nsecs = 0;
proto_tree_add_time(tree, hf_zbee_zcl_thermostat_schedule_time, tvb, offset, 2, &tv);
offset += 2;
if (mode_sequence & ZBEE_ZCL_CMD_THERMOSTAT_SCHEDULE_MODE_SEQUENCE_HEAT) {
float setpoint = (gint16)tvb_get_letohs(tvb, offset);
proto_tree_add_float(tree, hf_zbee_zcl_thermostat_schedule_heat,
tvb, offset, 2, (setpoint / 100.0f));
offset += 2;
}
if (mode_sequence & ZBEE_ZCL_CMD_THERMOSTAT_SCHEDULE_MODE_SEQUENCE_COOL) {
float setpoint = (gint16)tvb_get_letohs(tvb, offset);
proto_tree_add_float(tree, hf_zbee_zcl_thermostat_schedule_cool,
tvb, offset, 2, (setpoint / 100.0f));
offset += 2;
}
}
return (offset - start);
}
static int
dissect_zbee_zcl_thermostat(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
float amount;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_thermostat_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_thermostat_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
offset++;
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_THERMOSTAT_SETPOINT:
proto_tree_add_item(tree, hf_zbee_zcl_thermostat_setpoint_mode,
tvb, offset, 1, ENC_NA);
offset++;
amount = (gint8)tvb_get_guint8(tvb, offset);
proto_tree_add_float(tree, hf_zbee_zcl_thermostat_setpoint_amount,
tvb, offset, 1, (amount / 100.0f));
offset++;
break;
case ZBEE_ZCL_CMD_ID_THERMOSTAT_GET_SCHEDULE:
dissect_zcl_thermostat_schedule_days(tree, tvb, offset);
offset++;
dissect_zcl_thermostat_schedule_mode(tree, tvb, offset);
offset++;
break;
case ZBEE_ZCL_CMD_ID_THERMOSTAT_SET_SCHEDULE:
dissect_zcl_thermostat_schedule(tree, tvb, offset);
break;
case ZBEE_ZCL_CMD_ID_THERMOSTAT_GET_RELAY_LOG:
default:
break;
}
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_thermostat_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_thermostat_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
offset++;
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_THERMOSTAT_GET_SCHEDULE_RESPONSE:
dissect_zcl_thermostat_schedule(tree, tvb, offset);
break;
case ZBEE_ZCL_CMD_ID_THERMOSTAT_GET_RELAY_LOG_RESPONSE:
default:
break;
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_thermostat_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_thermostat(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_thermostat_attr_id,
{ "Attribute", "zbee_zcl_hvac.thermostat.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_thermostat_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_thermostat_srv_rx_cmd_id,
{ "Command", "zbee_zcl_hvac.thermostat.cmd.srv_rx.id", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_thermostat_srv_rx_cmd_names), 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_thermostat_srv_tx_cmd_id,
{ "Command", "zbee_zcl_hvac.thermostat.cmd.srv_tx.id", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_thermostat_srv_tx_cmd_names), 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_thermostat_setpoint_mode,
{ "Mode", "zbee_zcl_hvac.thermostat.mode", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_thermostat_setpoint_mode_names), 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_thermostat_setpoint_amount,
{ "Amount", "zbee_zcl_hvac.thermostat.amount", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_num_trans,
{ "Number of Transitions for Sequence", "zbee_zcl_hvac.thermostat.num_trans", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_day_sequence,
{ "Days of Week for Sequence", "zbee_zcl_hvac.thermostat.day_sequence", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_day_sunday,
{ "Sunday", "zbee_zcl_hvac.thermostat.day.sunday", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x01, NULL,
HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_day_monday,
{ "Monday", "zbee_zcl_hvac.thermostat.day.monday", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x02, NULL,
HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_day_tuesday,
{ "Tuesday", "zbee_zcl_hvac.thermostat.day.tuesday", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x04, NULL,
HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_day_wednesday,
{ "Wednesday", "zbee_zcl_hvac.thermostat.day.wednesday", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x08, NULL,
HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_day_thursday,
{ "Thursday", "zbee_zcl_hvac.thermostat.day.thursday", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x10, NULL,
HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_day_friday,
{ "Friday", "zbee_zcl_hvac.thermostat.day.friday", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x20, NULL,
HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_day_saturday,
{ "Saturday", "zbee_zcl_hvac.thermostat.day.saturday", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x40, NULL,
HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_day_vacation,
{ "Away/Vacation", "zbee_zcl_hvac.thermostat.day.vacation", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x80, NULL,
HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_mode_sequence,
{ "Mode for Sequence", "zbee_zcl_hvac.thermostat.mode_sequence", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_mode_heat,
{ "Heating", "zbee_zcl_hvac.thermostat.mode.heat", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x01, NULL, HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_mode_cool,
{ "Cooling", "zbee_zcl_hvac.thermostat.mode.cool", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x02, NULL, HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_time,
{ "Transition Time", "zbee_zcl_hvac.thermostat.time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Setpoint transition time relative to midnight of the scheduled day", HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_heat,
{ "Heating Setpoint", "zbee_zcl_hvac.thermostat.heat", FT_FLOAT, BASE_NONE, NULL, 0x0,
"Heating setpoint in degrees Celcius", HFILL }},
{ &hf_zbee_zcl_thermostat_schedule_cool,
{ "Cooling Setpoint", "zbee_zcl_hvac.thermostat.cool", FT_FLOAT, BASE_NONE, NULL, 0x0,
"Cooling setpoint in degrees Celcius", HFILL }}
};
static gint *ett[ZBEE_ZCL_THERMOSTAT_NUM_ETT];
ett[0] = &ett_zbee_zcl_thermostat;
ett[1] = &ett_zbee_zcl_thermostat_schedule_days;
ett[2] = &ett_zbee_zcl_thermostat_schedule_mode;
proto_zbee_zcl_thermostat = proto_register_protocol("ZigBee ZCL Thermostat", "ZCL Thermostat", ZBEE_PROTOABBREV_ZCL_THERMOSTAT);
proto_register_field_array(proto_zbee_zcl_thermostat, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_THERMOSTAT, dissect_zbee_zcl_thermostat, proto_zbee_zcl_thermostat);
}
void
proto_reg_handoff_zbee_zcl_thermostat(void)
{
dissector_handle_t thermostat_handle;
thermostat_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_THERMOSTAT);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_THERMOSTAT, thermostat_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_thermostat,
ett_zbee_zcl_thermostat,
ZBEE_ZCL_CID_THERMOSTAT,
hf_zbee_zcl_thermostat_attr_id,
hf_zbee_zcl_thermostat_srv_rx_cmd_id,
hf_zbee_zcl_thermostat_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_thermostat_attr_data
);
}
static void
dissect_zcl_ias_zone_status(proto_tree *tree, tvbuff_t *tvb, guint offset)
{
static const int *ias_zone_statuses[] = {
&hf_zbee_zcl_ias_zone_status_alarm1,
&hf_zbee_zcl_ias_zone_status_alarm2,
&hf_zbee_zcl_ias_zone_status_tamper,
&hf_zbee_zcl_ias_zone_status_battery,
&hf_zbee_zcl_ias_zone_status_supervision_reports,
&hf_zbee_zcl_ias_zone_status_restore_reports,
&hf_zbee_zcl_ias_zone_status_trouble,
&hf_zbee_zcl_ias_zone_status_ac_mains,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_zcl_ias_zone_status, ett_zbee_zcl_ias_zone_status, ias_zone_statuses, ENC_NA);
}
static int
dissect_zbee_zcl_ias_zone(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
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
val_to_str_const(cmd_id, zbee_zcl_ias_zone_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_ias_zone_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
offset++;
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_IAS_ZONE_ENROLL_RESPONSE:
proto_tree_add_item(tree, hf_zbee_zcl_ias_zone_enroll_code, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_zbee_zcl_ias_zone_zone_id, tvb, offset, 1, ENC_NA);
offset++;
break;
default:
break;
}
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_ias_zone_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_ias_zone_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
offset++;
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_IAS_ZONE_ENROLL_NOTIFY:
dissect_zcl_ias_zone_status(tree, tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ias_zone_ext_status, tvb, offset,
1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ias_zone_zone_id, tvb, offset, 1,
ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ias_zone_delay, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
case ZBEE_ZCL_CMD_ID_IAS_ZONE_ENROLL_REQUEST:
default:
break;
}
}
return tvb_reported_length(tvb);
}
static void
dissect_zcl_ias_zone_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_IAS_ZONE_STATE:
proto_tree_add_item(tree, hf_zbee_zcl_ias_zone_state, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_IAS_ZONE_TYPE:
proto_tree_add_item(tree, hf_zbee_zcl_ias_zone_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_IAS_ZONE_STATUS:
dissect_zcl_ias_zone_status(tree, tvb, *offset);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_IAS_CIE_ADDRESS:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_reg_handoff_zbee_zcl_ias_zone(void)
{
dissector_handle_t zone_handle;
zone_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_IAS_ZONE);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_IAS_ZONE, zone_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_ias_zone,
ett_zbee_zcl_ias_zone,
ZBEE_ZCL_CID_IAS_ZONE,
hf_zbee_zcl_ias_zone_attr_id,
hf_zbee_zcl_ias_zone_srv_rx_cmd_id,
hf_zbee_zcl_ias_zone_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_ias_zone_attr_data
);
}
void
proto_register_zbee_zcl_ias_zone(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_ias_zone_attr_id,
{ "Attribute", "zbee_zcl_ias.zone.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_ias_zone_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ias_zone_srv_rx_cmd_id,
{ "Command", "zbee_zcl_ias.zone.cmd.srv_rx.id", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_ias_zone_srv_rx_cmd_names), 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ias_zone_srv_tx_cmd_id,
{ "Command", "zbee_zcl_ias.zone.cmd.srv_tx.id", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_ias_zone_srv_tx_cmd_names), 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ias_zone_enroll_code,
{ "Enroll response code", "zbee_zcl_ias.zone.enroll_code", FT_UINT8, BASE_HEX,
VALS(zbee_zcl_ias_zone_enroll_code_names), 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ias_zone_zone_id,
{ "Zone ID", "zbee_zcl_ias.zone.zone_id", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ias_zone_state,
{ "ZoneState", "zbee_zcl_ias.zone.state", FT_UINT16, BASE_HEX, VALS(zbee_ias_state_names), 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ias_zone_type,
{ "ZoneType", "zbee_zcl_ias.zone.type", FT_UINT16, BASE_HEX, VALS(zbee_ias_type_names), 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ias_zone_status,
{ "ZoneStatus", "zbee_zcl_ias.zone.status", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ias_zone_delay,
{ "Delay (in quarterseconds)", "zbee_zcl_ias.zone.delay", FT_UINT16, BASE_DEC, NULL, 0x0, NULL,
HFILL }},
{ &hf_zbee_zcl_ias_zone_ext_status,
{ "Extended Status", "zbee_zcl_ias.zone.ext_status", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL }},
{ &hf_zbee_zcl_ias_zone_status_alarm1,
{ "Alarm 1", "zbee_zcl_ias.zone.status.alarm_1", FT_BOOLEAN, 16, TFS(&tfs_alarmed_or_not), ZBEE_IAS_ZONE_STATUS_ALARM1, NULL,
HFILL }},
{ &hf_zbee_zcl_ias_zone_status_alarm2,
{ "Alarm 2", "zbee_zcl_ias.zone.status.alarm_2", FT_BOOLEAN, 16, TFS(&tfs_alarmed_or_not), ZBEE_IAS_ZONE_STATUS_ALARM2, NULL,
HFILL }},
{ &hf_zbee_zcl_ias_zone_status_battery,
{ "Battery", "zbee_zcl_ias.zone.status.battery", FT_BOOLEAN, 16, TFS(&tfs_battery), ZBEE_IAS_ZONE_STATUS_BATTERY, NULL,
HFILL }},
{ &hf_zbee_zcl_ias_zone_status_tamper,
{ "Tamper", "zbee_zcl_ias.zone.status.tamper", FT_BOOLEAN, 16, TFS(&tfs_tampered_or_not), ZBEE_IAS_ZONE_STATUS_TAMPER, NULL,
HFILL }},
{ &hf_zbee_zcl_ias_zone_status_supervision_reports,
{ "Supervision Reports", "zbee_zcl_ias.zone.status.supervision_reports", FT_BOOLEAN, 16,
TFS(&tfs_reports_or_not), ZBEE_IAS_ZONE_STATUS_SUPERVISION, NULL, HFILL }},
{ &hf_zbee_zcl_ias_zone_status_restore_reports,
{ "Restore Reports", "zbee_zcl_ias.zone.status.restore_reports", FT_BOOLEAN, 16,
TFS(&tfs_reports_restore), ZBEE_IAS_ZONE_STATUS_RESTORE, NULL, HFILL }},
{ &hf_zbee_zcl_ias_zone_status_trouble,
{ "Trouble", "zbee_zcl_ias.zone.status.trouble", FT_BOOLEAN, 16, TFS(&tfs_trouble_failure), ZBEE_IAS_ZONE_STATUS_TROUBLE, NULL,
HFILL }},
{ &hf_zbee_zcl_ias_zone_status_ac_mains,
{ "AC (mains)", "zbee_zcl_ias.zone.status.ac_mains", FT_BOOLEAN, 16, TFS(&tfs_ac_mains), ZBEE_IAS_ZONE_STATUS_AC_MAINS, NULL,
HFILL }}
};
static gint *ett[ZBEE_ZCL_IAS_ZONE_NUM_ETT];
ett[0] = &ett_zbee_zcl_ias_zone;
ett[1] = &ett_zbee_zcl_ias_zone_status;
proto_zbee_zcl_ias_zone = proto_register_protocol("ZigBee ZCL IAS Zone", "ZCL IAS Zone", ZBEE_PROTOABBREV_ZCL_IAS_ZONE);
proto_register_field_array(proto_zbee_zcl_ias_zone, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_IAS_ZONE, dissect_zbee_zcl_ias_zone, proto_zbee_zcl_ias_zone);
}
