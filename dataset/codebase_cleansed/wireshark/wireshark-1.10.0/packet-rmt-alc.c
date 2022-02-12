static void alc_prefs_set_default(struct _alc_prefs *alc_prefs)
{
alc_prefs->use_default_udp_port = FALSE;
alc_prefs->default_udp_port = 4001;
lct_prefs_set_default(&alc_prefs->lct);
fec_prefs_set_default(&alc_prefs->fec);
}
static void alc_prefs_register(struct _alc_prefs *alc_prefs, module_t *module)
{
prefs_register_bool_preference(module,
"default.udp_port.enabled",
"Use default UDP port",
"Whether that payload of UDP packets with a specific destination port should be automatically dissected as ALC packets",
&alc_prefs->use_default_udp_port);
prefs_register_uint_preference(module,
"default.udp_port",
"Default UDP destination port",
"Specifies the UDP destination port for automatic dissection of ALC packets",
10, &alc_prefs->default_udp_port);
lct_prefs_register(&alc_prefs->lct, module);
fec_prefs_register(&alc_prefs->fec, module);
}
static void alc_prefs_save(struct _alc_prefs *p, struct _alc_prefs *p_old)
{
*p_old = *p;
}
static void dissect_alc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
struct _alc alc;
guint offset;
proto_item *ti;
proto_tree *alc_tree;
tvbuff_t *new_tvb;
gboolean is_flute = FALSE;
offset = 0;
memset(&alc, 0, sizeof(struct _alc));
pinfo->current_proto = "ALC";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ALC");
col_clear(pinfo->cinfo, COL_INFO);
alc.version = hi_nibble(tvb_get_guint8(tvb, offset));
if (tree)
{
ti = proto_tree_add_item(tree, proto, tvb, offset, -1, ENC_NA);
alc_tree = proto_item_add_subtree(ti, ett.main);
proto_tree_add_uint(alc_tree, hf.version, tvb, offset, 1, alc.version);
} else
alc_tree = NULL;
if (alc.version == 1) {
struct _lct_ptr l;
struct _fec_ptr f;
l.lct = &alc.lct;
l.hf = &hf.lct;
l.ett = &ett.lct;
l.prefs = &preferences.lct;
f.fec = &alc.fec;
f.hf = &hf.fec;
f.ett = &ett.fec;
f.prefs = &preferences.fec;
is_flute = lct_dissector(l, f, tvb, alc_tree, &offset);
if (alc.fec.encoding_id_present && tvb_length(tvb) > offset)
fec_dissector(f, tvb, alc_tree, &offset);
if (tvb_length(tvb) > offset){
if(is_flute){
new_tvb = tvb_new_subset_remaining(tvb,offset);
call_dissector(xml_handle, new_tvb, pinfo, alc_tree);
}else{
proto_tree_add_none_format(alc_tree, hf.payload, tvb, offset, -1, "Payload (%u bytes)", tvb_length(tvb) - offset);
}
}
if (check_col(pinfo->cinfo, COL_INFO))
{
lct_info_column(&alc.lct, pinfo);
fec_info_column(&alc.fec, pinfo);
}
lct_dissector_free(&alc.lct);
fec_dissector_free(&alc.fec);
} else {
if (tree)
proto_tree_add_text(alc_tree, tvb, 0, -1, "Sorry, this dissector supports ALC version 1 only");
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Version: %u (not supported)", alc.version);
}
}
void proto_reg_handoff_alc(void)
{
static dissector_handle_t handle;
static gboolean preferences_initialized = FALSE;
static struct _alc_prefs preferences_old;
if (!preferences_initialized)
{
preferences_initialized = TRUE;
handle = create_dissector_handle(dissect_alc, proto);
dissector_add_handle("udp.port", handle);
xml_handle = find_dissector("xml");
} else {
if (preferences_old.use_default_udp_port)
dissector_delete_uint("udp.port", preferences_old.default_udp_port, handle);
}
if (preferences.use_default_udp_port)
dissector_add_uint("udp.port", preferences.default_udp_port, handle);
alc_prefs_save(&preferences, &preferences_old);
}
void proto_register_alc(void)
{
static hf_register_info hf_ptr[] = {
{ &hf.version,
{ "Version", "alc.version", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
LCT_FIELD_ARRAY(hf.lct, "alc"),
FEC_FIELD_ARRAY(hf.fec, "alc"),
{ &hf.payload,
{ "Payload", "alc.payload", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static gint *ett_ptr[] = {
&ett.main,
LCT_SUBTREE_ARRAY(ett.lct),
FEC_SUBTREE_ARRAY(ett.fec)
};
module_t *module;
memset(&hf, 0xff, sizeof(struct _alc_hf));
memset(&ett, 0xff, sizeof(struct _alc_ett));
proto = proto_register_protocol("Asynchronous Layered Coding", "ALC", "alc");
proto_register_field_array(proto, hf_ptr, array_length(hf_ptr));
proto_register_subtree_array(ett_ptr, array_length(ett_ptr));
alc_prefs_set_default(&preferences);
module = prefs_register_protocol(proto, proto_reg_handoff_alc);
alc_prefs_register(&preferences, module);
register_dissector("alc", dissect_alc, proto);
}
