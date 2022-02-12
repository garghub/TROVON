static int
rs_acct_dissect_lookup_rqst (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint32 key_size;
const char *keyx_t = NULL;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_rs_acct_lookup_rqst_var, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_rs_acct_lookup_rqst_key_size, &key_size);
if (key_size){
proto_tree_add_item (tree, hf_rs_acct_lookup_rqst_key_t, tvb, offset, key_size, ENC_ASCII|ENC_NA);
keyx_t = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, key_size, ENC_ASCII);
offset += key_size;
col_append_fstr(pinfo->cinfo, COL_INFO,
" Request for: %s ", keyx_t);
} else {
col_append_str(pinfo->cinfo, COL_INFO,
" Request (other)");
}
return offset;
}
static int
rs_acct_dissect_get_projlist_rqst (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint32 key_size;
const char *keyx_t = NULL;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_rs_acct_get_projlist_rqst_var1, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_rs_acct_get_projlist_rqst_key_size, &key_size);
proto_tree_add_item (tree, hf_rs_acct_get_projlist_rqst_key_t,
tvb, offset, key_size, ENC_ASCII|ENC_NA);
keyx_t = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, key_size, ENC_ASCII);
offset += key_size;
col_append_fstr(pinfo->cinfo, COL_INFO,
" Request for: %s", keyx_t);
return offset;
}
void
proto_register_rs_acct (void)
{
static hf_register_info hf[] = {
{ &hf_rs_acct_opnum,
{ "Operation", "rs_acct.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rs_acct_lookup_rqst_var,
{ "Var", "rs_acct.lookup_rqst_var", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rs_acct_lookup_rqst_key_size,
{ "Key Size", "rs_acct.lookup_rqst_key_size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rs_acct_lookup_rqst_key_t,
{ "Key", "rs_acct.lookup_rqst_key_t", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rs_acct_get_projlist_rqst_var1,
{ "Var1", "rs_acct.get_projlist_rqst_var1", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rs_acct_get_projlist_rqst_key_size,
{ "Var1", "rs_acct.get_projlist_rqst_key_size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rs_acct_get_projlist_rqst_key_t,
{ "Var1", "rs_acct.get_projlist_rqst_key_t", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_rs_acct,
};
proto_rs_acct = proto_register_protocol ("DCE/RPC RS_ACCT", "RS_ACCT", "rs_acct");
proto_register_field_array (proto_rs_acct, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_acct (void)
{
dcerpc_init_uuid (proto_rs_acct, ett_rs_acct, &uuid_rs_acct, ver_rs_acct, rs_acct_dissectors, hf_rs_acct_opnum);
}
