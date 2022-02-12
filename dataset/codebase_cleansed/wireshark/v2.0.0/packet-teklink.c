static int dissect_teklink_tlaframeopen_call(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_string(tvb, tree, hf_teklink_unknown_string, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_teklink_unknown_string, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_teklink_unknown_string, offset, NULL);
return offset;
}
static int dissect_teklink_tlaframeclose_call(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
return dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, 0);
}
static int dissect_teklink_tlaframeclose_reply(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
return dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, 0);
}
static int dissect_teklink_tlaframeopen_reply(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
return offset;
}
static int dissect_teklink_get_software_version_reply(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_string(tvb, tree, hf_teklink_unknown_string, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_teklink_unknown_string, offset, NULL);
return offset;
}
static int dissect_teklink_call65_call(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_cmd, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
return offset;
}
static int dissect_teklink_call65_reply(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
return dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, 0);
}
static int dissect_teklink_info_reply(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_locked, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_tla_type, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_string(tvb, tree, hf_teklink_unknown_string, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_teklink_location, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_teklink_user, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_teklink_host, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_teklink_unknown_string, offset, NULL);
return offset;
}
static int dissect_teklink_info_call(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
return offset;
}
static int dissect_teklink_vtc_ident(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
return offset;
}
static int dissect_teklink_vtc_sigstatall(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
return offset;
}
static int dissect_teklink_vtc_outen(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
int offset = 0;
guint32 sig = tvb_get_ntohl(tvb, offset);
guint32 sigon = tvb_get_ntohl(tvb, offset + 4);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_dstnames, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_sigen, offset);
col_append_fstr(pinfo->cinfo, COL_INFO," %s, %s ",
val_to_str(sig, teklink_vtc_dstnames, "Unknown destination %d"),
sigon ? "VTC_OUT_FORCE_ON" : "VTC_OUT_FORCE_OFF");
return offset;
}
static int dissect_teklink_vtc_map(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
guint32 src, dst;
int offset = 0;
src = tvb_get_ntohl(tvb, offset);
dst = tvb_get_ntohl(tvb, offset + 4);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_srcnames, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_dstnames, offset);
col_append_fstr(pinfo->cinfo, COL_INFO," %s, %s ",
val_to_str(src, teklink_vtc_srcnames, "Unknown source %d"),
val_to_str(dst, teklink_vtc_dstnames, "Unknown destination %d"));
return offset;
}
static int dissect_teklink_vtc_clk(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
guint32 sig, clksource, clkedge, clkmode;
int offset = 0;
sig = tvb_get_ntohl(tvb, offset);
clksource = tvb_get_ntohl(tvb, offset + 4);
clkedge = tvb_get_ntohl(tvb, offset + 8);
clkmode = tvb_get_ntohl(tvb, offset + 12);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_dstnames, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_clksource, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_clkedge, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_clkmode, offset);
col_append_fstr(pinfo->cinfo, COL_INFO," %s, %s, %s, %s",
val_to_str(sig, teklink_vtc_dstnames, "Unknown destination %d"),
val_to_str(clksource, teklink_vtc_clksource, "Unknown clocksource %d"),
val_to_str(clkedge, teklink_vtc_clkedge, "Unknown edge setting %d"),
val_to_str(clkmode, teklink_vtc_clkmode, "Unknown mode setting %d"));
return offset;
}
static int dissect_teklink_vtc_mode(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
guint32 sig, edge, mode;
int offset = 0;
sig = tvb_get_ntohl(tvb, offset);
edge = tvb_get_ntohl(tvb, offset + 4);
mode = tvb_get_ntohl(tvb, offset + 12);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_dstnames, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_edge, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_mode, offset);
col_append_fstr(pinfo->cinfo, COL_INFO," %s, %s, %s",
val_to_str(sig, teklink_vtc_dstnames, "Unknown destination %d"),
val_to_str(edge, teklink_vtc_edge, "Unknown edge setting %d"),
val_to_str(mode, teklink_vtc_modes, "Unknown mode setting %d"));
return offset;
}
static int dissect_teklink_vtc_outsetup(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
guint32 sig, en, pol, feedback;
int offset = 0;
sig = tvb_get_ntohl(tvb, offset);
en = tvb_get_ntohl(tvb, offset + 4);
pol = tvb_get_ntohl(tvb, offset + 8);
feedback = tvb_get_ntohl(tvb, offset + 12);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_dstnames, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_sigen, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_sigpol, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_sigfeedback, offset);
col_append_fstr(pinfo->cinfo, COL_INFO," %s, %s, %s, %s",
val_to_str(sig, teklink_vtc_dstnames, "Unknown destination %d"),
val_to_str(pol, teklink_vtc_sigpol, "Unknown signal polarity %d"),
val_to_str(en, teklink_vtc_sigen, "Unknown signal enable %d"),
val_to_str(feedback, teklink_vtc_sigfeedback, "Unknown signal feedback setting %d"));
return offset;
}
static int dissect_teklink_vtc_res(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
int offset = 0;
guint32 sig = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_vtc_dstnames, offset);
col_append_fstr(pinfo->cinfo, COL_INFO," %s",
val_to_str(sig, teklink_vtc_dstnames, "Unknown destination %d"));
return offset;
}
static int dissect_teklink_vtl_spinbits(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, offset);
return offset;
}
static int dissect_teklink_vtl_zmode(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
return dissect_rpc_uint32(tvb, tree, hf_teklink_unknown_long, 0);
}
void
proto_register_teklink(void)
{
static hf_register_info hf_core[] = {
{ &hf_teklink_procedure, {
"Procedure", "teklink.procedure", FT_UINT8, BASE_DEC,
VALS(teklink_proc_vals), 0, NULL, HFILL }},
{ &hf_teklink_unknown_long, {
"Unknown long", "teklink.long", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_teklink_unknown_string, {
"Unknown String", "teklink.string", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_teklink_cmd, {
"Command", "teklink.command", FT_UINT32, BASE_DEC,
VALS(teklink_cmd_vals), 0, NULL, HFILL }},
{ &hf_teklink_tla_type, {
"TLA Type", "teklink.tla_type", FT_UINT32, BASE_DEC,
VALS(teklink_tla_types), 0, NULL, HFILL }},
{ &hf_teklink_host, {
"Host", "teklink.host", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_teklink_user, {
"User", "teklink.user", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_teklink_location, {
"Location", "teklink.location", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_teklink_locked, {
"Locked", "teklink.locked", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_teklink_vtc_dstnames, {
"Destination signal", "teklink.signal.destination", FT_UINT32, BASE_HEX,
VALS(teklink_vtc_dstnames), 0, NULL, HFILL }},
{ &hf_teklink_vtc_srcnames, {
"Source signal", "teklink.signal.source", FT_UINT32, BASE_HEX,
VALS(teklink_vtc_srcnames), 0, NULL, HFILL }},
{ &hf_teklink_vtc_sigen, {
"Signal Enable", "teklink.signal.enable", FT_UINT32, BASE_HEX,
VALS(teklink_vtc_sigen), 0, NULL, HFILL }},
{ &hf_teklink_vtc_sigpol, {
"Signal Polarity", "teklink.signal.polarity", FT_UINT32, BASE_HEX,
VALS(teklink_vtc_sigpol), 0, NULL, HFILL }},
{ &hf_teklink_vtc_clkmode, {
"Clock Mode", "teklink.clock.polarity", FT_UINT32, BASE_HEX,
VALS(teklink_vtc_clkmode), 0, NULL, HFILL }},
{ &hf_teklink_vtc_clkedge, {
"Clock Edge", "teklink.clock.polarity", FT_UINT32, BASE_HEX,
VALS(teklink_vtc_clkedge), 0, NULL, HFILL }},
{ &hf_teklink_vtc_clksource, {
"Clock Source", "teklink.clock.source", FT_UINT32, BASE_HEX,
VALS(teklink_vtc_clksource), 0, NULL, HFILL }},
{ &hf_teklink_vtc_mode, {
"Signal Mode", "teklink.signal.mode", FT_UINT32, BASE_HEX,
VALS(teklink_vtc_modes), 0, NULL, HFILL }},
{ &hf_teklink_vtc_edge, {
"Signal Edge", "teklink.signal.edge", FT_UINT32, BASE_HEX,
VALS(teklink_vtc_edge), 0, NULL, HFILL }},
{ &hf_teklink_vtc_sigfeedback, {
"Signal Feedbmode", "teklink.signal.feedback", FT_UINT32, BASE_HEX,
VALS(teklink_vtc_sigfeedback), 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_teklink
};
proto_teklink = proto_register_protocol("TEKLINK", "TEKLINK", "teklink");
proto_register_field_array(proto_teklink, hf_core, array_length(hf_core));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_teklink(void)
{
rpc_init_prog(proto_teklink, PROGRAM_TEKLINK, ett_teklink,
G_N_ELEMENTS(teklink_vers_info), teklink_vers_info);
}
