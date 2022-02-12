static void
dissect_dpvreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *it;
proto_tree *dpvreq_tree = NULL;
guint16 transid;
guint8 dschan;
transid = tvb_get_ntohs (tvb, 0);
dschan = tvb_get_guint8 (tvb, 2);
col_clear (pinfo->cinfo, COL_INFO);
col_add_fstr (pinfo->cinfo, COL_INFO,
"DOCSIS Path Verify Request: Transaction-Id = %u DS-Ch %d",
transid, dschan);
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_dpvreq, tvb, 0, -1,
"DPV Request");
dpvreq_tree = proto_item_add_subtree (it, ett_docsis_dpvreq);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpvreq_tranid, tvb,
0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpvreq_dschan, tvb,
2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpvreq_flags, tvb,
3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpvreq_us_sf, tvb,
4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpvreq_n, tvb,
8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpvreq_start, tvb,
10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpvreq_end, tvb,
11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpvreq_ts_start, tvb,
12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpvreq_ts_end, tvb,
16, 4, ENC_BIG_ENDIAN);
}
}
void
proto_register_docsis_dpvreq (void)
{
static hf_register_info hf[] = {
{&hf_docsis_dpvreq_tranid,
{"Transaction Id", "docsis_dpvreq.tranid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpvreq_dschan,
{"Downstream Channel ID", "docsis_dpvreq.dschan",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpvreq_flags,
{"Flags", "docsis_dpvreq.flags",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpvreq_us_sf,
{"Upstream Service Flow ID", "docsis_dpvreq.us_sf",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpvreq_n,
{"N (Measurement avaraging factor)", "docsis_dpvreq.n",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpvreq_start,
{"Start Reference Point", "docsis_dpvreq.start",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpvreq_end,
{"End Reference Point", "docsis_dpvreq.end",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpvreq_ts_start,
{"Timestamp Start", "docsis_dpvreq.ts_start",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpvreq_ts_end,
{"Timestamp End", "docsis_dpvreq.ts_end",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_dpvreq,
};
proto_docsis_dpvreq =
proto_register_protocol ("DOCSIS Path Verify Request",
"DOCSIS DPV-REQ", "docsis_dpvreq");
proto_register_field_array (proto_docsis_dpvreq, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_dpvreq", dissect_dpvreq, proto_docsis_dpvreq);
}
void
proto_reg_handoff_docsis_dpvreq (void)
{
dissector_handle_t docsis_dpvreq_handle;
docsis_dpvreq_handle = find_dissector ("docsis_dpvreq");
dissector_add_uint ("docsis_mgmt", 0x27, docsis_dpvreq_handle);
}
