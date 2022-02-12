static int
dissect_zbee_zcl_ias_ace(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
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
val_to_str_const(cmd_id, zbee_zcl_ias_ace_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_ias_ace_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_ias_ace, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_IAS_ACE_ARM:
dissect_zcl_ias_ace_arm(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_IAS_ACE_BYPASS:
dissect_zcl_ias_ace_bypass(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_IAS_ACE_GET_ZONE_INFO:
dissect_zcl_ias_ace_get_zone_info(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_IAS_ACE_EMERGENCY:
case ZBEE_ZCL_CMD_ID_IAS_ACE_FIRE:
case ZBEE_ZCL_CMD_ID_IAS_ACE_PANIC:
case ZBEE_ZCL_CMD_ID_IAS_ACE_GET_ZONE_ID_MAP:
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_ias_ace_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_ias_ace_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_ias_ace, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_IAS_ACE_ARM_RES:
dissect_zcl_ias_ace_arm_res(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_IAS_ACE_GET_ZONE_ID_MAP_RES:
dissect_zcl_ias_ace_get_zone_id_map_res(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_IAS_ACE_GET_ZONE_INFO_RES:
dissect_zcl_ias_ace_get_zone_info_res(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_ias_ace_arm(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ias_ace_arm_mode, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void
dissect_zcl_ias_ace_bypass(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_item *zone_id_list = NULL;
proto_tree *sub_tree = NULL;
guint8 num, i;
num = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_ias_ace_no_of_zones, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
zone_id_list = proto_tree_add_item(tree, hf_zbee_zcl_ias_ace_zone_id_list, tvb, *offset, num, ENC_NA);
sub_tree = proto_item_add_subtree(zone_id_list, ett_zbee_zcl_ias_ace_zone_id);
for(i = 0; i < num; i++){
proto_tree_add_item(sub_tree, hf_zbee_zcl_ias_ace_zone_id, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
}
static void
dissect_zcl_ias_ace_get_zone_info(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ias_ace_zone_id, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void
dissect_zcl_ias_ace_arm_res(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ias_ace_arm_notif, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void
dissect_zcl_ias_ace_get_zone_id_map_res(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint8 i;
for(i = 0; i < 16; i++){
proto_tree_add_item(tree, hf_zbee_zcl_ias_ace_zone_id_map_section, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
}
static void
dissect_zcl_ias_ace_get_zone_info_res(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ias_ace_zone_id, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ias_ace_zone_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ias_ace_ieee_add, tvb, *offset, 8, ENC_NA);
*offset += 8;
}
void
proto_register_zbee_zcl_ias_ace(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_ias_ace_arm_mode,
{ "Arm Mode", "zbee_zcl_sas.ias_ace.arm_mode", FT_UINT8, BASE_DEC, VALS(arm_mode_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ias_ace_no_of_zones,
{ "Number of Zones", "zbee_zcl_sas.ias_ace.no_of_zones", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ias_ace_zone_id,
{ "Zone ID", "zbee_zcl_sas.ias_ace.zone_id", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ias_ace_zone_id_list,
{ "Zone ID List", "zbee_zcl_sas.ias_ace.zone_id_list", FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ias_ace_arm_notif,
{ "Arm Notifications", "zbee_zcl_sas.ias_ace.arm_notif", FT_UINT8, BASE_DEC, VALS(arm_notif_values),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ias_ace_zone_id_map_section,
{ "Zone ID Map Section", "zbee_zcl_sas.ias_ace.zone_id_map_section", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ias_ace_zone_type,
{ "Zone Type", "zbee_zcl_sas.ias_ace.zone_type", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ias_ace_ieee_add,
{ "IEEE Address", "zbee_zcl_sas.ias_ace.ieee_add", FT_BYTES, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ias_ace_srv_rx_cmd_id,
{ "Command", "zbee_zcl_sas.ias_ace.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ias_ace_srv_rx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ias_ace_srv_tx_cmd_id,
{ "Command", "zbee_zcl_sas.ias_ace.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ias_ace_srv_tx_cmd_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_IAS_ACE_NUM_ETT];
ett[0] = &ett_zbee_zcl_ias_ace;
ett[1] = &ett_zbee_zcl_ias_ace_zone_id;
ett[2] = &ett_zbee_zcl_ias_ace_zone_id_map_sec;
ett[3] = &ett_zbee_zcl_ias_ace_zone_id_map_sec_elem;
proto_zbee_zcl_ias_ace = proto_register_protocol("ZigBee ZCL IAS ACE", "ZCL IAS ACE", ZBEE_PROTOABBREV_ZCL_IAS_ACE);
proto_register_field_array(proto_zbee_zcl_ias_ace, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_IAS_ACE, dissect_zbee_zcl_ias_ace, proto_zbee_zcl_ias_ace);
}
void
proto_reg_handoff_zbee_zcl_ias_ace(void)
{
dissector_handle_t ias_ace_handle;
ias_ace_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_IAS_ACE);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_IAS_ACE, ias_ace_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_ias_ace,
ett_zbee_zcl_ias_ace,
ZBEE_ZCL_CID_IAS_ACE,
-1,
hf_zbee_zcl_ias_ace_srv_rx_cmd_id,
hf_zbee_zcl_ias_ace_srv_tx_cmd_id,
NULL
);
}
static int
dissect_zbee_zcl_ias_wd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
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
val_to_str_const(cmd_id, zbee_zcl_ias_wd_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_ias_wd_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_ias_wd, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_IAS_WD_START_WARNING:
dissect_zcl_ias_wd_start_warning(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_IAS_WD_SQUAWK:
dissect_zcl_ias_wd_squawk(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_ias_wd_start_warning(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ias_wd_warning_mode, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_zbee_zcl_ias_wd_strobe_2bit, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ias_wd_warning_duration, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_ias_wd_squawk(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ias_wd_squawk_mode, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_zbee_zcl_ias_wd_strobe_1bit, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_zbee_zcl_ias_wd_squawk_level, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
void
dissect_zcl_ias_wd_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_IAS_WD_MAX_DURATION:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_ias_wd(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_ias_wd_attr_id,
{ "Attribute", "zbee_zcl_sas.ias_wd.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_ias_wd_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ias_wd_warning_mode,
{ "Warning Mode", "zbee_zcl_sas.ias_wd.warning_mode", FT_UINT8, BASE_DEC, VALS(warning_mode_values),
ZBEE_ZCL_IAS_WD_WARNING_MODE_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_ias_wd_strobe_2bit,
{ "Strobe", "zbee_zcl_sas.ias_wd.strobe", FT_UINT8, BASE_DEC, VALS(strobe_2bit_values),
ZBEE_ZCL_IAS_WD_STROBE_2BIT_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_ias_wd_squawk_mode,
{ "Squawk Mode", "zbee_zcl_sas.ias_wd.squawk_mode", FT_UINT8, BASE_DEC, VALS(squawk_mode_values),
ZBEE_ZCL_IAS_WD_SWQUAWK_MODE_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_ias_wd_strobe_1bit,
{ "Strobe", "zbee_zcl_sas.ias_wd.strobe", FT_UINT8, BASE_DEC, VALS(strobe_1bit_values),
ZBEE_ZCL_IAS_WD_STROBE_1BIT_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_ias_wd_warning_duration,
{ "Warning Duration", "zbee_zcl_sas.ias_wd.warning_duration", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ias_wd_squawk_level,
{ "Squawk Level", "zbee_zcl_sas.ias_wd.squawk_level", FT_UINT8, BASE_DEC, VALS(squawk_level_values),
ZBEE_ZCL_IAS_WD_SWQUAWK_LEVEL_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_ias_wd_srv_rx_cmd_id,
{ "Command", "zbee_zcl_sas.ias_wd.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ias_wd_srv_rx_cmd_names),
0x00, NULL, HFILL } }
};
static gint *ett[ZBEE_ZCL_IAS_WD_NUM_ETT];
ett[0] = &ett_zbee_zcl_ias_wd;
proto_zbee_zcl_ias_wd = proto_register_protocol("ZigBee ZCL IAS WD", "ZCL IAS WD", ZBEE_PROTOABBREV_ZCL_IAS_WD);
proto_register_field_array(proto_zbee_zcl_ias_wd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_IAS_WD, dissect_zbee_zcl_ias_wd, proto_zbee_zcl_ias_wd);
}
void
proto_reg_handoff_zbee_zcl_ias_wd(void)
{
dissector_handle_t ias_wd_handle;
ias_wd_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_IAS_WD);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_IAS_WD, ias_wd_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_ias_wd,
ett_zbee_zcl_ias_wd,
ZBEE_ZCL_CID_IAS_WD,
hf_zbee_zcl_ias_wd_attr_id,
hf_zbee_zcl_ias_wd_srv_rx_cmd_id,
-1,
(zbee_zcl_fn_attr_data)dissect_zcl_ias_wd_attr_data
);
}
