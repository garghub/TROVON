static void
rq10(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_10_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
rs10(tvbuff_t *tvb, proto_tree *tree)
{
static const int *flags[] = { &hf_ipmi_stor_10_access, NULL };
proto_tree_add_item(tree, hf_ipmi_stor_10_size, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 2, 1, NULL, NULL, ett_ipmi_stor_10_flags, flags, ENC_LITTLE_ENDIAN, 0);
}
static void
rq11(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_11_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_11_offset, tvb, 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_11_count, tvb, 3, 1, ENC_LITTLE_ENDIAN);
}
static void
rs11(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_11_ret_count, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_11_data, tvb, 1, tvb_length(tvb) - 1, ENC_NA);
}
static void
rq12(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_12_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_12_offset, tvb, 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_12_data, tvb, 1, tvb_length(tvb) - 1, ENC_NA);
}
static void
rs12(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_12_ret_count, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
rs20(tvbuff_t *tvb, proto_tree *tree)
{
static const int *ops[] = { &hf_ipmi_stor_20_op_overflow, &hf_ipmi_stor_20_op_update,
&hf_ipmi_stor_20_op_delete, &hf_ipmi_stor_20_op_partial_add, &hf_ipmi_stor_20_op_reserve,
&hf_ipmi_stor_20_op_allocinfo, NULL };
proto_tree_add_item(tree, hf_ipmi_stor_20_sdr_version, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_20_rec_count, tvb, 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_20_free_space, tvb, 3, 2, ENC_LITTLE_ENDIAN);
ipmi_add_timestamp(tree, hf_ipmi_stor_20_ts_add, tvb, 5);
ipmi_add_timestamp(tree, hf_ipmi_stor_20_ts_erase, tvb, 9);
proto_tree_add_bitmask_text(tree, tvb, 13, 1, "Operation Support: ", NULL,
ett_ipmi_stor_20_ops, ops, ENC_LITTLE_ENDIAN, 0);
}
static void
rs21(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_21_units, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_21_size, tvb, 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_21_free, tvb, 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_21_largest, tvb, 6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_21_maxrec, tvb, 8, 1, ENC_LITTLE_ENDIAN);
}
static void
rs22(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_22_rsrv_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
rq23(tvbuff_t *tvb, proto_tree *tree)
{
guint8 v = tvb_get_guint8(tvb, 5);
proto_tree_add_item(tree, hf_ipmi_stor_23_rsrv_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_23_rec_id, tvb, 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_23_offset, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_uint_format_value(tree, hf_ipmi_stor_23_count, tvb, 5, 1,
v, "%d%s", v, v == 0xff ? " (entire record)" : "");
}
static void
rs23(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_23_next, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_23_data, tvb, 2, tvb_length(tvb) - 2, ENC_NA);
}
static void
rq24(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_24_data, tvb, 0, tvb_length(tvb), ENC_NA);
}
static void
rs24(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_24_added_rec_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
rq25(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte6[] = { &hf_ipmi_stor_25_inprogress, NULL };
proto_tree_add_item(tree, hf_ipmi_stor_25_rsrv_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_25_rec_id, tvb, 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_25_offset, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 5, 1, NULL, NULL,
ett_ipmi_stor_25_byte6, byte6, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_stor_25_data, tvb, 6, tvb_length(tvb) - 6, ENC_NA);
}
static void
rs25(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_25_added_rec_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
rq26(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_25_rsrv_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_25_rec_id, tvb, 2, 2, ENC_LITTLE_ENDIAN);
}
static void
rs26(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_26_del_rec_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
rq27(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_27_rsrv_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_27_clr, tvb, 2, 3, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_ipmi_stor_27_action, tvb, 5, 1, ENC_LITTLE_ENDIAN);
}
static void
rs27(tvbuff_t *tvb, proto_tree *tree)
{
static const int *status[] = { &hf_ipmi_stor_27_status, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_stor_27_status, status, ENC_LITTLE_ENDIAN, 0);
}
static void
rs28(tvbuff_t *tvb, proto_tree *tree)
{
ipmi_add_timestamp(tree, hf_ipmi_stor_28_time, tvb, 0);
}
static void
rq29(tvbuff_t *tvb, proto_tree *tree)
{
ipmi_add_timestamp(tree, hf_ipmi_stor_29_time, tvb, 0);
}
static void
rq2c(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_stor_2c_init_agent, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_stor_2c_rq_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
rs2c(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_stor_2c_init_state, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_stor_2c_rs_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
rs40(tvbuff_t *tvb, proto_tree *tree)
{
static const int *ops[] = { &hf_ipmi_stor_40_op_overflow, &hf_ipmi_stor_40_op_delete,
&hf_ipmi_stor_40_op_partial_add, &hf_ipmi_stor_40_op_reserve, &hf_ipmi_stor_40_op_allocinfo, NULL };
proto_tree_add_item(tree, hf_ipmi_stor_40_sel_version, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_40_entries, tvb, 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_40_free_space, tvb, 3, 2, ENC_LITTLE_ENDIAN);
ipmi_add_timestamp(tree, hf_ipmi_stor_40_ts_add, tvb, 5);
ipmi_add_timestamp(tree, hf_ipmi_stor_40_ts_erase, tvb, 9);
proto_tree_add_bitmask_text(tree, tvb, 13, 1, "Operation Support: ", NULL,
ett_ipmi_stor_40_ops, ops, ENC_LITTLE_ENDIAN, 0);
}
static void
rs41(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_41_units, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_41_size, tvb, 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_41_free, tvb, 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_41_largest, tvb, 6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_41_maxrec, tvb, 8, 1, ENC_LITTLE_ENDIAN);
}
static void
rs42(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_42_rsrv_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
rq43(tvbuff_t *tvb, proto_tree *tree)
{
guint8 v = tvb_get_guint8(tvb, 5);
proto_tree_add_item(tree, hf_ipmi_stor_43_rsrv_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_43_rec_id, tvb, 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_43_offset, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_uint_format_value(tree, hf_ipmi_stor_43_count, tvb, 5, 1,
v, "%d%s", v, v == 0xff ? " (entire record)" : "");
}
static void
rs43(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_43_next, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_43_data, tvb, 2, tvb_length(tvb) - 2, ENC_NA);
}
static void
rq44(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_44_data, tvb, 0, tvb_length(tvb), ENC_NA);
}
static void
rs44(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_44_added_rec_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
rq45(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte6[] = { &hf_ipmi_stor_45_inprogress, NULL };
proto_tree_add_item(tree, hf_ipmi_stor_45_rsrv_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_45_rec_id, tvb, 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_45_offset, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 5, 1, NULL, NULL,
ett_ipmi_stor_45_byte6, byte6, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_stor_45_data, tvb, 6, tvb_length(tvb) - 6, ENC_NA);
}
static void
rs45(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_45_added_rec_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
rq46(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_45_rsrv_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_45_rec_id, tvb, 2, 2, ENC_LITTLE_ENDIAN);
}
static void
rs46(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_46_del_rec_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
rq47(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_stor_47_rsrv_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_47_clr, tvb, 2, 3, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_ipmi_stor_47_action, tvb, 5, 1, ENC_LITTLE_ENDIAN);
}
static void
rs47(tvbuff_t *tvb, proto_tree *tree)
{
static const int *status[] = { &hf_ipmi_stor_47_status, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_stor_47_status, status, ENC_LITTLE_ENDIAN, 0);
}
static void
rs48(tvbuff_t *tvb, proto_tree *tree)
{
ipmi_add_timestamp(tree, hf_ipmi_stor_48_time, tvb, 0);
}
static void
rq49(tvbuff_t *tvb, proto_tree *tree)
{
ipmi_add_timestamp(tree, hf_ipmi_stor_49_time, tvb, 0);
}
static void
rq5a(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_stor_5a_log_type, NULL };
if (!tree) {
ipmi_setsaveddata(0, tvb_get_guint8(tvb, 0) & 0x0f);
return;
}
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_stor_5a_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
rs5a(tvbuff_t *tvb, proto_tree *tree)
{
guint32 v;
if (!ipmi_getsaveddata(0, &v) || v > 2) {
proto_tree_add_item(tree, hf_ipmi_stor_5a_unknown, tvb, 0, tvb_length(tvb), ENC_NA);
return;
}
ipmi_add_timestamp(tree, hf_ipmi_stor_5a_ts_add, tvb, 0);
if (v == 0) {
proto_tree_add_item(tree, hf_ipmi_stor_5a_num_entries, tvb, 4, 4, ENC_LITTLE_ENDIAN);
} else if (v == 1 || v == 2) {
proto_tree_add_item(tree, hf_ipmi_stor_5a_iana, tvb, 4, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_5a_bytes, tvb, 7, 7, ENC_NA);
}
}
static void
rq5b(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_stor_5b_log_type, NULL };
guint8 v = tvb_get_guint8(tvb, 0);
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_stor_5b_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
if (v > 2) {
proto_tree_add_item(tree, hf_ipmi_stor_5b_unknown, tvb, 1, tvb_length(tvb) - 1, ENC_NA);
return;
}
ipmi_add_timestamp(tree, hf_ipmi_stor_5b_ts_add, tvb, 1);
if (v == 0) {
proto_tree_add_item(tree, hf_ipmi_stor_5b_num_entries, tvb, 5, 4, ENC_LITTLE_ENDIAN);
} else if (v == 1 || v == 2) {
proto_tree_add_item(tree, hf_ipmi_stor_5b_iana, tvb, 5, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_stor_5b_bytes, tvb, 8, 8, ENC_NA);
}
}
void
ipmi_register_storage(gint proto_ipmi)
{
static hf_register_info hf[] = {
{ &hf_ipmi_stor_10_fruid,
{ "FRU ID",
"ipmi.st10.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_10_size,
{ "FRU Inventory area size",
"ipmi.st10.size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_10_access,
{ "Device is accessed",
"ipmi.st10.access", FT_BOOLEAN, 8, TFS(&tfs_10_access), 0x01, NULL, HFILL }},
{ &hf_ipmi_stor_11_fruid,
{ "FRU ID",
"ipmi.st11.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_11_offset,
{ "Offset to read",
"ipmi.st11.offset", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_11_count,
{ "Count to read",
"ipmi.st11.count", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_11_ret_count,
{ "Returned count",
"ipmi.st11.ret_count", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_11_data,
{ "Requested data",
"ipmi.st11.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_12_fruid,
{ "FRU ID",
"ipmi.st12.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_12_offset,
{ "Offset to read",
"ipmi.st12.offset", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_12_data,
{ "Requested data",
"ipmi.st12.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_12_ret_count,
{ "Returned count",
"ipmi.st12.ret_count", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_20_sdr_version,
{ "SDR Version",
"ipmi.st20.sdr_version", FT_UINT8, BASE_CUSTOM, ipmi_fmt_version, 0, NULL, HFILL }},
{ &hf_ipmi_stor_20_rec_count,
{ "Record Count",
"ipmi.st20.rec_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_20_free_space,
{ "Free Space",
"ipmi.st20.free_space", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_20_ts_add,
{ "Most recent addition timestamp",
"ipmi.st20.ts_add", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_20_ts_erase,
{ "Most recent erase timestamp",
"ipmi.st20.ts_erase", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_20_op_overflow,
{ "Overflow",
"ipmi.st20.op_overflow", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_stor_20_op_update,
{ "SDR Repository Update",
"ipmi.st20.op_update", FT_UINT8, BASE_HEX, vals_20_update, 0x60, NULL, HFILL }},
{ &hf_ipmi_stor_20_op_delete,
{ "Delete SDR",
"ipmi.st20.op_delete", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_stor_20_op_partial_add,
{ "Partial Add SDR",
"ipmi.st20.op_partial_add", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_stor_20_op_reserve,
{ "Reserve SDR Repository",
"ipmi.st20.op_reserve", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_stor_20_op_allocinfo,
{ "Get SDR Repository Allocation Info",
"ipmi.st20.op_allocinfo", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_stor_21_units,
{ "Number of allocation units",
"ipmi.st21.units", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_21_size,
{ "Allocation unit size",
"ipmi.st21.size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_21_free,
{ "Number of free units",
"ipmi.st21.free", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_21_largest,
{ "Largest free block (in units)",
"ipmi.st21.largest", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_21_maxrec,
{ "Maximum record size (in units)",
"ipmi.st21.maxrec", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_22_rsrv_id,
{ "Reservation ID",
"ipmi.st22.rsrv_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_23_rsrv_id,
{ "Reservation ID",
"ipmi.st23.rsrv_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_23_rec_id,
{ "Record ID",
"ipmi.st23.rec_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_23_offset,
{ "Offset into record",
"ipmi.st23.offset", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_23_count,
{ "Bytes to read",
"ipmi.st23.count", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_23_next,
{ "Next Record ID",
"ipmi.st23.next", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_23_data,
{ "Record Data",
"ipmi.st23.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_24_data,
{ "SDR Data",
"ipmi.st24.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_24_added_rec_id,
{ "Record ID for added record",
"ipmi.st23.added_rec_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_25_rsrv_id,
{ "Reservation ID",
"ipmi.st25.rsrv_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_25_rec_id,
{ "Record ID",
"ipmi.st25.rec_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_25_offset,
{ "Offset into record",
"ipmi.st25.offset", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_25_inprogress,
{ "In progress",
"ipmi.st25.inprogress", FT_UINT8, BASE_HEX, vals_25_inprogress, 0x0f, NULL, HFILL }},
{ &hf_ipmi_stor_25_data,
{ "SDR Data",
"ipmi.st25.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_25_added_rec_id,
{ "Record ID for added record",
"ipmi.st25.added_rec_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
#if 0
{ &hf_ipmi_stor_26_rsrv_id,
{ "Reservation ID",
"ipmi.st26.rsrv_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_26_rec_id,
{ "Record ID",
"ipmi.st26.rec_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
#endif
{ &hf_ipmi_stor_26_del_rec_id,
{ "Deleted Record ID",
"ipmi.st26.del_rec_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_27_rsrv_id,
{ "Reservation ID",
"ipmi.st27.rsrv_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_27_clr,
{ "Confirmation (should be CLR)",
"ipmi.st27.clr", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_27_action,
{ "Action",
"ipmi.st27.action", FT_UINT8, BASE_HEX, vals_27_action, 0, NULL, HFILL }},
{ &hf_ipmi_stor_27_status,
{ "Erasure Status",
"ipmi.st27.status", FT_UINT8, BASE_HEX, vals_27_status, 0x0f, NULL, HFILL }},
{ &hf_ipmi_stor_28_time,
{ "Time",
"ipmi.st28.time", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_29_time,
{ "Time",
"ipmi.st29.time", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_2c_init_agent,
{ "Initialization agent",
"ipmi.st2c.init_agent", FT_BOOLEAN, 8, TFS(&tfs_2c_init_agent), 0x01, NULL, HFILL }},
{ &hf_ipmi_stor_2c_init_state,
{ "Initialization",
"ipmi.st2c.init_state", FT_BOOLEAN, 8, TFS(&tfs_2c_init_state), 0x01, NULL, HFILL }},
{ &hf_ipmi_stor_40_sel_version,
{ "SEL Version",
"ipmi.st40.sel_version", FT_UINT8, BASE_CUSTOM, ipmi_fmt_version, 0, NULL, HFILL }},
{ &hf_ipmi_stor_40_entries,
{ "Entries",
"ipmi.st40.rec_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_40_free_space,
{ "Free Space",
"ipmi.st40.free_space", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_40_ts_add,
{ "Most recent addition timestamp",
"ipmi.st40.ts_add", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_40_ts_erase,
{ "Most recent erase timestamp",
"ipmi.st40.ts_erase", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_40_op_overflow,
{ "Overflow",
"ipmi.st40.op_overflow", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_stor_40_op_delete,
{ "Delete SEL",
"ipmi.st40.op_delete", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_stor_40_op_partial_add,
{ "Partial Add SEL Entry",
"ipmi.st40.op_partial_add", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_stor_40_op_reserve,
{ "Reserve SEL",
"ipmi.st40.op_reserve", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_stor_40_op_allocinfo,
{ "Get SEL Allocation Info",
"ipmi.st40.op_allocinfo", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_stor_41_units,
{ "Number of allocation units",
"ipmi.st41.units", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_41_size,
{ "Allocation unit size",
"ipmi.st41.size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_41_free,
{ "Number of free units",
"ipmi.st41.free", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_41_largest,
{ "Largest free block (in units)",
"ipmi.st41.largest", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_41_maxrec,
{ "Maximum record size (in units)",
"ipmi.st41.maxrec", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_42_rsrv_id,
{ "Reservation ID",
"ipmi.st42.rsrv_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_43_rsrv_id,
{ "Reservation ID",
"ipmi.st43.rsrv_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_43_rec_id,
{ "Record ID",
"ipmi.st43.rec_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_43_offset,
{ "Offset into record",
"ipmi.st43.offset", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_43_count,
{ "Bytes to read",
"ipmi.st43.count", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_43_next,
{ "Next Record ID",
"ipmi.st43.next", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_43_data,
{ "Record Data",
"ipmi.st43.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_44_data,
{ "SDR Data",
"ipmi.st44.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_44_added_rec_id,
{ "Record ID for added record",
"ipmi.st43.added_rec_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_45_rsrv_id,
{ "Reservation ID",
"ipmi.st45.rsrv_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_45_rec_id,
{ "Record ID",
"ipmi.st45.rec_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_45_offset,
{ "Offset into record",
"ipmi.st45.offset", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_45_inprogress,
{ "In progress",
"ipmi.st45.inprogress", FT_UINT8, BASE_HEX, vals_45_inprogress, 0x0f, NULL, HFILL }},
{ &hf_ipmi_stor_45_data,
{ "Record Data",
"ipmi.st45.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_45_added_rec_id,
{ "Record ID for added record",
"ipmi.st45.added_rec_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
#if 0
{ &hf_ipmi_stor_46_rsrv_id,
{ "Reservation ID",
"ipmi.st46.rsrv_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_46_rec_id,
{ "Record ID",
"ipmi.st46.rec_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
#endif
{ &hf_ipmi_stor_46_del_rec_id,
{ "Deleted Record ID",
"ipmi.st46.del_rec_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_47_rsrv_id,
{ "Reservation ID",
"ipmi.st47.rsrv_id", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_47_clr,
{ "Confirmation (should be CLR)",
"ipmi.st47.clr", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_47_action,
{ "Action",
"ipmi.st47.action", FT_UINT8, BASE_HEX, vals_47_action, 0, NULL, HFILL }},
{ &hf_ipmi_stor_47_status,
{ "Erasure Status",
"ipmi.st47.status", FT_UINT8, BASE_HEX, vals_47_status, 0x0f, NULL, HFILL }},
{ &hf_ipmi_stor_48_time,
{ "Time",
"ipmi.st48.time", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_49_time,
{ "Time",
"ipmi.st49.time", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_5a_log_type,
{ "Log type",
"ipmi.st5a.log_type", FT_UINT8, BASE_HEX, log_type_vals, 0x0f, NULL, HFILL }},
{ &hf_ipmi_stor_5a_ts_add,
{ "Last addition timestamp",
"ipmi.st5a.ts_add", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_5a_num_entries,
{ "Number of entries in MCA Log",
"ipmi.st5a.num_entries", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_5a_iana,
{ "OEM IANA",
"ipmi.st5a.iana", FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_5a_bytes,
{ "Log status bytes",
"ipmi.st5a.bytes", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_5a_unknown,
{ "Unknown log format (cannot parse data)",
"ipmi.st5a.unknown", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_5b_log_type,
{ "Log type",
"ipmi.st5b.log_type", FT_UINT8, BASE_HEX, log_type_vals, 0x0f, NULL, HFILL }},
{ &hf_ipmi_stor_5b_ts_add,
{ "Last addition timestamp",
"ipmi.st5b.ts_add", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_5b_num_entries,
{ "Number of entries in MCA Log",
"ipmi.st5b.num_entries", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_5b_iana,
{ "OEM IANA",
"ipmi.st5b.iana", FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_5b_bytes,
{ "Log status bytes",
"ipmi.st5b.bytes", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_stor_5b_unknown,
{ "Unknown log format (cannot parse data)",
"ipmi.st5b.unknown", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ipmi_stor_10_flags,
&ett_ipmi_stor_20_ops,
&ett_ipmi_stor_25_byte6,
&ett_ipmi_stor_27_status,
&ett_ipmi_stor_2c_rq_byte1,
&ett_ipmi_stor_2c_rs_byte1,
&ett_ipmi_stor_40_ops,
&ett_ipmi_stor_45_byte6,
&ett_ipmi_stor_47_status,
&ett_ipmi_stor_5a_byte1,
&ett_ipmi_stor_5b_byte1,
};
proto_register_field_array(proto_ipmi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ipmi_register_netfn_cmdtab(IPMI_STORAGE_REQ, IPMI_OEM_NONE, NULL, 0, NULL,
cmd_storage, array_length(cmd_storage));
}
