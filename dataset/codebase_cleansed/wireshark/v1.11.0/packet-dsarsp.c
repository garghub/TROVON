static void
dissect_dsarsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *it;
proto_tree *dsarsp_tree = NULL;
guint16 transid;
guint8 response;
tvbuff_t *next_tvb;
transid = tvb_get_ntohs (tvb, 0);
response = tvb_get_guint8 (tvb, 2);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Service Add Response ID = %u (%s)", transid,
val_to_str (response, docsis_conf_code, "%d"));
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_dsarsp, tvb, 0, -1,
"DSA Response");
dsarsp_tree = proto_item_add_subtree (it, ett_docsis_dsarsp);
proto_tree_add_item (dsarsp_tree, hf_docsis_dsarsp_tranid, tvb, 0, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item (dsarsp_tree, hf_docsis_dsarsp_response, tvb, 2, 1,
ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining (tvb, 3);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dsarsp_tree);
}
void
proto_register_docsis_dsarsp (void)
{
static hf_register_info hf[] = {
{&hf_docsis_dsarsp_tranid,
{"Transaction Id", "docsis_dsarsp.tranid",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Service Identifier", HFILL}
},
{&hf_docsis_dsarsp_response,
{"Confirmation Code", "docsis_dsarsp.confcode",
FT_UINT8, BASE_DEC, VALS (docsis_conf_code), 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_dsarsp,
};
proto_docsis_dsarsp =
proto_register_protocol ("DOCSIS Dynamic Service Addition Response",
"DOCSIS DSA-RSP", "docsis_dsarsp");
proto_register_field_array (proto_docsis_dsarsp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_dsarsp", dissect_dsarsp, proto_docsis_dsarsp);
}
void
proto_reg_handoff_docsis_dsarsp (void)
{
dissector_handle_t docsis_dsarsp_handle;
docsis_dsarsp_handle = find_dissector ("docsis_dsarsp");
docsis_tlv_handle = find_dissector ("docsis_tlv");
dissector_add_uint ("docsis_mgmt", 0x10, docsis_dsarsp_handle);
}
