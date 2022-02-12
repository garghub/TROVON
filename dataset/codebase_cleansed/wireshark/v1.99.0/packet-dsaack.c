static void
dissect_dsaack (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *it;
proto_tree *dsaack_tree = NULL;
guint16 transid;
guint8 response;
tvbuff_t *next_tvb;
transid = tvb_get_ntohs (tvb, 0);
response = tvb_get_guint8 (tvb, 2);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Service Add Ack ID = %u (%s)", transid,
val_to_str (response, docsis_conf_code, "%d"));
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_dsaack, tvb, 0, -1,
"DSA Acknowledge");
dsaack_tree = proto_item_add_subtree (it, ett_docsis_dsaack);
proto_tree_add_item (dsaack_tree, hf_docsis_dsaack_tranid, tvb, 0, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item (dsaack_tree, hf_docsis_dsaack_response, tvb, 2, 1,
ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining (tvb, 3);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dsaack_tree);
}
void
proto_register_docsis_dsaack (void)
{
static hf_register_info hf[] = {
{&hf_docsis_dsaack_tranid,
{"Transaction Id", "docsis_dsaack.tranid",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Service Identifier", HFILL}
},
{&hf_docsis_dsaack_response,
{"Confirmation Code", "docsis_dsaack.confcode",
FT_UINT8, BASE_DEC, VALS (docsis_conf_code), 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_dsaack,
};
proto_docsis_dsaack =
proto_register_protocol ("DOCSIS Dynamic Service Addition Acknowledge",
"DOCSIS DSA-ACK", "docsis_dsaack");
proto_register_field_array (proto_docsis_dsaack, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_dsaack", dissect_dsaack, proto_docsis_dsaack);
}
void
proto_reg_handoff_docsis_dsaack (void)
{
dissector_handle_t docsis_dsaack_handle;
docsis_dsaack_handle = find_dissector ("docsis_dsaack");
docsis_tlv_handle = find_dissector ("docsis_tlv");
dissector_add_uint ("docsis_mgmt", 0x11, docsis_dsaack_handle);
}
