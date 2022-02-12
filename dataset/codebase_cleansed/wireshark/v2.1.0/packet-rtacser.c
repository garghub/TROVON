static void
rtacser_ppi_prompt(packet_info *pinfo _U_, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Payload as");
}
static gpointer
rtacser_ppi_value(packet_info *pinfo _U_)
{
return 0;
}
static void
dissect_rtacser_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *rtacser_item, *cl_item;
proto_tree *rtacser_tree, *cl_tree;
int offset = 0, len;
guint event_type;
nstime_t tv;
gboolean cts, dcd, dsr, rts, dtr, ring, mbok;
tvbuff_t *payload_tvb;
len = RTACSER_HEADER_LEN;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTAC Serial");
col_clear(pinfo->cinfo, COL_INFO);
rtacser_item = proto_tree_add_protocol_format(tree, proto_rtacser, tvb, 0, len, "RTAC Serial Line");
rtacser_tree = proto_item_add_subtree(rtacser_item, ett_rtacser);
tv.secs = tvb_get_ntohl(tvb, offset);
tv.nsecs = tvb_get_ntohl(tvb, offset+4)*1000;
proto_tree_add_time(rtacser_tree, hf_rtacser_timestamp, tvb, offset, 8, &tv);
offset += 8;
event_type = tvb_get_guint8(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_INFO, "%-21s", val_to_str_const(event_type, rtacser_eventtype_vals, "Unknown Type"));
proto_tree_add_item(rtacser_tree, hf_rtacser_event_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
cts = tvb_get_guint8(tvb, offset) & RTACSER_CTRL_CTS;
dcd = tvb_get_guint8(tvb, offset) & RTACSER_CTRL_DCD;
dsr = tvb_get_guint8(tvb, offset) & RTACSER_CTRL_DSR;
rts = tvb_get_guint8(tvb, offset) & RTACSER_CTRL_RTS;
dtr = tvb_get_guint8(tvb, offset) & RTACSER_CTRL_DTR;
ring = tvb_get_guint8(tvb, offset) & RTACSER_CTRL_RING;
mbok = tvb_get_guint8(tvb, offset) & RTACSER_CTRL_MBOK;
cl_tree = proto_tree_add_subtree(rtacser_tree, tvb, offset, 1, ett_rtacser_cl, &cl_item, "Control Lines");
col_append_str(pinfo->cinfo, COL_INFO, " ( ");
(cts) ? col_append_str(pinfo->cinfo, COL_INFO, "CTS") : col_append_str(pinfo->cinfo, COL_INFO, "/CTS");
(dcd) ? col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "DCD") : col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "/DCD");
(dsr) ? col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "DSR") : col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "/DSR");
(rts) ? col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "RTS") : col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "/RTS");
(dtr) ? col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "DTR") : col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "/DTR");
(ring) ? col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "RING") : col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "/RING");
(mbok) ? col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "MBOK") : col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "/MBOK");
col_append_str(pinfo->cinfo, COL_INFO, " )");
proto_item_append_text(cl_item, " (");
(cts) ? proto_item_append_text(cl_item, "CTS, ") : proto_item_append_text(cl_item, "/CTS, ");
(dcd) ? proto_item_append_text(cl_item, "DCD, ") : proto_item_append_text(cl_item, "/DCD, ");
(dsr) ? proto_item_append_text(cl_item, "DSR, ") : proto_item_append_text(cl_item, "/DSR, ");
(rts) ? proto_item_append_text(cl_item, "RTS, ") : proto_item_append_text(cl_item, "/RTS, ");
(dtr) ? proto_item_append_text(cl_item, "DTR, ") : proto_item_append_text(cl_item, "/DTR, ");
(ring) ? proto_item_append_text(cl_item, "RING, ") : proto_item_append_text(cl_item, "/RING, ");
(mbok) ? proto_item_append_text(cl_item, "MBOK") : proto_item_append_text(cl_item, "/MBOK");
proto_item_append_text(cl_item, ")");
proto_tree_add_item(cl_tree, hf_rtacser_ctrl_cts, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cl_tree, hf_rtacser_ctrl_dcd, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cl_tree, hf_rtacser_ctrl_dsr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cl_tree, hf_rtacser_ctrl_rts, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cl_tree, hf_rtacser_ctrl_dtr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cl_tree, hf_rtacser_ctrl_ring, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cl_tree, hf_rtacser_ctrl_mbok, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rtacser_tree, hf_rtacser_footer, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
payload_tvb = tvb_new_subset_remaining(tvb, RTACSER_HEADER_LEN);
if (!dissector_try_uint(subdissector_table, 0, payload_tvb, pinfo, tree)){
call_data_dissector(payload_tvb, pinfo, tree);
}
}
}
static int
dissect_rtacser(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint length = tvb_captured_length(tvb);
if(length < 12) {
return 0;
}
dissect_rtacser_data(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_rtacser(void)
{
static hf_register_info rtacser_hf[] = {
{ &hf_rtacser_timestamp,
{ "Arrived At Time", "rtacser.timestamp", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rtacser_event_type,
{ "Event Type", "rtacser.eventtype", FT_UINT8, BASE_HEX, VALS(rtacser_eventtype_vals), 0x0, NULL, HFILL }},
{ &hf_rtacser_ctrl_cts,
{ "CTS", "rtacser.cts", FT_UINT8, BASE_DEC, NULL, RTACSER_CTRL_CTS, NULL, HFILL }},
{ &hf_rtacser_ctrl_dcd,
{ "DCD", "rtacser.dcd", FT_UINT8, BASE_DEC, NULL, RTACSER_CTRL_DCD, NULL, HFILL }},
{ &hf_rtacser_ctrl_dsr,
{ "DSR", "rtacser.dsr", FT_UINT8, BASE_DEC, NULL, RTACSER_CTRL_DSR, NULL, HFILL }},
{ &hf_rtacser_ctrl_rts,
{ "RTS", "rtacser.rts", FT_UINT8, BASE_DEC, NULL, RTACSER_CTRL_RTS, NULL, HFILL }},
{ &hf_rtacser_ctrl_dtr,
{ "DTR", "rtacser.dtr", FT_UINT8, BASE_DEC, NULL, RTACSER_CTRL_DTR, NULL, HFILL }},
{ &hf_rtacser_ctrl_ring,
{ "RING", "rtacser.ring", FT_UINT8, BASE_DEC, NULL, RTACSER_CTRL_RING, NULL, HFILL }},
{ &hf_rtacser_ctrl_mbok,
{ "MBOK", "rtacser.mbok", FT_UINT8, BASE_DEC, NULL, RTACSER_CTRL_MBOK, NULL, HFILL }},
{ &hf_rtacser_footer,
{ "Footer", "rtacser.footer", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_rtacser,
&ett_rtacser_cl,
};
static build_valid_func rtacser_da_ppi_build_value[1] = {rtacser_ppi_value};
static decode_as_value_t rtacser_da_ppi_values[1] = {{rtacser_ppi_prompt, 1, rtacser_da_ppi_build_value}};
static decode_as_t rtacser_da_ppi = {"rtacser", "RTAC Serial", "rtacser.data", 1, 0, rtacser_da_ppi_values, "RTAC Serial", NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
module_t *rtacser_module;
proto_rtacser = proto_register_protocol("RTAC Serial", "RTAC Serial", "rtacser");
rtacser_handle = register_dissector("rtacser", dissect_rtacser, proto_rtacser);
subdissector_table = register_dissector_table("rtacser.data", "RTAC Serial Data Subdissector", proto_rtacser, FT_UINT32, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
proto_register_field_array(proto_rtacser, rtacser_hf, array_length(rtacser_hf));
proto_register_subtree_array(ett, array_length(ett));
rtacser_module = prefs_register_protocol(proto_rtacser, proto_reg_handoff_rtacser);
prefs_register_obsolete_preference(rtacser_module, "rtacserial_payload_proto");
register_decode_as(&rtacser_da_ppi);
}
void
proto_reg_handoff_rtacser(void)
{
dissector_add_uint("wtap_encap", WTAP_ENCAP_RTAC_SERIAL, rtacser_handle);
}
