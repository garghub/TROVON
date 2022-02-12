static guint
canopen_detect_msg_type(guint function_code, guint node_id)
{
switch (function_code) {
case FC_NMT:
return MT_NMT_CTRL;
break;
case FC_SYNC:
if (node_id == 0) {
return MT_SYNC;
} else {
return MT_EMERGENCY;
}
break;
case FC_TIME_STAMP:
return MT_TIME_STAMP;
break;
case FC_PDO1_TX:
return MT_PDO;
break;
case FC_PDO1_RX:
return MT_PDO;
break;
case FC_PDO2_TX:
return MT_PDO;
break;
case FC_PDO2_RX:
return MT_PDO;
break;
case FC_PDO3_TX:
return MT_PDO;
break;
case FC_PDO3_RX:
return MT_PDO;
break;
case FC_PDO4_TX:
return MT_PDO;
break;
case FC_PDO4_RX:
return MT_PDO;
break;
case FC_DEFAULT_SDO_TX:
return MT_SDO;
break;
case FC_DEFAULT_SDO_RX:
return MT_SDO;
break;
case FC_NMT_ERR_CONTROL:
return MT_NMT_GUARD;
break;
default:
return MT_UNKNOWN;
break;
}
}
static int
dissect_canopen(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
guint function_code;
guint node_id;
guint32 time_stamp_msec;
guint32 time_stamp_days;
struct can_identifier can_id;
guint msg_type_id;
nstime_t time_stamp;
gint can_data_len = tvb_reported_length(tvb);
const gchar *function_code_str;
int offset = 0;
DISSECTOR_ASSERT(data);
can_id = *((struct can_identifier*)data);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CANopen");
col_clear(pinfo->cinfo, COL_INFO);
node_id = can_id.id & 0x7F;
function_code = (can_id.id >> 7) & 0x0F;
msg_type_id = canopen_detect_msg_type(function_code, node_id);
if (node_id == 0 ) {
function_code_str = val_to_str(function_code, CAN_open_bcast_msg_type_vals, "Unknown (%u)");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", function_code_str);
} else {
function_code_str = val_to_str(function_code, CAN_open_p2p_msg_type_vals, "Unknown (%u)");
col_add_fstr(pinfo->cinfo, COL_INFO, "p2p %s", function_code_str);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
tvb_bytes_to_ep_str_punct(tvb, offset, can_data_len, ' '));
if (tree) {
proto_item *ti, *cob_ti, *type_ti;
proto_tree *canopen_tree;
proto_tree *canopen_cob_tree;
proto_tree *canopen_type_tree;
ti = proto_tree_add_item(tree, proto_canopen, tvb, 0, -1, ENC_NA);
canopen_tree = proto_item_add_subtree(ti, ett_canopen);
cob_ti = proto_tree_add_uint(canopen_tree, hf_canopen_cob_id, tvb, 0, 0, can_id.id);
canopen_cob_tree = proto_item_add_subtree(cob_ti, ett_canopen);
ti = proto_tree_add_uint(canopen_cob_tree, hf_canopen_function_code, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(canopen_cob_tree, hf_canopen_node_id, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
type_ti = proto_tree_add_text(canopen_tree, tvb, 0,
(msg_type_id != MT_SYNC) ? -1 : 0,
"Type: %s", function_code_str);
canopen_type_tree = proto_item_add_subtree(type_ti, ett_canopen);
switch(msg_type_id)
{
case MT_NMT_CTRL:
proto_tree_add_item(canopen_type_tree,
hf_canopen_nmt_ctrl_cs, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(canopen_type_tree,
hf_canopen_nmt_ctrl_node_id, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case MT_NMT_GUARD:
proto_tree_add_item(canopen_type_tree,
hf_canopen_nmt_guard_state, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case MT_SYNC:
break;
case MT_TIME_STAMP:
time_stamp_msec = tvb_get_letohl(tvb, offset);
time_stamp_days = tvb_get_ntohs(tvb, offset + 4);
time_stamp.secs = (time_stamp_days + TS_DAYS_BETWEEN_1970_AND_1984)
* TS_SECONDS_IN_PER_DAY + (time_stamp_msec / 1000);
time_stamp.nsecs = (time_stamp_msec % 1000) * TS_NANOSEC_PER_MSEC;
proto_tree_add_time(canopen_type_tree,
hf_canopen_time_stamp, tvb, offset, 6, &time_stamp);
proto_tree_add_uint(canopen_type_tree,
hf_canopen_time_stamp_ms, tvb, offset, 4, time_stamp_msec);
offset += 2;
proto_tree_add_uint(canopen_type_tree,
hf_canopen_time_stamp_days, tvb, offset, 2, time_stamp_days);
break;
case MT_EMERGENCY:
proto_tree_add_item(canopen_type_tree,
hf_canopen_em_err_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(canopen_type_tree,
hf_canopen_em_err_reg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(canopen_type_tree,
hf_canopen_em_err_field, tvb, offset, 4, ENC_NA);
break;
case MT_PDO:
if (can_data_len != 0) {
proto_tree_add_item(canopen_type_tree,
hf_canopen_pdo_data, tvb, offset, can_data_len, ENC_NA);
}
else {
proto_tree_add_string(canopen_type_tree,
hf_canopen_pdo_data_string, tvb, offset, 0, "empty");
}
break;
case MT_SDO:
proto_tree_add_item(canopen_type_tree,
hf_canopen_sdo_cmd, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(canopen_type_tree,
hf_canopen_sdo_main_idx, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(canopen_type_tree,
hf_canopen_sdo_sub_idx, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(canopen_type_tree,
hf_canopen_sdo_data, tvb, offset, 4, ENC_NA);
break;
}
}
return tvb_length(tvb);
}
void
proto_register_canopen(void)
{
static hf_register_info hf[] = {
{ &hf_canopen_cob_id,
{ "COB-ID", "canopen.cob_id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_function_code,
{ "Function code", "canopen.function_code",
FT_UINT32, BASE_HEX, NULL, 0x780,
NULL, HFILL }
},
{ &hf_canopen_node_id,
{ "Node-ID", "canopen.node_id",
FT_UINT32, BASE_HEX, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_canopen_pdo_data,
{ "Data", "canopen.pdo.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_pdo_data_string,
{ "Data", "canopen.pdo.data",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_sdo_cmd,
{ "SDO command byte", "canopen.sdo.cmd",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_sdo_main_idx,
{ "OD main-index", "canopen.sdo.main_idx",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_sdo_sub_idx,
{ "OD sub-index", "canopen.sdo.sub_idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_sdo_data,
{ "Data", "canopen.sdo.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_em_err_code,
{ "Error code", "canopen.em.err_code",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_em_err_reg,
{ "Error register", "canopen.em.err_reg",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_em_err_field,
{ "Manufacture specific error field", "canopen.em.err_field",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_nmt_ctrl_cs,
{ "Command specifier", "canopen.nmt_ctrl.cd",
FT_UINT8, BASE_HEX, VALS(nmt_ctrl_cs), 0xFF,
NULL, HFILL }
},
{ &hf_canopen_nmt_ctrl_node_id,
{ "Node-ID", "canopen.nmt_ctrl.node_id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_nmt_guard_state,
{ "Node-ID", "canopen.nmt_guard.state",
FT_UINT8, BASE_HEX, VALS(nmt_guard_state), 0x7F,
NULL, HFILL }
},
{ &hf_canopen_time_stamp,
{ "Time stamp", "canopen.time_stamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_time_stamp_ms,
{ "Time, after Midnight in Milliseconds", "canopen.time_stamp_ms",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_time_stamp_days,
{ "Current day since 1 Jan 1984", "canopen.time_stamp_days",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_canopen
};
proto_canopen = proto_register_protocol("CANopen",
"CANOPEN",
"canopen");
new_register_dissector("canopen", dissect_canopen, proto_canopen);
proto_register_field_array(proto_canopen, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
