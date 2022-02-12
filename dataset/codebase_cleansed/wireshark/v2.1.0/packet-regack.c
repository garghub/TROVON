static int
dissect_regack (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *regack_tree = NULL;
guint16 sid;
guint8 response;
tvbuff_t *next_tvb;
sid = tvb_get_ntohs (tvb, 0);
response = tvb_get_guint8 (tvb, 2);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Registration Acknowledge SID = %u (%s)", sid,
val_to_str (response, docsis_conf_code, "%d"));
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_regack, tvb, 0, -1,
"Registration Acknowledge");
regack_tree = proto_item_add_subtree (it, ett_docsis_regack);
proto_tree_add_item (regack_tree, hf_docsis_regack_sid, tvb, 0, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item (regack_tree, hf_docsis_regack_response, tvb, 2, 1,
ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining (tvb, 3);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, regack_tree);
return tvb_captured_length(tvb);
}
void
proto_register_docsis_regack (void)
{
static hf_register_info hf[] = {
{&hf_docsis_regack_sid,
{"Service Identifier", "docsis_regack.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_regack_response,
{"Response Code", "docsis_regack.respnse",
FT_UINT8, BASE_DEC, VALS (docsis_conf_code), 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_regack,
};
proto_docsis_regack =
proto_register_protocol ("DOCSIS Registration Acknowledge",
"DOCSIS REG-ACK", "docsis_regack");
proto_register_field_array (proto_docsis_regack, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_regack", dissect_regack, proto_docsis_regack);
}
void
proto_reg_handoff_docsis_regack (void)
{
dissector_handle_t docsis_regack_handle;
docsis_regack_handle = find_dissector ("docsis_regack");
docsis_tlv_handle = find_dissector ("docsis_tlv");
dissector_add_uint ("docsis_mgmt", 0x0e, docsis_regack_handle);
}
