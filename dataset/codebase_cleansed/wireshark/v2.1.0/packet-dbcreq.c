static int
dissect_dbcreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *dbcreq_item;
proto_tree *dbcreq_tree = NULL;
guint16 transid;
tvbuff_t *next_tvb;
transid = tvb_get_ntohs (tvb, 0);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Bonding Change Request: Tran-Id = %u", transid);
if (tree)
{
dbcreq_item = proto_tree_add_protocol_format (tree, proto_docsis_dbcreq,
tvb, 0, -1,
"Dynamic Bonding Change Request");
dbcreq_tree = proto_item_add_subtree (dbcreq_item, ett_docsis_dbcreq);
proto_tree_add_item (dbcreq_tree, hf_docsis_dbcreq_tranid,
tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item( dbcreq_tree, hf_docsis_dbcreq_number_of_fragments,
tvb, 2, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( dbcreq_tree, hf_docsis_dbcreq_fragment_sequence_number ,
tvb, 3, 1, ENC_BIG_ENDIAN );
}
next_tvb = tvb_new_subset_remaining (tvb, 4);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dbcreq_tree);
return tvb_captured_length(tvb);
}
void
proto_register_docsis_dbcreq (void)
{
static hf_register_info hf[] = {
{&hf_docsis_dbcreq_tranid,
{"Transaction Id", "docsis_dbcreq.tranid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dbcreq_number_of_fragments,
{"Number of Fragments", "docsis_dbcreq.number_of_fragments",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dbcreq_fragment_sequence_number,
{"Fragment Seq No", "docsis_dbcreq.fragment_sequence_number",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_dbcreq,
};
proto_docsis_dbcreq = proto_register_protocol ("DOCSIS Dynamic Bonding Change Request",
"DOCSIS DBC-REQ",
"docsis_dbcreq");
proto_register_field_array (proto_docsis_dbcreq, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_dbcreq", dissect_dbcreq, proto_docsis_dbcreq);
}
void
proto_reg_handoff_docsis_dbcreq (void)
{
dissector_handle_t docsis_dbcreq_handle;
docsis_dbcreq_handle = find_dissector ("docsis_dbcreq");
docsis_tlv_handle = find_dissector ("docsis_tlv");
dissector_add_uint ("docsis_mgmt", 0x24, docsis_dbcreq_handle);
}
