static gint
dissect_btmcap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *main_item;
proto_tree *main_tree;
proto_item *pitem;
gint offset = 0;
guint32 op_code;
guint32 response_code;
guint32 mdl_id;
guint32 mdep_id;
guint32 bluetooth_clock_sync_time;
guint64 timestamp_sync_time;
main_item = proto_tree_add_item(tree, proto_btmcap, tvb, offset, -1, ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_btmcap);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MCAP");
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
pitem = proto_tree_add_item(main_tree, hf_btmcap_op_code, tvb, offset, 1, ENC_BIG_ENDIAN);
op_code = tvb_get_guint8(tvb, offset);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str(op_code, op_code_vals, "Unknown Op Code"));
if (op_code >= 0x11 && op_code <= 0x20) {
proto_item_append_text(pitem, " (Clock Sync)");
col_append_str(pinfo->cinfo, COL_INFO, " (Clock Sync)");
} else {
proto_item_append_text(pitem, " (Standard)");
col_append_str(pinfo->cinfo, COL_INFO, " (Standard)");
}
if (op_code & 0x01) {
switch(op_code) {
case 0x01:
case 0x03:
case 0x05:
case 0x07:
pitem = proto_tree_add_item(main_tree, hf_btmcap_mdl_id, tvb, offset, 2, ENC_BIG_ENDIAN);
mdl_id = tvb_get_ntohs(tvb, offset);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, " - MDL ID: %u", mdl_id);
if (mdl_id == 0xFFFF) {
proto_item_append_text(pitem, " (Indicates all MDLs)");
col_append_fstr(pinfo->cinfo, COL_INFO, " (Indicates all MDLs)");
} else if (mdl_id >= 0x0001 && mdl_id <= 0xFEFF) {
proto_item_append_text(pitem, " (Dynamic Range)");
col_append_fstr(pinfo->cinfo, COL_INFO, " (Dynamic Range)");
} else if (mdl_id == 0x0000) {
proto_item_append_text(pitem, " (Reserved)");
col_append_str(pinfo->cinfo, COL_INFO, " (Reserved)");
}
if (op_code != 0x07 && mdl_id == 0xFFFF) {
expert_add_info(pinfo, pitem, &ei_btmcap_mdl_id_ffff);
}
if (op_code == 0x01) {
pitem = proto_tree_add_item(main_tree, hf_btmcap_mdep_id, tvb, offset, 1, ENC_BIG_ENDIAN);
mdep_id = tvb_get_guint8(tvb, offset);
offset += 1;
if (mdep_id <= 0x7F) {
proto_item_append_text(pitem, " (Available for use)");
} else {
proto_item_append_text(pitem, " (Reserved)");
}
proto_tree_add_item(main_tree, hf_btmcap_configuration, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case 0x11:
pitem = proto_tree_add_item(main_tree, hf_btmcap_timestamp_required_accuracy, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pitem, " ppm");
offset += 2;
break;
case 0x13:
proto_tree_add_item(main_tree, hf_btmcap_timestamp_update_information, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
pitem = proto_tree_add_item(main_tree, hf_btmcap_bluetooth_clock_sync_time, tvb, offset, 4, ENC_BIG_ENDIAN);
bluetooth_clock_sync_time = tvb_get_ntohl(tvb, offset);
if (bluetooth_clock_sync_time == 0xFFFFFFFF)
proto_item_append_text(pitem, " (Instant Synchronization)");
else
proto_item_append_text(pitem, " (Baseband Half-Slot Instant)");
offset += 4;
pitem = proto_tree_add_item(main_tree, hf_btmcap_timestamp_sync_time, tvb, offset, 8, ENC_BIG_ENDIAN);
timestamp_sync_time = tvb_get_ntoh64(tvb, offset);
if (timestamp_sync_time == G_GUINT64_CONSTANT(0xFFFFFFFFFFFFFFFF))
proto_item_append_text(pitem, " (No Time Synchronization)");
else
proto_item_append_text(pitem, " (Time-Stamp Clock Instant)");
offset += 8;
break;
case 0x15:
pitem = proto_tree_add_item(main_tree, hf_btmcap_bluetooth_clock_sync_time, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(pitem, " (Baseband Half-Slot Instant)");
offset += 4;
pitem = proto_tree_add_item(main_tree, hf_btmcap_timestamp_sync_time, tvb, offset, 8, ENC_BIG_ENDIAN);
proto_item_append_text(pitem, " (Time-Stamp Clock Instant)");
offset += 8;
pitem = proto_tree_add_item(main_tree, hf_btmcap_timestamp_sample_accuracy, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pitem, " us");
offset += 2;
break;
}
} else {
proto_tree_add_item(main_tree, hf_btmcap_response_code, tvb, offset, 1, ENC_BIG_ENDIAN);
response_code = tvb_get_guint8(tvb, offset);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s", val_to_str(response_code, response_code_vals, "Unknown ResponseCode"));
if (op_code >= 0x11 && op_code <= 0x20) {
switch(op_code) {
case 0x12:
pitem = proto_tree_add_item(main_tree, hf_btmcap_bluetooth_clock_access_resolution, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(pitem, " (Baseband half-slots)");
offset += 1;
pitem = proto_tree_add_item(main_tree, hf_btmcap_sync_lead_time, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pitem, " ms");
offset += 2;
pitem = proto_tree_add_item(main_tree, hf_btmcap_timestamp_native_resolution, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pitem, " us");
offset += 2;
pitem = proto_tree_add_item(main_tree, hf_btmcap_timestamp_native_accuracy, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pitem, " ppm");
offset += 2;
break;
case 0x14:
pitem = proto_tree_add_item(main_tree, hf_btmcap_bluetooth_clock_sync_time, tvb, offset, 4, ENC_BIG_ENDIAN);
bluetooth_clock_sync_time = tvb_get_ntohl(tvb, offset);
if (bluetooth_clock_sync_time == 0xFFFFFFFF)
proto_item_append_text(pitem, " (Instant Synchronization)");
else
proto_item_append_text(pitem, " (Baseband Half-Slot Instant)");
offset += 4;
pitem = proto_tree_add_item(main_tree, hf_btmcap_timestamp_sync_time, tvb, offset, 8, ENC_BIG_ENDIAN);
timestamp_sync_time = tvb_get_ntoh64(tvb, offset);
if (timestamp_sync_time == G_GUINT64_CONSTANT(0xFFFFFFFFFFFFFFFF))
proto_item_append_text(pitem, " (No Time Synchronization)");
else
proto_item_append_text(pitem, " (Time-Stamp Clock Instant)");
offset += 8;
pitem = proto_tree_add_item(main_tree, hf_btmcap_timestamp_sample_accuracy, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pitem, " us");
offset += 2;
break;
}
} else {
pitem = proto_tree_add_item(main_tree, hf_btmcap_mdl_id, tvb, offset, 2, ENC_BIG_ENDIAN);
mdl_id = tvb_get_ntohs(tvb, offset);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, " - %u", mdl_id);
if (mdl_id == 0xFFFF) {
proto_item_append_text(pitem, " (Indicates all MDLs)");
col_append_str(pinfo->cinfo, COL_INFO, " (Indicates all MDLs)");
} else if (mdl_id >= 0x0001 && mdl_id <= 0xFEFF) {
proto_item_append_text(pitem, " (Dynamic Range)");
col_append_str(pinfo->cinfo, COL_INFO, " (Dynamic Range)");
} else if (mdl_id == 0x0000) {
proto_item_append_text(pitem, " (Reserved)");
col_append_str(pinfo->cinfo, COL_INFO, " (Reserved)");
}
if ((op_code == 0x03 || op_code == 0x05 || op_code == 0x07) && tvb_length_remaining(tvb, offset)) {
expert_add_info_format(pinfo, pitem, &ei_btmcap_response_parameters_bad,
"The Response Parameters for MD_RECONNECT_MDL_RSP shall have length zero.");
} else if (tvb_length_remaining(tvb, offset)) {
pitem = proto_tree_add_item(main_tree, hf_btmcap_response_parameters, tvb, offset, -1, ENC_NA);
if (response_code != 0x00) {
expert_add_info_format(pinfo, pitem, &ei_btmcap_response_parameters_bad,
"When the Response Code is not Success, the Response Parameters shall have length zero.");
}
offset += tvb_length_remaining(tvb, offset);
}
}
}
if (tvb_length_remaining(tvb, offset)) {
pitem = proto_tree_add_item(main_tree, hf_btmcap_data, tvb, offset, -1, ENC_NA);
expert_add_info(pinfo, pitem, &ei_btmcap_unexpected_data);
offset = tvb_length(tvb);
}
return offset;
}
void
proto_register_btmcap(void)
{
module_t *module;
expert_module_t *expert_btmcap;
static hf_register_info hf[] = {
{ &hf_btmcap_op_code,
{ "Op Code", "btmcap.op_code",
FT_UINT8, BASE_HEX, VALS(op_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_btmcap_response_code,
{ "Response Code", "btmcap.response_code",
FT_UINT8, BASE_HEX, VALS(response_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_btmcap_mdl_id,
{ "MDL ID", "btmcap.mdl_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_btmcap_mdep_id,
{ "MDEP ID", "btmcap.mdep_id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_btmcap_configuration,
{ "Configuration", "btmcap.configuration",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_btmcap_timestamp_required_accuracy,
{ "Timestamp Required Accuracy", "btmcap.timestamp_required_accuracy",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btmcap_timestamp_update_information,
{ "Timestamp Update Information", "btmcap.timestamp_update_information",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btmcap_bluetooth_clock_sync_time,
{ "Bluetooth Clock Sync Time", "btmcap.bluetooth_clock_sync_time",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btmcap_timestamp_sync_time,
{ "Timestamp Sync Time", "btmcap.timestamp_sync_time",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btmcap_timestamp_sample_accuracy,
{ "Timestamp Sample Accuracy", "btmcap.timestamp_sample_accuracy",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btmcap_bluetooth_clock_access_resolution,
{ "Bluetooth Clock Access Resolution","btmcap.bluetooth_clock_access_resolution",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btmcap_sync_lead_time,
{ "Sync Lead Time", "btmcap.sync_lead_time",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btmcap_timestamp_native_resolution,
{ "Timestamp Native Resolution", "btmcap.timestamp_native_resolution",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btmcap_timestamp_native_accuracy,
{ "Timestamp Native Accuracy", "btmcap.timestamp_native_accuracy",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btmcap_response_parameters,
{ "Response Parameters", "btmcap.response_parameters",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btmcap_data,
{ "Data", "btmcap.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_btmcap
};
static ei_register_info ei[] = {
{ &ei_btmcap_mdl_id_ffff, { "btmcap.mdl_id.ffff", PI_PROTOCOL, PI_WARN, "The value 0xFFFF is not a valid MDL ID for this request and shall not be used.", EXPFILL }},
{ &ei_btmcap_response_parameters_bad, { "btmcap.response_parameters.bad", PI_PROTOCOL, PI_WARN, "Response parameters bad", EXPFILL }},
{ &ei_btmcap_unexpected_data, { "btmcap.unexpected_data", PI_PROTOCOL, PI_WARN, "Unexpected data", EXPFILL }},
};
proto_btmcap = proto_register_protocol("Bluetooth MCAP Protocol", "BT MCAP", "btmcap");
btmcap_handle = new_register_dissector("btmcap", dissect_btmcap, proto_btmcap);
proto_register_field_array(proto_btmcap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_btmcap = expert_register_protocol(proto_btmcap);
expert_register_field_array(expert_btmcap, ei, array_length(ei));
module = prefs_register_protocol(proto_btmcap, NULL);
prefs_register_static_text_preference(module, "mcap.version",
"Bluetooth Protocol MCAP version: 1.0",
"Version of protocol supported by this dissector.");
}
void
proto_reg_handoff_btmcap(void)
{
dissector_add_uint("btl2cap.service", BTSDP_MCAP_CONTROL_CHANNEL_PROTOCOL_UUID, btmcap_handle);
dissector_add_uint("btl2cap.service", BTSDP_MCAP_DATA_CHANNEL_PROTOCOL_UUID, btmcap_handle);
dissector_add_uint("btl2cap.service", BTSDP_HDP_SERVICE_UUID, btmcap_handle);
dissector_add_uint("btl2cap.service", BTSDP_HDP_SOURCE_SERVICE_UUID, btmcap_handle);
dissector_add_uint("btl2cap.service", BTSDP_HDP_SINK_SERVICE_UUID, btmcap_handle);
dissector_add_handle("btl2cap.psm", btmcap_handle);
dissector_add_handle("btl2cap.cid", btmcap_handle);
}
