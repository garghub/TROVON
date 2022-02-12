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
return MT_NMT_ERR_CTRL;
break;
case LSS_MASTER_CAN_ID >> 7:
if (node_id == (LSS_MASTER_CAN_ID & 0x7F)) {
return MT_LSS_MASTER;
} else if (node_id == (LSS_SLAVE_CAN_ID & 0x7F)) {
return MT_LSS_SLAVE;
}
return MT_UNKNOWN;
break;
default:
return MT_UNKNOWN;
break;
}
}
static void
dissect_sdo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *canopen_type_tree, guint function_code)
{
int offset = 0;
guint8 sdo_mux = 0, sdo_data = 0;
guint8 sdo_cs = 0;
sdo_cs = tvb_get_bits8(tvb, 0, 3);
if (function_code == FC_DEFAULT_SDO_RX) {
col_append_fstr(pinfo->cinfo, COL_INFO,
": %s", val_to_str(sdo_cs, sdo_ccs,
"Unknown (0x%x)"));
proto_tree_add_bitmask(canopen_type_tree, tvb, offset,
hf_canopen_sdo_cmd, ett_canopen_sdo_cmd, sdo_cmd_fields_ccs[sdo_cs], ENC_LITTLE_ENDIAN);
offset++;
switch (sdo_cs) {
case SDO_CCS_DOWN_SEG_REQ:
sdo_mux = 0;
sdo_data = 7;
break;
case SDO_CCS_INIT_DOWN_REQ:
sdo_mux = 1;
sdo_data = 4;
break;
case SDO_CCS_INIT_UP_REQ:
sdo_mux = 1;
sdo_data = 0;
break;
case SDO_CCS_UP_SEQ_REQ:
sdo_mux = 0;
sdo_data = 0;
break;
case SDO_CS_ABORT_TRANSFER:
case SDO_CCS_BLOCK_UP:
case SDO_CCS_BLOCK_DOWN:
sdo_mux = 1;
sdo_data = 4;
break;
default:
return;
}
} else {
col_append_fstr(pinfo->cinfo, COL_INFO,
": %s", val_to_str(sdo_cs, sdo_scs,
"Unknown (0x%x)"));
proto_tree_add_bitmask(canopen_type_tree, tvb, offset,
hf_canopen_sdo_cmd, ett_canopen_sdo_cmd, sdo_cmd_fields_scs[sdo_cs], ENC_LITTLE_ENDIAN);
offset++;
switch (sdo_cs) {
case SDO_SCS_UP_SEQ_RESP:
sdo_mux = 0;
sdo_data = 7;
break;
case SDO_SCS_DOWN_SEG_RESP:
sdo_mux = 0;
sdo_data = 0;
break;
case SDO_SCS_INIT_UP_RESP:
sdo_mux = 1;
sdo_data = 4;
break;
case SDO_SCS_INIT_DOWN_RESP:
sdo_mux = 1;
sdo_data = 0;
break;
case SDO_CS_ABORT_TRANSFER:
case SDO_SCS_BLOCK_DOWN:
case SDO_SCS_BLOCK_UP:
sdo_mux = 1;
sdo_data = 4;
break;
default:
return;
}
}
if (sdo_mux) {
proto_tree_add_item(canopen_type_tree,
hf_canopen_sdo_main_idx, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(canopen_type_tree,
hf_canopen_sdo_sub_idx, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
}
if (sdo_cs == 4) {
proto_tree_add_item(canopen_type_tree,
hf_canopen_sdo_abort_code, tvb, offset, 4, ENC_LITTLE_ENDIAN);
return;
}
if (sdo_data) {
proto_tree_add_item(canopen_type_tree,
hf_canopen_sdo_data, tvb, offset, sdo_data, ENC_NA);
} else {
proto_tree_add_item(canopen_type_tree,
hf_canopen_reserved, tvb, offset, 7 - 3 * sdo_mux - sdo_data , ENC_NA);
}
}
static void
dissect_lss(tvbuff_t *tvb, packet_info *pinfo, proto_tree *canopen_type_tree, guint msg_type_id)
{
int offset = 0;
int reserved = 0;
guint8 lss_cs;
guint8 lss_bc_mask;
guint16 lss_abt_delay;
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_cs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
lss_cs = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str(lss_cs, lss_cs_code, "Unknown (0x%x)"));
offset++;
if (msg_type_id == MT_LSS_MASTER) {
switch (lss_cs) {
case LSS_CS_SWITCH_GLOBAL:
col_append_fstr(pinfo->cinfo, COL_INFO,
": %s", val_to_str(tvb_get_guint8(tvb, offset), lss_switch_mode, "Unknown (0x%x)"));
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_switch_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
reserved = 6;
break;
case LSS_CS_SWITCH_SELECTIVE_VENDOR:
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_addr_vendor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
reserved = 3;
break;
case LSS_CS_SWITCH_SELECTIVE_PRODUCT:
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_addr_product, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
reserved = 3;
break;
case LSS_CS_SWITCH_SELECTIVE_REVISION:
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_addr_revision, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
reserved = 3;
break;
case LSS_CS_SWITCH_SELECTIVE_SERIAL:
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_addr_serial, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
reserved = 3;
break;
case LSS_CS_CONF_NODE_ID:
col_append_fstr(pinfo->cinfo, COL_INFO, ": 0x%02x", tvb_get_guint8(tvb, offset));
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_nid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
reserved = 6;
break;
case LSS_CS_CONF_BIT_TIMING:
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_bt_tbl_selector, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
col_append_fstr(pinfo->cinfo, COL_INFO,
": %s", val_to_str(tvb_get_guint8(tvb, offset), bit_timing_tbl, "Unknown (0x%x)"));
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_bt_tbl_index, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
reserved = 5;
break;
case LSS_CS_CONF_ACT_BIT_TIMING:
lss_abt_delay = tvb_get_letohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %d ms", lss_abt_delay);
proto_tree_add_uint_format_value(canopen_type_tree,
hf_canopen_lss_abt_delay, tvb, offset, 2, lss_abt_delay,
"%d ms (0x%02x)", lss_abt_delay, lss_abt_delay);
offset += 2;
reserved = 5;
break;
case LSS_CS_CONF_STORE:
case LSS_CS_INQ_VENDOR_ID:
case LSS_CS_INQ_PRODUCT_CODE:
case LSS_CS_INQ_REV_NUMBER:
case LSS_CS_INQ_SERIAL_NUMBER:
case LSS_CS_INQ_NODE_ID:
reserved = 7;
break;
case LSS_CS_IDENT_REMOTE_VENDOR:
case LSS_CS_IDENT_REMOTE_PRODUCT:
case LSS_CS_IDENT_REMOTE_REV_LOW:
case LSS_CS_IDENT_REMOTE_REV_HIGH:
case LSS_CS_IDENT_REMOTE_SERIAL_LOW:
case LSS_CS_IDENT_REMOTE_SERIAL_HIGH:
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s 0x%08x",
val_to_str(lss_cs, lss_id_remote_slave, "(Unknown)"), tvb_get_letohl(tvb, offset));
proto_tree_add_item(canopen_type_tree,
*hf_canopen_lss_addr_ident[lss_cs - LSS_CS_IDENT_REMOTE_VENDOR], tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
reserved = 3;
break;
case LSS_CS_IDENT_REMOTE_NON_CONF:
reserved = 7;
break;
case LSS_CS_IDENT_FASTSCAN:
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_fastscan_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
lss_bc_mask = tvb_get_guint8(tvb, offset);
if (lss_bc_mask == 0x80) {
proto_tree_add_uint_format_value(canopen_type_tree,
hf_canopen_lss_fastscan_check, tvb, offset, 1, lss_bc_mask,
"All LSS slaves (0x%02x)", lss_bc_mask);
} else if (lss_bc_mask < 32) {
proto_tree_add_uint_format_value(canopen_type_tree,
hf_canopen_lss_fastscan_check, tvb, offset, 1,
lss_bc_mask, "0x%x (0x%02x)",
~((1 << lss_bc_mask) - 1),
lss_bc_mask);
} else {
proto_tree_add_uint_format_value(canopen_type_tree,
hf_canopen_lss_fastscan_check, tvb, offset, 1, lss_bc_mask,
"Reserved (0x%02x)", lss_bc_mask);
}
offset++;
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_fastscan_sub, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_fastscan_next, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
default:
return;
}
} else {
switch (lss_cs) {
case LSS_CS_SWITCH_SELECTIVE_RESP:
reserved = 7;
break;
case LSS_CS_CONF_NODE_ID:
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_conf_id_err_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_spec_err, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
reserved = 5;
break;
case LSS_CS_CONF_BIT_TIMING:
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_conf_bt_err_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_spec_err, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
reserved = 5;
break;
case LSS_CS_CONF_STORE:
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_store_conf_err_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_spec_err, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
reserved = 5;
break;
case LSS_CS_INQ_VENDOR_ID:
case LSS_CS_INQ_PRODUCT_CODE:
case LSS_CS_INQ_REV_NUMBER:
case LSS_CS_INQ_SERIAL_NUMBER:
col_append_fstr(pinfo->cinfo, COL_INFO,
", %s 0x%08x", val_to_str(lss_cs, lss_inquire_id, "(Unknown)"), tvb_get_letohl(tvb, offset));
proto_tree_add_item(canopen_type_tree,
*hf_canopen_lss_addr_inquire[lss_cs - LSS_CS_INQ_VENDOR_ID], tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
reserved = 3;
break;
case LSS_CS_INQ_NODE_ID:
col_append_fstr(pinfo->cinfo, COL_INFO,
", %s 0x%08x", val_to_str(lss_cs, lss_inquire_id, "(Unknown)"), tvb_get_letohl(tvb, offset));
proto_tree_add_item(canopen_type_tree,
hf_canopen_lss_nid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
reserved = 6;
break;
case LSS_CS_IDENT_SLAVE:
reserved = 7;
break;
case LSS_CS_IDENT_NON_CONF_SLAVE:
reserved = 7;
break;
default:
return;
}
}
if (reserved) {
proto_tree_add_item(canopen_type_tree,
hf_canopen_reserved, tvb, offset, reserved, ENC_NA);
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
guint8 nmt_node_id;
proto_item *ti, *cob_ti;
proto_tree *canopen_tree;
proto_tree *canopen_cob_tree;
proto_tree *canopen_type_tree;
DISSECTOR_ASSERT(data);
can_id = *((struct can_identifier*)data);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CANopen");
col_clear(pinfo->cinfo, COL_INFO);
node_id = can_id.id & 0x7F;
function_code = (can_id.id >> 7) & 0x0F;
msg_type_id = canopen_detect_msg_type(function_code, node_id);
if (msg_type_id == MT_LSS_MASTER) {
function_code_str = "LSS (Master)";
col_add_str(pinfo->cinfo, COL_INFO, function_code_str);
} else if (msg_type_id == MT_LSS_SLAVE) {
function_code_str = "LSS (Slave)";
col_add_str(pinfo->cinfo, COL_INFO, function_code_str);
} else {
if (node_id == 0 ) {
function_code_str = val_to_str(function_code, CAN_open_bcast_msg_type_vals, "Unknown (%u)");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", function_code_str);
} else {
function_code_str = val_to_str(function_code, CAN_open_p2p_msg_type_vals, "Unknown (%u)");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", function_code_str);
}
}
ti = proto_tree_add_item(tree, proto_canopen, tvb, 0, tvb_reported_length(tvb), ENC_NA);
canopen_tree = proto_item_add_subtree(ti, ett_canopen);
cob_ti = proto_tree_add_uint(canopen_tree, hf_canopen_cob_id, tvb, 0, 0, can_id.id);
canopen_cob_tree = proto_item_add_subtree(cob_ti, ett_canopen_cob);
ti = proto_tree_add_uint(canopen_cob_tree, hf_canopen_function_code, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(canopen_cob_tree, hf_canopen_node_id, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
canopen_type_tree = proto_tree_add_subtree_format(canopen_tree, tvb, 0,
tvb_reported_length(tvb),
ett_canopen_type, NULL, "Type: %s", function_code_str);
switch(msg_type_id)
{
case MT_NMT_CTRL:
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str(tvb_get_guint8(tvb, offset), nmt_ctrl_cs, "Unknown (0x%x)"));
proto_tree_add_item(canopen_type_tree,
hf_canopen_nmt_ctrl_cs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
nmt_node_id = tvb_get_guint8(tvb, offset);
if (nmt_node_id == 0x00) {
col_append_fstr(pinfo->cinfo, COL_INFO, " [All]");
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " [0x%x]", nmt_node_id);
}
proto_tree_add_item(canopen_type_tree,
hf_canopen_nmt_ctrl_node_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case MT_NMT_ERR_CTRL:
if (tvb_reported_length(tvb) > 0) {
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str(tvb_get_bits8(tvb, 1, 7), nmt_guard_state, "(Unknown)"));
proto_tree_add_item(canopen_type_tree,
hf_canopen_nmt_guard_toggle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(canopen_type_tree,
hf_canopen_nmt_guard_state, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " [0x%x]", node_id);
break;
case MT_SYNC:
if (tvb_reported_length(tvb) > 0) {
col_append_fstr(pinfo->cinfo, COL_INFO, " [%d]", tvb_get_guint8(tvb, offset));
proto_tree_add_item(canopen_type_tree,
hf_canopen_sync_counter, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
break;
case MT_TIME_STAMP:
time_stamp_msec = tvb_get_letohl(tvb, offset);
time_stamp_days = tvb_get_letohs(tvb, offset + 4);
time_stamp.secs = (time_stamp_days + TS_DAYS_BETWEEN_1970_AND_1984)
* TS_SECONDS_IN_PER_DAY + (time_stamp_msec / 1000);
time_stamp.nsecs = (time_stamp_msec % 1000) * TS_NANOSEC_PER_MSEC;
proto_tree_add_time(canopen_type_tree,
hf_canopen_time_stamp, tvb, offset, 6, &time_stamp);
proto_tree_add_uint(canopen_type_tree,
hf_canopen_time_stamp_ms, tvb, offset, 4, time_stamp_msec);
offset += 4;
proto_tree_add_uint(canopen_type_tree,
hf_canopen_time_stamp_days, tvb, offset, 2, time_stamp_days);
break;
case MT_EMERGENCY:
proto_tree_add_item(canopen_type_tree,
hf_canopen_em_err_code, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(canopen_type_tree,
hf_canopen_em_err_reg, tvb, offset, 1, ENC_LITTLE_ENDIAN);
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
dissect_sdo(tvb, pinfo, canopen_type_tree, function_code);
break;
case MT_LSS_MASTER:
case MT_LSS_SLAVE:
dissect_lss(tvb, pinfo, canopen_type_tree, msg_type_id);
break;
}
return tvb_reported_length(tvb);
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
{ "Data", "canopen.pdo.data.bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_pdo_data_string,
{ "Data", "canopen.pdo.data.string",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_sdo_cmd,
{ "SDO command byte", "canopen.sdo.cmd",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_sdo_cmd_ccs,
{ "Client command specifier", "canopen.sdo.ccs",
FT_UINT8, BASE_HEX, VALS(sdo_ccs), 0xE0,
NULL, HFILL }
},
{ &hf_canopen_sdo_cmd_scs,
{ "Server command specifier", "canopen.sdo.ccs",
FT_UINT8, BASE_HEX, VALS(sdo_scs), 0xE0,
NULL, HFILL }
},
{ &hf_canopen_sdo_cmd_toggle,
{ "Toggle bit", "canopen.sdo.toggle",
FT_UINT8, BASE_DEC, NULL, 0x10,
"toggle", HFILL }},
{ &hf_canopen_sdo_cmd_updown_n,
{ "Non-data bytes", "canopen.sdo.n",
FT_UINT8, BASE_DEC, NULL, 0x0E,
"toggle", HFILL }},
{ &hf_canopen_sdo_cmd_updown_c,
{ "No more segments", "canopen.sdo.c",
FT_BOOLEAN, 8, NULL, 0x01,
"toggle", HFILL }},
{ &hf_canopen_sdo_cmd_init_n,
{ "Non-data bytes", "canopen.sdo.n",
FT_UINT8, BASE_DEC, NULL, 0x0C,
"toggle", HFILL }},
{ &hf_canopen_sdo_cmd_init_e,
{ "Expedited transfer", "canopen.sdo.e",
FT_BOOLEAN, 8, NULL, 0x02,
"toggle", HFILL }},
{ &hf_canopen_sdo_cmd_init_s,
{ "Data set size indicated", "canopen.sdo.s",
FT_BOOLEAN, 8, NULL, 0x01,
"toggle", HFILL }},
{ &hf_canopen_sdo_main_idx,
{ "OD main-index", "canopen.sdo.main_idx",
FT_UINT16, BASE_HEX|BASE_RANGE_STRING, RVALS(obj_dict), 0x0,
NULL, HFILL }
},
{ &hf_canopen_sdo_sub_idx,
{ "OD sub-index", "canopen.sdo.sub_idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_sdo_data,
{ "Data", "canopen.sdo.data.bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_sdo_abort_code,
{ "Abort code", "canopen.sdo.abort_code",
FT_UINT32, BASE_HEX, VALS(sdo_abort_code), 0x0,
NULL, HFILL }
},
{ &hf_canopen_reserved,
{ "Reserved", "canopen.reserved",
FT_BYTES, BASE_NONE, NULL, 0x00,
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
{ &hf_canopen_nmt_guard_toggle,
{ "Reserved/Toggle", "canopen.nmt_guard.toggle",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_canopen_nmt_guard_state,
{ "State", "canopen.nmt_guard.state",
FT_UINT8, BASE_HEX, VALS(nmt_guard_state), 0x7F,
NULL, HFILL }
},
{ &hf_canopen_sync_counter,
{ "Counter", "canopen.sync.counter",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_cs,
{ "Command specifier", "canopen.lss.cs",
FT_UINT8, BASE_HEX, VALS(lss_cs_code), 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_addr_vendor,
{ "Vendor-ID", "canopen.lss.addr.vendor",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_addr_product,
{ "Product-code", "canopen.lss.addr.product",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_addr_revision,
{ "Revision-number", "canopen.lss.addr.revision",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_addr_revision_low,
{ "Revision-number (low)", "canopen.lss.addr.revision_low",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_addr_revision_high,
{ "Revision-number (high)", "canopen.lss.addr.revision_high",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_addr_serial,
{ "Serial-number", "canopen.lss.addr.serial",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_addr_serial_low,
{ "Serial-number (low)", "canopen.lss.addr.serial_low",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_addr_serial_high,
{ "Serial-number (high)", "canopen.lss.addr.serial_high",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_fastscan_id,
{ "IDNumber", "canopen.lss.fastscan.id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_fastscan_check,
{ "Bit Check", "canopen.lss.fastscan.check",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_fastscan_sub,
{ "LSS Sub", "canopen.lss.fastscan.sub",
FT_UINT8, BASE_HEX, VALS(lss_fastscan_subnext), 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_fastscan_next,
{ "LSS Next", "canopen.lss.fastscan.next",
FT_UINT8, BASE_HEX, VALS(lss_fastscan_subnext), 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_switch_mode,
{ "Mode", "canopen.lss.switch.mode",
FT_UINT8, BASE_HEX, VALS(lss_switch_mode), 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_nid,
{ "NID", "canopen.lss.nid",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_conf_id_err_code,
{ "Error code", "canopen.lss.conf_id.err_code",
FT_UINT8, BASE_HEX, VALS(lss_conf_id_err_code), 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_conf_bt_err_code,
{ "Error code", "canopen.lss.conf_bt.err_code",
FT_UINT8, BASE_HEX, VALS(lss_conf_bt_err_code), 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_store_conf_err_code,
{ "Error code", "canopen.lss.store_conf.err_code",
FT_UINT8, BASE_HEX, VALS(lss_store_conf_err_code), 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_spec_err,
{ "Spec-error", "canopen.lss.spec_err",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_bt_tbl_selector,
{ "Table selector", "canopen.lss.bt.tbl_selector",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_bt_tbl_index,
{ "Table index", "canopen.lss.bt.tbl_index",
FT_UINT8, BASE_HEX, VALS(bit_timing_tbl), 0x0,
NULL, HFILL }
},
{ &hf_canopen_lss_abt_delay,
{ "Switch delay", "canopen.lss.abt_delay",
FT_UINT16, BASE_DEC, NULL, 0x0,
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
&ett_canopen,
&ett_canopen_cob,
&ett_canopen_type,
&ett_canopen_sdo_cmd
};
proto_canopen = proto_register_protocol("CANopen",
"CANOPEN",
"canopen");
proto_register_field_array(proto_canopen, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_canopen(void)
{
dissector_handle_t canopen_handle;
canopen_handle = create_dissector_handle( dissect_canopen, proto_canopen );
dissector_add_for_decode_as("can.subdissector", canopen_handle );
}
