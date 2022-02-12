static int
dissect_lsc_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *lsc_tree;
guint8 op_code;
guint32 stream;
guint expected_len;
if (tvb_captured_length(tvb) < LSC_MIN_LEN)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LSC");
col_clear(pinfo->cinfo, COL_INFO);
op_code = tvb_get_guint8(tvb, 2);
stream = tvb_get_ntohl(tvb, 4);
switch (op_code)
{
case LSC_PAUSE:
expected_len = LSC_PAUSE_LEN;
break;
case LSC_RESUME:
expected_len = LSC_RESUME_LEN;
break;
case LSC_STATUS:
expected_len = LSC_STATUS_LEN;
break;
case LSC_RESET:
expected_len = LSC_RESET_LEN;
break;
case LSC_JUMP:
expected_len = LSC_JUMP_LEN;
break;
case LSC_PLAY:
expected_len = LSC_PLAY_LEN;
break;
case LSC_DONE:
case LSC_PAUSE_REPLY:
case LSC_RESUME_REPLY:
case LSC_STATUS_REPLY:
case LSC_RESET_REPLY:
case LSC_JUMP_REPLY:
case LSC_PLAY_REPLY:
expected_len = LSC_REPLY_LEN;
break;
default:
expected_len = LSC_MIN_LEN;
break;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s, session %.8u",
val_to_str(op_code, op_code_vals, "Unknown op code (0x%x)"),
stream);
if (tvb_reported_length(tvb) < expected_len)
col_append_str(pinfo->cinfo, COL_INFO, " [Too short]");
else if (tvb_reported_length(tvb) > expected_len)
col_append_str(pinfo->cinfo, COL_INFO, " [Too long]");
if (tree) {
ti = proto_tree_add_item(tree, proto_lsc, tvb, 0, -1, ENC_NA);
lsc_tree = proto_item_add_subtree(ti, ett_lsc);
proto_tree_add_uint(lsc_tree, hf_lsc_op_code, tvb, 2, 1, op_code);
proto_tree_add_uint_format_value(lsc_tree, hf_lsc_stream_handle, tvb, 4, 4,
stream, "%.8u", stream);
proto_tree_add_item(lsc_tree, hf_lsc_version, tvb, 0, 1, ENC_NA);
proto_tree_add_item(lsc_tree, hf_lsc_trans_id, tvb, 1, 1, ENC_NA);
if (isReply(op_code))
proto_tree_add_item(lsc_tree, hf_lsc_status_code, tvb, 3, 1,
ENC_NA);
switch (op_code)
{
case LSC_PAUSE:
proto_tree_add_item(lsc_tree, hf_lsc_stop_npt, tvb, 8, 4,
ENC_BIG_ENDIAN);
break;
case LSC_RESUME:
proto_tree_add_item(lsc_tree, hf_lsc_start_npt, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(lsc_tree, hf_lsc_scale_num, tvb, 12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(lsc_tree, hf_lsc_scale_denom, tvb, 14, 2, ENC_BIG_ENDIAN);
break;
case LSC_JUMP:
case LSC_PLAY:
proto_tree_add_item(lsc_tree, hf_lsc_start_npt, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(lsc_tree, hf_lsc_stop_npt, tvb, 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(lsc_tree, hf_lsc_scale_num, tvb, 16, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(lsc_tree, hf_lsc_scale_denom, tvb, 18, 2, ENC_BIG_ENDIAN);
break;
case LSC_DONE:
case LSC_PAUSE_REPLY:
case LSC_RESUME_REPLY:
case LSC_STATUS_REPLY:
case LSC_RESET_REPLY:
case LSC_JUMP_REPLY:
case LSC_PLAY_REPLY:
proto_tree_add_item(lsc_tree, hf_lsc_current_npt, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(lsc_tree, hf_lsc_scale_num, tvb, 12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(lsc_tree, hf_lsc_scale_denom, tvb, 14, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(lsc_tree, hf_lsc_mode, tvb, 16, 1, ENC_BIG_ENDIAN);
break;
default:
break;
}
}
return tvb_captured_length(tvb);
}
static int
dissect_lsc_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
return dissect_lsc_common(tvb, pinfo, tree, data);
}
static guint
get_lsc_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint8 op_code;
guint pdu_len;
op_code = tvb_get_guint8(tvb, offset + 2);
switch (op_code)
{
case LSC_PAUSE:
pdu_len = LSC_PAUSE_LEN;
break;
case LSC_RESUME:
pdu_len = LSC_RESUME_LEN;
break;
case LSC_STATUS:
pdu_len = LSC_STATUS_LEN;
break;
case LSC_RESET:
pdu_len = LSC_RESET_LEN;
break;
case LSC_JUMP:
pdu_len = LSC_JUMP_LEN;
break;
case LSC_PLAY:
pdu_len = LSC_PLAY_LEN;
break;
case LSC_DONE:
case LSC_PAUSE_REPLY:
case LSC_RESUME_REPLY:
case LSC_STATUS_REPLY:
case LSC_RESET_REPLY:
case LSC_JUMP_REPLY:
case LSC_PLAY_REPLY:
pdu_len = LSC_REPLY_LEN;
break;
default:
pdu_len = LSC_OPCODE_LEN;
break;
}
return pdu_len;
}
static int
dissect_lsc_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, LSC_OPCODE_LEN, get_lsc_pdu_len,
dissect_lsc_common, data);
return tvb_captured_length(tvb);
}
void
proto_register_lsc(void)
{
static hf_register_info hf[] = {
{ &hf_lsc_version,
{ "Version", "lsc.version",
FT_UINT8, BASE_DEC, NULL, 0,
"Version of the Pegasus LSC protocol", HFILL }
},
{ &hf_lsc_trans_id,
{ "Transaction ID", "lsc.trans_id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_lsc_op_code,
{ "Op Code", "lsc.op_code",
FT_UINT8, BASE_HEX, VALS(op_code_vals), 0,
"Operation Code", HFILL }
},
{ &hf_lsc_status_code,
{ "Status Code", "lsc.status_code",
FT_UINT8, BASE_HEX, VALS(status_code_vals), 0,
NULL, HFILL }
},
{ &hf_lsc_stream_handle,
{ "Stream Handle", "lsc.stream_handle",
FT_UINT32, BASE_DEC, NULL, 0,
"Stream identification handle", HFILL }
},
{ &hf_lsc_start_npt,
{ "Start NPT", "lsc.start_npt",
FT_INT32, BASE_DEC, NULL, 0,
"Start Time (milliseconds)", HFILL }
},
{ &hf_lsc_stop_npt,
{ "Stop NPT", "lsc.stop_npt",
FT_INT32, BASE_DEC, NULL, 0,
"Stop Time (milliseconds)", HFILL }
},
{ &hf_lsc_current_npt,
{ "Current NPT", "lsc.current_npt",
FT_INT32, BASE_DEC, NULL, 0,
"Current Time (milliseconds)", HFILL }
},
{ &hf_lsc_scale_num,
{ "Scale Numerator", "lsc.scale_num",
FT_INT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_lsc_scale_denom,
{ "Scale Denominator", "lsc.scale_denum",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_lsc_mode,
{ "Server Mode", "lsc.mode",
FT_UINT8, BASE_HEX, VALS(mode_vals), 0,
"Current Server Mode", HFILL }
}
};
static gint *ett[] = {
&ett_lsc,
};
proto_lsc = proto_register_protocol("Pegasus Lightweight Stream Control", "LSC", "lsc");
proto_register_field_array(proto_lsc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_lsc(void)
{
dissector_handle_t lsc_udp_handle;
dissector_handle_t lsc_tcp_handle;
lsc_udp_handle = create_dissector_handle(dissect_lsc_udp, proto_lsc);
lsc_tcp_handle = create_dissector_handle(dissect_lsc_tcp, proto_lsc);
dissector_add_for_decode_as_with_preference("udp.port", lsc_udp_handle);
dissector_add_for_decode_as_with_preference("tcp.port", lsc_tcp_handle);
}
