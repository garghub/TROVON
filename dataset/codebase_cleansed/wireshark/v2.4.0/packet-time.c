static int
dissect_time(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *time_tree;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TIME");
col_add_fstr(pinfo->cinfo, COL_INFO, "TIME %s",
pinfo->srcport == pinfo->match_uint ? "Response":"Request");
ti = proto_tree_add_item(tree, proto_time, tvb, 0, -1, ENC_NA);
time_tree = proto_item_add_subtree(ti, ett_time);
proto_tree_add_boolean(time_tree, hf_time_response, tvb, 0, 0, pinfo->srcport==pinfo->match_uint);
if (pinfo->srcport == pinfo->match_uint) {
guint32 delta_seconds = tvb_get_ntohl(tvb, 0);
proto_tree_add_uint_format(time_tree, hf_time_time, tvb, 0, 4,
delta_seconds, "%s",
abs_time_secs_to_str(wmem_packet_scope(), delta_seconds-2208988800U,
(absolute_time_display_e)time_display_type, TRUE));
}
return tvb_captured_length(tvb);
}
void
proto_register_time(void)
{
static hf_register_info hf[] = {
{ &hf_time_time,
{ "Time", "time.time",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Seconds since 00:00 (midnight) 1 January 1900 GMT", HFILL }},
{ &hf_time_response,
{ "Type", "time.response",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_response_request), 0x0,
"Response or Request", HFILL }}
};
static gint *ett[] = {
&ett_time,
};
module_t *time_pref ;
proto_time = proto_register_protocol("Time Protocol", "TIME", "time");
proto_register_field_array(proto_time, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
time_pref = prefs_register_protocol(proto_time, NULL);
prefs_register_enum_preference(time_pref,
"display_time_type",
"Time Display",
"Time display type",
(gint *)&time_display_type,
time_display_types,
FALSE);
}
void
proto_reg_handoff_time(void)
{
dissector_handle_t time_handle;
time_handle = create_dissector_handle(dissect_time, proto_time);
dissector_add_uint_with_preference("udp.port", TIME_PORT, time_handle);
dissector_add_uint_with_preference("tcp.port", TIME_PORT, time_handle);
}
