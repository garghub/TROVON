static int
dissect_cmctrlreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *cmctrlreq_tree = NULL;
guint16 transid;
tvbuff_t *next_tvb;
transid = tvb_get_ntohs (tvb, 0);
col_add_fstr (pinfo->cinfo, COL_INFO,
"CM Control Request: Transaction-Id = %u", transid);
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_cmctrlreq, tvb, 0, -1,
"CM Control Request");
cmctrlreq_tree = proto_item_add_subtree (it, ett_docsis_cmctrlreq);
proto_tree_add_item (cmctrlreq_tree, hf_docsis_cmctrlreq_tranid, tvb, 0, 2,
ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining (tvb, 2);
call_dissector (cmctrl_tlv_handle, next_tvb, pinfo, cmctrlreq_tree);
return tvb_captured_length(tvb);
}
void
proto_register_docsis_cmctrlreq (void)
{
static hf_register_info hf[] = {
{&hf_docsis_cmctrlreq_tranid,
{"Transaction Id", "docsis_cmctrlreq.tranid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_cmctrlreq,
};
proto_docsis_cmctrlreq =
proto_register_protocol ("DOCSIS CM Control Request",
"DOCSIS CM-CTRL-REQ", "docsis_cmctrlreq");
proto_register_field_array (proto_docsis_cmctrlreq, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_cmctrlreq", dissect_cmctrlreq, proto_docsis_cmctrlreq);
}
void
proto_reg_handoff_docsis_cmctrlreq (void)
{
dissector_handle_t docsis_cmctrlreq_handle;
docsis_cmctrlreq_handle = find_dissector ("docsis_cmctrlreq");
cmctrl_tlv_handle = find_dissector ("cmctrl_tlv");
dissector_add_uint ("docsis_mgmt", 0x2A, docsis_cmctrlreq_handle);
}
