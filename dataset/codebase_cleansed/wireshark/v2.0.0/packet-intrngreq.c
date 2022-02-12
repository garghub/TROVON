static void
dissect_intrngreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *intrngreq_item;
proto_tree *intrngreq_tree;
guint16 sid;
sid = tvb_get_ntohs (tvb, 0);
col_add_fstr (pinfo->cinfo, COL_INFO, "Ranging Request: SID = %u",sid);
if (tree)
{
intrngreq_item =
proto_tree_add_protocol_format (tree, proto_docsis_intrngreq, tvb, 0,
tvb_captured_length(tvb),
"Initial Ranging Request");
intrngreq_tree = proto_item_add_subtree (intrngreq_item, ett_docsis_intrngreq);
proto_tree_add_item (intrngreq_tree, hf_docsis_intrngreq_sid, tvb, 0, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item (intrngreq_tree, hf_docsis_intrngreq_down_chid, tvb, 2, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (intrngreq_tree, hf_docsis_intrngreq_up_chid, tvb, 3,
1, ENC_BIG_ENDIAN);
}
}
void
proto_register_docsis_intrngreq (void)
{
static hf_register_info hf[] = {
{&hf_docsis_intrngreq_sid,
{"Service Identifier", "docsis_intrngreq.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_intrngreq_down_chid,
{"Downstream Channel ID", "docsis_intrngreq.downchid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_intrngreq_up_chid,
{"Upstream Channel ID", "docsis_intrngreq.upchid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_intrngreq,
};
proto_docsis_intrngreq = proto_register_protocol ("DOCSIS Initial Ranging Message",
"DOCSIS INT-RNG-REQ",
"docsis_intrngreq");
proto_register_field_array (proto_docsis_intrngreq, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_intrngreq", dissect_intrngreq, proto_docsis_intrngreq);
}
void
proto_reg_handoff_docsis_intrngreq (void)
{
dissector_handle_t docsis_intrngreq_handle;
docsis_intrngreq_handle = find_dissector ("docsis_intrngreq");
dissector_add_uint ("docsis_mgmt", 0x1E, docsis_intrngreq_handle);
}
