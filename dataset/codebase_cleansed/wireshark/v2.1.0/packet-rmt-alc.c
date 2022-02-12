static int
dissect_alc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint8 version;
lct_data_exchange_t lct;
fec_data_exchange_t fec;
int len;
guint offset = 0;
proto_item *ti;
proto_tree *alc_tree;
tvbuff_t *new_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ALC");
col_clear(pinfo->cinfo, COL_INFO);
version = hi_nibble(tvb_get_guint8(tvb, offset));
ti = proto_tree_add_item(tree, proto_rmt_alc, tvb, offset, -1, ENC_NA);
alc_tree = proto_item_add_subtree(ti, ett_main);
ti = proto_tree_add_uint(alc_tree, hf_version, tvb, offset, 1, version);
if (version != 1) {
expert_add_info(pinfo, ti, &ei_version1_only);
col_add_fstr(pinfo->cinfo, COL_INFO, "Version: %u (not supported)", version);
return 0;
}
new_tvb = tvb_new_subset_remaining(tvb,offset);
lct.ext_192 = g_ext_192;
lct.ext_193 = g_ext_193;
lct.codepoint = 0;
lct.is_flute = FALSE;
len = call_dissector_with_data(rmt_lct_handle, new_tvb, pinfo, alc_tree, &lct);
if (len < 0)
return offset;
offset += len;
if (g_codepoint_as_fec_encoding && tvb_reported_length(tvb) > offset)
{
fec.encoding_id = lct.codepoint;
new_tvb = tvb_new_subset_remaining(tvb,offset);
len = call_dissector_with_data(rmt_fec_handle, new_tvb, pinfo, alc_tree, &fec);
if (len < 0)
return offset;
offset += len;
}
if (tvb_reported_length(tvb) > offset){
if(lct.is_flute){
new_tvb = tvb_new_subset_remaining(tvb,offset);
call_dissector(xml_handle, new_tvb, pinfo, alc_tree);
}else{
proto_tree_add_item(alc_tree, hf_payload, tvb, offset, -1, ENC_NA);
}
}
return tvb_reported_length(tvb);
}
void proto_register_alc(void)
{
static hf_register_info hf_ptr[] = {
{ &hf_version,
{ "Version", "alc.version", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_payload,
{ "Payload", "alc.payload", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static gint *ett_ptr[] = {
&ett_main,
};
static ei_register_info ei[] = {
{ &ei_version1_only, { "alc.version1_only", PI_PROTOCOL, PI_WARN, "Sorry, this dissector supports ALC version 1 only", EXPFILL }},
};
module_t *module;
expert_module_t* expert_rmt_alc;
proto_rmt_alc = proto_register_protocol("Asynchronous Layered Coding", "ALC", "alc");
register_dissector("alc", dissect_alc, proto_rmt_alc);
proto_register_field_array(proto_rmt_alc, hf_ptr, array_length(hf_ptr));
proto_register_subtree_array(ett_ptr, array_length(ett_ptr));
expert_rmt_alc = expert_register_protocol(proto_rmt_alc);
expert_register_field_array(expert_rmt_alc, ei, array_length(ei));
module = prefs_register_protocol(proto_rmt_alc, proto_reg_handoff_alc);
prefs_register_obsolete_preference(module, "default.udp_port.enabled");
prefs_register_uint_preference(module,
"default.udp_port",
"UDP destination port",
"Specifies the UDP destination port for automatic dissection of ALC packets",
10, &g_default_udp_port);
prefs_register_bool_preference(module,
"lct.codepoint_as_fec_id",
"LCT Codepoint as FEC Encoding ID",
"Whether the LCT header Codepoint field should be considered the FEC Encoding ID of carried object",
&g_codepoint_as_fec_encoding);
prefs_register_enum_preference(module,
"lct.ext.192",
"LCT header extension 192",
"How to decode LCT header extension 192",
&g_ext_192,
enum_lct_ext_192,
FALSE);
prefs_register_enum_preference(module,
"lct.ext.193",
"LCT header extension 193",
"How to decode LCT header extension 193",
&g_ext_193,
enum_lct_ext_193,
FALSE);
}
void proto_reg_handoff_alc(void)
{
static dissector_handle_t handle;
static gboolean preferences_initialized = FALSE;
static guint old_udp_port = 0;
if (!preferences_initialized)
{
preferences_initialized = TRUE;
handle = create_dissector_handle(dissect_alc, proto_rmt_alc);
dissector_add_for_decode_as("udp.port", handle);
xml_handle = find_dissector_add_dependency("xml", proto_rmt_alc);
rmt_lct_handle = find_dissector_add_dependency("rmt-lct", proto_rmt_alc);
rmt_fec_handle = find_dissector_add_dependency("rmt-fec", proto_rmt_alc);
}
if(old_udp_port != 0 && old_udp_port != g_default_udp_port){
dissector_delete_uint("udp.port", old_udp_port, handle);
}
if(g_default_udp_port != 0 && old_udp_port != g_default_udp_port) {
dissector_add_uint("udp.port", g_default_udp_port, handle);
}
old_udp_port = g_default_udp_port;
}
