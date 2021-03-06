static void sam_timeout_base(gchar* buf, guint32 value) {
if (value == 0x00) {
g_snprintf(buf, ITEM_LABEL_LENGTH, "No timeout control");
} else if (0x01 <= value && value <= 0x13) {
g_snprintf(buf, ITEM_LABEL_LENGTH, "%u ms", value * 50);
} else {
g_snprintf(buf, ITEM_LABEL_LENGTH, "%u.%03u s", value * 50 / 1000, value * 50 % 1000);
}
}
static gint
dissect_status(proto_tree *tree, tvbuff_t *tvb, gint offset)
{
proto_tree_add_item(tree, hf_pn532_status_nad_present, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_pn532_status_mi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_pn532_status_error_code, tvb, offset, 1, ENC_BIG_ENDIAN);
return offset + 1;
}
static void
dissect_pn532(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item;
proto_tree *pn532_tree;
proto_item *sub_item;
proto_tree *sub_tree;
proto_item *next_item;
proto_tree *next_tree;
guint8 cmd;
guint8 config;
guint8 baudrate;
guint8 length;
guint8 value;
guint8 type;
guint8 item_value;
tvbuff_t *next_tvb;
gint offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PN532");
item = proto_tree_add_item(tree, proto_pn532, tvb, 0, -1, ENC_NA);
pn532_tree = proto_item_add_subtree(item, ett_pn532);
proto_tree_add_item(pn532_tree, hf_pn532_direction, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_command, tvb, offset, 1, ENC_NA);
cmd = tvb_get_guint8(tvb, offset);
offset += 1;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_ext_const(cmd, &pn532_commands_ext, "Unknown command"));
switch (cmd) {
case DIAGNOSE_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_test_number, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_parameters_length, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_parameters, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
break;
case DIAGNOSE_RSP:
if (tvb_length_remaining(tvb, offset) >= 1) {
proto_tree_add_item(pn532_tree, hf_pn532_parameters_length, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_parameters, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
}
break;
case GET_FIRMWARE_VERSION_REQ:
break;
case GET_FIRMWARE_VERSION_RSP:
proto_tree_add_item(pn532_tree, hf_pn532_ic_version, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_fw_version, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_fw_revision, tvb, offset, 1, ENC_NA);
offset += 1;
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_fw_support, tvb, offset, 1, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn532_fw_support);
proto_tree_add_item(sub_tree, hf_pn532_fw_support_rfu, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_pn532_fw_support_iso_018092, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_pn532_fw_support_iso_iec_14443_type_b, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_pn532_fw_support_iso_iec_14443_type_a, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case GET_GENERAL_STATUS_REQ:
break;
case GET_GENERAL_STATUS_RSP:
proto_tree_add_item(pn532_tree, hf_pn532_error, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_field, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_NbTg, tvb, offset, 1, ENC_BIG_ENDIAN);
value = tvb_get_guint8(tvb, offset);
offset += 1;
for (item_value = 1; item_value <= value; item_value += 1) {
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_target, tvb, offset, 4, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn532_target);
proto_item_append_text(sub_item, " %u/%u", item_value, value);
proto_tree_add_item(sub_tree, hf_pn532_Tg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_pn532_brrx, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_pn532_brtx, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_pn532_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
proto_tree_add_item(pn532_tree, hf_pn532_sam_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case READ_REGISTER_REQ:
while (tvb_length_remaining(tvb, offset) >= 2) {
proto_tree_add_item(pn532_tree, hf_pn532_register_address, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
break;
case READ_REGISTER_RSP:
while (tvb_length_remaining(tvb, offset) >= 1) {
proto_tree_add_item(pn532_tree, hf_pn532_register_value, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case WRITE_REGISTER_REQ:
while (tvb_length_remaining(tvb, offset) >= 3) {
proto_tree_add_item(pn532_tree, hf_pn532_register_address, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pn532_tree, hf_pn532_register_value, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case WRITE_REGISTER_RSP:
break;
case READ_GPIO_REQ:
break;
case READ_GPIO_RSP:
proto_tree_add_item(pn532_tree, hf_pn532_gpio_p3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_gpio_p7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_gpio_ioi1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case WRITE_GPIO_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_gpio_p3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_gpio_p7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case WRITE_GPIO_RSP:
break;
case SET_SERIAL_BAUD_RATE_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_baudrate, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case SET_SERIAL_BAUD_RATE_RSP:
break;
case SET_PARAMETERS_REQ:
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_flags, tvb, offset, 1, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn532_flags);
proto_tree_add_item(sub_tree, hf_pn532_flags_rfu_7, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_flags_remove_preamble_and_postamble, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_flags_iso_14443_4_picc_emulation, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_flags_automatic_rats, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_flags_rfu_3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_flags_automatic_atr_res, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_flags_did_used, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_flags_nad_used, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case SET_PARAMETERS_RSP:
break;
case SAM_CONFIGURATION_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_sam_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_sam_timeout, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (tvb_length_remaining(tvb, offset) >= 1) {
proto_tree_add_item(pn532_tree, hf_pn532_sam_irq, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case SAM_CONFIGURATION_RSP:
break;
case POWER_DOWN_REQ:
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_wakeup_enable, tvb, offset, 1, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn532_wakeup_enable);
proto_tree_add_item(sub_tree, hf_pn532_wakeup_enable_i2c, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_wakeup_enable_gpio, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_wakeup_enable_spi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_wakeup_enable_hsu, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_wakeup_enable_rf_level_detector, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_wakeup_enable_rfu_2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_wakeup_enable_int_1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_wakeup_enable_int_0, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (tvb_length_remaining(tvb, offset) >= 1) {
proto_tree_add_item(pn532_tree, hf_pn532_generate_irq, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case POWER_DOWN_RSP:
offset = dissect_status(pn532_tree, tvb, offset);
break;
case RF_CONFIGURATION_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_config, tvb, offset, 1, ENC_BIG_ENDIAN);
config = tvb_get_guint8(tvb, offset);
offset += 1;
switch(config) {
case 0x01:
proto_tree_add_item(pn532_tree, hf_pn532_config_not_used, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_config_auto_rfca, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_config_rf, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case 0x02:
proto_tree_add_item(pn532_tree, hf_pn532_config_rfu, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_atr_res_timeout, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_timeout_non_dep, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case 0x04:
proto_tree_add_item(pn532_tree, hf_pn532_config_max_rty_com, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case 0x05:
proto_tree_add_item(pn532_tree, hf_pn532_config_max_rty_atr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_max_rty_psl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_max_rty_passive_activation, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case 0x0A:
case 0x0B:
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_rf_cfg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_gs_n_on, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_cw_gs_p, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_mod_gs_p, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_demon_rf_on, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_rx_threshold, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_demon_rf_off, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_gs_n_off, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (config == 0x0A) {
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_mod_width, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_mif_nfc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_tx_bit_phase, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case 0x0C:
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_gs_n_on, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_mod_gs_p, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_config_ciu_rx_threshold, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case 0x0D:
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_config_212_kbps, tvb, offset, 3, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn532_config_212_kbps);
proto_tree_add_item(sub_tree, hf_pn532_config_ciu_rx_threshold, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_pn532_config_ciu_mod_width, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_pn532_config_ciu_mif_nfc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_config_424_kbps, tvb, offset, 3, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn532_config_424_kbps);
proto_tree_add_item(sub_tree, hf_pn532_config_ciu_rx_threshold, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_pn532_config_ciu_mod_width, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_pn532_config_ciu_mif_nfc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_config_848_kbps, tvb, offset, 3, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn532_config_848_kbps);
proto_tree_add_item(sub_tree, hf_pn532_config_ciu_rx_threshold, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_pn532_config_ciu_mod_width, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_pn532_config_ciu_mif_nfc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
default:
proto_tree_add_expert(pn532_tree, pinfo, &ei_unknown_data, tvb, offset, tvb_length_remaining(tvb, offset));
offset += tvb_length_remaining(tvb, offset);
}
break;
case RF_CONFIGURATION_RSP:
break;
case RF_REGULATION_TEST_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_txmode_nu_7, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_txmode_tx_speed, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_txmode_nu_2_3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_txmode_tx_framing, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case RF_REGULATION_TEST_RSP:
break;
case IN_JUMP_FOR_DEP_REQ:
case IN_JUMP_FOR_PSL_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_communication_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_activation_baudrate, tvb, offset, 1, ENC_BIG_ENDIAN);
baudrate = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_jump_next_not_used_3_7, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_jump_next_passive_initiator_data, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_jump_next_gi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_jump_next_nfc_id_3i, tvb, offset, 1, ENC_BIG_ENDIAN);
value = tvb_get_guint8(tvb, offset);
offset += 1;
if (value & 0x01) {
if (baudrate == 0x00) {
proto_tree_add_item(pn532_tree, hf_pn532_passive_initiator_data, tvb, offset, 4, ENC_NA);
offset += 4;
} else {
proto_tree_add_item(pn532_tree, hf_pn532_passive_initiator_data, tvb, offset, 5, ENC_NA);
offset += 5;
}
}
if (value & 0x02) {
proto_tree_add_item(pn532_tree, hf_pn532_nfc_id_3i, tvb, offset, 10, ENC_NA);
offset += 10;
}
if (value & 0x04) {
proto_tree_add_item(pn532_tree, hf_pn532_gi, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
}
break;
case IN_JUMP_FOR_DEP_RSP:
case IN_JUMP_FOR_PSL_RSP:
offset = dissect_status(pn532_tree, tvb, offset);
proto_tree_add_item(pn532_tree, hf_pn532_Tg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_nfc_id_3t, tvb, offset, 10, ENC_NA);
offset += 10;
proto_tree_add_item(pn532_tree, hf_pn532_did_target, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_send_bit_rate_target, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_receive_bit_rate_target, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_timeout, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_optional_parameters, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_gt, tvb, offset, 10, ENC_NA);
offset += 10;
break;
case IN_LIST_PASSIVE_TARGET_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_MaxTg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_BrTy, tvb, offset, 1, ENC_BIG_ENDIAN);
baudrate = tvb_get_guint8(tvb, offset);
offset += 1;
switch(baudrate) {
case ISO_IEC_14443A_106:
while (tvb_length_remaining(tvb, offset) >= 4) {
proto_tree_add_item(pn532_tree, hf_pn532_14443a_uid, tvb, 6, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case FELICA_212:
case FELICA_424:
next_tvb = tvb_new_subset(tvb, offset, 5, 5);
call_dissector(sub_handles[SUB_FELICA], next_tvb, pinfo, tree);
offset += 5;
break;
case ISO_IEC_14443B_106:
proto_tree_add_item(pn532_tree, hf_pn532_afi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (tvb_length_remaining(tvb, offset) >= 1) {
proto_tree_add_item(pn532_tree, hf_pn532_polling_method, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case JEWEL_14443A_106:
break;
}
break;
case IN_LIST_PASSIVE_TARGET_RSP:
proto_tree_add_item(pn532_tree, hf_pn532_NbTg, tvb, offset, 1, ENC_BIG_ENDIAN);
value = tvb_get_guint8(tvb, offset);
offset += 1;
for (item_value = 1; item_value <= value; item_value += 1) {
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_target, tvb, offset, 0, ENC_NA);
proto_item_append_text(sub_item, " %u/%u", item_value, value);
if (tvb_reported_length(tvb) == 18) {
proto_tree_add_item(pn532_tree, hf_pn532_14443b_pupi, tvb, 5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443b_app_data, tvb, 9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443b_proto_info, tvb, 13, 3, ENC_BIG_ENDIAN);
}
if (tvb_reported_length(tvb) == 10) {
proto_tree_add_item(pn532_tree, hf_pn532_14443a_atqa, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443a_uid, tvb, 6, 4, ENC_BIG_ENDIAN);
}
if ((tvb_reported_length(tvb) == 21) || (tvb_reported_length(tvb) == 15) || (tvb_reported_length(tvb) == 12)) {
proto_tree_add_item(pn532_tree, hf_pn532_14443a_atqa, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443a_sak, tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443a_uid_length, tvb, 7, 1, ENC_BIG_ENDIAN);
if (tvb_reported_length(tvb) != 12) {
proto_tree_add_item(pn532_tree, hf_pn532_14443a_uid, tvb, 8, 7, ENC_BIG_ENDIAN);
if (tvb_reported_length(tvb) == 21) {
proto_tree_add_item(pn532_tree, hf_pn532_14443a_ats, tvb, 16, 5, ENC_BIG_ENDIAN);
}
}
else {
proto_tree_add_item(pn532_tree, hf_pn532_14443a_uid, tvb, 8, 4, ENC_BIG_ENDIAN);
}
}
if (tvb_reported_length(tvb) == 26 || tvb_reported_length(tvb) == 28 || tvb_reported_length(tvb) == 31) {
if (tvb_get_ntohs(tvb, 4) == 0x0004 || tvb_get_ntohs(tvb, 4) == 0x08) {
proto_tree_add_item(pn532_tree, hf_pn532_14443a_atqa, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443a_sak, tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443a_uid_length, tvb, 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443a_uid, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443a_ats_length, tvb, 12, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(tvb, 13);
call_dissector(sub_handles[SUB_DATA], next_tvb, pinfo, tree);
}
}
if (tvb_reported_length(tvb) == 24) {
proto_tree_add_item(pn532_tree, hf_pn532_payload_length, tvb, 4, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset(tvb, 5, tvb_get_guint8(tvb, 4) - 1, 19);
call_dissector(sub_handles[SUB_FELICA], next_tvb, pinfo, tree);
}
}
break;
case IN_ATR_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_Tg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_next_not_used_2_7, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_next_gi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_next_nfc_id_3i, tvb, offset, 1, ENC_BIG_ENDIAN);
value = tvb_get_guint8(tvb, offset);
offset += 1;
if (value & 0x01) {
proto_tree_add_item(pn532_tree, hf_pn532_nfc_id_3i, tvb, offset, 10, ENC_NA);
offset += 10;
}
if (value & 0x02) {
proto_tree_add_item(pn532_tree, hf_pn532_gi, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
}
break;
case IN_ATR_RSP:
offset = dissect_status(pn532_tree, tvb, offset);
proto_tree_add_item(pn532_tree, hf_pn532_nfc_id_3t, tvb, offset, 10, ENC_NA);
offset += 10;
proto_tree_add_item(pn532_tree, hf_pn532_did_target, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_send_bit_rate_target, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_receive_bit_rate_target, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_timeout, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_optional_parameters, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_gt, tvb, offset, 10, ENC_NA);
offset += 10;
break;
case IN_PSL_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_Tg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_brit, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_brti, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case IN_PSL_RSP:
offset = dissect_status(pn532_tree, tvb, offset);
break;
case IN_DATA_EXCHANGE_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_Tg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (sub_selected == SUB_MIFARE) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(sub_handles[SUB_MIFARE], next_tvb, pinfo, tree);
offset += tvb_length_remaining(tvb, offset);
} else if (sub_selected == SUB_ISO7816) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
pinfo->p2p_dir = P2P_DIR_SENT;
call_dissector(sub_handles[SUB_ISO7816], next_tvb, pinfo, tree);
offset += tvb_length_remaining(tvb, offset);
} else {
proto_tree_add_item(pn532_tree, hf_pn532_data_out, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
}
break;
case IN_DATA_EXCHANGE_RSP:
offset = dissect_status(pn532_tree, tvb, offset);
if (sub_selected == SUB_ISO7816) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
pinfo->p2p_dir = P2P_DIR_RECV;
call_dissector(sub_handles[SUB_ISO7816], next_tvb, pinfo, tree);
offset += tvb_length_remaining(tvb, offset);
} else {
proto_tree_add_item(pn532_tree, hf_pn532_data_in, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
}
break;
case IN_COMMUNICATE_THRU_REQ:
if (sub_selected == SUB_FELICA) {
proto_tree_add_item(pn532_tree, hf_pn532_payload_length, tvb, 2, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(tvb, 3);
call_dissector(sub_handles[SUB_FELICA], next_tvb, pinfo, tree);
} else {
proto_tree_add_item(pn532_tree, hf_pn532_data_out, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
}
break;
case IN_COMMUNICATE_THRU_RSP:
offset = dissect_status(pn532_tree, tvb, offset);
if (sub_selected == SUB_FELICA) {
proto_tree_add_item(pn532_tree, hf_pn532_payload_length, tvb, 3, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(tvb, 4);
call_dissector(sub_handles[SUB_FELICA], next_tvb, pinfo, tree);
} else {
proto_tree_add_item(pn532_tree, hf_pn532_data_in, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
}
break;
case IN_DESELECT_REQ:
case IN_RELEASE_REQ:
case IN_SELECT_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_Tg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case IN_DESELECT_RSP:
case IN_RELEASE_RSP:
case IN_SELECT_RSP:
offset = dissect_status(pn532_tree, tvb, offset);
break;
case IN_AUTO_POLL_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_poll_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_period, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_autopoll_type, tvb, offset, 1, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn532_autopoll_type);
proto_tree_add_item(sub_tree, hf_pn532_autopoll_type_act, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_autopoll_type_dep, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_autopoll_type_tcl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_autopoll_type_mf_fe, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_autopoll_type_not_used, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_autopoll_type_baudrate_and_modulation, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
while (tvb_length_remaining(tvb, offset) >= 1) {
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_autopoll_type, tvb, offset, 1, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn532_autopoll_type);
proto_tree_add_item(sub_tree, hf_pn532_autopoll_type_act, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_autopoll_type_dep, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_autopoll_type_tcl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_autopoll_type_mf_fe, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_autopoll_type_not_used, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_pn532_autopoll_type_baudrate_and_modulation, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case IN_AUTO_POLL_RSP:
proto_tree_add_item(pn532_tree, hf_pn532_NbTg, tvb, offset, 1, ENC_BIG_ENDIAN);
value = tvb_get_guint8(tvb, offset);
offset += 1;
for (item_value = 1; item_value <= value; item_value += 1) {
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_target, tvb, offset, 4, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn532_target);
proto_item_append_text(sub_item, " %u/%u", item_value, value);
next_item = proto_tree_add_item(sub_tree, hf_pn532_autopoll_type, tvb, offset, 1, ENC_BIG_ENDIAN);
next_tree = proto_item_add_subtree(next_item, ett_pn532_autopoll_type);
proto_tree_add_item(next_tree, hf_pn532_autopoll_type_act, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(next_tree, hf_pn532_autopoll_type_dep, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(next_tree, hf_pn532_autopoll_type_tcl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(next_tree, hf_pn532_autopoll_type_mf_fe, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(next_tree, hf_pn532_autopoll_type_not_used, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(next_tree, hf_pn532_autopoll_type_baudrate_and_modulation, tvb, offset, 1, ENC_BIG_ENDIAN);
type = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(sub_tree, hf_pn532_target_data_length, tvb, offset, 1, ENC_BIG_ENDIAN);
length = tvb_get_guint8(tvb, offset);
proto_item_set_len(sub_item, length + 4);
offset += 1;
if (type & 0x40) {
if (type & 0x80) {
proto_tree_add_item(pn532_tree, hf_pn532_target_data, tvb, offset, length, ENC_NA);
offset += length;
}
proto_tree_add_item(pn532_tree, hf_pn532_nfc_id_3t, tvb, offset, 10, ENC_NA);
offset += 10;
proto_tree_add_item(pn532_tree, hf_pn532_did_target, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_send_bit_rate_target, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_receive_bit_rate_target, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_timeout, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_optional_parameters, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_gt, tvb, offset, 10, ENC_NA);
offset += 10;
} else {
proto_tree_add_item(pn532_tree, hf_pn532_target_data, tvb, offset, length, ENC_NA);
offset += length;
}
}
break;
case TG_INIT_AS_TARGET_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_mode_nu_3_7, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_mode_picc_only, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_mode_dep_only, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_mode_passive_only, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_mode_mifare_parameters, tvb, offset, 6, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn532_mifare_parameters);
proto_tree_add_item(sub_tree, hf_pn532_mode_mifare_parameters_sens_res, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_pn532_mode_mifare_parameters_nfc_id_1t, tvb, offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(sub_tree, hf_pn532_mode_mifare_parameters_sel_res, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
sub_item = proto_tree_add_item(pn532_tree, hf_pn532_mode_felica_parameters, tvb, offset, 18, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn532_felica_parameters);
proto_tree_add_item(sub_tree, hf_pn532_mode_felica_parameters_nfc_id_2t, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(sub_tree, hf_pn532_mode_felica_parameters_pad, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(sub_tree, hf_pn532_mode_felica_parameters_system_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pn532_tree, hf_pn532_mode_nfc_id_3t, tvb, offset, 10, ENC_NA);
offset += 10;
proto_tree_add_item(pn532_tree, hf_pn532_mode_gt_length, tvb, offset, 1, ENC_BIG_ENDIAN);
length = tvb_get_guint8(tvb, offset);
offset += 1;
if (length > 0) {
proto_tree_add_item(pn532_tree, hf_pn532_mode_gt, tvb, offset, length, ENC_NA);
offset += length;
}
proto_tree_add_item(pn532_tree, hf_pn532_mode_tk_length, tvb, offset, 1, ENC_BIG_ENDIAN);
length = tvb_get_guint8(tvb, offset);
offset += 1;
if (length > 0) {
proto_tree_add_item(pn532_tree, hf_pn532_mode_tk, tvb, offset, length, ENC_NA);
offset += length;
}
break;
case TG_INIT_AS_TARGET_RSP:
proto_tree_add_item(pn532_tree, hf_pn532_mode_nu_7, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_mode_baudrate, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_mode_iso_iec_14443_4_picc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_mode_dep, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_mode_framing_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_initiator_command, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
break;
case TG_SET_GENERAL_BYTES_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_gt, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
break;
case TG_SET_GENERAL_BYTES_RSP:
offset = dissect_status(pn532_tree, tvb, offset);
break;
case TG_GET_DATA_REQ:
break;
case TG_GET_DATA_RSP:
offset = dissect_status(pn532_tree, tvb, offset);
proto_tree_add_item(pn532_tree, hf_pn532_data_in, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
break;
case TG_SET_DATA_REQ:
case TG_SET_METADATA_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_data_out, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
break;
case TG_SET_DATA_RSP:
case TG_SET_METADATA_RSP:
offset = dissect_status(pn532_tree, tvb, offset);
break;
case TG_GET_INITIATOR_CMD_REQ:
break;
case TG_GET_INITIATOR_CMD_RSP:
offset = dissect_status(pn532_tree, tvb, offset);
proto_tree_add_item(pn532_tree, hf_pn532_initiator_command, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
break;
case TG_RESP_TO_INITIATOR_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_tg_response, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
break;
case TG_RESP_TO_INITIATOR_RSP:
offset = dissect_status(pn532_tree, tvb, offset);
break;
case TG_GET_TARGET_STATUS_REQ:
break;
case TG_GET_TARGET_STATUS_RSP:
proto_tree_add_item(pn532_tree, hf_pn532_state, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pn532_tree, hf_pn532_brit_nu_7, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_brit_speed_initiator, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_brit_nu_3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_brit_speed_target, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
default:
proto_tree_add_expert(pn532_tree, pinfo, &ei_unknown_data, tvb, offset, tvb_length_remaining(tvb, offset));
offset += tvb_length_remaining(tvb, offset);
break;
}
if (tvb_length_remaining(tvb, offset) > 0) {
proto_tree_add_expert(pn532_tree, pinfo, &ei_unexpected_data, tvb, offset, tvb_length_remaining(tvb, offset));
}
}
void proto_register_pn532(void)
{
module_t *pref_mod;
expert_module_t *expert_pn532;
static hf_register_info hf[] = {
{&hf_pn532_command,
{"Command", "pn532.cmd", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&pn532_commands_ext, 0x0, NULL, HFILL}},
{&hf_pn532_direction,
{"Direction", "pn532.tfi", FT_UINT8, BASE_HEX,
VALS(pn532_directions), 0x0, NULL, HFILL}},
{&hf_pn532_status_nad_present,
{"NAD Present", "pn532.status.nad_present", FT_UINT8, BASE_HEX,
NULL, 0x80, NULL, HFILL}},
{&hf_pn532_status_mi,
{"MI", "pn532.status.mi", FT_UINT8, BASE_HEX,
NULL, 0x40, NULL, HFILL}},
{&hf_pn532_status_error_code,
{"Error Code", "pn532.status.error_code", FT_UINT8, BASE_HEX,
VALS(pn532_errors), 0x3F, NULL, HFILL}},
{&hf_pn532_error,
{"Last Error", "pn532.last_error", FT_UINT8, BASE_HEX,
VALS(pn532_errors), 0x00, NULL, HFILL}},
{&hf_pn532_BrTy,
{"Baud Rate and Modulation", "pn532.BrTy", FT_UINT8, BASE_HEX,
VALS(pn532_brtypes), 0x0, NULL, HFILL}},
{&hf_pn532_MaxTg,
{"Maximum Number of Targets", "pn532.MaxTg", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_Tg,
{"Logical Target Number", "pn532.Tg", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_NbTg,
{"Number of Targets", "pn532.NbTg", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_payload_length,
{"Payload Length", "pn532.payload.length", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_ic_version,
{"Integrated Circuit Version", "pn532.ic.version", FT_UINT8, BASE_HEX,
NULL, 0x0, "Version of the IC. For PN532, the contain of this byte is 0x32", HFILL}},
{&hf_pn532_fw_version,
{"Firmware Version", "pn532.fw.version", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_fw_revision,
{"Firmware Revision", "pn532.fw.revision", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_fw_support,
{"Firmware Support", "pn532.fw.support", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_fw_support_rfu,
{"RFU", "pn532.fw.support.rfu", FT_UINT8, BASE_HEX,
NULL, 0xF8, NULL, HFILL}},
{&hf_pn532_fw_support_iso_018092,
{"ISO 018092", "pn532.fw.support.iso_018092", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{&hf_pn532_fw_support_iso_iec_14443_type_b,
{"ISO/IEC 14443 Type B", "pn532.fw.support.iso_iec_14443_type_b", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{&hf_pn532_fw_support_iso_iec_14443_type_a,
{"ISO/IEC 14443 Type A", "pn532.fw.support.iso_iec_14443_type_a", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{&hf_pn532_14443a_sak,
{"ISO/IEC 14443-A SAK", "pn532.iso.14443a.sak", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443a_atqa,
{"ISO/IEC 14443-A ATQA", "pn532.iso.14443a.atqa", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443a_uid,
{"ISO/IEC 14443-A UID", "pn532.iso.14443a.uid", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443a_uid_length,
{"ISO/IEC 14443-A UID Length", "pn532.iso.14443a.uid.length", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443a_ats_length,
{"ISO/IEC 14443-A ATS Length", "pn532.iso.14443a.ats.length", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443a_ats,
{"ISO/IEC 14443-A ATS", "pn532.iso.14443a.ats", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443b_pupi,
{"ISO/IEC 14443-B PUPI", "pn532.iso.14443b.pupi", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443b_app_data,
{"ISO/IEC 14443-B Application Data", "pn532.iso.14443b.app.data", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443b_proto_info,
{"ISO/IEC 14443-B Protocol Info", "pn532.iso.14443b.protocol.info", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_sam_mode,
{"SAM Mode", "pn532.sam.mode", FT_UINT8, BASE_HEX,
VALS(pn532_sam_modes), 0x0, NULL, HFILL}},
{&hf_pn532_sam_timeout,
{"SAM Timeout", "pn532.sam.timeout", FT_UINT8, BASE_CUSTOM,
sam_timeout_base, 0x0, NULL, HFILL}},
{&hf_pn532_sam_irq,
{"SAM IRQ", "pn532.sam.irq", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_config,
{"Config Item", "pn532.config", FT_UINT8, BASE_HEX,
VALS(pn532_config_vals), 0x0, NULL, HFILL}},
{&hf_pn532_config_not_used,
{"Not used", "pn532.config.not_used", FT_UINT8, BASE_HEX,
NULL, 0xFC, NULL, HFILL}},
{&hf_pn532_config_auto_rfca,
{"Auto RFCA", "pn532.config.auto_rfca", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{&hf_pn532_config_rf,
{"RF", "pn532.config.rf", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{&hf_pn532_config_rfu,
{"RFU", "pn532.config.rfu", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_atr_res_timeout,
{"ATR Res Timeout", "pn532.config.atr_res_timeout", FT_UINT8, BASE_HEX,
VALS(pn532_config_timeout_vals), 0x00, NULL, HFILL}},
{&hf_pn532_config_timeout_non_dep,
{"TimeOut during non-DEP communications", "pn532.config.timeout_non_dep", FT_UINT8, BASE_HEX,
VALS(pn532_config_timeout_vals), 0x00, NULL, HFILL}},
{&hf_pn532_config_max_rty_com,
{"Max Retry COM", "pn532.config.max_rty_com", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_max_rty_atr,
{"Max Retry ATR", "pn532.config.max_rty_atr", FT_UINT8, BASE_DEC,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_max_rty_psl,
{"Max Retry PSL", "pn532.config.max_rty_psl", FT_UINT8, BASE_DEC,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_max_rty_passive_activation,
{"Max Retry Passive Activation", "pn532.config.max_rty_passive_activation", FT_UINT8, BASE_DEC,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_afi,
{"AFI", "pn532.afi", FT_UINT8, BASE_DEC,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_polling_method,
{"Polling Method", "pn532.polling_method", FT_UINT8, BASE_DEC,
VALS(pn532_polling_method_vals), 0x00, NULL, HFILL}},
{&hf_pn532_config_ciu_rf_cfg,
{"CIU RF Cfg", "pn532.ciu_rf_cfg", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_ciu_gs_n_on,
{"CIU GsN On", "pn532.ciu_gs_n_on", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_ciu_gs_n_off,
{"CIU GsN Off", "pn532.ciu_gs_n_off", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_ciu_cw_gs_p,
{"CIU CW GsP", "pn532.ciu_cw_gs_p", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_ciu_demon_rf_on,
{"CIU Demon when RF is On", "pn532.ciu_demon_rf_on", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_ciu_demon_rf_off,
{"CIU Demon when RF is Off", "pn532.ciu_demon_rf_off", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_ciu_rx_threshold,
{"CIU RX Threshold", "pn532.ciu_rx_threshold", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_ciu_mod_width,
{"CIU Mod Width", "pn532.ciu_mod_width", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_ciu_mod_gs_p,
{"CIU Mod GsP", "pn532.ciu_mod_gs_p", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_ciu_mif_nfc,
{"CIU Mif NFC", "pn532.ciu_mif_nfc", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_ciu_tx_bit_phase,
{"CIU TX Bit Phase", "pn532.ciu_tx_bit_phase", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_212_kbps,
{"212 kbps settings", "pn532.212_kbps", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_424_kbps,
{"424 kbps settings", "pn532.424_kbps", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_config_848_kbps,
{"848 kbps settings", "pn532.848_kbps", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_state,
{"State", "pn532.state", FT_UINT8, BASE_HEX,
VALS(pn532_state_vals), 0x00, NULL, HFILL}},
{&hf_pn532_brit_nu_7,
{"Not Used", "pn532.brit.not_used.7", FT_UINT8, BASE_HEX,
NULL, 0x80, NULL, HFILL}},
{&hf_pn532_brit_speed_initiator,
{"Speed Initiator", "pn532.brit.speed_initiator", FT_UINT8, BASE_HEX,
VALS(pn532_speed_vals), 0x70, NULL, HFILL}},
{&hf_pn532_brit_nu_3,
{"Not Used", "pn532.brit.not_used.3", FT_UINT8, BASE_HEX,
NULL, 0x08, NULL, HFILL}},
{&hf_pn532_brit_speed_target,
{"Speed Target", "pn532.brit.speed_target", FT_UINT8, BASE_HEX,
VALS(pn532_speed_vals), 0x07, NULL, HFILL}},
{&hf_pn532_tg_response,
{"TG Response", "pn532.tg_response", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_initiator_command,
{"Initiator Command", "pn532.initiator_command", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_data_out,
{"Data Out", "pn532.data_out", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_data_in,
{"Data In", "pn532.data_in", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_gt,
{"Gt", "pn532.gt", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_gi,
{"Gi", "pn532.gi", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_nu_3_7,
{"Not Used", "pn532.mode.not_used.3_7", FT_UINT8, BASE_HEX,
NULL, 0xF8, NULL, HFILL}},
{&hf_pn532_mode_picc_only,
{"PICC Only", "pn532.mode.picc_only", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{&hf_pn532_mode_dep_only,
{"DEP Only", "pn532.mode.dep_only", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{&hf_pn532_mode_passive_only,
{"Passive Only", "pn532.mode.passive_only", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{&hf_pn532_mode_mifare_parameters,
{"Mifare Parameters", "pn532.mode.mifare_parameters", FT_NONE, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_mifare_parameters_sens_res,
{"SENS RES", "pn532.mode.mifare_parameters.sens_res", FT_UINT16, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_mifare_parameters_nfc_id_1t,
{"NFC ID 1t", "pn532.mode.mifare_parameters.nfc_id_1t", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_mifare_parameters_sel_res,
{"SEL RES", "pn532.mode.mifare_parameters.sel_res", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_felica_parameters,
{"FeliCA Parameters", "pn532.mode.felica_parameters", FT_NONE, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_felica_parameters_nfc_id_2t,
{"NFC ID 2t", "pn532.mode.felica_parameters.nfc_id_2t", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_felica_parameters_pad,
{"Pad", "pn532.mode.felica_parameters.pad", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_felica_parameters_system_code,
{"System Code", "pn532.mode.felica_parameters.system_code", FT_UINT16, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_nfc_id_3t,
{"NFC ID 3t", "pn532.mode.nfc_id_3t", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_gt,
{"Gt", "pn532.mode.gt", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_gt_length,
{"Gt Length", "pn532.mode.gt.length", FT_UINT8, BASE_DEC,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_tk,
{"Tk", "pn532.mode.tk", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_tk_length,
{"Tk Length", "pn532.mode.tk.length", FT_UINT8, BASE_DEC,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_mode_nu_7,
{"Not Used", "pn532.mode.not_used.7", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{&hf_pn532_mode_baudrate,
{"Baudrate", "pn532.mode.baudrate", FT_UINT8, BASE_HEX,
VALS(pn532_speed_vals), 0x70, NULL, HFILL}},
{&hf_pn532_mode_iso_iec_14443_4_picc,
{"ISO/IEC 14443-4 PICC", "pn532.mode.iso_iec_14443_4_picc", FT_BOOLEAN, 8,
NULL, 0x08, NULL, HFILL}},
{&hf_pn532_mode_dep,
{"DEP", "pn532.mode.dep", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{&hf_pn532_mode_framing_type,
{"Framing Type", "pn532.mode.framing_type", FT_UINT8, BASE_HEX,
VALS(pn532_framing_type_vals), 0x03, NULL, HFILL}},
{&hf_pn532_brit,
{"BRit", "pn532.brit", FT_UINT8, BASE_HEX,
VALS(pn532_speed_vals), 0x00, NULL, HFILL}},
{&hf_pn532_brti,
{"BRti", "pn532.brti", FT_UINT8, BASE_HEX,
VALS(pn532_speed_vals), 0x00, NULL, HFILL}},
{&hf_pn532_txmode_nu_7,
{"Not Used", "pn532.txmode.not_used.7", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{&hf_pn532_txmode_tx_speed,
{"Tx Speed", "pn532.txmode.txspeed", FT_UINT8, BASE_HEX,
VALS(pn532_txspeed_vals), 0x70, NULL, HFILL}},
{&hf_pn532_txmode_nu_2_3,
{"Not Used", "pn532.txmode.not_used.2_3", FT_UINT8, BASE_HEX,
NULL, 0xC0, NULL, HFILL}},
{&hf_pn532_txmode_tx_framing,
{"Tx Framing", "pn532.txmode.not_used.2_3", FT_UINT8, BASE_HEX,
VALS(pn532_txframing_vals), 0x03, NULL, HFILL}},
{&hf_pn532_baudrate,
{"Baudrate", "pn532.baudrate", FT_UINT8, BASE_HEX,
VALS(pn532_baudrate_vals), 0x00, NULL, HFILL}},
{&hf_pn532_flags,
{"Flags", "pn532.flags", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_flags_rfu_7,
{"RFU", "pn532.flags.rfu.7", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{&hf_pn532_flags_remove_preamble_and_postamble,
{"Remove Preamble and Postamble", "pn532.flags.remove_preamble_and_postamble", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL}},
{&hf_pn532_flags_iso_14443_4_picc_emulation,
{"ISO 14443-4 PICC Emulation", "pn532.flags.iso_14443_4_picc_emulation", FT_BOOLEAN, 8,
NULL, 0x20, NULL, HFILL}},
{&hf_pn532_flags_automatic_rats,
{"Automatic RATS", "pn532.flags.automatic_rats", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{&hf_pn532_flags_rfu_3,
{"RFU", "pn532.flags.rfu.3", FT_BOOLEAN, 8,
NULL, 0x08, NULL, HFILL}},
{&hf_pn532_flags_automatic_atr_res,
{"Automatic ATR RES", "pn532.flags.automatic_atr_res", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{&hf_pn532_flags_did_used,
{"DID Used", "pn532.flags.did_used", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{&hf_pn532_flags_nad_used,
{"NAD Used", "pn532.flags.nad_used", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{&hf_pn532_wakeup_enable,
{"Wakeup Enable", "pn532.wakeup_enable", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_target,
{"Target", "pn532.target", FT_NONE, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_generate_irq,
{"Generate IRQ", "pn532.generate_irq", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_register_address,
{"Register Address", "pn532.register.address", FT_UINT16, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_register_value,
{"Register Value", "pn532.register.value", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_field,
{"Field", "pn532.register.value", FT_BOOLEAN, BASE_NONE,
&tfs_present_not_present, 0x00, "Field indicates if an external RF field is present and detected by the PN532", HFILL}},
{&hf_pn532_brrx,
{"Baudrate Rx", "pn532.brrx", FT_UINT8, BASE_HEX,
VALS(pn532_speed_vals), 0x00, NULL, HFILL}},
{&hf_pn532_brtx,
{"Baudrate Tx", "pn532.brtx", FT_UINT8, BASE_HEX,
VALS(pn532_speed_vals), 0x00, NULL, HFILL}},
{&hf_pn532_type,
{"Type", "pn532.type", FT_UINT8, BASE_HEX,
VALS(pn532_type_vals), 0x00, NULL, HFILL}},
{&hf_pn532_sam_status,
{"SAM Status", "pn532.sam.status", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_wakeup_enable_i2c,
{"I2C", "pn532.wakeup_enable.i2c", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{&hf_pn532_wakeup_enable_gpio,
{"GPIO", "pn532.wakeup_enable.gpio", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL}},
{&hf_pn532_wakeup_enable_spi,
{"SPI", "pn532.wakeup_enable.spi", FT_BOOLEAN, 8,
NULL, 0x20, NULL, HFILL}},
{&hf_pn532_wakeup_enable_hsu,
{"HSU", "pn532.wakeup_enable.hsu", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{&hf_pn532_wakeup_enable_rf_level_detector,
{"RF Level Detector", "pn532.wakeup_enable.rf_level_detector", FT_BOOLEAN, 8,
NULL, 0x08, NULL, HFILL}},
{&hf_pn532_wakeup_enable_rfu_2,
{"RFU", "pn532.wakeup_enable.rfu_2", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{&hf_pn532_wakeup_enable_int_1,
{"I2C", "pn532.wakeup_enable.int.1", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{&hf_pn532_wakeup_enable_int_0,
{"I2C", "pn532.wakeup_enable.int.0", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{&hf_pn532_gpio_ioi1,
{"GPIO IOI1", "pn532.gpio.ioi1", FT_UINT8, BASE_HEX,
NULL, 0xFF, NULL, HFILL}},
{&hf_pn532_gpio_p3,
{"GPIO P3", "pn532.gpio.p3", FT_UINT8, BASE_HEX,
NULL, 0xFF, NULL, HFILL}},
{&hf_pn532_gpio_p7,
{"GPIO P7", "pn532.gpio.p7", FT_UINT8, BASE_HEX,
NULL, 0xFF, NULL, HFILL}},
{&hf_pn532_poll_number,
{"Poll Number", "pn532.poll_number", FT_UINT8, BASE_DEC,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_period,
{"Period", "pn532.period", FT_UINT8, BASE_DEC,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_autopoll_type,
{"Type", "pn532.autopoll_type", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_target_data,
{"Target Data", "pn532.target_data", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_target_data_length,
{"Target Data Length", "pn532.target_data.length", FT_UINT8, BASE_DEC,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_autopoll_type_act,
{"Active Mode", "pn532.autopoll_type.active", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{&hf_pn532_autopoll_type_dep,
{"DEP", "pn532.autopoll_type.dep", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL}},
{&hf_pn532_autopoll_type_tcl,
{"TCL", "pn532.autopoll_type.tcl", FT_BOOLEAN, 8,
NULL, 0x20, NULL, HFILL}},
{&hf_pn532_autopoll_type_mf_fe,
{"Mf_Fe", "pn532.autopoll_type.mf_fe", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{&hf_pn532_autopoll_type_not_used,
{"Not used", "pn532.autopoll_type.not_used", FT_BOOLEAN, 8,
NULL, 0x08, NULL, HFILL}},
{&hf_pn532_autopoll_type_baudrate_and_modulation,
{"Baudrate and Modulation", "pn532.autopoll_type.baudrate_and_modulation", FT_UINT8, BASE_HEX,
VALS(pn532_brtypes), 0x07, NULL, HFILL}},
{&hf_pn532_nfc_id_3i,
{"NFC ID 3i", "pn532.nfc_id_3i", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_next_not_used_2_7,
{"Not Used", "pn532.next.not_used.2_7", FT_BOOLEAN, 8,
NULL, 0xFC, NULL, HFILL}},
{&hf_pn532_next_gi,
{"Gi", "pn532.next.gi", FT_BOOLEAN, 8,
&tfs_present_not_present, 0x02, NULL, HFILL}},
{&hf_pn532_next_nfc_id_3i,
{"NFC ID 3i", "pn532.next.nfc_id_3i", FT_BOOLEAN, 8,
&tfs_present_not_present, 0x01, NULL, HFILL}},
{&hf_pn532_nfc_id_3t,
{"NFC ID 3t", "pn532.nfc_id_3t", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_communication_mode,
{"Communication Mode", "pn532.communication_mode", FT_UINT8, BASE_HEX,
VALS(pn532_communication_mode_vals), 0x00, NULL, HFILL}},
{&hf_pn532_activation_baudrate,
{"Baudrate", "pn532.activation_baudrate", FT_UINT8, BASE_HEX,
VALS(pn532_speed_vals), 0x70, NULL, HFILL}},
{&hf_pn532_jump_next_not_used_3_7,
{"Not Used", "pn532.jump_next.not_used.3_7", FT_BOOLEAN, 8,
NULL, 0xF8, NULL, HFILL}},
{&hf_pn532_jump_next_gi,
{"Gi", "pn532.jump_next.gi", FT_BOOLEAN, 8,
&tfs_present_not_present, 0x04, NULL, HFILL}},
{&hf_pn532_jump_next_nfc_id_3i,
{"NFC ID 3i", "pn532.jump_next.nfc_id_3i", FT_BOOLEAN, 8,
&tfs_present_not_present, 0x02, NULL, HFILL}},
{&hf_pn532_jump_next_passive_initiator_data,
{"Passive Initiator Data", "pn532.jump_next.passive_initiator_data", FT_BOOLEAN, 8,
&tfs_present_not_present, 0x01, NULL, HFILL}},
{&hf_pn532_passive_initiator_data,
{"Passive Initiator Data", "pn532.passive_initiator_data", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_did_target,
{"DID Target", "pn532.did_target", FT_UINT8, BASE_HEX_DEC,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_send_bit_rate_target,
{"Send Bit Rate Target", "pn532.send_bit_rate_target", FT_UINT8, BASE_DEC_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_receive_bit_rate_target,
{"Receive Bit Rate Target", "pn532.receive_bit_rate_target", FT_UINT8, BASE_DEC_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_timeout,
{"Timeout", "pn532.timeout", FT_UINT8, BASE_DEC_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_optional_parameters,
{"Optional Parameters", "pn532.optional_parameters", FT_UINT8, BASE_HEX,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_test_number,
{"Test Number", "pn532.test_number", FT_UINT8, BASE_HEX,
VALS(pn532_test_number_vals), 0x00, NULL, HFILL}},
{&hf_pn532_parameters,
{"Parameters", "pn532.diagnose_parameters", FT_BYTES, BASE_NONE,
NULL, 0x00, NULL, HFILL}},
{&hf_pn532_parameters_length,
{"Parameters Length", "pn532.diagnose_parameters.length", FT_UINT8, BASE_DEC,
NULL, 0x00, NULL, HFILL}},
};
static ei_register_info ei[] = {
{ &ei_unknown_data, { "pn532.expert.unknown_data", PI_PROTOCOL, PI_NOTE, "Unknown data", EXPFILL }},
{ &ei_unexpected_data, { "pn532.expert.unexpected_data", PI_PROTOCOL, PI_WARN, "Unexpected data", EXPFILL }},
};
static gint *ett[] = {
&ett_pn532,
&ett_pn532_flags,
&ett_pn532_target,
&ett_pn532_fw_support,
&ett_pn532_config_212_kbps,
&ett_pn532_config_424_kbps,
&ett_pn532_config_848_kbps,
&ett_pn532_mifare_parameters,
&ett_pn532_felica_parameters,
&ett_pn532_wakeup_enable,
&ett_pn532_autopoll_type
};
static const enum_val_t sub_enum_vals[] = {
{ "data", "Data", SUB_DATA },
{ "felica", "Sony FeliCa", SUB_FELICA },
{ "mifare", "NXP MiFare", SUB_MIFARE },
{ "iso7816", "ISO 7816", SUB_ISO7816 },
{ NULL, NULL, 0 }
};
proto_pn532 = proto_register_protocol("NXP PN532", "PN532", "pn532");
proto_register_field_array(proto_pn532, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_pn532 = expert_register_protocol(proto_pn532);
expert_register_field_array(expert_pn532, ei, array_length(ei));
pref_mod = prefs_register_protocol(proto_pn532, NULL);
prefs_register_static_text_preference(pref_mod, "version",
"PN532 protocol version is based on: \"UM0701-02; PN532 User Manual\"",
"Version of protocol supported by this dissector.");
prefs_register_enum_preference(pref_mod, "prtype532", "Payload Type", "Protocol payload type",
&sub_selected, sub_enum_vals, FALSE);
pn532_dissector_table = register_dissector_table("pn532.payload", "PN532 Payload", FT_UINT8, BASE_DEC);
register_dissector("pn532", dissect_pn532, proto_pn532);
}
void proto_reg_handoff_pn532(void)
{
sub_handles[SUB_DATA] = find_dissector("data");
sub_handles[SUB_FELICA] = find_dissector("felica");
sub_handles[SUB_MIFARE] = find_dissector("mifare");
sub_handles[SUB_ISO7816] = find_dissector("iso7816");
}
