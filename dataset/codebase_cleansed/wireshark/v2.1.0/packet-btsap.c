static gint
dissect_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *top_tree,
proto_tree *tree, gint offset, guint8 *parameter, gint *parameter_offset)
{
proto_item *parameter_item;
proto_item *pitem;
proto_tree *ptree;
tvbuff_t *next_tvb;
guint parameter_id;
guint parameter_length;
guint parameter_padding_length;
guint padding_length;
guint length;
guint16 max_msg_size;
guint8 connection_status;
guint8 result_code;
guint8 disconnection_type;
guint8 status_change;
guint8 transport_protocol;
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_ntohs(tvb, offset + 2);
parameter_padding_length = parameter_length % 4;
if (parameter_padding_length > 0)
parameter_padding_length = 4 - parameter_padding_length;
parameter_item = proto_tree_add_none_format(tree, hf_btsap_parameter, tvb, offset,
2 + 2 + parameter_length + parameter_padding_length, "Parameter: %s: ",
val_to_str_const(parameter_id, parameter_id_vals, "Unknown ParameterID"));
ptree = proto_item_add_subtree(parameter_item, ett_btsap_parameter);
proto_tree_add_item(ptree, hf_btsap_parameter_id, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s", val_to_str_const(parameter_id, parameter_id_vals, "Unknown ParameterID"));
offset += 1;
proto_tree_add_item(ptree, hf_btsap_parameter_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
pitem = proto_tree_add_item(ptree, hf_btsap_parameter_length, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pitem, " (in 4 bytes sections, padding length: %u)", parameter_padding_length);
offset += 2;
switch(parameter_id) {
case 0x00:
proto_tree_add_item(ptree, hf_btsap_parameter_max_msg_size, tvb, offset, 2, ENC_BIG_ENDIAN);
max_msg_size = tvb_get_ntohs(tvb, offset);
proto_item_append_text(parameter_item, "%u", max_msg_size);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %u", max_msg_size);
length = 2;
padding_length = 2;
break;
case 0x01:
proto_tree_add_item(ptree, hf_btsap_parameter_connection_status, tvb, offset, 1, ENC_BIG_ENDIAN);
connection_status = tvb_get_guint8(tvb, offset);
proto_item_append_text(parameter_item, "%s", val_to_str_const(connection_status, connection_status_vals, "Unknown"));
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(connection_status, connection_status_vals, "Unknown"));
length = 1;
padding_length = 3;
break;
case 0x02:
proto_tree_add_item(ptree, hf_btsap_parameter_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
result_code = tvb_get_guint8(tvb, offset);
proto_item_append_text(parameter_item, "%s", val_to_str_const(result_code, result_code_vals, "Unknown"));
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(result_code, result_code_vals, "Unknown"));
length = 1;
padding_length = 3;
break;
case 0x03:
proto_tree_add_item(ptree, hf_btsap_parameter_disconnection_type, tvb, offset, 1, ENC_BIG_ENDIAN);
disconnection_type = tvb_get_guint8(tvb, offset);
proto_item_append_text(parameter_item, "%s", val_to_str_const(disconnection_type, disconnection_type_vals, "Unknown"));
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(disconnection_type, disconnection_type_vals, "Unknown"));
length = 1;
padding_length = 3;
break;
case 0x04:
if (gsm_sim_cmd_handle && top_dissect != TOP_DISSECT_OFF) {
next_tvb = tvb_new_subset_length(tvb, offset, parameter_length);
col_append_str(pinfo->cinfo, COL_INFO, ": ");
if (top_dissect == TOP_DISSECT_INTERNAL) {
call_dissector(gsm_sim_cmd_handle, next_tvb, pinfo, ptree);
} else {
col_clear(pinfo->cinfo, COL_INFO);
call_dissector(gsm_sim_cmd_handle, next_tvb, pinfo, top_tree);
}
} else {
proto_tree_add_item(ptree, hf_btsap_data, tvb, offset, parameter_length, ENC_NA);
}
length = parameter_length;
padding_length = parameter_padding_length;
break;
case 0x05:
if (gsm_sim_resp_handle && top_dissect != TOP_DISSECT_OFF) {
next_tvb = tvb_new_subset_length(tvb, offset, parameter_length);
col_append_str(pinfo->cinfo, COL_INFO, ": ");
if (top_dissect == TOP_DISSECT_INTERNAL) {
call_dissector(gsm_sim_resp_handle, next_tvb, pinfo, ptree);
} else {
col_clear(pinfo->cinfo, COL_INFO);
call_dissector(gsm_sim_resp_handle, next_tvb, pinfo, top_tree);
}
} else {
proto_tree_add_item(ptree, hf_btsap_data, tvb, offset, parameter_length, ENC_NA);
}
length = parameter_length;
padding_length = parameter_padding_length;
break;
case 0x06:
if (iso7816_atr_handle && top_dissect != TOP_DISSECT_OFF) {
next_tvb = tvb_new_subset_length(tvb, offset, parameter_length);
col_append_str(pinfo->cinfo, COL_INFO, ": ");
if (top_dissect == TOP_DISSECT_INTERNAL) {
call_dissector(iso7816_atr_handle, next_tvb, pinfo, ptree);
} else {
col_clear(pinfo->cinfo, COL_INFO);
call_dissector(iso7816_atr_handle, next_tvb, pinfo, top_tree);
}
} else {
proto_tree_add_item(ptree, hf_btsap_data, tvb, offset, parameter_length, ENC_NA);
}
length = parameter_length;
padding_length = parameter_padding_length;
break;
case 0x07:
proto_tree_add_item(ptree, hf_btsap_parameter_card_reader_status_card_powered, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptree, hf_btsap_parameter_card_reader_status_card_present, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptree, hf_btsap_parameter_card_reader_status_card_reader_present_lower, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptree, hf_btsap_parameter_card_reader_status_card_reader_present, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptree, hf_btsap_parameter_card_reader_status_card_reader_removable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptree, hf_btsap_parameter_card_reader_status_card_reader_identity, tvb, offset, 1, ENC_BIG_ENDIAN);
length = 1;
padding_length = 3;
break;
case 0x08:
proto_tree_add_item(ptree, hf_btsap_parameter_status_change, tvb, offset, 1, ENC_BIG_ENDIAN);
status_change = tvb_get_guint8(tvb, offset);
proto_item_append_text(parameter_item, "%s", val_to_str_const(status_change, status_change_vals, "Unknown"));
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(status_change, status_change_vals, "Unknown"));
length = 1;
padding_length = 3;
break;
case 0x09:
proto_tree_add_item(ptree, hf_btsap_parameter_transport_protocol, tvb, offset, 1, ENC_BIG_ENDIAN);
transport_protocol = tvb_get_guint8(tvb, offset);
proto_item_append_text(parameter_item, "%u", transport_protocol);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %u", transport_protocol);
length = 1;
padding_length = 3;
break;
case 0x10:
if (gsm_sim_cmd_handle && top_dissect != TOP_DISSECT_OFF) {
next_tvb = tvb_new_subset_length(tvb, offset, parameter_length);
col_append_str(pinfo->cinfo, COL_INFO, ": ");
if (top_dissect == TOP_DISSECT_INTERNAL) {
call_dissector(gsm_sim_cmd_handle, next_tvb, pinfo, ptree);
} else {
col_clear(pinfo->cinfo, COL_INFO);
call_dissector(gsm_sim_cmd_handle, next_tvb, pinfo, top_tree);
}
} else {
proto_tree_add_item(ptree, hf_btsap_data, tvb, offset, parameter_length, ENC_NA);
}
length = parameter_length;
padding_length = parameter_padding_length;
break;
default:
proto_tree_add_item(ptree, hf_btsap_data, tvb, offset, parameter_length, ENC_NA);
length = parameter_length;
padding_length = parameter_padding_length;
}
*parameter = parameter_id;
*parameter_offset = offset;
if (length != parameter_length || padding_length != parameter_padding_length) {
expert_add_info_format(pinfo, pitem, &ei_btsap_parameter_error,
"Parameter Length does not meet content length");
}
offset += parameter_length;
if (parameter_padding_length > 0) {
pitem = proto_tree_add_item(ptree, hf_btsap_parameter_padding, tvb, offset, parameter_padding_length, ENC_NA);
proto_item_append_text(pitem, " (length %d)", parameter_padding_length);
offset += parameter_padding_length;
}
return offset;
}
static gint
dissect_btsap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *btsap_tree;
guint offset = 0;
guint msg_id;
guint number_of_parameters;
guint8 *parameters;
gint *parameter_offsets;
guint parameters_check = 0;
guint required_parameters = 0;
guint i_parameter;
guint i_next_parameter;
ti = proto_tree_add_item(tree, proto_btsap, tvb, offset, -1, ENC_NA);
btsap_tree = proto_item_add_subtree(ti, ett_btsap);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SAP");
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_set_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_set_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "UnknownDirection ");
break;
}
proto_tree_add_item(btsap_tree, hf_btsap_header_msg_id, tvb, offset, 1, ENC_BIG_ENDIAN);
msg_id = tvb_get_guint8(tvb, offset);
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(msg_id, msg_id_vals, "Unknown MsgID"));
offset += 1;
proto_tree_add_item(btsap_tree, hf_btsap_header_number_of_parameters, tvb, offset, 1, ENC_BIG_ENDIAN);
number_of_parameters = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(btsap_tree, hf_btsap_header_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
parameters = (guint8 *) wmem_alloc(wmem_packet_scope(), number_of_parameters * sizeof(guint8));
parameter_offsets = (gint *) wmem_alloc0(wmem_packet_scope(), number_of_parameters * sizeof(guint));
for (i_parameter = 0; i_parameter < number_of_parameters; ++i_parameter) {
offset = dissect_parameter(tvb, pinfo, tree, btsap_tree, offset, &parameters[i_parameter], &parameter_offsets[i_parameter]);
}
switch(msg_id) {
case 0x02:
case 0x03:
case 0x07:
case 0x09:
case 0x0B:
case 0x0D:
case 0x0F:
case 0x12:
required_parameters = 0;
break;
case 0x0A:
case 0x0C:
case 0x0E:
case 0x14:
required_parameters = 1;
for (i_parameter = 0; i_parameter < number_of_parameters; ++i_parameter) {
if (parameters[i_parameter] == PARAMETER_RESULT_CODE) ++parameters_check;
}
break;
case 0x00:
required_parameters = 1;
for (i_parameter = 0; i_parameter < number_of_parameters; ++i_parameter) {
if (parameters[i_parameter] == PARAMETER_MAX_MSG_SIZE) ++parameters_check;
}
break;
case 0x01:
required_parameters = 1;
for (i_parameter = 0; i_parameter < number_of_parameters; ++i_parameter) {
if (parameters[i_parameter] == PARAMETER_CONNECTION_STATUS) {
if (tvb_get_guint8(tvb, parameter_offsets[i_parameter]) != 0x00) {
for (i_next_parameter = 0; i_next_parameter < number_of_parameters; ++i_next_parameter) {
if (parameters[i_next_parameter] == PARAMETER_MAX_MSG_SIZE) {
++parameters_check;
required_parameters = 2;
}
}
}
++parameters_check;
}
}
break;
case 0x04:
required_parameters = 1;
for (i_parameter = 0; i_parameter < number_of_parameters; ++i_parameter) {
if (parameters[i_parameter] == PARAMETER_DISCONNECTION_TYPE) ++parameters_check;
}
break;
case 0x05:
required_parameters = 1;
for (i_parameter = 0; i_parameter < number_of_parameters; ++i_parameter) {
if (parameters[i_parameter] == PARAMETER_COMMAND_APDU ||
parameters[i_parameter] == PARAMETER_COMMAND_APDU_7816)
++parameters_check;
}
break;
case 0x06:
required_parameters = 1;
for (i_parameter = 0; i_parameter < number_of_parameters; ++i_parameter) {
if (parameters[i_parameter] == PARAMETER_RESULT_CODE) {
if (tvb_get_guint8(tvb, parameter_offsets[i_parameter]) == 0x00) {
for (i_next_parameter = 0; i_next_parameter < number_of_parameters; ++i_next_parameter) {
if (parameters[i_next_parameter] == PARAMETER_RESPONSE_APDU) {
++parameters_check;
required_parameters = 2;
}
}
}
++parameters_check;
}
}
break;
case 0x08:
required_parameters = 1;
for (i_parameter = 0; i_parameter < number_of_parameters; ++i_parameter) {
if (parameters[i_parameter] == PARAMETER_RESULT_CODE) {
if (tvb_get_guint8(tvb, parameter_offsets[i_parameter]) == 0x00) {
for (i_next_parameter = 0; i_next_parameter < number_of_parameters; ++i_next_parameter) {
if (parameters[i_next_parameter] == PARAMETER_ATR) {
++parameters_check;
required_parameters = 2;
}
}
}
++parameters_check;
}
}
break;
case 0x10:
required_parameters = 1;
for (i_parameter = 0; i_parameter < number_of_parameters; ++i_parameter) {
if (parameters[i_parameter] == PARAMETER_RESULT_CODE) {
if (tvb_get_guint8(tvb, parameter_offsets[i_parameter]) == 0x00) {
for (i_next_parameter = 0; i_next_parameter < number_of_parameters; ++i_next_parameter) {
if (parameters[i_next_parameter] == PARAMETER_CARD_READER_STATUS) {
++parameters_check;
required_parameters = 2;
}
}
}
++parameters_check;
}
}
break;
case 0x11:
required_parameters = 1;
for (i_parameter = 0; i_parameter < number_of_parameters; ++i_parameter) {
if (parameters[i_parameter] == PARAMETER_STATUS_CHANGE) ++parameters_check;
}
break;
case 0x13:
required_parameters = 1;
for (i_parameter = 0; i_parameter < number_of_parameters; ++i_parameter) {
if (parameters[i_parameter] == PARAMETER_TRANSPORT_PROTOCOL) ++parameters_check;
}
break;
}
if (parameters_check < required_parameters) {
proto_tree_add_expert_format(tree, pinfo, &ei_btsap_parameter_error,
tvb, offset, 0, "There are no required parameters");
} else if (parameters_check > required_parameters) {
proto_tree_add_expert_format(tree, pinfo, &ei_btsap_parameter_error,
tvb, offset, 0, "Invalid parameters");
}
if (number_of_parameters < required_parameters) {
proto_tree_add_expert_format(tree, pinfo, &ei_btsap_parameter_error,
tvb, offset, 0, "Too few parameters");
} else if (number_of_parameters > required_parameters) {
proto_tree_add_expert_format(tree, pinfo, &ei_btsap_parameter_error,
tvb, offset, 0, "Too many parameters");
}
if (tvb_reported_length(tvb) > offset)
proto_tree_add_expert(tree, pinfo, &ei_unexpected_data, tvb, offset, tvb_reported_length_remaining(tvb, offset));
return offset;
}
void
proto_register_btsap(void)
{
module_t *module;
expert_module_t *expert_btsap;
static hf_register_info hf[] = {
{ &hf_btsap_header_msg_id,
{ "MsgID", "btsap.msg_id",
FT_UINT8, BASE_HEX, VALS(msg_id_vals), 0x00,
NULL, HFILL }
},
{ &hf_btsap_header_number_of_parameters,
{ "Number of Parameters", "btsap.number_of_parameters",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btsap_header_reserved,
{ "reserved", "btsap.reserved",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btsap_parameter,
{ "Parameter", "btsap.parameter",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btsap_parameter_id,
{ "Parameter ID", "btsap.parameter_id",
FT_UINT8, BASE_HEX, VALS(parameter_id_vals), 0x00,
NULL, HFILL }
},
{ &hf_btsap_parameter_reserved,
{ "reserved", "btsap.parameter.reserved",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btsap_parameter_length,
{ "Parameter Length", "btsap.parameter.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btsap_parameter_padding,
{ "Parameter Padding", "btsap.parameter.padding",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btsap_parameter_max_msg_size,
{ "Max Msg Size", "btsap.parameter.max_msg_size",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btsap_parameter_connection_status,
{ "Connection Status", "btsap.parameter.connection_status",
FT_UINT8, BASE_HEX, VALS(connection_status_vals), 0x00,
NULL, HFILL }
},
{ &hf_btsap_parameter_result_code,
{ "Result Code", "btsap.parameter.result_code",
FT_UINT8, BASE_HEX, VALS(result_code_vals), 0x00,
NULL, HFILL }
},
{ &hf_btsap_parameter_disconnection_type,
{ "Disconnection Type", "btsap.parameter.disconnection_type",
FT_UINT8, BASE_HEX, VALS(disconnection_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_btsap_parameter_card_reader_status_card_reader_identity,
{ "Identify of Card Reader", "btsap.parameter.card_reader_status.card_reader_identity",
FT_UINT8, BASE_HEX, NULL, 0x03,
NULL, HFILL }
},
{ &hf_btsap_parameter_card_reader_status_card_reader_removable,
{ "Card Reader is Removable", "btsap.parameter.card_reader_status.card_reader_removable",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_btsap_parameter_card_reader_status_card_reader_present,
{ "Card Reader is Present", "btsap.parameter.card_reader_status.card_reader_present",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_btsap_parameter_card_reader_status_card_reader_present_lower,
{ "Card Reader Present is ID-1 Size","btsap.parameter.card_reader_status.card_reader_present_lower",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_btsap_parameter_card_reader_status_card_present,
{ "Card is Present in Reader", "btsap.parameter.card_reader_status.card_present",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_btsap_parameter_card_reader_status_card_powered,
{ "Card in Reader is Powered", "btsap.parameter.card_reader_status.card_powered",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_btsap_parameter_status_change,
{ "Status Change", "btsap.parameter.status_change",
FT_UINT8, BASE_HEX, VALS(status_change_vals), 0x00,
NULL, HFILL }
},
{ &hf_btsap_parameter_transport_protocol,
{ "Transport Protocol", "btsap.parameter.transport_protocol",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btsap_data,
{ "Data", "btsap.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_btsap,
&ett_btsap_parameter
};
static ei_register_info ei[] = {
{ &ei_btsap_parameter_error, { "btsap.parameter_error", PI_PROTOCOL, PI_WARN, "Parameter error", EXPFILL }},
{ &ei_unexpected_data, { "btsap.unexpected_data", PI_PROTOCOL, PI_WARN, "Unexpected_data", EXPFILL }},
};
proto_btsap = proto_register_protocol("Bluetooth SAP Profile", "BT SAP", "btsap");
btsap_handle = register_dissector("btsap", dissect_btsap, proto_btsap);
proto_register_field_array(proto_btsap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_btsap = expert_register_protocol(proto_btsap);
expert_register_field_array(expert_btsap, ei, array_length(ei));
module = prefs_register_protocol(proto_btsap, NULL);
prefs_register_static_text_preference(module, "sap.version",
"Bluetooth Profile SAP version: 1.1",
"Version of protocol supported by this dissector.");
prefs_register_enum_preference(module, "sap.top_dissect",
"Dissecting the top protocols", "Dissecting the top protocols",
&top_dissect, pref_top_dissect, FALSE);
}
void
proto_reg_handoff_btsap(void)
{
gsm_sim_cmd_handle = find_dissector_add_dependency("gsm_sim.command", proto_btsap);
gsm_sim_resp_handle = find_dissector_add_dependency("gsm_sim.response", proto_btsap);
iso7816_atr_handle = find_dissector_add_dependency("iso7816.atr", proto_btsap);
dissector_add_string("bluetooth.uuid", "112d", btsap_handle);
dissector_add_for_decode_as("btrfcomm.dlci", btsap_handle);
}
