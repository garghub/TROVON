static void
dissect_llt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti=NULL;
proto_tree *llt_tree=NULL;
guint8 message_type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LLT");
message_type = tvb_get_guint8(tvb, 3);
if(check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "Message type: %s", val_to_str(message_type, message_type_vs, "Unknown (0x%02x)"));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_llt, tvb, 0, -1, ENC_NA);
llt_tree = proto_item_add_subtree(ti, ett_llt);
}
proto_tree_add_item(llt_tree, hf_llt_cluster_num, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(llt_tree, hf_llt_message_type, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(llt_tree, hf_llt_node_id, tvb, 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(llt_tree, hf_llt_sequence_num, tvb, 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(llt_tree, hf_llt_message_time, tvb, 40, 4, ENC_BIG_ENDIAN);
}
void
proto_register_llt(void)
{
module_t *llt_module;
static hf_register_info hf[] = {
{ &hf_llt_cluster_num, { "Cluster number", "llt.cluster_num",
FT_UINT8, BASE_DEC, NULL, 0,
"Cluster number that this node belongs to", HFILL } },
{ &hf_llt_message_type, { "Message type", "llt.message_type",
FT_UINT8, BASE_HEX, VALS(message_type_vs), 0,
"Type of LLT message contained in this frame", HFILL } },
{ &hf_llt_node_id, { "Node ID", "llt.node_id",
FT_UINT8, BASE_DEC, NULL, 0,
"Number identifying this node within the cluster", HFILL } },
{ &hf_llt_sequence_num, { "Sequence number", "llt.sequence_num",
FT_UINT32, BASE_DEC, NULL, 0,
"Sequence number of this frame", HFILL } },
{ &hf_llt_message_time, { "Message time", "llt.message_time",
FT_UINT32, BASE_DEC, NULL, 0,
"Number of ticks since this node was last rebooted", HFILL } }
};
static gint *ett[] = {
&ett_llt,
};
proto_llt = proto_register_protocol("Veritas Low Latency Transport (LLT)", "LLT", "llt");
proto_register_field_array(proto_llt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
llt_module = prefs_register_protocol(proto_llt, proto_reg_handoff_llt);
prefs_register_uint_preference(llt_module, "alternate_ethertype", "Alternate ethertype value (in hex)",
"Dissect this ethertype as LLT traffic in addition to the default, 0xCAFE.",
16, &preference_alternate_ethertype);
}
void
proto_reg_handoff_llt(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t llt_handle;
static guint preference_alternate_ethertype_last;
if (!initialized) {
llt_handle = create_dissector_handle(dissect_llt, proto_llt);
dissector_add_uint("ethertype", ETHERTYPE_LLT, llt_handle);
initialized = TRUE;
} else {
if (preference_alternate_ethertype_last != 0x0) {
dissector_delete_uint("ethertype", preference_alternate_ethertype_last, llt_handle);
}
}
preference_alternate_ethertype_last = preference_alternate_ethertype;
if (preference_alternate_ethertype != 0x0) {
dissector_add_uint("ethertype", preference_alternate_ethertype, llt_handle);
}
}
