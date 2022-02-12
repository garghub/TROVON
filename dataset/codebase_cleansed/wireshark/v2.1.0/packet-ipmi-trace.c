static void
dissect_ipmb_state_notify(tvbuff_t * tvb, proto_tree * tree)
{
proto_tree_add_item(tree, hf_trace_notify_format,
tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 1,
hf_trace_ipmb_state, ett_trace_ipmb_state,
bits_chn_state_info, ENC_LITTLE_ENDIAN);
}
static int
dissect_ipmi_trace(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint block_type, chn_num, data_type, tmp;
tvbuff_t * next_tvb;
if (tvb_captured_length(tvb) < 11) {
call_data_dissector(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
tmp = tvb_get_guint8(tvb, 0);
block_type = (tmp >> 4) & 3;
chn_num = tmp & 0xF;
data_type = tvb_get_guint8(tvb, 7);
col_add_fstr(pinfo->cinfo, COL_DEF_SRC, "Channel %d", chn_num);
col_set_str(pinfo->cinfo, COL_PROTOCOL,
val_to_str(data_type, str_protocol_types,
"Reserved (0x%02x)"));
col_clear(pinfo->cinfo, COL_INFO);
if (block_type == HPM2_TRACE_PACKET_DATA) {
col_set_str(pinfo->cinfo, COL_INFO, "Trace Packet Data");
} else if (block_type == HPM2_CHN_STATE_NOTIFY) {
col_set_str(pinfo->cinfo, COL_INFO,
"Channel State Change Notification");
} else if (block_type == HPM2_EMBED_ASCII_MSG) {
char str[257];
guint str_len = tvb_get_guint8(tvb, 10);
if (str_len) {
tvb_memcpy(tvb, str, 11, str_len);
str[str_len] = 0;
col_add_str(pinfo->cinfo, COL_INFO, str);
}
} else {
col_set_str(pinfo->cinfo, COL_INFO, "Reserved");
}
if ( tree ) {
proto_item * ti;
proto_tree * trace_tree;
proto_tree * stamp_tree;
nstime_t timestamp;
ti = proto_tree_add_item(tree, proto_ipmi_trace, tvb, 0, -1, ENC_NA);
trace_tree = proto_item_add_subtree(ti, ett_ipmi_trace);
proto_tree_add_bitmask(trace_tree, tvb, 0, hf_trace_block_type,
ett_trace_block_type, bits_trace_block_type,
ENC_LITTLE_ENDIAN);
timestamp.secs = tvb_get_letohl(tvb, 1);
timestamp.nsecs = (int) tvb_get_letohs(tvb, 5) * 1000000;
ti = proto_tree_add_time(trace_tree, hf_trace_timestamp, tvb, 1,
6, &timestamp);
stamp_tree = proto_item_add_subtree(ti, ett_trace_timestamp);
proto_tree_add_item(stamp_tree, hf_trace_timestamp_sec,
tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stamp_tree, hf_trace_timestamp_msec,
tvb, 5, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(trace_tree, hf_trace_data_type,
tvb, 7, 1, ENC_LITTLE_ENDIAN);
if (data_type == IPMI_PROTO_IPMB_1_0) {
proto_tree_add_bitmask(trace_tree, tvb, 8,
hf_trace_protocol_data, ett_trace_protocol_data,
bits_ipmb_protocol_data, ENC_LITTLE_ENDIAN);
} else if (data_type == IPMI_PROTO_KCS
|| data_type == IPMI_PROTO_SMIC
|| data_type == IPMI_PROTO_BT_10
|| data_type == IPMI_PROTO_BT_15) {
proto_tree_add_bitmask(trace_tree, tvb, 8,
hf_trace_protocol_data, ett_trace_protocol_data,
bits_host_protocol_data, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(trace_tree, hf_trace_protocol_data, tvb,
8, 2, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(trace_tree, hf_trace_data_len, tvb,
10, 1, ENC_LITTLE_ENDIAN);
}
next_tvb = tvb_new_subset_remaining(tvb, 11);
if (block_type == HPM2_TRACE_PACKET_DATA) {
ipmi_dissect_arg_t arg;
arg.context = IPMI_E_NONE;
arg.channel = chn_num;
arg.flags = tvb_get_guint8(tvb, 8);
if (!dissector_try_uint_new(proto_dissector_table,
data_type, next_tvb, pinfo, tree, TRUE, &arg)) {
call_data_dissector(next_tvb, pinfo, tree);
}
} else if (block_type == HPM2_CHN_STATE_NOTIFY
&& data_type == IPMI_PROTO_IPMB_1_0) {
dissect_ipmb_state_notify(next_tvb, tree);
} else {
call_data_dissector(next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
void
proto_register_ipmi_trace(void)
{
proto_ipmi_trace = proto_register_protocol("IPMI Trace Data Collection",
"ipmi-trace", "ipmi.trace");
proto_register_field_array(proto_ipmi_trace, ipmi_trace_hf,
array_length(ipmi_trace_hf));
proto_register_subtree_array(ipmi_trace_ett,
array_length(ipmi_trace_ett));
proto_dissector_table = register_dissector_table("ipmi.protocol",
"IPMI Channel Protocol Type", proto_ipmi_trace, FT_UINT8, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
}
void
proto_reg_handoff_ipmi_trace(void)
{
dissector_handle_t ipmi_trace_handle;
ipmi_trace_handle = create_dissector_handle(dissect_ipmi_trace,
proto_ipmi_trace);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IPMI_TRACE, ipmi_trace_handle);
dissector_add_uint("ipmi.protocol", IPMI_PROTO_IPMB_1_0,
find_dissector("ipmb"));
dissector_add_uint("ipmi.protocol", IPMI_PROTO_KCS,
find_dissector("kcs"));
dissector_add_uint("ipmi.protocol", IPMI_PROTO_TMODE,
find_dissector("tmode"));
}
