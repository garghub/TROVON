static int
dissect_regrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *regrsp_tree = NULL;
guint16 sid;
guint8 response;
tvbuff_t *next_tvb;
sid = tvb_get_ntohs (tvb, 0);
response = tvb_get_guint8 (tvb, 2);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Registration Response SID = %u (%s)", sid,
val_to_str (response, docsis_conf_code, "%d"));
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_regrsp, tvb, 0, -1,
"Registration Response");
regrsp_tree = proto_item_add_subtree (it, ett_docsis_regrsp);
proto_tree_add_item (regrsp_tree, hf_docsis_regrsp_sid, tvb, 0, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item (regrsp_tree, hf_docsis_regrsp_response, tvb, 2, 1,
ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining (tvb, 3);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, regrsp_tree);
return tvb_captured_length(tvb);
}
void
proto_register_docsis_regrsp (void)
{
static hf_register_info hf[] = {
{&hf_docsis_regrsp_sid,
{"Service Identifier", "docsis_regrsp.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_regrsp_response,
{"Response Code", "docsis_regrsp.respnse",
FT_UINT8, BASE_DEC, VALS (docsis_conf_code), 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_regrsp,
};
proto_docsis_regrsp =
proto_register_protocol ("DOCSIS Registration Responses", "DOCSIS REG-RSP",
"docsis_regrsp");
proto_register_field_array (proto_docsis_regrsp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_regrsp", dissect_regrsp, proto_docsis_regrsp);
}
void
proto_reg_handoff_docsis_regrsp (void)
{
dissector_handle_t docsis_regrsp_handle;
docsis_regrsp_handle = find_dissector ("docsis_regrsp");
docsis_tlv_handle = find_dissector ("docsis_tlv");
dissector_add_uint ("docsis_mgmt", 0x07, docsis_regrsp_handle);
}
