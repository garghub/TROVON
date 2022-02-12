static void
dissect_ehdlc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 4;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "EHDLC");
col_clear(pinfo->cinfo, COL_INFO);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_item *ti = NULL;
proto_tree *ehdlc_tree = NULL;
guint16 len, msg_type;
tvbuff_t *next_tvb;
guint16 control;
gboolean is_response = FALSE, is_extended = TRUE;
gint header_length = 2;
msg_type = tvb_get_guint8(tvb, offset);
len = tvb_get_guint8(tvb, offset+1);
#if 0
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(msg_type, ehdlc_protocol_vals,
"unknown 0x%02x"));
#endif
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_ehdlc,
tvb, offset, MIN(len, tvb_length_remaining(tvb,offset)),
"Ericsson HDLC protocol, type: %s",
val_to_str(msg_type, ehdlc_protocol_vals,
"unknown 0x%02x"));
ehdlc_tree = proto_item_add_subtree(ti, ett_ehdlc);
proto_tree_add_item(ehdlc_tree, hf_ehdlc_protocol,
tvb, offset, 1, ENC_BIG_ENDIAN);
#if 0
proto_tree_add_item(ehdlc_tree, hf_ehdlc_sapi,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ehdlc_tree, hf_ehdlc_c_r,
tvb, offset, 1, ENC_BIG_ENDIAN);
#endif
proto_tree_add_item(ehdlc_tree, hf_ehdlc_data_len,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
control = dissect_xdlc_control(tvb, offset+2, pinfo, ehdlc_tree, hf_ehdlc_control,
ett_ehdlc_control, &ehdlc_cf_items, &ehdlc_cf_items_ext,
NULL, NULL, is_response, is_extended, FALSE);
header_length += XDLC_CONTROL_LEN(control, is_extended);
if (XDLC_IS_INFORMATION(control)) {
next_tvb = tvb_new_subset(tvb, offset+header_length,
len-header_length, len-header_length);
switch (msg_type) {
case 0x20:
if (len <= 4)
break;
call_dissector(sub_handles[SUB_RSL], next_tvb, pinfo, tree);
break;
case 0xbc:
case 0xdc:
case 0xa0:
case 0xc0:
if (len <= 4)
break;
call_dissector(sub_handles[SUB_OML], next_tvb, pinfo, tree);
break;
default:
call_dissector(sub_handles[SUB_DATA], next_tvb, pinfo, tree);
break;
}
} else if (control == (XDLC_U | XDLC_XID)) {
proto_tree_add_item(ehdlc_tree, hf_ehdlc_xid_payload,
tvb, offset+header_length,
len-header_length, ENC_NA);
}
if (len == 0)
len = 1;
offset += len;
}
}
void
proto_register_ehdlc(void)
{
static hf_register_info hf[] = {
{ &hf_ehdlc_data_len,
{ "DataLen", "ehdlc.data_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The length of the data (in bytes)", HFILL }
},
{ &hf_ehdlc_protocol,
{ "Protocol", "ehdlc.protocol",
FT_UINT8, BASE_HEX, VALS(ehdlc_protocol_vals), 0x0,
"The HDLC Sub-Protocol", HFILL }
},
{ &hf_ehdlc_sapi,
{ "SAPI", "ehdlc.sapi",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_ehdlc_c_r,
{ "C/R", "ehdlc.c_r",
FT_UINT8, BASE_HEX, NULL, 0x20,
NULL, HFILL }
},
{ &hf_ehdlc_xid_payload,
{ "XID Payload", "ehdlc.xid_payload",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ehdlc_control,
{ "Control Field", "ehdlc.control",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_ehdlc_n_r,
{ "N(R)", "ehdlc.control.n_r",
FT_UINT16, BASE_DEC, NULL, XDLC_N_R_EXT_MASK,
NULL, HFILL }
},
{ &hf_ehdlc_n_s,
{ "N(S)", "ehdlc.control.n_s",
FT_UINT16, BASE_DEC, NULL, XDLC_N_S_EXT_MASK,
NULL, HFILL }
},
{ &hf_ehdlc_p,
{ "Poll", "ehdlc.control.p",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), XDLC_P_F,
NULL, HFILL }
},
{ &hf_ehdlc_p_ext,
{ "Poll", "ehdlc.control.p",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), XDLC_P_F_EXT,
NULL, HFILL }
},
{ &hf_ehdlc_f,
{ "Final", "ehdlc.control.f",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), XDLC_P_F,
NULL, HFILL }
},
{ &hf_ehdlc_f_ext,
{ "Final", "ehdlc.control.f",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), XDLC_P_F_EXT,
NULL, HFILL }
},
{ &hf_ehdlc_s_ftype,
{ "Supervisory frame type", "ehdlc.control.s_ftype",
FT_UINT16, BASE_HEX, VALS(stype_vals), XDLC_S_FTYPE_MASK,
NULL, HFILL }
},
{ &hf_ehdlc_u_modifier_cmd,
{ "Command", "ehdlc.control.u_modifier_cmd",
FT_UINT8, BASE_HEX, VALS(modifier_vals_cmd), XDLC_U_MODIFIER_MASK,
NULL, HFILL }
},
{ &hf_ehdlc_u_modifier_resp,
{ "Response", "ehdlc.control.u_modifier_resp",
FT_UINT8, BASE_HEX, VALS(modifier_vals_resp), XDLC_U_MODIFIER_MASK,
NULL, HFILL }
},
{ &hf_ehdlc_ftype_i,
{ "Frame Type", "ehdlc.control.ftype",
FT_UINT16, BASE_HEX, VALS(ftype_vals), XDLC_I_MASK,
NULL, HFILL }
},
{ &hf_ehdlc_ftype_s_u,
{ "Frame Type", "ehdlc.control.ftype",
FT_UINT8, BASE_HEX, VALS(ftype_vals), XDLC_S_U_MASK,
NULL, HFILL }
},
{ &hf_ehdlc_ftype_s_u_ext,
{ "Frame Type", "ehdlc.control.ftype",
FT_UINT16, BASE_HEX, VALS(ftype_vals), XDLC_S_U_MASK,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_ehdlc,
&ett_ehdlc_control,
};
proto_ehdlc =
proto_register_protocol("Ericsson HDLC",
"Ericsson HDLC as used in A-bis over IP", "ehdlc");
proto_register_field_array(proto_ehdlc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("ehdlc", dissect_ehdlc, proto_ehdlc);
}
void
proto_reg_handoff_ehdlc(void)
{
sub_handles[SUB_RSL] = find_dissector("gsm_abis_rsl");
sub_handles[SUB_OML] = find_dissector("gsm_abis_oml");
sub_handles[SUB_DATA] = find_dissector("data");
}
