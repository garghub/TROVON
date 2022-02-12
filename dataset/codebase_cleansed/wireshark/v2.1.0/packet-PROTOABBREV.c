static int
dissect_PROTOABBREV(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti, *expert_ti;
proto_tree *PROTOABBREV_tree;
guint offset = 0;
int len = 0;
if (tvb_reported_length(tvb) < PROTOABBREV_MIN_LENGTH)
return 0;
if (tvb_captured_length(tvb) < MAX_NEEDED_FOR_HEURISTICS)
return 0;
if ( TEST_HEURISTICS_FAIL )
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PROTOABBREV");
#if 0
col_clear(pinfo->cinfo, COL_INFO);
#endif
col_set_str(pinfo->cinfo, COL_INFO, "XXX Request");
ti = proto_tree_add_item(tree, proto_PROTOABBREV, tvb, 0, -1, ENC_NA);
PROTOABBREV_tree = proto_item_add_subtree(ti, ett_PROTOABBREV);
expert_ti = proto_tree_add_item(PROTOABBREV_tree, hf_PROTOABBREV_FIELDABBREV, tvb,
offset, len, ENC_xxx);
offset += len;
if ( TEST_EXPERT_condition )
expert_add_info(pinfo, expert_ti, &ei_PROTOABBREV_EXPERTABBREV);
return tvb_captured_length(tvb);
}
void
proto_register_PROTOABBREV(void)
{
module_t *PROTOABBREV_module;
expert_module_t *expert_PROTOABBREV;
static hf_register_info hf[] = {
{ &hf_PROTOABBREV_FIELDABBREV,
{ "FIELDNAME", "PROTOABBREV.FIELDABBREV",
FT_FIELDTYPE, FIELDDISPLAY, FIELDCONVERT, BITMASK,
"FIELDDESCR", HFILL }
}
};
static gint *ett[] = {
&ett_PROTOABBREV
};
static ei_register_info ei[] = {
{ &ei_PROTOABBREV_EXPERTABBREV,
{ "PROTOABBREV.EXPERTABBREV", PI_SEVERITY, PI_GROUP,
"EXPERTDESCR", EXPFILL }
}
};
proto_PROTOABBREV = proto_register_protocol("PROTONAME",
"PROTOSHORTNAME", "PROTOABBREV");
proto_register_field_array(proto_PROTOABBREV, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_PROTOABBREV = expert_register_protocol(proto_PROTOABBREV);
expert_register_field_array(expert_PROTOABBREV, ei, array_length(ei));
PROTOABBREV_module = prefs_register_protocol(proto_PROTOABBREV,
proto_reg_handoff_PROTOABBREV);
PROTOABBREV_module = prefs_register_protocol_subtree(const char *subtree,
proto_PROTOABBREV, proto_reg_handoff_PROTOABBREV);
prefs_register_bool_preference(PROTOABBREV_module, "show_hex",
"Display numbers in Hex",
"Enable to display numerical values in hexadecimal.",
&pref_hex);
prefs_register_uint_preference(PROTOABBREV_module, "tcp.port", "PROTOABBREV TCP Port",
" PROTOABBREV TCP port if other than the default",
10, &tcp_port_pref);
}
void
proto_reg_handoff_PROTOABBREV(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t PROTOABBREV_handle;
static int current_port;
if (!initialized) {
PROTOABBREV_handle = create_dissector_handle(dissect_PROTOABBREV,
proto_PROTOABBREV);
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", current_port, PROTOABBREV_handle);
}
current_port = tcp_port_pref;
dissector_add_uint("tcp.port", current_port, PROTOABBREV_handle);
}
