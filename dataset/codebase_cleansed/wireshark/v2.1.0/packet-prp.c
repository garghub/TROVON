static int
dissect_prp_redundancy_control_trailer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *prp_tree;
guint i;
guint length;
guint offset;
guint16 lan_id;
guint16 lsdu_size;
guint16 prp1_suffix;
guint trailer_start;
guint trailer_length;
trailer_start = 0;
trailer_length = 0;
length = tvb_reported_length(tvb);
if(length < 14)
return 0;
if(ETHERTYPE_VLAN == tvb_get_ntohs(tvb, 12))
{
offset = 18;
}
else
{
offset = 14;
}
if (!tree)
return tvb_captured_length(tvb);
for(i=length-4; i>=offset; i--)
{
lan_id = tvb_get_ntohs(tvb, (i+2)) >> 12;
lsdu_size = tvb_get_ntohs(tvb, (i+2)) & 0x0fff;
if(lsdu_size == i+4-offset && (lan_id == 0xa || lan_id == 0xb))
{
trailer_start = i;
trailer_length = 4;
break;
}
if (length > 64) {
break;
}
}
{
lan_id = tvb_get_ntohs(tvb, length-4) >> 12;
lsdu_size = tvb_get_ntohs(tvb, length-4) & 0x0fff;
prp1_suffix = tvb_get_ntohs(tvb, length-2);
if(prp1_suffix == ETHERTYPE_PRP && (lan_id == 0xa || lan_id == 0xb))
{
trailer_start = length-6;
trailer_length = 6;
}
}
if(trailer_length != 0)
{
ti = proto_tree_add_item(tree, proto_prp, tvb, trailer_start,
trailer_length, ENC_NA);
prp_tree = proto_item_add_subtree(ti, ett_prp_redundancy_control_trailer);
if (trailer_length == 4) {
ti = proto_tree_add_string(prp_tree, hf_prp_redundancy_control_trailer_version,
tvb, trailer_start, trailer_length, "PRP-0");
} else {
ti = proto_tree_add_string(prp_tree, hf_prp_redundancy_control_trailer_version,
tvb, trailer_start, trailer_length, "PRP-1");
}
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_item(prp_tree, hf_prp_redundancy_control_trailer_sequence_nr,
tvb, trailer_start, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(prp_tree, hf_prp_redundancy_control_trailer_lan,
tvb, trailer_start+2, 2, ENC_BIG_ENDIAN);
if (trailer_length == 4) {
proto_tree_add_item(prp_tree, hf_prp_redundancy_control_trailer_size,
tvb, trailer_start+2, 2, ENC_BIG_ENDIAN);
} else {
int lsdu_size_correct = length-offset;
if (lsdu_size == lsdu_size_correct) {
proto_tree_add_uint_format(prp_tree, hf_prp_redundancy_control_trailer_size,
tvb, trailer_start+2, 2, lsdu_size,
"LSDU size: %d [correct]", lsdu_size);
} else {
proto_tree_add_uint_format(prp_tree, hf_prp_redundancy_control_trailer_size,
tvb, trailer_start+2, 2, lsdu_size,
"LSDU size: %d [WRONG, should be %d]", lsdu_size, lsdu_size_correct);
}
proto_tree_add_item(prp_tree, hf_prp_redundancy_control_trailer_suffix,
tvb, trailer_start+4, 2, ENC_BIG_ENDIAN);
}
}
return tvb_captured_length(tvb);
}
void proto_register_prp(void)
{
static hf_register_info hf[] = {
{ &hf_prp_redundancy_control_trailer_sequence_nr,
{ "Sequence number", "prp.trailer.prp_sequence_nr",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_prp_redundancy_control_trailer_lan,
{ "LAN", "prp.trailer.prp_lan",
FT_UINT16, BASE_DEC, VALS(prp_lan_vals), 0xf000,
NULL, HFILL }
},
{ &hf_prp_redundancy_control_trailer_size,
{ "Size", "prp.trailer.prp_size",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_prp_redundancy_control_trailer_suffix,
{ "Suffix", "prp.trailer.prp1_suffix",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_prp_redundancy_control_trailer_version,
{ "PRP Version", "prp.trailer.version",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_prp_redundancy_control_trailer,
};
module_t *prp_module;
proto_prp = proto_register_protocol("Parallel Redundancy Protocol (IEC62439 Part 3)",
"PRP", "prp");
prp_module = prefs_register_protocol(proto_prp, proto_reg_handoff_prp);
prefs_register_bool_preference(prp_module, "enable", "Enable dissector",
"Enable this dissector (default is false)",
&prp_enable_dissector);
proto_register_field_array(proto_prp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_prp(void)
{
static gboolean prefs_initialized = FALSE;
if (!prefs_initialized) {
dissector_handle_t prp_redundancy_control_trailer_handle;
prp_redundancy_control_trailer_handle = create_dissector_handle(dissect_prp_redundancy_control_trailer, proto_prp);
register_postdissector(prp_redundancy_control_trailer_handle);
prefs_initialized = TRUE;
}
proto_set_decoding(proto_prp, prp_enable_dissector);
}
