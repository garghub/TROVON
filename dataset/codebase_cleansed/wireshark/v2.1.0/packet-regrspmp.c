static int
dissect_regrspmp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *regrspmp_tree = NULL;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_INFO, "REG-RSP-MP Message:");
if (tree)
{
it = proto_tree_add_protocol_format (tree, proto_docsis_regrspmp, tvb, 0, -1,"REG-RSP-MP Message");
regrspmp_tree = proto_item_add_subtree (it, ett_docsis_regrspmp);
proto_tree_add_item (regrspmp_tree, hf_docsis_regrspmp_sid, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (regrspmp_tree, hf_docsis_regrspmp_response, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (regrspmp_tree, hf_docsis_regrspmp_number_of_fragments, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (regrspmp_tree, hf_docsis_regrspmp_fragment_sequence_number, tvb, 4, 1, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining (tvb, 5);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, regrspmp_tree);
return tvb_captured_length(tvb);
}
void
proto_register_docsis_regrspmp (void)
{
static hf_register_info hf[] = {
{&hf_docsis_regrspmp_sid,
{"Sid", "docsis_regrspmp.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Reg-Rsp-Mp Sid", HFILL}
},
{&hf_docsis_regrspmp_response,
{"Response", "docsis_regrspmp.response",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Reg-Rsp-Mp Response", HFILL}
},
{&hf_docsis_regrspmp_number_of_fragments,
{"Number of Fragments", "docsis_regrspmp.number_of_fragments",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Reg-Rsp-Mp Number of Fragments", HFILL}
},
{&hf_docsis_regrspmp_fragment_sequence_number,
{"Fragment Sequence Number", "docsis_regrspmp.fragment_sequence_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Reg-Rsp-Mp Fragment Sequence Number", HFILL}
},
};
static gint *ett[] = {
&ett_docsis_regrspmp,
};
proto_docsis_regrspmp =
proto_register_protocol ("DOCSIS Registration Response Multipart",
"DOCSIS Reg-Rsp-Mp", "docsis_regrspmp");
proto_register_field_array (proto_docsis_regrspmp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_regrspmp", dissect_regrspmp, proto_docsis_regrspmp);
}
void
proto_reg_handoff_docsis_regrspmp (void)
{
dissector_handle_t docsis_regrspmp_handle;
docsis_tlv_handle = find_dissector ("docsis_tlv");
docsis_regrspmp_handle = find_dissector ("docsis_regrspmp");
dissector_add_uint ("docsis_mgmt", 45, docsis_regrspmp_handle);
}
