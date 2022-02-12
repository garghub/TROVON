static void
dissect_dbcack (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *dbcack_item;
proto_tree *dbcack_tree = NULL;
guint16 transid;
tvbuff_t *next_tvb;
transid = tvb_get_ntohs (tvb, 0);
col_clear (pinfo->cinfo, COL_INFO);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Bonding Change Acknowledge: Tran-Id = %u", transid);
if (tree)
{
dbcack_item = proto_tree_add_protocol_format (tree, proto_docsis_dbcack,
tvb, 0, -1,
"Dynamic Bonding Change Acknowledge");
dbcack_tree = proto_item_add_subtree (dbcack_item, ett_docsis_dbcack);
proto_tree_add_item (dbcack_tree, hf_docsis_dbcack_tranid,
tvb, 0, 2, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining (tvb, 2);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dbcack_tree);
}
void
proto_register_docsis_dbcack (void)
{
static hf_register_info hf[] = {
{&hf_docsis_dbcack_tranid,
{"Transaction Id", "docsis_dbcack.tranid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_dbcack,
};
proto_docsis_dbcack = proto_register_protocol ("DOCSIS Dynamic Bonding Change Acknowledge",
"DOCSIS DBC-ACK",
"docsis_dbcack");
proto_register_field_array (proto_docsis_dbcack, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_dbcack", dissect_dbcack, proto_docsis_dbcack);
}
void
proto_reg_handoff_docsis_dbcack (void)
{
dissector_handle_t docsis_dbcack_handle;
docsis_dbcack_handle = find_dissector ("docsis_dbcack");
docsis_tlv_handle = find_dissector ("docsis_tlv");
dissector_add_uint ("docsis_mgmt", 0x26, docsis_dbcack_handle);
}
