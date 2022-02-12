static void
dissect_rngreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *it;
proto_tree *rngreq_tree;
guint16 sid;
sid = tvb_get_ntohs (tvb, 0);
if (sid > 0)
col_add_fstr (pinfo->cinfo, COL_INFO, "Ranging Request: SID = %u",
sid);
else
col_set_str(pinfo->cinfo, COL_INFO, "Initial Ranging Request SID = 0");
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_rngreq, tvb, 0, -1,
"Ranging Request");
rngreq_tree = proto_item_add_subtree (it, ett_docsis_rngreq);
proto_tree_add_item (rngreq_tree, hf_docsis_rngreq_sid, tvb, 0, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item (rngreq_tree, hf_docsis_rngreq_down_chid, tvb, 2, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (rngreq_tree, hf_docsis_rngreq_pend_compl, tvb, 3,
1, ENC_BIG_ENDIAN);
}
}
void
proto_register_docsis_rngreq (void)
{
static hf_register_info hf[] = {
{&hf_docsis_rngreq_sid,
{"Service Identifier", "docsis_rngreq.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_rngreq_down_chid,
{"Downstream Channel ID", "docsis_rngreq.downchid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_rngreq_pend_compl,
{"Pending Till Complete", "docsis_rngreq.pendcomp",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Upstream Channel ID", HFILL}
},
};
static gint *ett[] = {
&ett_docsis_rngreq,
};
proto_docsis_rngreq = proto_register_protocol ("DOCSIS Range Request Message",
"DOCSIS RNG-REQ",
"docsis_rngreq");
proto_register_field_array (proto_docsis_rngreq, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_rngreq", dissect_rngreq, proto_docsis_rngreq);
}
void
proto_reg_handoff_docsis_rngreq (void)
{
dissector_handle_t docsis_rngreq_handle;
docsis_rngreq_handle = find_dissector ("docsis_rngreq");
dissector_add_uint ("docsis_mgmt", 0x04, docsis_rngreq_handle);
}
