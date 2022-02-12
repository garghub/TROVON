static void
dissect_cimetrics_mstp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *subtree;
gint offset = 0;
#ifdef BACNET_MSTP_SUMMARY_IN_TREE
guint8 mstp_frame_type = 0;
guint8 mstp_frame_source = 0;
guint8 mstp_frame_destination = 0;
#endif
#ifdef BACNET_MSTP_SUMMARY_IN_TREE
mstp_frame_type = tvb_get_guint8(tvb, offset+3);
mstp_frame_destination = tvb_get_guint8(tvb, offset+4);
mstp_frame_source = tvb_get_guint8(tvb, offset+5);
ti = proto_tree_add_protocol_format(tree,
proto_cimetrics_mstp, tvb, offset, 9,
"BACnet MS/TP, Src (%u), Dst (%u), %s",
mstp_frame_source, mstp_frame_destination,
mstp_frame_type_text(mstp_frame_type));
#else
ti = proto_tree_add_item(tree, proto_cimetrics_mstp, tvb, offset, 9, ENC_NA);
#endif
subtree = proto_item_add_subtree(ti, ett_cimetrics_mstp);
proto_tree_add_item(subtree, hf_cimetrics_mstp_timer, tvb,
offset++, 2, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_cimetrics_mstp_value, tvb,
offset++, 1, ENC_LITTLE_ENDIAN);
dissect_mstp(tvb, pinfo, tree, subtree, offset);
}
void
proto_register_cimetrics(void)
{
static hf_register_info hf[] = {
{ &hf_cimetrics_mstp_timer,
{ "Delta Time", "cimetrics_mstp.timer",
FT_UINT16, BASE_DEC, NULL, 0,
"Milliseconds", HFILL }
},
{ &hf_cimetrics_mstp_value,
{ "8-bit value", "cimetrics_mstp.value",
FT_UINT8, BASE_DEC, NULL, 0,
"value", HFILL }
}
};
static hf_register_info hf2[] = {
{ &hf_llc_cimetrics_pid,
{ "PID", "llc.cimetrics_pid",
FT_UINT16, BASE_HEX, VALS(cimetrics_pid_vals), 0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_cimetrics_mstp
};
proto_cimetrics_mstp = proto_register_protocol("Cimetrics MS/TP",
"Cimetrics MS/TP", "cimetrics");
proto_register_field_array(proto_cimetrics_mstp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("cimetrics", dissect_cimetrics_mstp,
proto_cimetrics_mstp);
llc_add_oui(OUI_CIMETRICS, "llc.cimetrics_pid",
"Cimetrics OUI PID", hf2);
}
void
proto_reg_handoff_cimetrics(void)
{
dissector_handle_t mstp_handle;
mstp_handle = find_dissector("cimetrics");
dissector_add_uint("llc.cimetrics_pid", 1, mstp_handle);
bacnet_handle = find_dissector("bacnet");
data_handle = find_dissector("data");
}
