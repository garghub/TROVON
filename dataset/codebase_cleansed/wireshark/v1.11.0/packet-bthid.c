static gint
dissect_hid_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, guint report_type)
{
gboolean shortcut_helper = FALSE;
unsigned int protocol_code;
unsigned int modifier;
unsigned int keycode;
unsigned int leds;
unsigned int buttons;
proto_tree_add_item(tree, hf_bthid_protocol_code, tvb, offset, 1, ENC_BIG_ENDIAN);
protocol_code = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s", val_to_str_const(protocol_code, protocol_code_vals, "unknown type"));
offset += 1;
switch (protocol_code) {
case 0x01:
if (report_type == 0x02) {
proto_tree_add_item(tree, hf_bthid_data_keyboard_leds_constants, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_keyboard_leds_kana, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_keyboard_leds_compose, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_keyboard_leds_scroll_lock, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_keyboard_leds_caps_lock, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_keyboard_leds_num_lock, tvb, offset, 1, ENC_BIG_ENDIAN);
leds = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - LEDs: ");
if (leds & 0x01) {
col_append_fstr(pinfo->cinfo, COL_INFO, "NumLock");
shortcut_helper = TRUE;
}
if (leds & 0x02) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, ", ");
col_append_fstr(pinfo->cinfo, COL_INFO, "CapsLock");
shortcut_helper = TRUE;
}
if (leds & 0x04) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, ", ");
col_append_fstr(pinfo->cinfo, COL_INFO, "ScrollLock");
shortcut_helper = TRUE;
}
if (leds & 0x08) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, ", ");
col_append_fstr(pinfo->cinfo, COL_INFO, "Compose");
shortcut_helper = TRUE;
}
if (leds & 0x10) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, ", ");
col_append_fstr(pinfo->cinfo, COL_INFO, "Kana");
shortcut_helper = TRUE;
}
if (leds & 0x20) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, ", ");
col_append_fstr(pinfo->cinfo, COL_INFO, "Constant1");
shortcut_helper = TRUE;
}
if (leds & 0x40) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, ", ");
col_append_fstr(pinfo->cinfo, COL_INFO, "Constant2");
shortcut_helper = TRUE;
}
if (leds & 0x80) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, ", ");
col_append_fstr(pinfo->cinfo, COL_INFO, "Constant3");
}
if (!leds) {
col_append_fstr(pinfo->cinfo, COL_INFO, "none");
}
offset += 1;
break;
} else if (report_type != 0x01) {
break;
}
proto_tree_add_item(tree, hf_bthid_data_keyboard_modifier_right_gui, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_keyboard_modifier_right_alt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_keyboard_modifier_right_shift, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_keyboard_modifier_right_ctrl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_keyboard_modifier_left_gui, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_keyboard_modifier_left_alt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_keyboard_modifier_left_shift, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_keyboard_modifier_left_ctrl, tvb, offset, 1, ENC_BIG_ENDIAN);
modifier = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - ");
if (modifier & 0x80) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "RIGHT GUI");
shortcut_helper = TRUE;
}
if (modifier & 0x40) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "RIGHT ALT");
shortcut_helper = TRUE;
}
if (modifier & 0x20) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "RIGHT SHIFT");
shortcut_helper = TRUE;
}
if (modifier & 0x10) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "RIGHT CTRL");
shortcut_helper = TRUE;
}
if (modifier & 0x08) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "LEFT GUI");
shortcut_helper = TRUE;
}
if (modifier & 0x04) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "LEFT ALT");
shortcut_helper = TRUE;
}
if (modifier & 0x02) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "LEFT SHIFT");
shortcut_helper = TRUE;
}
if (modifier & 0x01) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "LEFT CTRL");
shortcut_helper = TRUE;
}
offset += 1;
proto_tree_add_item(tree, hf_bthid_data_keyboard_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthid_data_keyboard_keycode_1, tvb, offset, 1, ENC_BIG_ENDIAN);
keycode = tvb_get_guint8(tvb, offset);
offset += 1;
if (keycode) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext(keycode, &keycode_vals_ext, "Unknown"));
shortcut_helper = TRUE;
}
proto_tree_add_item(tree, hf_bthid_data_keyboard_keycode_2, tvb, offset, 1, ENC_BIG_ENDIAN);
keycode = tvb_get_guint8(tvb, offset);
offset += 1;
if (keycode) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext(keycode, &keycode_vals_ext, "Unknown"));
shortcut_helper = TRUE;
}
proto_tree_add_item(tree, hf_bthid_data_keyboard_keycode_3, tvb, offset, 1, ENC_BIG_ENDIAN);
keycode = tvb_get_guint8(tvb, offset);
offset += 1;
if (keycode) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext(keycode, &keycode_vals_ext, "Unknown"));
shortcut_helper = TRUE;
}
proto_tree_add_item(tree, hf_bthid_data_keyboard_keycode_4, tvb, offset, 1, ENC_BIG_ENDIAN);
keycode = tvb_get_guint8(tvb, offset);
offset += 1;
if (keycode) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext(keycode, &keycode_vals_ext, "Unknown"));
shortcut_helper = TRUE;
}
proto_tree_add_item(tree, hf_bthid_data_keyboard_keycode_5, tvb, offset, 1, ENC_BIG_ENDIAN);
keycode = tvb_get_guint8(tvb, offset);
offset += 1;
if (keycode) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext(keycode, &keycode_vals_ext, "Unknown"));
shortcut_helper = TRUE;
}
proto_tree_add_item(tree, hf_bthid_data_keyboard_keycode_6, tvb, offset, 1, ENC_BIG_ENDIAN);
keycode = tvb_get_guint8(tvb, offset);
offset += 1;
if (keycode) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext(keycode, &keycode_vals_ext, "Unknown"));
shortcut_helper = TRUE;
}
if (shortcut_helper == FALSE) {
col_append_fstr(pinfo->cinfo, COL_INFO, "<action key up>");
}
break;
case 0x02:
proto_tree_add_item(tree, hf_bthid_data_mouse_button_8, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_mouse_button_7, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_mouse_button_6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_mouse_button_5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_mouse_button_4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_mouse_button_middle, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_mouse_button_right, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthid_data_mouse_button_left, tvb, offset, 1, ENC_BIG_ENDIAN);
buttons = tvb_get_guint8(tvb, offset);
offset += 1;
if (buttons) col_append_fstr(pinfo->cinfo, COL_INFO, " - ");
if (buttons & 0x01) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "Button LEFT");
shortcut_helper = TRUE;
}
if (buttons & 0x02) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "Button RIGHT");
shortcut_helper = TRUE;
}
if (buttons & 0x04) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "Button MIDDLE");
}
if (buttons & 0x08) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "Button 4");
shortcut_helper = TRUE;
}
if (buttons & 0x10) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "Button 5");
shortcut_helper = TRUE;
}
if (buttons & 0x20) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "Button 6");
shortcut_helper = TRUE;
}
if (buttons & 0x40) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "Button 7");
shortcut_helper = TRUE;
}
if (buttons & 0x80) {
if (shortcut_helper) col_append_fstr(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "Button 8");
}
proto_tree_add_item(tree, hf_bthid_data_mouse_x_displacement, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthid_data_mouse_y_displacement, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (tvb_length_remaining(tvb, offset)) {
proto_tree_add_item(tree, hf_bthid_data_mouse_horizontal_scroll_wheel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (tvb_length_remaining(tvb, offset)) {
proto_tree_add_item(tree, hf_bthid_data_mouse_vertical_scroll_wheel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (tvb_length_remaining(tvb, offset)) {
proto_tree_add_item(tree, hf_bthid_data, tvb, offset, -1, ENC_NA);
offset += tvb_length_remaining(tvb, offset);
}
break;
}
return offset;
}
static int
dissect_bthid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *bthid_tree;
gint offset = 0;
guint transaction_type;
guint parameter;
guint protocol;
guint idle_rate;
guint8 control_operation;
proto_item *pitem;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HID");
col_clear(pinfo->cinfo, COL_INFO);
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_add_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_add_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown direction %d ",
pinfo->p2p_dir);
break;
}
ti = proto_tree_add_item(tree, proto_bthid, tvb, offset, -1, ENC_NA);
bthid_tree = proto_item_add_subtree(ti, ett_bthid);
pitem = proto_tree_add_item(bthid_tree, hf_bthid_transaction_type, tvb, offset, 1, ENC_BIG_ENDIAN);
transaction_type = tvb_get_guint8(tvb, offset);
parameter = transaction_type & 0x0F;
transaction_type = transaction_type >> 4;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_const(transaction_type, transaction_type_vals, "Unknown TransactionType"));
switch(transaction_type) {
case 0x00:
proto_tree_add_item(bthid_tree, hf_bthid_parameter_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, " - Result Code: %s", val_to_str_const(parameter, result_code_vals, "reserved"));
break;
case 0x01:
pitem = proto_tree_add_item(bthid_tree, hf_bthid_parameter_control_operation, tvb, offset, 1, ENC_BIG_ENDIAN);
control_operation = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - Control Operation: %s", val_to_str_const(parameter, control_operation_vals, "reserved"));
if (control_operation < 3 && show_deprecated)
expert_add_info(pinfo, pitem, &ei_bthid_parameter_control_operation_deprecated);
offset += 1;
break;
case 0x04:
proto_tree_add_item(bthid_tree, hf_bthid_parameter_size, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bthid_tree, hf_bthid_parameter_reserved_2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bthid_tree, hf_bthid_parameter_report_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, " - Size: %s, Report Type: %s",
val_to_str_const(parameter >> 3 , size_vals, "reserved"),
val_to_str_const(parameter & 0x03, report_type_vals, "reserved"));
if (((parameter >> 3) && tvb_length_remaining(tvb, offset) >= 3) ||
(!(parameter >> 3) && tvb_length_remaining(tvb, offset) >= 1)) {
proto_tree_add_item(bthid_tree, hf_bthid_report_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (parameter >> 3) {
proto_tree_add_item(bthid_tree, hf_bthid_buffer_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
break;
case 0x05:
proto_tree_add_item(bthid_tree, hf_bthid_parameter_reserved_32, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bthid_tree, hf_bthid_parameter_report_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, " - Report Type: %s",
val_to_str_const(parameter & 0x03, report_type_vals, "reserved"));
proto_tree_add_item(bthid_tree, hf_bthid_data, tvb, offset, -1, ENC_NA);
offset += tvb_length_remaining(tvb, offset);
break;
case 0x06:
proto_tree_add_item(bthid_tree, hf_bthid_parameter_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(bthid_tree, hf_bthid_protocol, tvb, offset, 1, ENC_BIG_ENDIAN);
protocol = tvb_get_guint8(tvb, offset) & 0x01;
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, " - Protocol: %s",
val_to_str_const(protocol, protocol_vals, "reserved"));
break;
case 0x07:
proto_tree_add_item(bthid_tree, hf_bthid_parameter_reserved_31, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bthid_tree, hf_bthid_protocol, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, " - Protocol: %s",
val_to_str_const(parameter & 0x01, protocol_vals, "reserved"));
break;
case 0x08:
case 0x09:
if (show_deprecated)
expert_add_info(pinfo, pitem, &ei_bthid_transaction_type_deprecated);
proto_tree_add_item(bthid_tree, hf_bthid_parameter_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
pitem = proto_tree_add_item(bthid_tree, hf_bthid_idle_rate, tvb, offset, 1, ENC_BIG_ENDIAN);
idle_rate = tvb_get_guint8(tvb, offset);
proto_item_append_text(pitem, " (%u.%03u ms)", idle_rate * 4 / 1000, idle_rate * 4 % 1000);
col_append_fstr(pinfo->cinfo, COL_INFO, " - Idle Rate: %u.%03u ms", idle_rate*4/1000, idle_rate*4%1000);
offset += 1;
break;
case 0x0B:
if (show_deprecated)
expert_add_info(pinfo, pitem, &ei_bthid_transaction_type_deprecated);
case 0x0A:
proto_tree_add_item(bthid_tree, hf_bthid_parameter_reserved_32, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bthid_tree, hf_bthid_parameter_report_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s", val_to_str_const(parameter, report_type_vals, "reserved"));
offset = dissect_hid_data(tvb, pinfo, bthid_tree, offset, parameter & 0x03);
break;
}
return offset;
}
void
proto_register_bthid(void)
{
module_t *module;
expert_module_t* expert_bthid;
static hf_register_info hf[] = {
{ &hf_bthid_transaction_type,
{ "Transaction Type", "bthid.transaction_type",
FT_UINT8, BASE_HEX, VALS(transaction_type_vals), 0xF0,
NULL, HFILL }
},
{ &hf_bthid_parameter_reserved,
{ "Parameter reserved", "bthid.parameter.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_bthid_parameter_reserved_32,
{ "Parameter reserved", "bthid.parameter.reserved_32",
FT_UINT8, BASE_HEX, NULL, 0x0C,
NULL, HFILL }
},
{ &hf_bthid_parameter_reserved_31,
{ "Parameter reserved", "bthid.parameter.reserved_31",
FT_UINT8, BASE_HEX, NULL, 0x0E,
NULL, HFILL }
},
{ &hf_bthid_parameter_reserved_2,
{ "Parameter reserved", "bthid.parameter.reserved_2",
FT_UINT8, BASE_HEX, NULL, 0x04,
NULL, HFILL }
},
{ &hf_bthid_parameter_report_type,
{ "Report Type", "bthid.parameter.report_type",
FT_UINT8, BASE_HEX, VALS(report_type_vals), 0x03,
NULL, HFILL }
},
{ &hf_bthid_parameter_size,
{ "Size", "bthid.parameter.size",
FT_UINT8, BASE_HEX, VALS(size_vals), 0x08,
NULL, HFILL }
},
{ &hf_bthid_parameter_result_code,
{ "Result Code", "bthid.result_code",
FT_UINT8, BASE_HEX, VALS(result_code_vals), 0x0F,
NULL, HFILL }
},
{ &hf_bthid_parameter_control_operation,
{ "Control Operation", "bthid.control_operation",
FT_UINT8, BASE_HEX, VALS(control_operation_vals), 0x0F,
NULL, HFILL }
},
{ &hf_bthid_protocol,
{ "Protocol", "bthid.protocol",
FT_UINT8, BASE_HEX, VALS(protocol_vals), 0x01,
NULL, HFILL }
},
{ &hf_bthid_idle_rate,
{ "Idle Rate", "bthid.idle_rate",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthid_report_id,
{ "Report Id", "bthid.report_id",
FT_UINT8, BASE_HEX, VALS(protocol_code_vals), 0x00,
NULL, HFILL }
},
{ &hf_bthid_buffer_size,
{ "Buffer Size", "bthid.buffer_size",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthid_protocol_code,
{ "Protocol Code", "bthid.data.protocol_code",
FT_UINT8, BASE_HEX, VALS(protocol_code_vals), 0x00,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_reserved,
{ "Reserved", "bthid.data.keyboard.reserved",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_keycode_1,
{ "Keycode 1", "bthid.data.keyboard.keycode_1",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keycode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_keycode_2,
{ "Keycode 2", "bthid.data.keyboard.keycode_2",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keycode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_keycode_3,
{ "Keycode 3", "bthid.data.keyboard.keycode_3",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keycode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_keycode_4,
{ "Keycode 4", "bthid.data.keyboard.keycode_4",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keycode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_keycode_5,
{ "Keycode 5", "bthid.data.keyboard.keycode_5",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keycode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_keycode_6,
{ "Keycode 6", "bthid.data.keyboard.keycode_6",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keycode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_modifier_right_gui,
{ "Modifier: RIGHT GUI", "bthid.data.keyboard.modifier.right_gui",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_modifier_right_alt,
{ "Modifier: RIGHT ALT", "bthid.data.keyboard.modifier.right_alt",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_modifier_right_shift,
{ "Modifier: RIGHT SHIFT", "bthid.data.keyboard.modifier.right_shift",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_modifier_right_ctrl,
{ "Modifier: RIGHT CTRL", "bthid.data.keyboard.modifier.right_ctrl",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_modifier_left_gui,
{ "Modifier: LEFT GUI", "bthid.data.keyboard.modifier.left_gui",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_modifier_left_alt,
{ "Modifier: LEFT ALT", "bthid.data.keyboard.modifier.left_alt",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_modifier_left_shift,
{ "Modifier: LEFT SHIFT", "bthid.data.keyboard.modifier.left_shift",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_modifier_left_ctrl,
{ "Modifier: LEFT CTRL", "bthid.data.keyboard.modifier.left_ctrl",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_leds_constants,
{ "Constants", "bthid.data.keyboard.leds.constants",
FT_UINT8, BASE_HEX, NULL, 0xE0,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_leds_kana,
{ "KANA", "bthid.data.keyboard.leds.kana",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_leds_compose,
{ "COMPOSE", "bthid.data.keyboard.leds.compose",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_leds_scroll_lock,
{ "SCROLL LOCK", "bthid.data.keyboard.leds.scroll_lock",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_leds_caps_lock,
{ "CAPS LOCK", "bthid.data.keyboard.leds.caps_lock",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_bthid_data_keyboard_leds_num_lock,
{ "NUM LOCK", "bthid.data.keyboard.leds.num_lock",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_bthid_data_mouse_button_8,
{ "Button 8", "bthid.data.mouse.button.8",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_bthid_data_mouse_button_7,
{ "Button 7", "bthid.data.mouse.button.7",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_bthid_data_mouse_button_6,
{ "Button 6", "bthid.data.mouse.button.6",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_bthid_data_mouse_button_5,
{ "Button 5", "bthid.data.mouse.button.5",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_bthid_data_mouse_button_4,
{ "Button 4", "bthid.data.mouse.button.4",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_bthid_data_mouse_button_middle,
{ "Button Middle", "bthid.data.mouse.button.middle",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_bthid_data_mouse_button_right,
{ "Button Right", "bthid.data.mouse.button.right",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_bthid_data_mouse_button_left,
{ "Button Left", "bthid.data.mouse.button.left",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_bthid_data_mouse_x_displacement,
{ "X Displacement", "bthid.data.mouse.x_displacement",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthid_data_mouse_y_displacement,
{ "Y Displacement", "bthid.data.mouse.y_displacement",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthid_data_mouse_horizontal_scroll_wheel,
{ "Horizontal Scroll Wheel", "bthid.data.mouse.scroll_wheel.horizontal",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthid_data_mouse_vertical_scroll_wheel,
{ "Vertical Scroll Wheel", "bthid.data.mouse.scroll_wheel.vertical",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthid_data,
{ "Data", "bthid.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_bthid
};
static ei_register_info ei[] = {
{ &ei_bthid_parameter_control_operation_deprecated, { "bthid.control_operation.deprecated", PI_PROTOCOL, PI_WARN, "This value of Control Operation is deprecated by HID 1.1", EXPFILL }},
{ &ei_bthid_transaction_type_deprecated, { "bthid.transaction_type.deprecated", PI_PROTOCOL, PI_WARN, "This Transaction Type is deprecated by HID 1.1", EXPFILL }},
};
proto_bthid = proto_register_protocol("Bluetooth HID Profile", "BT HID", "bthid");
new_register_dissector("bthid", dissect_bthid, proto_bthid);
proto_register_field_array(proto_bthid, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_bthid = expert_register_protocol(proto_bthid);
expert_register_field_array(expert_bthid, ei, array_length(ei));
module = prefs_register_protocol(proto_bthid, NULL);
prefs_register_static_text_preference(module, "hid.version",
"Bluetooth Profile HID version: 1.1",
"Version of profile supported by this dissector.");
prefs_register_bool_preference(module, "hid.deprecated",
"Show what is deprecated in HID 1.1",
"Show what is deprecated in HID 1.1", &show_deprecated);
}
void
proto_reg_handoff_bthid(void)
{
dissector_handle_t bthid_handle;
bthid_handle = find_dissector("bthid");
dissector_add_uint("btl2cap.service", BTSDP_HID_SERVICE_UUID, bthid_handle);
dissector_add_uint("btl2cap.service", BTSDP_HIDP_PROTOCOL_UUID, bthid_handle);
dissector_add_uint("btl2cap.psm", BTL2CAP_PSM_HID_CTRL, bthid_handle);
dissector_add_uint("btl2cap.psm", BTL2CAP_PSM_HID_INTR, bthid_handle);
dissector_add_handle("btl2cap.cid", bthid_handle);
}
