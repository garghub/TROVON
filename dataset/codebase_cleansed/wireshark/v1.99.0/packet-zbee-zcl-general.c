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
return tvb_length(tvb);
}
void
dissect_zcl_basic_attr_id(proto_tree *tree, tvbuff_t *tvb, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_basic_attr_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
}
void
dissect_zcl_basic_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint8 value8;
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
value8 = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 1, "Alarm Mask: 0x%02x", value8);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_basic_alarm_mask);
proto_tree_add_item(sub_tree, hf_zbee_zcl_basic_alarm_mask_gen_hw_fault, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_basic_alarm_mask_gen_sw_fault, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_basic_alarm_mask_reserved, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_BASIC_DISABLE_LOCAL_CFG:
value8 = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 1, "Disable Local Config: 0x%02x", value8);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_basic_dis_local_cfg);
proto_tree_add_item(sub_tree, hf_zbee_zcl_basic_disable_local_cfg_reset, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_basic_disable_local_cfg_device_cfg, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_basic_disable_local_cfg_reserved, tvb, *offset, 1, ENC_NA);
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
static void
dissect_zcl_basic_cmd_id(proto_tree* tree, tvbuff_t* tvb, guint* offset, guint8 cmd_dir)
{
if (cmd_dir == ZBEE_ZCL_FCF_TO_CLIENT)
proto_tree_add_item(tree, hf_zbee_zcl_basic_srv_rx_cmd_id, tvb, *offset, 1, ENC_NA);
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
{ &hf_zbee_zcl_basic_alarm_mask_gen_hw_fault,
{ "General hardware fault", "zbee_zcl_general.basic.attr.alarm_mask.gen_hw_fault", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_BASIC_ALARM_GEN_HW_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_basic_alarm_mask_gen_sw_fault,
{ "General software fault", "zbee_zcl_general.basic.attr.alarm_mask.gen_sw_fault", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_BASIC_ALARM_GEN_SW_FAULT, NULL, HFILL } },
{ &hf_zbee_zcl_basic_alarm_mask_reserved,
{ "Reserved", "zbee_zcl_general.basic.attr.alarm_mask.reserved", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_BASIC_ALARM_RESERVED, NULL, HFILL } },
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
new_register_dissector(ZBEE_PROTOABBREV_ZCL_BASIC, dissect_zbee_zcl_basic, proto_zbee_zcl_basic);
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
(zbee_zcl_fn_attr_id)dissect_zcl_basic_attr_id,
(zbee_zcl_fn_attr_data)dissect_zcl_basic_attr_data,
(zbee_zcl_fn_cmd_id)dissect_zcl_basic_cmd_id
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
return tvb_length(tvb);
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
dissect_zcl_identify_attr_id(proto_tree *tree, tvbuff_t *tvb, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_identify_attr_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
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
static void
dissect_zcl_identify_cmd_id(proto_tree* tree, tvbuff_t* tvb, guint* offset, guint8 cmd_dir)
{
if (cmd_dir == ZBEE_ZCL_FCF_TO_CLIENT)
proto_tree_add_item(tree, hf_zbee_zcl_identify_srv_rx_cmd_id, tvb, *offset, 1, ENC_NA);
else
proto_tree_add_item(tree, hf_zbee_zcl_identify_srv_tx_cmd_id, tvb, *offset, 1, ENC_NA);
}
void
proto_register_zbee_zcl_identify(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_identify_attr_id,
{ "Attribute", "zbee_zcl_general.identify.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_identify_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_identify_identify_time,
{ "Identify Time", "zbee_zcl_general.identify.attr.identify_time", FT_UINT16, BASE_CUSTOM, decode_zcl_time_in_seconds,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_identify_identify_timeout,
{ "Identify Timeout", "zbee_zcl_general.identify.identify_timeout", FT_UINT16, BASE_CUSTOM, decode_zcl_time_in_seconds,
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
new_register_dissector(ZBEE_PROTOABBREV_ZCL_IDENTIFY, dissect_zbee_zcl_identify, proto_zbee_zcl_identify);
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
(zbee_zcl_fn_attr_id)dissect_zcl_identify_attr_id,
(zbee_zcl_fn_attr_data)dissect_zcl_identify_attr_data,
(zbee_zcl_fn_cmd_id)dissect_zcl_identify_cmd_id
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
return tvb_length(tvb);
}
void
dissect_zcl_on_off_attr_id(proto_tree *tree, tvbuff_t *tvb, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_on_off_attr_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
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
static void
dissect_zcl_on_off_cmd_id(proto_tree* tree, tvbuff_t* tvb, guint* offset, guint8 cmd_dir)
{
if (cmd_dir == ZBEE_ZCL_FCF_TO_CLIENT)
proto_tree_add_item(tree, hf_zbee_zcl_on_off_srv_rx_cmd_id, tvb, *offset, 1, ENC_NA);
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
new_register_dissector(ZBEE_PROTOABBREV_ZCL_ONOFF, dissect_zbee_zcl_on_off, proto_zbee_zcl_on_off);
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
(zbee_zcl_fn_attr_id)dissect_zcl_on_off_attr_id,
(zbee_zcl_fn_attr_data)dissect_zcl_on_off_attr_data,
(zbee_zcl_fn_cmd_id)dissect_zcl_on_off_cmd_id
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
return tvb_length(tvb);
}
static void dissect_zcl_part_trasfpartframe(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree *sub_tree = NULL;
proto_item *ti;
guint8 options;
guint16 u16len;
guint8 frame_len;
guint8 *data_frame;
options = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 1, "Fragmentation Options: 0x%02x", options);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_part_fragm_options);
proto_tree_add_item(sub_tree, hf_zbee_zcl_part_opt_first_block, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_part_opt_indic_len, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_part_opt_res, tvb, *offset, 1, ENC_NA);
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
data_frame = tvb_bytes_to_ep_str_punct(tvb, *offset, frame_len, ':');
proto_tree_add_string(tree, hf_zbee_zcl_part_part_frame, tvb, *offset, frame_len, data_frame);
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
proto_tree *sub_tree = NULL;
proto_item *ti;
guint tvb_len = tvb_reported_length(tvb);
guint i = 0;
guint8 options;
guint16 first_frame_id;
guint16 nack_id;
options = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 1, "Ack Options: 0x%02x", options);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_part_ack_opts);
proto_tree_add_item(sub_tree, hf_zbee_zcl_part_ack_opt_nack_id_len, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_part_ack_opt_res, tvb, *offset, 1, ENC_NA);
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
static void
dissect_zcl_part_attr_id(proto_tree *tree, tvbuff_t *tvb, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_part_attr_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_zcl_part_cmd_id(proto_tree* tree, tvbuff_t* tvb, guint* offset, guint8 cmd_dir)
{
if (cmd_dir == ZBEE_ZCL_FCF_TO_CLIENT)
proto_tree_add_item(tree, hf_zbee_zcl_part_srv_rx_cmd_id, tvb, *offset, 1, ENC_NA);
else
proto_tree_add_item(tree, hf_zbee_zcl_part_srv_tx_cmd_id, tvb, *offset, 1, ENC_NA);
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
{ "Partition Frame", "zbee_zcl_general.part.part_frame", FT_STRING, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_part_partitioned_cluster_id,
{ "Partitioned Cluster ID", "zbee_zcl_general.part.part_cluster_id", FT_UINT16, BASE_HEX, VALS(zbee_aps_cid_names),
0x00, NULL, HFILL } },
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
new_register_dissector(ZBEE_PROTOABBREV_ZCL_PART, dissect_zbee_zcl_part, proto_zbee_zcl_part);
}
void proto_reg_handoff_zbee_zcl_part(void)
{
dissector_handle_t part_handle;
part_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_PART);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_PARTITION, part_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_part,
ett_zbee_zcl_part,
ZBEE_ZCL_CID_PARTITION,
(zbee_zcl_fn_attr_id)dissect_zcl_part_attr_id,
NULL,
(zbee_zcl_fn_cmd_id)dissect_zcl_part_cmd_id
);
}
static void
decode_zcl_ota_curr_time(gchar *s, guint32 value)
{
if (value == ZBEE_ZCL_OTA_TIME_NOW)
g_snprintf(s, ITEM_LABEL_LENGTH, "Now");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%s", abs_time_secs_to_str(wmem_packet_scope(), value, ABSOLUTE_TIME_LOCAL, 1));
return;
}
static void
decode_zcl_ota_req_time(gchar *s, guint32 value)
{
if (value == ZBEE_ZCL_OTA_TIME_WAIT)
g_snprintf(s, ITEM_LABEL_LENGTH, "Wrong Value");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%s from now", time_secs_to_str(wmem_packet_scope(), value));
return;
}
static void
decode_zcl_ota_upgr_time(gchar *s, guint32 value)
{
if (value == ZBEE_ZCL_OTA_TIME_WAIT)
g_snprintf(s, ITEM_LABEL_LENGTH, "Wait for upgrade command");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%s from now", time_secs_to_str(wmem_packet_scope(), value));
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
proto_tree *sub_tree = NULL;
proto_item *ti;
guint32 file_version;
file_version = tvb_get_ntohl(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 4, "File Version: 0x%08x", file_version);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_ota_file_version);
proto_tree_add_item(sub_tree, hf_zbee_zcl_ota_file_version_appl_release, tvb, *offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_zbee_zcl_ota_file_version_appl_build, tvb, *offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_zbee_zcl_ota_file_version_stack_release, tvb, *offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_zbee_zcl_ota_file_version_stack_build, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
}
static guint8
dissect_zcl_ota_field_ctrl_field(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree *sub_tree = NULL;
proto_item *ti;
guint8 field_ctrl;
field_ctrl = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 1, "Field Control: 0x%02x", field_ctrl);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_ota_field_ctrl);
proto_tree_add_item(sub_tree, hf_zbee_zcl_ota_field_ctrl_hw_ver_present, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_ota_field_ctrl_reserved, tvb, *offset, 1, ENC_NA);
*offset += 1;
return field_ctrl;
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
guint8 *image_data;
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
image_data = tvb_bytes_to_ep_str_punct(tvb, *offset, data_size, ':');
proto_tree_add_string(tree, hf_zbee_zcl_ota_image_data, tvb, *offset, data_size, image_data);
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
dissect_zcl_ota_attr_id(proto_tree *tree, tvbuff_t *tvb, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ota_attr_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
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
static void
dissect_zcl_ota_cmd_id(proto_tree* tree, tvbuff_t* tvb, guint* offset, guint8 cmd_dir)
{
if (cmd_dir == ZBEE_ZCL_FCF_TO_CLIENT)
proto_tree_add_item(tree, hf_zbee_zcl_ota_srv_rx_cmd_id, tvb, *offset, 1, ENC_NA);
else
proto_tree_add_item(tree, hf_zbee_zcl_ota_srv_tx_cmd_id, tvb, *offset, 1, ENC_NA);
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
return tvb_length(tvb);
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
{ "Query Jitter", "zbee_zcl_general.ota.query_jitter", FT_UINT8, BASE_CUSTOM, decode_zcl_time_in_seconds,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_manufacturer_code,
{ "Manufacturer Code", "zbee_zcl_general.ota.manufacturer_code", FT_UINT16, BASE_HEX, VALS(zbee_mfr_code_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_image_type,
{ "Image Type", "zbee_zcl_general.ota.image.type", FT_UINT16, BASE_HEX | BASE_RANGE_STRING,
RVALS(zbee_zcl_ota_image_type_names), 0x0, NULL, HFILL } },
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
{ "Image Size", "zbee_zcl_general.ota.image.size", FT_UINT32, BASE_CUSTOM, decode_zcl_ota_size_in_bytes,
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
{ "Page Size", "zbee_zcl_general.ota.page.size", FT_UINT16, BASE_CUSTOM, decode_zcl_ota_size_in_bytes,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_rsp_spacing,
{ "Response Spacing", "zbee_zcl_general.ota.rsp_spacing", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_ota_current_time,
{ "Current Time", "zbee_zcl_general.ota.current_time", FT_UINT32, BASE_CUSTOM, decode_zcl_ota_curr_time,
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ota_request_time,
{ "Request Time", "zbee_zcl_general.ota.request_time", FT_UINT32, BASE_CUSTOM, decode_zcl_ota_req_time,
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ota_upgrade_time,
{ "Upgrade Time", "zbee_zcl_general.ota.upgrade_time", FT_UINT32, BASE_CUSTOM, decode_zcl_ota_upgr_time,
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_ota_data_size,
{ "Data Size", "zbee_zcl_general.ota.data_size", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ota_image_data,
{ "Image Data", "zbee_zcl_general.ota.image.data", FT_STRING, BASE_NONE, NULL,
0x00, NULL, HFILL } }
};
gint *ett[ZBEE_ZCL_OTA_NUM_ETT];
ett[0] = &ett_zbee_zcl_ota;
ett[1] = &ett_zbee_zcl_ota_field_ctrl;
ett[2] = &ett_zbee_zcl_ota_file_version;
proto_zbee_zcl_ota = proto_register_protocol("ZigBee ZCL OTA", "ZCL OTA", ZBEE_PROTOABBREV_ZCL_OTA);
proto_register_field_array(proto_zbee_zcl_ota, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector(ZBEE_PROTOABBREV_ZCL_OTA, dissect_zbee_zcl_ota, proto_zbee_zcl_ota);
}
void proto_reg_handoff_zbee_zcl_ota(void)
{
dissector_handle_t ota_handle;
ota_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_OTA);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_OTA_UPGRADE, ota_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_ota,
ett_zbee_zcl_ota,
ZBEE_ZCL_CID_OTA_UPGRADE,
(zbee_zcl_fn_attr_id)dissect_zcl_ota_attr_id,
(zbee_zcl_fn_attr_data)dissect_zcl_ota_attr_data,
(zbee_zcl_fn_cmd_id)dissect_zcl_ota_cmd_id
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
return tvb_length(tvb);
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
for (i=0 ; i<num_of_sched_phases ; i++) {
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
for ( i=0 ; i<num_of_transferred_phases ; i++) {
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
power_profile_count = tvb_get_guint8(tvb, *offset);
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
proto_tree *sub_tree = NULL;
proto_item *ti;
guint8 options;
options = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 1, "Options: 0x%02x", options);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_pwr_prof_options);
proto_tree_add_item(sub_tree, hf_zbee_zcl_pwr_prof_options_01, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_pwr_prof_options_res, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_pwr_prof_stime, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_pwr_prof_attr_id(proto_tree *tree, tvbuff_t *tvb, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_attr_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_zcl_pwr_prof_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint8 value8;
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
value8 = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 1, "Data: 0x%02x", value8);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_pwr_prof_en_format);
proto_tree_add_item(sub_tree, hf_zbee_zcl_pwr_prof_energy_format_rdigit, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_pwr_prof_energy_format_ldigit, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_pwr_prof_energy_format_noleadingzero, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_PWR_PROF_ENERGY_REMOTE:
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_energy_remote, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_PWR_PROF_SCHED_MODE:
value8 = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 1, "Schedule Mode: 0x%02x", value8);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_pwr_prof_sched_mode);
proto_tree_add_item(sub_tree, hf_zbee_zcl_pwr_prof_sched_mode_cheapest, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_pwr_prof_sched_mode_greenest, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_pwr_prof_sched_mode_reserved, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static void
dissect_zcl_pwr_prof_cmd_id(proto_tree* tree, tvbuff_t* tvb, guint* offset, guint8 cmd_dir)
{
if (cmd_dir == ZBEE_ZCL_FCF_TO_CLIENT)
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_srv_rx_cmd_id, tvb, *offset, 1, ENC_NA);
else
proto_tree_add_item(tree, hf_zbee_zcl_pwr_prof_srv_tx_cmd_id, tvb, *offset, 1, ENC_NA);
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
{ "Power Profile ID", "zbee_zcl_general.pwrprof.pwrprofid", FT_UINT8, BASE_CUSTOM, decode_power_profile_id, 0x00,
"Identifier of the specific profile", HFILL } },
{ &hf_zbee_zcl_pwr_prof_currency,
{ "Currency", "zbee_zcl_general.pwrprof.currency", FT_UINT16, BASE_HEX, VALS(zbee_zcl_currecy_names), 0x0,
"Local unit of currency (ISO 4217) used in the price field.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_price,
{ "Price", "zbee_zcl_general.pwrprof.price", FT_UINT32, BASE_CUSTOM, decode_price_in_cents, 0x0,
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
{ "Scheduled Time", "zbee_zcl_general.pwrprof.scheduledtime", FT_UINT16, BASE_CUSTOM, decode_zcl_time_in_minutes, 0x0,
NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_macro_phase_id,
{ "Macro Phase ID", "zbee_zcl_general.pwrprof.macrophaseid", FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifier of the specific energy phase.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_expect_duration,
{ "Expected Duration", "zbee_zcl_general.pwrprof.expecduration", FT_UINT16, BASE_CUSTOM, decode_zcl_time_in_minutes, 0x0,
"The estimated duration of the specific phase.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_num_of_trans_phases,
{ "Number of Transferred Phases", "zbee_zcl_general.pwrprof.numoftransphases", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_peak_power,
{ "Peak Power", "zbee_zcl_general.pwrprof.peakpower", FT_UINT16, BASE_CUSTOM, decode_power_in_watt, 0x0,
"The estimated power for the specific phase.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_energy,
{ "Energy", "zbee_zcl_general.pwrprof.energy", FT_UINT16, BASE_CUSTOM, decode_energy, 0x0,
"The estimated energy consumption for the accounted phase.", HFILL } },
{ &hf_zbee_zcl_pwr_prof_max_active_delay,
{ "Max Activation Delay", "zbee_zcl_general.pwrprof.maxactivdelay", FT_UINT16, BASE_CUSTOM, func_decode_delayinminute, 0x0,
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
{ "Start After", "zbee_zcl_general.pwrprof.startafter", FT_UINT16, BASE_CUSTOM, decode_zcl_time_in_minutes, 0x0,
NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_stop_before,
{ "Stop Before", "zbee_zcl_general.pwrprof.stopbefore", FT_UINT16, BASE_CUSTOM, decode_zcl_time_in_minutes, 0x0,
NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_options_01,
{ "PowerProfileStartTime Field Present", "zbee_zcl_general.pwrprof.options.01", FT_BOOLEAN, 8, TFS(&tfs_true_false),
ZBEE_ZCL_OPT_PWRPROF_STIME_PRESENT, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_options_res,
{ "Reserved", "zbee_zcl_general.pwrprof.options.reserved", FT_UINT8, BASE_HEX, NULL,
ZBEE_ZCL_OPT_PWRPROF_RESERVED, NULL, HFILL } },
{ &hf_zbee_zcl_pwr_prof_pwr_prof_stime,
{ "Power Profile Start Time", "zbee_zcl_general.pwrprof.pwrprofstime", FT_UINT16, BASE_CUSTOM, decode_zcl_time_in_minutes, 0x0,
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
new_register_dissector(ZBEE_PROTOABBREV_ZCL_PWRPROF, dissect_zbee_zcl_pwr_prof, proto_zbee_zcl_pwr_prof);
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
(zbee_zcl_fn_attr_id)dissect_zcl_pwr_prof_attr_id,
(zbee_zcl_fn_attr_data)dissect_zcl_pwr_prof_attr_data,
(zbee_zcl_fn_cmd_id)dissect_zcl_pwr_prof_cmd_id
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
return tvb_length(tvb);
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
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint8 flags;
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_appl_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
flags = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 1, "Remote Enable Flags: 0x%02x", flags);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_appl_ctrl_flags);
proto_tree_add_item(sub_tree, hf_zbee_zcl_appl_ctrl_rem_en_flags, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_appl_ctrl_status2, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_status2_array, tvb, *offset, 3, ENC_BIG_ENDIAN);
}
static void
dissect_zcl_appl_ctrl_attr_id(proto_tree *tree, tvbuff_t *tvb, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_attr_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_zcl_appl_ctrl_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint16 raw_time;
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_APPL_CTRL_START_TIME:
case ZBEE_ZCL_ATTR_ID_APPL_CTRL_FINISH_TIME:
case ZBEE_ZCL_ATTR_ID_APPL_CTRL_REMAINING_TIME:
raw_time = tvb_get_letohs(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 2, "Data: 0x%04x", raw_time);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_appl_ctrl_time);
proto_tree_add_item(sub_tree, hf_zbee_zcl_appl_ctrl_time_mm, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sub_tree, hf_zbee_zcl_appl_ctrl_time_encoding_type, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sub_tree, hf_zbee_zcl_appl_ctrl_time_hh, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static void
dissect_zcl_appl_ctrl_cmd_id(proto_tree* tree, tvbuff_t* tvb, guint* offset, guint8 cmd_dir)
{
if (cmd_dir == ZBEE_ZCL_FCF_TO_CLIENT)
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_srv_rx_cmd_id, tvb, *offset, 1, ENC_NA);
else
proto_tree_add_item(tree, hf_zbee_zcl_appl_ctrl_srv_tx_cmd_id, tvb, *offset, 1, ENC_NA);
}
void
proto_register_zbee_zcl_appl_ctrl(void)
{
guint i, j;
static hf_register_info hf[] = {
{ &hf_zbee_zcl_appl_ctrl_attr_id,
{ "Attribute", "zbee_zcl_general.applctrl.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_appl_ctrl_attr_names),
0x0, NULL, HFILL } },
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
new_register_dissector(ZBEE_PROTOABBREV_ZCL_APPLCTRL, dissect_zbee_zcl_appl_ctrl, proto_zbee_zcl_appl_ctrl);
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
(zbee_zcl_fn_attr_id)dissect_zcl_appl_ctrl_attr_id,
(zbee_zcl_fn_attr_data)dissect_zcl_appl_ctrl_attr_data,
(zbee_zcl_fn_cmd_id)dissect_zcl_appl_ctrl_cmd_id
);
}
