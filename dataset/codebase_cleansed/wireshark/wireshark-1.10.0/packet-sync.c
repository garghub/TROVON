static void
dissect_sync (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *it;
proto_tree *sync_tree;
col_set_str(pinfo->cinfo, COL_INFO, "Sync Message:");
if (tree)
{
it = proto_tree_add_protocol_format (tree, proto_docsis_sync, tvb, 0, -1,"SYNC Message");
sync_tree = proto_item_add_subtree (it, ett_docsis_sync);
proto_tree_add_item (sync_tree, hf_docsis_sync_cmts_timestamp, tvb, 0, 4,
ENC_BIG_ENDIAN);
}
}
void
proto_register_docsis_sync (void)
{
static hf_register_info hf[] = {
{&hf_docsis_sync_cmts_timestamp,
{"CMTS Timestamp", "docsis_sync.cmts_timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Sync CMTS Timestamp", HFILL}
},
};
static gint *ett[] = {
&ett_docsis_sync,
};
proto_docsis_sync =
proto_register_protocol ("DOCSIS Synchronisation Message",
"DOCSIS Sync", "docsis_sync");
proto_register_field_array (proto_docsis_sync, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_sync", dissect_sync, proto_docsis_sync);
}
void
proto_reg_handoff_docsis_sync (void)
{
dissector_handle_t docsis_sync_handle;
docsis_sync_handle = find_dissector ("docsis_sync");
dissector_add_uint ("docsis_mgmt", 1, docsis_sync_handle);
}
