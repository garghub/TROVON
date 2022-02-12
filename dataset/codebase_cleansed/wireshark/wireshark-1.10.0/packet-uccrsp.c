static void
dissect_uccrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *it;
proto_tree *uccrsp_tree;
guint8 chid;
chid = tvb_get_guint8 (tvb, 0);
col_clear (pinfo->cinfo, COL_INFO);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Upstream Channel Change response Channel ID = %u (U%u)",
chid, (chid > 0 ? chid - 1 : chid));
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_uccrsp, tvb, 0, -1,
"UCC Response");
uccrsp_tree = proto_item_add_subtree (it, ett_docsis_uccrsp);
proto_tree_add_item (uccrsp_tree, hf_docsis_uccrsp_upchid, tvb, 0, 1,
ENC_BIG_ENDIAN);
}
}
void
proto_register_docsis_uccrsp (void)
{
static hf_register_info hf[] = {
{&hf_docsis_uccrsp_upchid,
{"Upstream Channel Id", "docsis_uccrsp.upchid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_uccrsp,
};
proto_docsis_uccrsp =
proto_register_protocol ("DOCSIS Upstream Channel Change Response",
"DOCSIS UCC-RSP", "docsis_uccrsp");
proto_register_field_array (proto_docsis_uccrsp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_uccrsp", dissect_uccrsp, proto_docsis_uccrsp);
}
void
proto_reg_handoff_docsis_uccrsp (void)
{
dissector_handle_t docsis_uccrsp_handle;
docsis_uccrsp_handle = find_dissector ("docsis_uccrsp");
dissector_add_uint ("docsis_mgmt", 0x09, docsis_uccrsp_handle);
}
