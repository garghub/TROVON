static gint
dissect_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gboolean is_client_message)
{
proto_item *pitem;
guint16 control_pdu_id;
guint credits;
guint timeout;
guint context_id;
guint notification_register;
guint number;
gint parameter_length;
pitem = proto_tree_add_item(tree, hf_bthcrp_control_pdu_id, tvb, offset, 2, ENC_BIG_ENDIAN);
control_pdu_id = tvb_get_ntohs(tvb, offset);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, "Control: %s %s",
((is_client_message) ? "Request" : "Response"),
val_to_str(control_pdu_id, control_pdu_id_vals, "Unknown PDU ID"));
if (control_pdu_id >= 0x8000) {
proto_item_append_text(pitem, " (Vendor Specific)");
col_append_str(pinfo->cinfo, COL_INFO, " (Vendor Specific)");
} else if (control_pdu_id == 0x0000 || control_pdu_id >= 0x000B ) {
proto_item_append_text(pitem, " (Reserved)");
col_append_str(pinfo->cinfo, COL_INFO, " (Reserved)");
}
proto_tree_add_item(tree, hf_bthcrp_control_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
pitem = proto_tree_add_item(tree, hf_bthcrp_control_parameter_length, tvb, offset, 2, ENC_BIG_ENDIAN);
parameter_length = tvb_get_ntohs(tvb, offset);
offset += 2;
if (!is_client_message && parameter_length < 2) {
expert_add_info_format(pinfo, pitem, &ei_bthcrp_control_parameter_length,
"Parameter length is shorter than 2 in response");
}
if (parameter_length < tvb_length_remaining(tvb, offset)) {
expert_add_info_format(pinfo, pitem, &ei_bthcrp_control_parameter_length,
"Parameter length is shorter than payload length");
} else if (parameter_length > tvb_length_remaining(tvb, offset)) {
expert_add_info_format(pinfo, pitem, &ei_bthcrp_control_parameter_length,
"Parameter length is larger than payload length");
}
if (!is_client_message) {
proto_tree_add_item(tree, hf_bthcrp_control_status, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (control_pdu_id >= 0x8000) {
if (tvb_length_remaining(tvb, offset)) {
proto_tree_add_item(tree, hf_bthcrp_data, tvb, offset, -1, ENC_NA);
offset += tvb_length_remaining(tvb, offset);
}
} else switch(control_pdu_id) {
case 0x0001:
if (is_client_message) {
proto_tree_add_item(tree, hf_bthcrp_control_client_credit_granted, tvb, offset, 4, ENC_BIG_ENDIAN);
credits = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - CreditGranted: %u", credits);
offset += 4;
}
break;
case 0x0002:
if (!is_client_message) {
proto_tree_add_item(tree, hf_bthcrp_control_server_credit_granted, tvb, offset, 4, ENC_BIG_ENDIAN);
credits = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - CreditGranted: %u", credits);
offset += 4;
}
break;
case 0x0003:
if (is_client_message) {
proto_tree_add_item(tree, hf_bthcrp_control_client_credit_return, tvb, offset, 4, ENC_BIG_ENDIAN);
credits = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - Client Credit Return: %u", credits);
offset += 4;
} else {
proto_tree_add_item(tree, hf_bthcrp_control_server_credit_return, tvb, offset, 4, ENC_BIG_ENDIAN);
credits = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - Server Credit Return: %u", credits);
offset += 4;
}
break;
case 0x0004:
if (is_client_message) {
proto_tree_add_item(tree, hf_bthcrp_control_client_credit_query, tvb, offset, 4, ENC_BIG_ENDIAN);
credits = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - Client Credit: %u", credits);
offset += 4;
} else {
proto_tree_add_item(tree, hf_bthcrp_control_server_credit_query, tvb, offset, 4, ENC_BIG_ENDIAN);
credits = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - Server Credit: %u", credits);
offset += 4;
}
break;
case 0x0005:
if (!is_client_message) {
proto_tree_add_item(tree, hf_bthcrp_control_status_reserved_76, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthcrp_control_status_paper_empty, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthcrp_control_status_select, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthcrp_control_status_not_error, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bthcrp_control_status_reserved_20, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case 0x0006:
if (is_client_message) {
proto_tree_add_item(tree, hf_bthcrp_control_start_byte, tvb, offset, 2, ENC_BIG_ENDIAN);
number = tvb_get_ntohs(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - Start Byte: %u", number);
offset += 2;
proto_tree_add_item(tree, hf_bthcrp_control_number_of_bytes, tvb, offset, 2, ENC_BIG_ENDIAN);
number = tvb_get_ntohs(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Number Of Bytes: %u", number);
offset += 2;
} else {
guint8 *id;
proto_tree_add_item(tree, hf_bthcrp_control_1284_id, tvb, offset, -1, ENC_ASCII | ENC_NA);
id = tvb_get_string_enc(NULL, tvb, offset, tvb_length_remaining(tvb, offset), ENC_ASCII);
col_append_fstr(pinfo->cinfo, COL_INFO, " - 1284 ID: %s", id);
offset += tvb_length_remaining(tvb, offset);
}
break;
case 0x0007:
case 0x0008:
break;
case 0x0009:
if (is_client_message) {
proto_tree_add_item(tree, hf_bthcrp_control_register, tvb, offset, 1, ENC_BIG_ENDIAN);
notification_register = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - Register: %s", val_to_str(notification_register, register_vals, "unknown register"));
offset += 1;
proto_tree_add_item(tree, hf_bthcrp_callback_context_id, tvb, offset, 4, ENC_BIG_ENDIAN);
context_id = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Callback ContextID: %u", context_id);
offset += 4;
proto_tree_add_item(tree, hf_bthcrp_control_callback_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
timeout = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Callback Timeout: %u", timeout);
offset += 4;
} else {
proto_tree_add_item(tree, hf_bthcrp_control_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
timeout = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - Timeout: %u", timeout);
offset += 4;
proto_tree_add_item(tree, hf_bthcrp_control_callback_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
timeout = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Callback Timeout: %u", timeout);
offset += 4;
}
break;
case 0x000A:
if (!is_client_message) {
proto_tree_add_item(tree, hf_bthcrp_control_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
timeout = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - Timeout: %u", timeout);
offset += 4;
}
break;
}
return offset;
}
static gint
dissect_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
tvbuff_t *next_tvb;
col_append_str(pinfo->cinfo, COL_INFO, "HCRP data stream");
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, tree);
offset += tvb_length_remaining(tvb, offset);
return offset;
}
static gint
dissect_notification(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gboolean is_client_message)
{
guint16 notification_pdu_id;
proto_item *pitem;
if (is_client_message) {
col_append_str(pinfo->cinfo, COL_INFO, "Notification: unexpected notification stream");
return offset;
}
pitem = proto_tree_add_item(tree, hf_bthcrp_notification_pdu_id, tvb, offset, 2, ENC_BIG_ENDIAN);
notification_pdu_id = tvb_get_ntohs(tvb, offset);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, "Notification: %s", val_to_str(notification_pdu_id, notification_pdu_id_vals, "Unknown PDU ID"));
if (notification_pdu_id >= 0x8000) {
proto_item_append_text(pitem, " (Vendor Specific)");
col_append_str(pinfo->cinfo, COL_INFO, " (Vendor Specific)");
if (tvb_length_remaining(tvb, offset)) {
proto_tree_add_item(tree, hf_bthcrp_data, tvb, offset, -1, ENC_NA);
offset += tvb_length_remaining(tvb, offset);
}
} else if (notification_pdu_id != 0x001) {
proto_item_append_text(pitem, " (Reserved)");
col_append_str(pinfo->cinfo, COL_INFO, " (Reserved)");
}
switch(notification_pdu_id) {
case 0x01:
proto_tree_add_item(tree, hf_bthcrp_callback_context_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
}
return offset;
}
static gint
dissect_bthcrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *main_item;
proto_tree *main_tree;
btl2cap_data_t *l2cap_data;
gint offset = 0;
gint protocol = -1;
wmem_tree_key_t key[10];
guint32 k_interface_id;
guint32 k_adapter_id;
guint32 k_sdp_psm;
guint32 k_direction;
guint32 k_bd_addr_oui;
guint32 k_bd_addr_id;
guint32 k_service_type;
guint32 k_service_channel;
guint32 k_frame_number;
guint32 interface_id;
guint32 adapter_id;
guint32 remote_bd_addr_oui;
guint32 remote_bd_addr_id;
service_info_t *service_info;
gboolean is_client_message = FALSE;
if (data == NULL)
return 0;
l2cap_data = (btl2cap_data_t *) data;
main_item = proto_tree_add_item(tree, proto_bthcrp, tvb, offset, -1, ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_bthcrp);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HCRP");
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_set_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_set_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown direction %d ",
pinfo->p2p_dir);
break;
}
interface_id = l2cap_data->interface_id;
adapter_id = l2cap_data->adapter_id;
k_interface_id = interface_id;
k_adapter_id = adapter_id;
k_sdp_psm = SDP_PSM_DEFAULT;
k_direction = (l2cap_data->is_local_psm) ? P2P_DIR_SENT : P2P_DIR_RECV;
if (k_direction == P2P_DIR_RECV) {
k_bd_addr_oui = l2cap_data->remote_bd_addr_oui;
k_bd_addr_id = l2cap_data->remote_bd_addr_id;
} else {
k_bd_addr_oui = 0;
k_bd_addr_id = 0;
}
remote_bd_addr_oui = k_bd_addr_oui;
remote_bd_addr_id = k_bd_addr_id;
k_service_type = BTSDP_L2CAP_PROTOCOL_UUID;
k_service_channel = l2cap_data->psm;
k_frame_number = pinfo->fd->num;
key[0].length = 1;
key[0].key = &k_interface_id;
key[1].length = 1;
key[1].key = &k_adapter_id;
key[2].length = 1;
key[2].key = &k_sdp_psm;
key[3].length = 1;
key[3].key = &k_direction;
key[4].length = 1;
key[4].key = &k_bd_addr_oui;
key[5].length = 1;
key[5].key = &k_bd_addr_id;
key[6].length = 1;
key[6].key = &k_service_type;
key[7].length = 1;
key[7].key = &k_service_channel;
key[8].length = 1;
key[8].key = &k_frame_number;
key[9].length = 0;
key[9].key = NULL;
service_info = btsdp_get_service_info(key);
if (service_info && service_info->interface_id == interface_id &&
service_info->adapter_id == adapter_id &&
service_info->sdp_psm == SDP_PSM_DEFAULT &&
((service_info->direction == P2P_DIR_RECV &&
service_info->bd_addr_oui == remote_bd_addr_oui &&
service_info->bd_addr_id == remote_bd_addr_id) ||
(service_info->direction != P2P_DIR_RECV &&
service_info->bd_addr_oui == 0 &&
service_info->bd_addr_id == 0)) &&
service_info->type == BTSDP_L2CAP_PROTOCOL_UUID &&
service_info->channel == l2cap_data->psm) {
if ((service_info->protocol == BTSDP_HARDCOPY_CONTROL_CHANNEL_PROTOCOL_UUID ||
service_info->protocol == BTSDP_HARDCOPY_DATA_CHANNEL_PROTOCOL_UUID) &&
((!l2cap_data->is_local_psm && pinfo->p2p_dir == P2P_DIR_SENT) ||
(l2cap_data->is_local_psm && pinfo->p2p_dir == P2P_DIR_RECV))) {
is_client_message = TRUE;
} else if (service_info->protocol == BTSDP_HARDCOPY_NOTIFICATION_PROTOCOL_UUID &&
((l2cap_data->is_local_psm && pinfo->p2p_dir == P2P_DIR_SENT) ||
(!l2cap_data->is_local_psm && pinfo->p2p_dir == P2P_DIR_RECV))) {
is_client_message = TRUE;
}
protocol = service_info->protocol;
}
if (force_client != FORCE_CLIENT_DEFAULT) {
is_client_message = (force_client == FORCE_CLIENT_YES && pinfo->p2p_dir == P2P_DIR_SENT) ||
(force_client != FORCE_CLIENT_YES && pinfo->p2p_dir == P2P_DIR_RECV);
}
if ((psm_control != 0 && l2cap_data->psm == psm_control) ||
(psm_control == 0 && protocol == BTSDP_HARDCOPY_CONTROL_CHANNEL_PROTOCOL_UUID)) {
offset = dissect_control(tvb, pinfo, main_tree, offset, is_client_message);
} else if ((psm_data_stream != 0 && l2cap_data->psm == psm_data_stream) ||
(psm_data_stream == 0 && protocol == BTSDP_HARDCOPY_DATA_CHANNEL_PROTOCOL_UUID)) {
offset = dissect_data(tvb, pinfo, main_tree, offset);
} else if ((psm_notification != 0 && l2cap_data->psm == psm_notification) ||
(psm_notification == 0 && protocol == BTSDP_HARDCOPY_NOTIFICATION_PROTOCOL_UUID)) {
offset = dissect_notification(tvb, pinfo, main_tree, offset, is_client_message);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "HCRP stream (CID: 0x%04X)", l2cap_data->cid);
}
if (tvb_length_remaining(tvb, offset)) {
proto_item *pitem;
pitem = proto_tree_add_item(main_tree, hf_bthcrp_data, tvb, offset, -1, ENC_NA);
expert_add_info(pinfo, pitem, &ei_bthcrp_unexpected_data);
}
return offset;
}
void
proto_register_bthcrp(void)
{
module_t *module;
expert_module_t* expert_bthcrp;
static hf_register_info hf[] = {
{ &hf_bthcrp_control_pdu_id,
{ "Control PDU ID", "bthcrp.control.pdu_id",
FT_UINT16, BASE_HEX, VALS(control_pdu_id_vals), 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_transaction_id,
{ "Transaction ID", "bthcrp.control.transaction_id",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_parameter_length,
{ "Parameter Length", "bthcrp.control.parameter_length",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_status,
{ "Status", "bthcrp.control.status",
FT_UINT16, BASE_HEX, VALS(status_vals), 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_notification_pdu_id,
{ "Notification PDU ID", "bthcrp.notification.pdu_id",
FT_UINT16, BASE_HEX, VALS(notification_pdu_id_vals), 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_callback_context_id,
{ "Callback Context ID", "bthcrp.callback.context_id",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_callback_timeout,
{ "Callback Timeout", "bthcrp.callback.timeout",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_timeout,
{ "Timeout", "bthcrp.timeout",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_register,
{ "Register", "bthcrp.register",
FT_UINT8, BASE_HEX, VALS(register_vals), 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_1284_id,
{ "1284 ID", "bthcrp.1284_id",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_start_byte,
{ "Start Byte", "bthcrp.start_byte",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_number_of_bytes,
{ "Number Of Bytes", "bthcrp.number_of_bytes",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_client_credit_granted,
{ "Client Credit Granted", "bthcrp.client_credit_granted",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_server_credit_granted,
{ "Server Credit Granted", "bthcrp.server_credit_granted",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_client_credit_return,
{ "Client Credit Return", "bthcrp.client_credit_return",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_server_credit_return,
{ "Server Credit Return", "bthcrp.server_credit_return",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_client_credit_query,
{ "Client Credit Query", "bthcrp.client_credit_query",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_server_credit_query,
{ "Server Credit Query", "bthcrp.server_credit_query",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthcrp_control_status_reserved_76,
{ "Reserved", "bthcrp.status.reserved76",
FT_UINT8, BASE_DEC, NULL, 0xC0,
NULL, HFILL }
},
{ &hf_bthcrp_control_status_paper_empty,
{ "Paper Empty", "bthcrp.status.paper_empty",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_bthcrp_control_status_select,
{ "Select", "bthcrp.status.select",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_bthcrp_control_status_not_error,
{ "Not Error", "bthcrp.status.not_error",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_bthcrp_control_status_reserved_20,
{ "Reserved", "bthcrp.status.reserved210",
FT_UINT8, BASE_HEX, NULL, 0x07,
NULL, HFILL }
},
{ &hf_bthcrp_data,
{ "Data", "bthcrp.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_bthcrp
};
static ei_register_info ei[] = {
{ &ei_bthcrp_control_parameter_length, { "bthcrp.control_parameter_length.bad", PI_PROTOCOL, PI_WARN, "Length bad", EXPFILL }},
{ &ei_bthcrp_unexpected_data, { "bthcrp.unexpected_data", PI_PROTOCOL, PI_WARN, "Unexpected data", EXPFILL }},
};
proto_bthcrp = proto_register_protocol("Bluetooth HCRP Profile", "BT HCRP", "bthcrp");
bthcrp_handle = new_register_dissector("bthcrp", dissect_bthcrp, proto_bthcrp);
proto_register_field_array(proto_bthcrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_bthcrp = expert_register_protocol(proto_bthcrp);
expert_register_field_array(expert_bthcrp, ei, array_length(ei));
module = prefs_register_protocol(proto_bthcrp, NULL);
prefs_register_static_text_preference(module, "hcrp.version",
"Bluetooth Profile HCRP version: 1.2",
"Version of profile supported by this dissector.");
prefs_register_obsolete_preference(module, "hcrp.is_client");
prefs_register_enum_preference(module, "hcrp.force_client", "Force Client",
"If \"yes\" localhost will be treat as Client, \"no\" as Server",
&force_client, force_client_enum, FALSE);
prefs_register_uint_preference(module, "hcrp.control.psm", "L2CAP PSM for Control",
"L2CAP PSM for Control",
10, &psm_control);
prefs_register_uint_preference(module, "hcrp.data.psm", "L2CAP PSM for Data",
"L2CAP PSM for Data",
10, &psm_data_stream);
prefs_register_uint_preference(module, "hcrp.notification.psm", "L2CAP PSM for Notification",
"L2CAP PSM for Notification",
10, &psm_notification);
}
void
proto_reg_handoff_bthcrp(void)
{
data_handle = find_dissector("data");
dissector_add_uint("btl2cap.service", BTSDP_HARDCOPY_CONTROL_CHANNEL_PROTOCOL_UUID, bthcrp_handle);
dissector_add_uint("btl2cap.service", BTSDP_HARDCOPY_DATA_CHANNEL_PROTOCOL_UUID, bthcrp_handle);
dissector_add_uint("btl2cap.service", BTSDP_HARDCOPY_NOTIFICATION_PROTOCOL_UUID, bthcrp_handle);
dissector_add_uint("btl2cap.service", BTSDP_HCRP_PRINT_SERVICE_UUID, bthcrp_handle);
dissector_add_uint("btl2cap.service", BTSDP_HCRP_SCAN_SERVICE_UUID, bthcrp_handle);
dissector_add_uint("btl2cap.service", BTSDP_HCRP_SERVICE_UUID, bthcrp_handle);
dissector_add_for_decode_as("btl2cap.psm", bthcrp_handle);
dissector_add_for_decode_as("btl2cap.cid", bthcrp_handle);
}
